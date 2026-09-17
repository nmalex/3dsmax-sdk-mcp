"""Barebones Tone Operator (Python lane) - the identity exposure control.

A tone operator maps a render's raw light energy to displayable RGB. It is picked in Rendering >
Exposure Control. This one maps nothing (identity); it says hello when its panel is opened. Deployed
as `slot_toneop`. Read the hello with `cartridge_logs -module slot_toneop`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def describe_ui(params=None, **kwargs):
    """The Exposure Control rollout. Opening it fires the greeting."""
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Tone Operator (Python) is live; this line came from "
                          "its payload when its Exposure Control panel was opened.")
    return ui.build(ui.VBox(ui.Label("Cartridge Tone Operator"), ui.Spacer(),
                            ui.Label("A no-op tone operator.")))


def on_ui_event(control_id, value=None, **kwargs):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")), "updates": outcome.get("updates") or []}


def describe(params=None):
    return {"payload": "slot_toneop", "version": "0.1.0", "lane": "python",
            "example": "barebones/tone-operator"}


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
