"""Barebones Color Picker (Python lane) - a plug-in colour selector shown when a swatch is clicked; here, one that just says hello.

WHICH SLOT HOSTS IT. The payload the `Cartridge Color Picker` slot loads by its fixed module name,
`slot_colpick`, registering one SuperClassID: COLPICK_CLASS_ID. See this example's README.md.

THE HELLO. Logged once from `pick`, which the slot calls when 3ds Max drives this plugin. Trigger it
as the README describes, then read `cartridge_logs -module slot_colpick`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Color Picker (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def pick(**event):
    """Called when 3ds Max drives this plugin. A real cartridge does its work here; this one says
    hello once and holds nothing."""
    _hello_once("colour pick (pick)")
    return {"ok": True}


def describe(params=None):
    return {"payload": "slot_colpick", "version": "0.1.0", "lane": "python",
            "example": "barebones/color-picker", "superClassId": "COLPICK_CLASS_ID"}


def init(**env):
    """Load-time crossing (FR-0006). The slot calls this at 3ds Max startup (NOTIFY_SYSTEM_STARTUP),
    before any host action, handing the environment only the slot can see. This is the INIT REPORT: it
    records that the cartridge loaded and the world it loaded into. It is deliberately NOT the
    cartridge's greeting - the greeting is logged only by the cartridge's own behaviour (the body
    above), so a load report is never mistaken for the thing working. `env` carries: maxRelease, slot,
    slotVersion, cartridgeAbi, gup."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slot"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The symmetric unload crossing: the slot calls this from LibShutdown. This is the UNLOAD REPORT -
    the cartridge records that it is being torn down and releases anything it held. Like init, it never
    logs the greeting; only the cartridge's own behaviour does that."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slot") or "cartridge"))
    return {"ok": True}
