"""Barebones MoCap Binding (Python lane) - a mocap binding that binds nothing.

A motion-capture device binding ties one channel of a mocap device to a controller, so a live input
drives an animated value; a device makes them. This one is standalone and binds nothing; the greeting
fires the first time the host asks the binding for its class name. Deployed as `slot_mcbind`.
Read the hello with `cartridge_logs -module slot_mcbind`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones MoCap Binding (Python) is live; this line came "
                          "from its payload the first time the host asked the binding for its name.")
    return {"name": "Cartridge MoCap Binding"}


def describe(params=None):
    return {"payload": "slot_mcbind", "version": "0.1.0", "lane": "python",
            "example": "barebones/mocap-binding"}


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
