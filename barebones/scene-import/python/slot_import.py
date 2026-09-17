"""Barebones Importer (Python lane) - a File > Import handler that imports nothing.

A scene importer claims a file extension and turns a file of that type into scene content - the
sibling of the exporter. This one claims a made-up .cart extension and imports nothing; the greeting
fires the first time a file of its type is imported. Deployed as `slot_import`.
Read the hello with `cartridge_logs -module slot_import`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Importer (Python) is live; this line came "
                          "from its payload the first time a file of this importer's type was imported.")
    return {"name": "Cartridge Importer"}


def describe(params=None):
    return {"payload": "slot_import", "version": "0.1.0", "lane": "python",
            "example": "barebones/scene-import"}


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
