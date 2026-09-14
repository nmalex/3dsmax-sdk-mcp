"""Barebones Video Post Filter (Python lane) - TEMPLATE, slot pending.

A Video Post image-processing filter - runs in the Video Post queue over a rendered image.

This plugin type is in the super-class census (SuperClassID FLT_CLASS_ID) but no slot ships for it yet, so
this payload cannot be loaded in the host today. It shows the shape: a hello logged from a dispatched
function (never at import - only a dispatched call's output is captured into cartridge_logs). When a
videopost-filter slot ships, wire this hello into the function that slot dispatches, and add your behaviour.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Video Post Filter (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe(params=None):
    return {"payload": "slot_flt", "version": "0.1.0", "lane": "python",
            "example": "barebones/videopost-filter", "template": True,
            "superClassId": "FLT_CLASS_ID"}
