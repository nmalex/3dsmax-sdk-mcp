"""@DISPLAY_NAME@ - a cartridge, scaffolded with a working panel and nothing else.

WHAT THIS IS AND WHY IT DOES NOTHING. This payload changes no geometry on purpose. An empty
cartridge is not a poor example - it is PROOF THAT THE WHOLE CROSSING WORKS before any of your
behaviour is in the way of reading the result. When you click the button and "Hello World"
appears, six things have just been shown to work at once:

    the manifest was read at startup   ->  your class was registered under your own name
    the class appeared in the host     ->  the slot found this file
    the interpreter loaded it          ->  describe_ui() built a real 3ds Max rollout
    a real control was clicked         ->  the event crossed back into this function
    the log line arrived               ->  the display channel works end to end

Everything after this is edits to a system already known to be connected. That is worth far more
than a scaffold that does something clever and leaves you guessing which half is broken.

WHERE BEHAVIOUR GOES. `deform` below receives the mesh as a flat list of floats and returns a
verdict. Change the points and return "changed": True and the mesh changes. That is the entire
contract for a modifier.

WHERE PARAMETERS DO NOT GO: HERE. State owned by this module dies with the interpreter, and an
interpreter is reloaded on every refresh - so a value kept in a global here is a value your user
loses without being told. A real parameter belongs in the slot's parameter block, which saves with
the scene, animates, and answers MAXScript. Until you have one, take the value from `params`.
"""

import mcp_bootstrap
import mcp_ui as ui


# -- the panel -----------------------------------------------------------------------------------
#
# describe_ui() is called on every build and on every refresh. It composes a widget tree; the slot
# places the controls and wires them. Handlers are attached inline and never cross the boundary -
# they stay on this side in a registry keyed by control id, and the slot reports events back by id.
#
# There is no About rollout here because you do not write one: the slot contributes it, pinned last.
# What it can say about THIS cartridge comes from `describe()` at the bottom of this file - the slot
# itself only knows what was compiled into it, which is why the entry in the Modifier List carries
# the SLOT's name rather than yours (docs\SLOTS.md). So if you want the About rollout to identify
# the thing you are editing, `describe()` is where you say so, and it is also how you tell whether
# the file you just saved is the file that is running.

def describe_ui(params=None):
    """The command-panel rollout for this cartridge."""
    return ui.build(
        ui.VBox(
            ui.Label("@DISPLAY_NAME@"),
            ui.Spacer(),
            ui.Button("Hello World", on_click=_say_hello),
        )
    )


def _say_hello():
    """The button's handler. Says so where a person can see it, and changes nothing."""
    # mcp_bootstrap.log, never print(). A bare print() is filed as VERBOSE and is quiet by default,
    # so a handler that ran and one that never fired would look identical from outside.
    mcp_bootstrap.log("display",
                      "Hello World - @DISPLAY_NAME@ is loaded, its panel is live, and this line "
                      "came from its Python payload.")
    return {}


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """One control changed. Runs its handler and tells the slot what to do next.

    `invalidate` is False here because nothing on this panel feeds the deformation yet. The day a
    control changes what `deform` produces, this becomes True or the viewport keeps showing the
    old mesh - which looks exactly like a deform that did not run.
    """
    outcome = ui.dispatch(control_id, value)
    return {
        "invalidate": False,
        "rebuild": bool(outcome.get("rebuild")),
        "updates": outcome.get("updates") or [],
    }


# -- the behaviour -------------------------------------------------------------------------------

def deform(points, box=None, tm=None, params=None):
    """The mesh, as a flat [x, y, z, x, y, z, ...] list. Reports what it saw and changes nothing.

    To make this cartridge do something: modify `points` in place and return "changed": True.
    """
    return {"vertices": len(points) // 3, "changed": False, "lane": "python"}


def describe(params=None):
    """What this payload is, for anything that asks."""
    return {"payload": "@MODULE@", "version": "0.1.0-dev", "lane": "python", "inert": True}
