"""Barebones Bitmap IO (Python lane) - an image-format handler that reads nothing.

A bitmap I/O plugin is the loader/saver behind an image file format (the .tga, .png, .exr handlers
are all one). This one claims a made-up .cbmp extension and reads nothing; the greeting fires the
first time the host inspects an image of its type. Deployed as `slot_bmio`.
Read the hello with `cartridge_logs -module slot_bmio`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Bitmap IO (Python) is live; this line came "
                          "from its payload the first time an image of its format was inspected.")
    return {"name": "Cartridge Bitmap IO"}


def describe(params=None):
    return {"payload": "slot_bmio", "version": "0.1.0", "lane": "python",
            "example": "barebones/bitmap-io"}


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
