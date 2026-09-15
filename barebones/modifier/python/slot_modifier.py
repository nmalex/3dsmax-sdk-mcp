"""Barebones Modifier (Python lane) - the smallest cartridge that proves the whole crossing.

WHAT THIS IS. A modifier cartridge that changes no geometry on purpose. An inert cartridge is not a
poor example - it is PROOF THAT THE WHOLE CROSSING WORKS before any behaviour is in the way of
reading the result. When this loads and its "Hello World" line appears in the log, six things have
just been shown to work at once:

    the slot was registered       ->  "Barebones Modifier" is in the Modifier List
    the slot found this file       ->  the interpreter loaded it as module `slot_modifier`
    the interpreter ran it          ->  describe_ui() built a real 3ds Max rollout
    a control was clicked           ->  the event crossed back into _say_hello()
    the log channel works           ->  the line below arrives in `cartridge_logs -module slot_modifier`

Everything after this is edits to a system already known to be connected.

WHICH SLOT HOSTS IT, AND WHICH OTHER CLASS IDS IT COULD BEAR. This file is the payload the
`Cartridge Modifier` slot loads by its fixed module name, `slot_modifier`, and that slot registers
one SuperClassID: OSM_CLASS_ID (an object-space modifier). The SAME payload shape - a `deform` that
is handed the mesh and hands it back - is what a WORLD-space modifier does too; only the slot it is
compiled into differs. See this example's README.md for the full table of the SuperClassIDs a
modifier-shaped cartridge can bear:

    OSM_CLASS_ID          object-space modifier   (this slot)
    WSM_CLASS_ID          world-space modifier    (a sibling slot; same deform contract, world space)

WHERE PARAMETERS GO: NOT HERE. State kept in this module dies with the interpreter, which is reloaded
on every refresh - so a value in a global here is one your user loses without being told, never saved
with the scene and never keyable. You DECLARE a parameter (describe_params below) and the slot keeps
it: saved with the scene, animatable, scriptable, and handed back as `params` on every call.
"""

import mcp_bootstrap
import mcp_ui as ui


# The "hello" is logged from a DISPATCHED function (deform / the button), never at import: a payload's
# log() line only rides back to `cartridge_logs` inside a call the slot dispatched - the stdout of a
# bare import is not captured. `_said_hello` makes it a once-per-load announcement rather than a
# per-evaluation one; a Refresh re-imports the module and it says hello again.
_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Modifier (Python) is live; this line came from "
                          "its payload on first %s." % where)


def describe_params():
    """The parameters this cartridge declares. One float, to show the shape; it is unused here."""
    return {
        "parameters": [
            {"name": "amount", "type": "float", "default": 1.0},
        ],
    }


def describe_ui(params=None, **kwargs):
    """The command-panel rollout: one labelled line and a Hello World button."""
    _hello_once("panel open")
    p = params or {}
    return ui.build(
        ui.VBox(
            ui.Label("Barebones Modifier - inert, and proud of it."),
            ui.Spacer(),
            ui.Field("Amount:", ui.Spinner(value=p.get("amount", 1.0),
                                           minimum=-1000.0, maximum=1000.0, step=0.01,
                                           param="amount")),
            ui.Spacer(),
            ui.Button("Hello World", on_click=_say_hello),
        )
    )


def _say_hello():
    """The button's handler. Says so where a person can see it, and changes nothing."""
    mcp_bootstrap.log("display",
                      "Hello World - the Barebones Modifier panel is live and this line came from "
                      "its Python payload, on a button click.")
    return {}


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """One control changed. Nothing here feeds the deform, so the viewport is not invalidated."""
    outcome = ui.dispatch(control_id, value)
    return {
        "invalidate": False,
        "rebuild": bool(outcome.get("rebuild")),
        "updates": outcome.get("updates") or [],
    }


def deform(points, box=None, tm=None, params=None):
    """The mesh as a flat [x, y, z, ...] list. Reports what it saw and changes nothing.

    To make this cartridge DO something: modify `points` in place and return "changed": True.
    """
    _hello_once("evaluation")
    return {"vertices": len(points) // 3, "changed": False, "lane": "python"}


def describe(params=None):
    """What this payload is, for anything that asks."""
    return {"payload": "slot_modifier", "version": "0.1.0", "lane": "python",
            "example": "barebones/modifier", "inert": True}


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
