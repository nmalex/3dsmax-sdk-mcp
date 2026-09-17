"""Barebones Texmap Container (Python lane) - a container that holds no texmaps.

A texmap container is the super-class whose objects hold texmaps for another plugin (the normal-bump
and vector-displacement maps are built on it). This one holds nothing; the greeting fires the first
time the host asks the object for its class name. Deployed as `slot_texcontainer`.
Read the hello with `cartridge_logs -module slot_texcontainer`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Texmap Container (Python) is live; this line came "
                          "from its payload the first time the host asked the container for its class name.")
    return {"name": "Cartridge Texmap Container"}


def describe(params=None):
    return {"payload": "slot_texcontainer", "version": "0.1.0", "lane": "python",
            "example": "barebones/texmap-container"}


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
