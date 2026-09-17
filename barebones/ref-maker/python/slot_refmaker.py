"""Barebones Ref Maker (Python lane) - a plain reference maker that makes no references.

A reference maker is the raw base of the reference system: something that holds references to other
objects but is not itself referenceable. This one makes no references; the greeting would fire the
first time the host asks it for its class name. Deployed as `slot_refmaker`.
Read the hello with `cartridge_logs -module slot_refmaker`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Ref Maker (Python) is live; this line came "
                          "from its payload the first time the host asked the maker for its class name.")
    return {"name": "Cartridge Ref Maker"}


def describe(params=None):
    return {"payload": "slot_refmaker", "version": "0.1.0", "lane": "python",
            "example": "barebones/ref-maker"}


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
