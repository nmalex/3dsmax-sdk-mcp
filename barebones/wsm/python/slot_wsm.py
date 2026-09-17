"""Barebones WSM (Python lane) - a world-space modifier that deforms nothing.

A world-space modifier (WSM) is the sibling of the object-space modifier, evaluated in world space -
its effect depends on where the object sits in the scene. This one deforms nothing; the greeting
fires the first time the host asks it for its class name. Deployed as `slot_wsm`.
Read the hello with `cartridge_logs -module slot_wsm`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones WSM (Python) is live; this line came "
                          "from its payload the first time the host asked the WSM for its class name.")
    return {"name": "Cartridge WSM"}


def describe(params=None):
    return {"payload": "slot_wsm", "version": "0.1.0", "lane": "python",
            "example": "barebones/wsm"}


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
