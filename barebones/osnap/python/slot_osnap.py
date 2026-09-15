"""Barebones Object Snap (Python lane) - contributes a snap point; here, contributes none.

WHAT AN OSNAP CARTRIDGE IS. It appears in Grid and Snap Settings as a snap the user can enable. While
the user drags with snapping on, 3ds Max asks each active snap for candidate points near the cursor;
the slot forwards that as `OsnapSnap`. A real snap returns points of interest on an object (a
midpoint, a centre); this barebones returns none and says hello, so you can prove the snap is
registered and asked before computing any geometry.

WHICH SLOT HOSTS IT. The payload the `Cartridge Snap` slot loads by its fixed module name,
`slot_osnap`, registering one SuperClassID: OSNAP_CLASS_ID.

THE HELLO. Logged once from `OsnapSnap`. Trigger it by enabling this snap in Grid and Snap Settings
and moving the cursor over an object while creating or moving, then read
`cartridge_logs -module slot_osnap`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Object Snap (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def OsnapSnap(**event):
    """Called while snapping to gather candidate points. A real snap returns points; this returns none."""
    _hello_once("snap query (OsnapSnap)")
    return {"points": [], "lane": "python"}


def describe(params=None):
    return {"payload": "slot_osnap", "version": "0.1.0", "lane": "python",
            "example": "barebones/osnap"}


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
