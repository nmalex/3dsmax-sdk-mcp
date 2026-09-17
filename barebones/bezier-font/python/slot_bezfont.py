"""Barebones Font (Python lane) - a font loader that builds no glyphs.

A Bezier-font loader turns a font into the outlines the Text shape extrudes (the built-in TrueType
loader is one). This one offers a single font, "Cartridge Font", and builds no glyphs; the greeting
fires the first time a Text shape opens that font. Deployed as `slot_bezfont`.
Read the hello with `cartridge_logs -module slot_bezfont`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Font (Python) is live; this line came "
                          "from its payload the first time a Text shape opened its font.")
    return {"name": "Cartridge Font"}


def describe(params=None):
    return {"payload": "slot_bezfont", "version": "0.1.0", "lane": "python",
            "example": "barebones/bezier-font"}


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
