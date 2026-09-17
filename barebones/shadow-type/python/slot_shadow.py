"""Barebones Shadow (Python lane) - a shadow generator that casts no shadow.

A shadow type is the plugin a light uses to cast shadows; each light picks one in its Shadow-type
dropdown. The slot registers one whose generator makes no shadow (fully lit); the greeting fires the
first time the renderer asks this type for a generator. Deployed as `slot_shadow`.
Read the hello with `cartridge_logs -module slot_shadow`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Shadow (Python) is live; this line came "
                          "from its payload the first time the renderer asked this type for a shadow generator.")
    return {"name": "Cartridge Shadow"}


def describe(params=None):
    return {"payload": "slot_shadow", "version": "0.1.0", "lane": "python",
            "example": "barebones/shadow-type"}


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
