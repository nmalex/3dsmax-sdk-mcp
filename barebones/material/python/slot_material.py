"""Barebones Material (Python lane) - a coloured, lit material. Python picks the colour; the slot
lights it.

WHAT A MATERIAL CARTRIDGE IS. A material the user assigns to objects (Material Editor > Materials >
MCP Cartridges > Cartridge Material). The renderer asks it to shade every sample, on its own threads,
millions of times a frame.

PER-SAMPLE WORK IS NEVER A PYTHON CALL. So the slot runs in one of two modes:

  * MANAGED - this file. When the material updates (main thread), `MtlUpdate` returns the material's
    COLOUR - `hue` at brightness `base`. The slot shades every sample with that colour lit by the
    scene's lights plus ambient (Lambert), natively; the viewport shows it too. This payload also
    declares the parameters (the slot keeps them - saved, animatable, `$.hue`) and builds the panel.
    `rim` and `lit` are the native lane's.
  * UNMANAGED - ../native/src/payload.cpp. A native payload that exports MaxMcpGetUnmanaged is pinned
    and called per sample; it lights the sample itself (ShadeSampleLight) and adds a rim term, from
    these same parameters - with no 3ds Max SDK header. In that mode this Python lane is refused.

HOW TO SEE IT WORK. Assign it to a Teapot and render: a teapot in the `hue` colour, shaded by the
lights - not the grey a slot with no cartridge answers.

WHICH SLOT HOSTS IT. The payload the `Cartridge Material` slot loads by its fixed module name,
`slot_material`, registering MATERIAL_CLASS_ID. See README.md.

THE HELLO. Logged once from `MtlUpdate`, which the slot calls when 3ds Max updates the material
before a render or the Material Editor's sample slot. Read it with
`cartridge_logs -module slot_material`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

_DEFAULTS = {"hue": 0.58, "base": 0.8, "rim": 0.3, "lit": True}


def _p(params):
    merged = dict(_DEFAULTS)
    if params:
        for key in _DEFAULTS:
            if key in params:
                merged[key] = params[key]
    merged["hue"] = float(merged["hue"])
    merged["base"] = float(merged["base"])
    merged["rim"] = float(merged["rim"])
    merged["lit"] = bool(merged["lit"])
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
                          "Hello World - Barebones Material (Python) is live; this line came from its "
                          "payload on the first %s." % where)


def describe_params():
    return {
        "parameters": [
            {"name": "hue", "type": "float", "default": _DEFAULTS["hue"]},
            {"name": "base", "type": "float", "default": _DEFAULTS["base"]},
            {"name": "rim", "type": "float", "default": _DEFAULTS["rim"]},
            {"name": "lit", "type": "bool", "default": _DEFAULTS["lit"]},
        ],
    }


def describe_ui(params=None, **kwargs):
    p = _p(params)
    return ui.build(
        ui.VBox(
            ui.Label("Colour (both modes); rim and lit (unmanaged)"),
            ui.Spacer(),
            ui.Field("Hue:", ui.Spinner(value=p["hue"], minimum=0.0, maximum=1.0, step=0.01,
                                        param="hue")),
            ui.Field("Base:", ui.Spinner(value=p["base"], minimum=0.0, maximum=1.0, step=0.01,
                                         param="base")),
            ui.Field("Rim:", ui.Spinner(value=p["rim"], minimum=0.0, maximum=1.0, step=0.01,
                                        param="rim")),
            ui.CheckBox("Lit by scene lights", checked=p["lit"], param="lit"),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def MtlUpdate(**event):
    """The material is being updated before use. Main thread; `params` are the slot's values."""
    _hello_once("update (MtlUpdate)")
    p = _p(event.get("params"))
    return {"ok": True, "lane": "python", "mode": "managed", "params": p,
            "color": list(_hsv(p["hue"], 0.75, p["base"]))}


def describe(params=None):
    return {"payload": "slot_material", "version": "0.1.0", "lane": "python",
            "example": "barebones/material"}


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
