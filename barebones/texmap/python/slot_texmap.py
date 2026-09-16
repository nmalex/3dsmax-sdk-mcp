"""Barebones Texture Map (Python lane) - a checker map. Python bakes the checker; the slot samples it.

WHAT A TEXTURE MAP CARTRIDGE IS. A map the user puts in any material's map slot (Material Editor >
Maps > MCP Cartridges > Cartridge Texture Map). The renderer asks it for a colour at every shading
sample, on its own threads, millions of times a frame.

PER-SAMPLE WORK IS NEVER A PYTHON CALL: the cost is wrong and the render threads cannot wait on an
interpreter. So the slot runs in one of two modes:

  * MANAGED - this file. When the map updates (main thread), `TexmapUpdate` BAKES the checker into a
    small image - one texel per tile - and returns it. The slot keeps that image and, for every
    sample, looks up the texel under the sample's UV (nearest, tiled) natively. Change a spinner and
    the next update bakes a new one. This payload also declares the parameters (the slot keeps them -
    saved, animatable, `$.tiles`) and builds the panel in the Material Editor.
  * UNMANAGED - ../native/src/payload.cpp. A native payload that exports MaxMcpGetUnmanaged is pinned
    and called per sample; it computes the same checker from the sample's UV directly. It includes no
    3ds Max SDK header: it reads each sample through the facade's ShadeSample* entries. In that mode
    this Python lane is refused - an unmanaged slot is native-only.

HOW TO SEE IT WORK. Put the map in a material's Diffuse slot and render a Plane: a `tiles` x `tiles`
checker of `bright` and `dark` grey over its UVs.

WHICH SLOT HOSTS IT. The payload the `Cartridge Texture Map` slot loads by its fixed module name,
`slot_texmap`, registering TEXMAP_CLASS_ID with the standard Coordinates rollout. See README.md.

THE HELLO. Logged once from `TexmapUpdate`, which the slot calls when 3ds Max updates the map before
using it - opening it in the Material Editor, rendering, or `renderMap`. Read it with
`cartridge_logs -module slot_texmap`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

_DEFAULTS = {"tiles": 4.0, "bright": 0.9, "dark": 0.1}


def _p(params):
    merged = dict(_DEFAULTS)
    for key in _DEFAULTS:
        if params and key in params:
            merged[key] = float(params[key])
    return merged


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Texture Map (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe_params():
    """The checker's three numbers. The slot keeps them; both lanes draw with them."""
    return {
        "parameters": [
            {"name": "tiles", "type": "float", "default": _DEFAULTS["tiles"]},
            {"name": "bright", "type": "float", "default": _DEFAULTS["bright"]},
            {"name": "dark", "type": "float", "default": _DEFAULTS["dark"]},
        ],
    }


def describe_ui(params=None, **kwargs):
    """The Material Editor rollout: three bound spinners."""
    p = _p(params)
    return ui.build(
        ui.VBox(
            ui.Label("Checker"),
            ui.Spacer(),
            ui.Field("Tiles:", ui.Spinner(value=p["tiles"], minimum=0.01, maximum=1000.0,
                                          step=0.1, param="tiles")),
            ui.Field("Bright:", ui.Spinner(value=p["bright"], minimum=0.0, maximum=1.0,
                                           step=0.01, param="bright")),
            ui.Field("Dark:", ui.Spinner(value=p["dark"], minimum=0.0, maximum=1.0,
                                         step=0.01, param="dark")),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """A spinner moved. The slot has already saved it; `invalidate` re-renders the sample slot."""
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def _bake(p):
    """The checker as an image: `tiles` texels a side, one per tile, row 0 at V = 0. The slot tiles it
    over UV 0..1, so texel (x, y) covers exactly tile (x, y)."""
    n = max(1, min(256, int(round(p["tiles"]))))
    rgb = []
    for y in range(n):
        for x in range(n):
            v = p["bright"] if (x + y) % 2 == 0 else p["dark"]
            rgb.extend((v, v, v))
    return {"width": n, "height": n, "rgb": rgb}


def TexmapUpdate(**event):
    """The map is being updated before use. Main thread; `params` are the slot's current values.
    Returns the IMAGE the slot shows until the next update."""
    _hello_once("update (TexmapUpdate)")
    p = _p(event.get("params"))
    return {"ok": True, "lane": "python", "mode": "managed", "params": p, "image": _bake(p)}


def describe(params=None):
    return {"payload": "slot_texmap", "version": "0.1.0", "lane": "python",
            "example": "barebones/texmap"}


def init(**env):
    """Load-time crossing: the INIT REPORT, never the greeting. `env` carries: maxRelease, slotName,
    slotVersion, cartridgeAbi, gup."""
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
