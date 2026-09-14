"""Barebones Data Channel Engine (Python lane) - TEMPLATE, slot pending.

A Data Channel modifier engine (IDataChannelEngine) - one operator in the Data Channel modifier's stack.

This plugin type is in the super-class census (SuperClassID DATACHANNELENGINE_SUPER_CLASS_ID) but no slot ships for it yet, so
this payload cannot be loaded in the host today. It shows the shape: a hello logged from a dispatched
function (never at import - only a dispatched call's output is captured into cartridge_logs). When a
datachannel-engine slot ships, wire this hello into the function that slot dispatches, and add your behaviour.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Data Channel Engine (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe(params=None):
    return {"payload": "slot_dcengine", "version": "0.1.0", "lane": "python",
            "example": "barebones/datachannel-engine", "template": True,
            "superClassId": "DATACHANNELENGINE_SUPER_CLASS_ID"}
