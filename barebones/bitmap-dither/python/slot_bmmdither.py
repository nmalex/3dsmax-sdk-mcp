"""Barebones Bitmap Dither (Python lane) - documents the shape - this super-class is not third-party registerable.

A bitmap dithering method - the dither applied when reducing an image's bit depth.

This plugin type is in the super-class census (SuperClassID BMM_DITHER_CLASS_ID) but no slot ships for it yet, so
this payload cannot be loaded in the host today. It shows the shape: a hello logged from a dispatched
function (never at import - only a dispatched call's output is captured into cartridge_logs). When a
bitmap-dither slot ships, wire this hello into the function that slot dispatches, and add your behaviour.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Bitmap Dither (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe(params=None):
    return {"payload": "slot_bmmdither", "version": "0.1.0", "lane": "python",
            "example": "barebones/bitmap-dither", "template": True,
            "superClassId": "BMM_DITHER_CLASS_ID"}
