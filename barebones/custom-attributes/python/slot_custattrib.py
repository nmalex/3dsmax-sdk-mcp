"""Barebones Custom Attributes (Python lane) - a block of parameters you attach to any object.

A custom attribute shows up as an extra rollout on an object, material or modifier. The slot
registers one and asks this payload to describe itself; the greeting fires the first time 3ds Max
asks the attribute for its name (as soon as it is attached). Deployed as `slot_custattrib`.
Read the hello with `cartridge_logs -module slot_custattrib`.
"""

import mcp_bootstrap

_said_hello = False


def Describe(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Custom Attributes (Python) is live; this line came "
                          "from its payload the first time the attribute was asked to describe itself.")
    return {"name": "Cartridge Custom Attributes"}


def describe(params=None):
    return {"payload": "slot_custattrib", "version": "0.1.0", "lane": "python",
            "example": "barebones/custom-attributes"}


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
