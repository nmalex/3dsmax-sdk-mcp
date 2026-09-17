"""Barebones TrackView Utility (Python lane) - a Track View tool that does nothing.

A Track View utility is a tool in Track View's Utilities menu that can read and edit the selected
tracks - the sibling of the command-panel Utility, hosted in Track View. This one does nothing; the
greeting fires the first time it is opened in Track View. Deployed as `slot_tvutil`.
Read the hello with `cartridge_logs -module slot_tvutil`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones TrackView Utility (Python) is live; this line came "
                          "from its payload the first time the utility was opened in Track View.")
    return {"name": "Cartridge TrackView Utility"}


def describe(params=None):
    return {"payload": "slot_tvutil", "version": "0.1.0", "lane": "python",
            "example": "barebones/trackview-utility"}


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
