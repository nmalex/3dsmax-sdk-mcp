"""Barebones Global Utility (Python lane) - an always-loaded service that does nothing.

A Global Utility Plugin (GUP) is a service 3ds Max starts at boot and stops at exit - this MCP server
is itself a GUP. This one runs nothing; the greeting fires once the system has finished starting
(the slot defers it there, since the payload runtime is not up during boot). Deployed as `slot_gup`.
Read the hello with `cartridge_logs -module slot_gup`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Global Utility (Python) is live; this line came "
                          "from its payload once the system had finished starting.")
    return {"name": "Cartridge Global Utility"}


def describe(params=None):
    return {"payload": "slot_gup", "version": "0.1.0", "lane": "python",
            "example": "barebones/global-utility"}


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
