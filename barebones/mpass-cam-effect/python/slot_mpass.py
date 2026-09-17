"""Barebones Multi-Pass Effect (Python lane) - a camera effect that blends nothing.

A multi-pass camera effect renders the camera several times and blends the frames (motion blur and
depth-of-field are the two 3ds Max ships), picked in a camera's Multi-Pass Effect dropdown. This one
renders one pass and blends nothing; the greeting fires the first time the host checks the effect
against a camera. Deployed as `slot_mpass`. Read the hello with `cartridge_logs -module slot_mpass`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Multi-Pass Effect (Python) is live; this line came "
                          "from its payload the first time the host checked the effect against a camera.")
    return {"name": "Cartridge Multi-Pass Effect"}


def describe(params=None):
    return {"payload": "slot_mpass", "version": "0.1.0", "lane": "python",
            "example": "barebones/mpass-cam-effect"}


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
