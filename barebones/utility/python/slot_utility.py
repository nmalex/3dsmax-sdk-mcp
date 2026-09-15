"""Barebones Utility (Python lane) - a Utilities-panel tool; here, one that just says hello.

WHAT A UTILITY CARTRIDGE IS. It appears under the Utilities panel (the hammer icon). When the user
opens it, the slot builds its rollout from `describe_ui()` and runs its button handlers; a utility
does not belong to any object and saves nothing in the scene - it is a tool you run. This barebones
shows one labelled line and a Hello World button, which is the whole crossing (panel, event, log)
with nothing in the way.

WHICH SLOT HOSTS IT, AND WHICH OTHER CLASS IDS IT COULD BEAR. This is the payload the
`Cartridge Utility` slot loads by its fixed module name, `slot_utility`, registering one SuperClassID:
UTILITY_CLASS_ID. A Track View utility is the same "a panel and some actions" shape in a different
host window:

    UTILITY_CLASS_ID             utility panel plugin   (this slot; the Utilities panel)
    TRACKVIEW_UTILITY_CLASS_ID   Track View utility     (a sibling slot; a Track View tool)

See this example's README.md for the full table.

THE HELLO. Logged once from `describe_ui` (built when the panel opens) and from the button. Trigger
it by opening this utility in the Utilities panel, then read `cartridge_logs -module slot_utility`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Utility (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def describe_ui(params=None, **kwargs):
    """The Utilities-panel rollout: one labelled line and a Hello World button."""
    _hello_once("panel open")
    return ui.build(
        ui.VBox(
            ui.Label("Barebones Utility - a tool you run, holding nothing."),
            ui.Spacer(),
            ui.Button("Hello World", on_click=_say_hello),
        )
    )


def _say_hello():
    mcp_bootstrap.log("display",
                      "Hello World - the Barebones Utility panel is live and this line came from "
                      "its Python payload, on a button click.")
    return {}


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": False, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def describe(params=None):
    return {"payload": "slot_utility", "version": "0.1.0", "lane": "python",
            "example": "barebones/utility"}


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
