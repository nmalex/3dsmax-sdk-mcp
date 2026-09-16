"""Barebones Controller (Python lane) - an animation controller that holds nothing and says hello.

WHAT A CONTROLLER CARTRIDGE IS. A controller is assigned to an animatable track - a node's position,
a modifier's amount, a material parameter - and 3ds Max asks it for the track's value every time that
value is needed (every frame of a render, every viewport redraw). This barebones is a FLOAT
controller (CTRL_FLOAT_CLASS_ID) that always answers the same number and, the first time it is asked,
says hello - the whole crossing (assign, evaluate, log) with no behaviour in the way. The same shape
serves every CTRL_* value type; only the value it returns differs.

WHICH SLOT HOSTS IT. The payload the `Cartridge Controller` slot loads by its fixed module name,
`slot_controller`, registering one SuperClassID: CTRL_FLOAT_CLASS_ID. See this example's README.md
for the CTRL_* table.

THE HELLO. Logged once from `get_value`, which the slot calls every time 3ds Max evaluates the track.
Trigger it by assigning this controller to any float track and evaluating it (move the time slider, or
read the value in MAXScript), then read `cartridge_logs -module slot_controller`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Controller (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def get_value(**event):
    """Called each time the assigned track is evaluated. A real controller computes the track's value
    here (from keys, an expression, a constraint); this one says hello once and returns a constant.

    The slot keeps the returned number and hands it to 3ds Max as the track's float value, so the
    payload never holds a 3ds Max object - it answers with a plain number and nothing else."""
    _hello_once("evaluation (get_value)")
    return {"value": 0.0}


def describe(params=None):
    return {"payload": "slot_controller", "version": "0.1.0", "lane": "python",
            "example": "barebones/controller", "superClassId": "CTRL_FLOAT_CLASS_ID"}


def init(**env):
    """Load-time crossing (FR-0006). The slot calls this at 3ds Max startup (NOTIFY_SYSTEM_STARTUP),
    before any host action, handing the environment only the slot can see. This is the INIT REPORT: it
    records that the cartridge loaded and the world it loaded into. It is deliberately NOT the
    cartridge's greeting - the greeting is logged only by the cartridge's own behaviour (the body
    above), so a load report is never mistaken for the thing working. `env` carries: maxRelease, slotName,
    slotVersion, cartridgeAbi, gup."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The symmetric unload crossing: the slot calls this from LibShutdown. This is the UNLOAD REPORT -
    the cartridge records that it is being torn down and releases anything it held. Like init, it never
    logs the greeting; only the cartridge's own behaviour does that."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}


# -- the panel -----------------------------------------------------------------------------------
#
# Shown in Track View > Properties (a modal dialog), and the Motion panel for a transform. The slot builds it from describe_ui() and puts its own About (version, build,
# Refresh) beside it - every slot whose plugin kind has a UI place does, the same way. Declaring no
# describe_ui is also fine: the slot then shows only About. A control bound with `param=` is saved
# only by a slot that keeps a parameter block (docs/SLOTS.md lists which); this one's button just
# proves the crossing.


def describe_ui(params=None, **kwargs):
    """The panel: one line and a Hello World button."""
    return ui.build(
        ui.VBox(
            ui.Label("Barebones Controller"),
            ui.Spacer(),
            ui.Button("Hello World", on_click=_panel_hello),
        )
    )


def _panel_hello():
    mcp_bootstrap.log("display",
                      "Hello World - the Barebones Controller panel is live and this line came from its "
                      "Python payload, on a button click.")
    return {}


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """One control changed. Nothing here changes what the plugin computes, so nothing is
    invalidated."""
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": False, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}
