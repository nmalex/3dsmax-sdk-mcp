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
loses without being told, never saved with the scene, never keyable and never reachable from a
script.

So you DECLARE a parameter and the slot keeps it. `describe_params()` below is the whole of it:
each entry becomes a real parameter of the modifier - saved, animatable, scriptable - and arrives
back as `params` on every call, sampled at the time being evaluated. A control names the one it
drives with `param=`, and the slot writes it before your handler ever runs. Nothing in this file
holds a value; the scaffold below shows the shape with one parameter it does not yet use.

`describe_params()` needs plugin 0.4.0-alpha.3 or newer. An older slot never calls it, and this
cartridge still loads and still works - it simply has no parameters. The types, the rules and what
MAXScript shows are in docs/SLOTS.md.
"""

import mcp_bootstrap
import mcp_ui as ui


# -- the parameters ------------------------------------------------------------------------------
#
# One entry per parameter, and the slot keeps every one of them: saved with the scene, keyable in
# Track View, and reachable from a script as $.modifiers[1].amount. They come back as `params` on
# describe_ui, on_ui_event and deform, read at whatever time is being evaluated.
#
# `type` is float, int, bool or string, and is REQUIRED - a missing one is far more often a typo
# than an intention. `default` is what the parameter STARTS at, applied once when it first appears
# and never again, so a Refresh does not overwrite what your user set. A RANGE does not go here:
# it belongs on the control that drives the parameter, as `minimum` and `maximum` below.
#
# Delete this function if your cartridge has no parameters; it is optional like every other one.

def describe_params():
    """The parameters this cartridge declares. Read when it opens, and on every Refresh."""
    return {
        "parameters": [
            {"name": "amount", "type": "float", "default": 1.0},
        ],
    }


# -- the panel -----------------------------------------------------------------------------------
#
# describe_ui() is called on every build and on every refresh. It composes a widget tree; the slot
# places the controls and wires them. Handlers are attached inline and never cross the boundary -
# they stay on this side in a registry keyed by control id, and the slot reports events back by id.
#
# There is no About rollout here because you do not write one: the slot contributes it, pinned last.
# It shows what was COMPILED INTO THE SLOT and nothing else - the slot's name, its version, its
# build stamp - which is also why the entry in the Modifier List carries the SLOT's name rather than
# yours (docs\SLOTS.md). `describe()` at the bottom of this file is NOT read by it today, and
# nothing else reads it either; it is kept because it is where the naming work will look, and
# because it is a good place to record which version of your payload is running. To tell whether the
# file you just saved is the file that is running, click Hello World and watch the listener.

def describe_ui(params=None):
    """The command-panel rollout for this cartridge."""
    p = params or {}
    return ui.build(
        ui.VBox(
            ui.Label("@DISPLAY_NAME@"),
            ui.Spacer(),
            # BOUND, not stored: `param=` names the parameter this spinner drives, and the slot
            # writes it before _say_hello or any other handler runs. `value=` is only where the
            # control OPENS, which is why it is read from params rather than from a constant.
            ui.Field("Amount:", ui.Spinner(value=p.get("amount", 1.0),
                                           minimum=-1000.0, maximum=1000.0, step=0.01,
                                           param="amount")),
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
