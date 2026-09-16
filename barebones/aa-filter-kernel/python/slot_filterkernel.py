"""Barebones AA Filter Kernel (Python lane) - the anti-aliasing weight curve the renderer samples; here, one that just says hello.

WHICH SLOT HOSTS IT. The payload the `Cartridge AA Filter Kernel` slot loads by its fixed module name,
`slot_filterkernel`, registering one SuperClassID: FILTER_KERNEL_CLASS_ID. See this example's README.md.

THE HELLO. Logged once from `compute`, which the slot calls when 3ds Max drives this plugin. Trigger it
as the README describes, then read `cartridge_logs -module slot_filterkernel`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones AA Filter Kernel (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def compute(**event):
    """Called when 3ds Max drives this plugin. A real cartridge does its work here; this one says
    hello once and holds nothing."""
    _hello_once("kernel build (compute)")
    return {"ok": True}


def describe(params=None):
    return {"payload": "slot_filterkernel", "version": "0.1.0", "lane": "python",
            "example": "barebones/aa-filter-kernel", "superClassId": "FILTER_KERNEL_CLASS_ID"}


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
# Shown in Render Setup, under the anti-aliasing filter. The slot builds it from describe_ui() and puts its own About (version, build,
# Refresh) beside it - every slot whose plugin kind has a UI place does, the same way. Declaring no
# describe_ui is also fine: the slot then shows only About. A control bound with `param=` is saved
# only by a slot that keeps a parameter block (docs/SLOTS.md lists which); this one's button just
# proves the crossing.


def describe_ui(params=None, **kwargs):
    """The panel: one line and a Hello World button."""
    return ui.build(
        ui.VBox(
            ui.Label("Barebones AA Filter"),
            ui.Spacer(),
            ui.Button("Hello World", on_click=_panel_hello),
        )
    )


def _panel_hello():
    mcp_bootstrap.log("display",
                      "Hello World - the Barebones AA Filter panel is live and this line came from its "
                      "Python payload, on a button click.")
    return {}


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """One control changed. Nothing here changes what the plugin computes, so nothing is
    invalidated."""
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": False, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}
