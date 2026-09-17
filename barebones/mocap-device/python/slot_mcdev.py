"""Barebones MoCap Device (Python lane) - a mocap input device that reads nothing.

A motion-capture input device is a live input source (a joystick, a MIDI device) the Motion Capture
utility drives an animation from. This one reads nothing and makes no bindings; the greeting fires
the first time the host asks the device for its name. Deployed as `slot_mcdev`.
Read the hello with `cartridge_logs -module slot_mcdev`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones MoCap Device (Python) is live; this line came "
                          "from its payload the first time the host asked the device for its name.")
    return {"name": "Cartridge MoCap Device"}


def describe(params=None):
    return {"payload": "slot_mcdev", "version": "0.1.0", "lane": "python",
            "example": "barebones/mocap-device"}


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
