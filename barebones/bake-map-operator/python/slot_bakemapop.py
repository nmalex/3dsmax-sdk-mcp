"""Barebones Bake Map Operator (Python lane) - TEMPLATE, slot pending.

A Bake To Texture bake-map operator - an operator over a common bake map.

This plugin type is in the super-class census (SuperClassID COMMON_BAKE_MAP_OPERATOR_CLASS_ID) but no slot ships for it yet, so
this payload cannot be loaded in the host today. It shows the shape: a hello logged from a dispatched
function (never at import - only a dispatched call's output is captured into cartridge_logs). When a
bake-map-operator slot ships, wire this hello into the function that slot dispatches, and add your behaviour.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Bake Map Operator (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe(params=None):
    return {"payload": "slot_bakemapop", "version": "0.1.0", "lane": "python",
            "example": "barebones/bake-map-operator", "template": True,
            "superClassId": "COMMON_BAKE_MAP_OPERATOR_CLASS_ID"}
