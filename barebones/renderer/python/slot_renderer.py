"""Barebones Renderer (Python lane) - a Choose-Renderer plugin; here, renders nothing.

WHAT A RENDERER CARTRIDGE IS. The user picks it in the Render Setup > Renderer rollout (Choose
Renderer). When a render runs, 3ds Max opens the renderer, asks it to render each frame, and closes
it; the slot forwards those as `RenderOpen` and `RenderRender`. A real renderer produces an image; a
barebones renderer leaves the output untouched and says hello, so you can prove the plugin is picked
and driven before writing a single ray.

WHICH SLOT HOSTS IT. The payload the `Cartridge Renderer` slot loads by its fixed module name,
`slot_renderer`, registering one SuperClassID: RENDERER_CLASS_ID. It is deliberately its own slot,
separate from the render EFFECT (see barebones/effect): they are different plugin kinds the user
picks in different places.

THE HELLO. Logged once from a dispatched function - `RenderOpen` fires when a render begins. Trigger
it by starting any render with this renderer chosen, then read `cartridge_logs -module slot_renderer`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Renderer (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def RenderOpen(**event):
    """Called once when a render begins, before any frame."""
    _hello_once("render open (RenderOpen)")
    return {"ok": True, "lane": "python"}


def RenderRender(**event):
    """Called once per frame. A real renderer writes the output bitmap here; this one does not."""
    _hello_once("frame (RenderRender)")
    return {"rendered": False, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_renderer", "version": "0.1.0", "lane": "python",
            "example": "barebones/renderer"}


def init(**env):
    """Load-time crossing (FR-0006). The slot calls this at 3ds Max startup (NOTIFY_SYSTEM_STARTUP),
    before any host action, handing the environment only the slot can see. This is the INIT REPORT: it
    records that the cartridge loaded and the world it loaded into. It is deliberately NOT the
    cartridge's greeting - the greeting is logged only by the cartridge's own behaviour (the body
    above), so a load report is never mistaken for the thing working. `env` carries: maxRelease, slotName,
    slotVersion, cartridgeAbi, gup."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The symmetric unload crossing: the slot calls this from LibShutdown. This is the UNLOAD REPORT -
    the cartridge records that it is being torn down and releases anything it held. Like init, it never
    logs the greeting; only the cartridge's own behaviour does that."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}
