"""Barebones Render Element (Python lane) - a render pass that outputs nothing.

A render element is one output pass of a render (diffuse, z-depth, an AO channel...), added in Render
Setup > Render Elements and written as its own image. This one outputs no channel; the greeting fires
the first time the render manager asks the element for its name. Deployed as `slot_renderelement`.
Read the hello with `cartridge_logs -module slot_renderelement`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Render Element (Python) is live; this line came "
                          "from its payload the first time the render manager asked the element for its name.")
    return {"name": "Cartridge Render Element"}


def describe(params=None):
    return {"payload": "slot_renderelement", "version": "0.1.0", "lane": "python",
            "example": "barebones/render-element"}


def init(**env):
    mcp_bootstrap.log("display",
                      "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge "
                      "ABI %s, gup present=%s. This is the init report, not the cartridge greeting."
                      % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
                         env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}
