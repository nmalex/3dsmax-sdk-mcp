"""Barebones Shader (Python lane) - a tinted Lambert shading model for the Standard material. Python
picks the tint; the slot lights with it.

WHAT A SHADER CARTRIDGE IS. A shading model in the Standard material's Shader dropdown, beside Blinn,
Phong, Metal and Strauss. The material textures its inputs (diffuse, specular, glossiness, opacity,
filter) and hands them to the shader for every sample, on the render threads, to be lit.

PER-SAMPLE WORK IS NEVER A PYTHON CALL. So the slot runs in one of two modes:

  * MANAGED - this file. When the material updates its shader (main thread), `ShaderUpdate` returns a
    TINT - `hue` at saturation `strength`. The slot lights the material's diffuse input with a plain
    Lambert term and multiplies it by that tint, for every sample, natively. This payload also
    declares the parameters (the slot keeps them - saved, animatable) and builds the panel beside the
    slot's About in the material's shader rollout. `wrap` and `rim` are the native lane's.
  * UNMANAGED - ../native/src/payload.cpp. A native payload that exports MaxMcpGetUnmanaged is pinned
    and called per sample; it reads the material's inputs (ShadeSampleIllumRead) and lights them with
    WRAP lighting and a rim term, from these same parameters - with no 3ds Max SDK header. In that mode
    this Python lane is refused. It applies the same tint.

HOW TO SEE IT WORK. In a Standard material pick Shader: Cartridge Shader, leave Diffuse white, and
render a Teapot: it comes out in the tint colour.

WHICH SLOT HOSTS IT. The payload the `Cartridge Shader` slot loads by its fixed module name,
`slot_shader`, registering SHADER_CLASS_ID. The shader's texture channels are: 0 Diffuse Color,
1 Specular Color, 2 Glossiness, 3 Opacity, 4 Filter Color. See README.md.

THE HELLO. Logged once from `ShaderUpdate`, which the slot calls when the material updates its shader
before a render. Read it with `cartridge_logs -module slot_shader`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

_DEFAULTS = {"hue": 0.08, "strength": 0.7, "wrap": 0.5, "rim": 0.2}


def _p(params):
    merged = dict(_DEFAULTS)
    for key in _DEFAULTS:
        if params and key in params:
            merged[key] = float(params[key])
    return merged


def _hsv(h, s, v):
    """A colour from hue (0..1, wraps), saturation and value - colorsys, without the import."""
    h = (h % 1.0) * 6.0
    i = int(h)
    f = h - i
    p, q, t = v * (1.0 - s), v * (1.0 - s * f), v * (1.0 - s * (1.0 - f))
    return [(v, t, p), (q, v, p), (p, v, t), (p, q, v), (t, p, v), (v, p, q)][i % 6]


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Shader (Python) is live; this line came from its "
                          "payload on the first %s." % where)


def describe_params():
    return {
        "parameters": [
            {"name": "hue", "type": "float", "default": _DEFAULTS["hue"]},
            {"name": "strength", "type": "float", "default": _DEFAULTS["strength"]},
            {"name": "wrap", "type": "float", "default": _DEFAULTS["wrap"]},
            {"name": "rim", "type": "float", "default": _DEFAULTS["rim"]},
        ],
    }


def describe_ui(params=None, **kwargs):
    p = _p(params)
    return ui.build(
        ui.VBox(
            ui.Label("Tint (both modes); wrap and rim (unmanaged)"),
            ui.Spacer(),
            ui.Field("Hue:", ui.Spinner(value=p["hue"], minimum=0.0, maximum=1.0, step=0.01,
                                        param="hue")),
            ui.Field("Strength:", ui.Spinner(value=p["strength"], minimum=0.0, maximum=1.0,
                                             step=0.01, param="strength")),
            ui.Field("Wrap:", ui.Spinner(value=p["wrap"], minimum=0.0, maximum=1.0, step=0.01,
                                         param="wrap")),
            ui.Field("Rim:", ui.Spinner(value=p["rim"], minimum=0.0, maximum=1.0, step=0.01,
                                        param="rim")),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def ShaderUpdate(**event):
    """The material is updating its shader before use. Main thread."""
    _hello_once("update (ShaderUpdate)")
    p = _p(event.get("params"))
    return {"ok": True, "lane": "python", "mode": "managed", "params": p,
            "tint": list(_hsv(p["hue"], min(1.0, max(0.0, p["strength"])), 1.0))}


def describe(params=None):
    return {"payload": "slot_shader", "version": "0.1.0", "lane": "python",
            "example": "barebones/shader"}


def init(**env):
    """Load-time crossing: the INIT REPORT, never the greeting."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The UNLOAD REPORT - never the greeting."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}
