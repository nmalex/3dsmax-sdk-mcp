"""Soap Bubble (Python lane) - a thin-film soap bubble as a MANAGED look.

WHAT THIS IS. The Python lane of the Soap Bubble material. Python never runs per shading sample: the
Cartridge Material slot calls `MtlUpdate` on the main thread when the material updates, and shades
every sample from what it returns - a LOOK (docs/SLOTS.md, "A managed look"). This lane bakes the
film into that look:

  image   the film's interference colour over the bubble's UVs - the same thickness model and the
          same spectral integration as the C++ lane, evaluated at normal incidence and baked into a
          96 x 48 image each update;
  ramp    by facing: brighter towards the rim, where a real film reflects more (Fresnel);
  rim     a white edge;
  lit     off - a soap film is reflection, not diffuse shading;
  opacity mostly transparent, so the background shows through.

WHAT IT CANNOT DO, AND THE C++ LANE DOES. A look is evaluated per sample by the slot, from fixed
inputs: the colour cannot shift with the viewing angle, the transparency cannot vary across the
bubble, and nothing reflects the lights. The C++ lane (../native/src/payload.cpp) runs the full
interference calculation for every sample, reflects a studio and the lights, and flows with the scene
time. Deploy it to see the real thing; this lane is the portable approximation.

ANIMATION. The update event carries no time, so the film moves with the `phase` parameter: key it
(the scene script does) and every frame bakes a new image.

WHICH SLOT HOSTS IT. The Cartridge Material, which loads the module `slot_material`. See README.md.
"""

import math

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

# The same parameters as the C++ lane, in the same order.
_PARAMS = (
    ("thickness_top", 150.0, 0.0, 2000.0, 5.0, "Top (nm):"),
    ("thickness_bottom", 600.0, 0.0, 2000.0, 5.0, "Bottom (nm):"),
    ("swirl", 320.0, 0.0, 1000.0, 5.0, "Swirl (nm):"),
    ("swirl_scale", 3.0, 0.1, 20.0, 0.1, "Swirl size:"),
    ("flow", 0.25, 0.0, 5.0, 0.01, "Flow speed:"),
    ("phase", 0.0, -1000.0, 1000.0, 0.01, "Phase:"),
    ("reflection", 1.0, 0.0, 5.0, 0.05, "Reflection:"),
    ("glints", 1.0, 0.0, 5.0, 0.05, "Glints:"),
)

FILM_IOR = 1.33
IMAGE_W, IMAGE_H = 96, 48


def _p(params):
    params = params or {}
    return {name: float(params.get(name, default)) for name, default, _lo, _hi, _step, _label in _PARAMS}


# -- colour science: the same table as the C++ lane -------------------------------------------------

def _lobe(x, mu, s1, s2):
    t = (x - mu) / (s1 if x < mu else s2)
    return math.exp(-0.5 * t * t)


def _spectrum(count=16):
    rows, total = [], [0.0, 0.0, 0.0]
    for i in range(count):
        lam = 400.0 + 300.0 * i / (count - 1)
        # CIE 1931 colour matching functions, Wyman et al. 2013 multi-lobe fit.
        x = 1.056 * _lobe(lam, 599.8, 37.9, 31.0) + 0.362 * _lobe(lam, 442.0, 16.0, 26.7) \
            - 0.065 * _lobe(lam, 501.1, 20.4, 26.2)
        y = 0.821 * _lobe(lam, 568.8, 46.9, 40.5) + 0.286 * _lobe(lam, 530.9, 16.3, 31.1)
        z = 1.217 * _lobe(lam, 437.0, 11.8, 36.0) + 0.681 * _lobe(lam, 459.0, 26.0, 13.8)
        rgb = (3.2406 * x - 1.5372 * y - 0.4986 * z,
               -0.9689 * x + 1.8758 * y + 0.0415 * z,
               0.0557 * x - 0.2040 * y + 1.0570 * z)
        rows.append((lam, rgb))
        total = [total[c] + rgb[c] for c in range(3)]
    return [(lam, tuple(rgb[c] / total[c] for c in range(3))) for lam, rgb in rows]


_SPECTRUM = _spectrum()


def _film_rgb(d):
    """The film's reflectance at normal incidence, as linear RGB, for thickness d (nm)."""
    f = ((FILM_IOR - 1.0) / (FILM_IOR + 1.0)) ** 2
    phase = 4.0 * math.pi * FILM_IOR * max(0.0, d)
    out = [0.0, 0.0, 0.0]
    for lam, w in _SPECTRUM:
        cd = math.cos(phase / lam)
        r = 2.0 * f * (1.0 - cd) / (1.0 + f * f - 2.0 * f * cd)
        for c in range(3):
            out[c] += r * w[c]
    return [max(0.0, v) for v in out]


# -- the film's thickness: the same model as the C++ lane ----------------------------------------------

def _hash(x, y, z):
    h = (x * 374761393 + y * 668265263 + z * 2147483647) & 0xFFFFFFFF
    h = ((h ^ (h >> 13)) * 1274126177) & 0xFFFFFFFF
    h ^= h >> 16
    return (h & 0xFFFFFF) / float(0xFFFFFF)


def _smooth(t):
    return t * t * (3.0 - 2.0 * t)


def _noise(x, y, z):
    xi, yi, zi = math.floor(x), math.floor(y), math.floor(z)
    xf, yf, zf = _smooth(x - xi), _smooth(y - yi), _smooth(z - zi)
    xi, yi, zi = int(xi), int(yi), int(zi)

    def lerp(a, b, t):
        return a + (b - a) * t

    x00 = lerp(_hash(xi, yi, zi), _hash(xi + 1, yi, zi), xf)
    x10 = lerp(_hash(xi, yi + 1, zi), _hash(xi + 1, yi + 1, zi), xf)
    x01 = lerp(_hash(xi, yi, zi + 1), _hash(xi + 1, yi, zi + 1), xf)
    x11 = lerp(_hash(xi, yi + 1, zi + 1), _hash(xi + 1, yi + 1, zi + 1), xf)
    return lerp(lerp(x00, x10, yf), lerp(x01, x11, yf), zf)


def _fbm(x, y, z, octaves=4):
    total, amp = 0.0, 0.5
    for _ in range(octaves):
        total += amp * _noise(x, y, z)
        x, y, z = x * 2.03 + 11.7, y * 2.03 + 3.1, z * 2.03 + 7.3
        amp *= 0.5
    return total


def _thickness(p, u, v):
    height = min(1.0, max(0.0, v))
    d = p["thickness_bottom"] + (p["thickness_top"] - p["thickness_bottom"]) * height ** 1.6
    angle = 2.0 * math.pi * u
    radius = p["swirl_scale"] / (2.0 * math.pi) * 2.0
    x, y = math.cos(angle) * radius, math.sin(angle) * radius
    along = p["phase"]
    z = height * p["swirl_scale"] - along
    wx = _fbm(x + 5.2, y + 1.3, z + along * 0.5, 3)
    wy = _fbm(x + 1.7, y + 9.2, z - along * 0.3, 3)
    x += 2.5 * (wx - 0.47)
    y += 2.5 * (wy - 0.47)
    d += p["swirl"] * 2.0 * (_fbm(x, y, z, 3) - 0.47)
    if height > 0.97:
        d *= max(0.0, (1.0 - height) / 0.03)
    return max(0.0, d)


def _bake(p):
    """The film as an image over UV: row 0 is v = 0 (the bottom of the bubble)."""
    rgb = []
    for row in range(IMAGE_H):
        v = (row + 0.5) / IMAGE_H
        for col in range(IMAGE_W):
            u = (col + 0.5) / IMAGE_W
            film = _film_rgb(_thickness(p, u, v))
            # A film reflects a few percent; the image carries its COLOUR, brightened to be seen,
            # and the ramp below decides how much of it shows where.
            peak = max(max(film), 1e-4)
            gain = min(1.0 / peak, 12.0)
            rgb.extend(min(1.0, c * gain) for c in film)
    return {"width": IMAGE_W, "height": IMAGE_H, "rgb": rgb}


# -- the payload protocol --------------------------------------------------------------------------------

def _hello_once():
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Soap Bubble (Python, managed) is live: the film is baked into a "
                          "look on each update.")


def describe_params():
    return {"parameters": [{"name": name, "type": "float", "default": default}
                           for name, default, _lo, _hi, _step, _label in _PARAMS]}


def describe_ui(params=None, **kwargs):
    p = _p(params)
    rows = [ui.Label("Soap film"), ui.Spacer()]
    for name, _default, lo, hi, step, label in _PARAMS:
        rows.append(ui.Field(label, ui.Spinner(value=p[name], minimum=lo, maximum=hi, step=step,
                                               param=name)))
    return ui.build(ui.VBox(*rows))


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def MtlUpdate(**event):
    """The material is being updated before use: bake the film into a look."""
    _hello_once()
    p = _p(event.get("params"))
    edge = min(1.0, 0.9 * p["reflection"])
    centre = min(1.0, 0.25 * p["reflection"])
    return {
        "ok": True,
        "image": _bake(p),
        "ramp": {"by": "facing", "colors": [[edge] * 3, [centre] * 3], "range": [0.0, 1.0],
                 "smooth": True},
        "lit": False,
        "rim": {"color": [0.9, 0.9, 1.0], "power": 5.0},
        "opacity": 0.3,
    }


def describe(params=None):
    return {"payload": "soap_bubble", "version": "0.1.0", "lane": "python",
            "example": "examples/soap-bubble"}


def init(**env):
    """Load-time crossing: the INIT REPORT, never the greeting."""
    mcp_bootstrap.log("display", "Soap Bubble payload (Python) init on load, slot v%s."
                      % env.get("slotVersion"))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The UNLOAD REPORT - never the greeting."""
    mcp_bootstrap.log("display", "Soap Bubble payload (Python) shutdown on slot unload.")
    return {"ok": True}
