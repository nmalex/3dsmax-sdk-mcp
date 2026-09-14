"""Barebones Object Snap (Python lane) - contributes a snap point; here, contributes none.

WHAT AN OSNAP CARTRIDGE IS. It appears in Grid and Snap Settings as a snap the user can enable. While
the user drags with snapping on, 3ds Max asks each active snap for candidate points near the cursor;
the slot forwards that as `OsnapSnap`. A real snap returns points of interest on an object (a
midpoint, a centre); this barebones returns none and says hello, so you can prove the snap is
registered and asked before computing any geometry.

WHICH SLOT HOSTS IT. The payload the `Cartridge Snap` slot loads by its fixed module name,
`slot_osnap`, registering one SuperClassID: OSNAP_CLASS_ID.

THE HELLO. Logged once from `OsnapSnap`. Trigger it by enabling this snap in Grid and Snap Settings
and moving the cursor over an object while creating or moving, then read
`cartridge_logs -module slot_osnap`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Object Snap (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def OsnapSnap(**event):
    """Called while snapping to gather candidate points. A real snap returns points; this returns none."""
    _hello_once("snap query (OsnapSnap)")
    return {"points": [], "lane": "python"}


def describe(params=None):
    return {"payload": "slot_osnap", "version": "0.1.0", "lane": "python",
            "example": "barebones/osnap"}
