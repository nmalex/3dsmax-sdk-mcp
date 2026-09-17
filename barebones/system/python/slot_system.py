"""Barebones System (Python lane) - Cartridge System, a plain helper that draws a wireframe tetrahedron.

WHAT A HELPER CARTRIDGE IS. A helper is a non-rendering object that exists to be seen and picked in
the viewport - Dummy, Point, Tape. This one answers ONE question for the helper slot: which lines to
draw. The slot draws them, selects the helper by them, and boxes them for zoom extents; this payload
returns numbers and never touches the viewport, or the 3ds Max SDK.

    HelperLines(params, time) -> {"lines": [[[x, y, z], ...], ...], "color": [r, g, b]}

A line is a list of at least two points, or {"points": [...], "closed": true} for a closed run. The
points are in the helper's own space, in system units. "color" is optional; without it the helper
draws in its wire colour, like any other object. The slot asks again only when a parameter changes,
so a redraw is never a cartridge call.

WHICH SLOT HOSTS IT. The helper slot loads this payload by its fixed module name, `slot_system`. In
the Create panel (Helpers > MCP Cartridges) and in the scene the helper is called **Cartridge System**;
its internal name is `Cartridge_Helper`, which is what a script assigns and what a .max file
resolves. Do not confuse it with **Tetra Dummy** (barebones/manipulator), which draws the same shape
as a manipulator gizmo: that one is a manipulator, this one is a plain helper.

ITS ONE PARAMETER, `size` - the EDGE LENGTH of the tetrahedron. describe_params() declares it; the
slot keeps the value (saved with the scene, animatable, `$.size`), and hands it back as `params`.
Creating the helper by click-and-drag writes the drag distance into `size` - the slot does that for
any cartridge that declares a float called `size`.

THE HELLO. Logged once from `HelperLines`, which the slot asks the first time the helper is drawn.
Create a Cartridge System and read `cartridge_logs -module slot_system`.
"""

import math

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

# The edge length, in system units. The declared DEFAULT - the answer for a params dict that has not
# arrived - never a second copy of the value, which lives in the slot.
DEFAULT_SIZE = 30.0

# Four alternate corners of a cube: a regular tetrahedron whose edge is 2 * sqrt(2).
_CORNERS = ((1.0, 1.0, 1.0), (1.0, -1.0, -1.0), (-1.0, 1.0, -1.0), (-1.0, -1.0, 1.0))


def _size(params):
    """The declared size from the slot's params, or the default when none has arrived."""
    try:
        return float((params or {}).get("size", DEFAULT_SIZE))
    except (TypeError, ValueError):
        return DEFAULT_SIZE


def _tetrahedron(edge):
    """All six edges, as six two-point lines."""
    scale = edge / (2.0 * math.sqrt(2.0))
    corners = [[c * scale for c in corner] for corner in _CORNERS]
    return [[corners[a], corners[b]] for a in range(4) for b in range(a + 1, 4)]


def HelperLines(params=None, **_event):
    """The lines the helper draws, in its own space."""
    global _said_hello
    size = _size(params)
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones System (Python) is live; this line came from its "
                          "payload on the first draw (HelperLines), a wireframe tetrahedron of edge %g." % size)
    return {"lines": _tetrahedron(size)}


def describe_params():
    """One float: the tetrahedron's edge length, the shape a Dummy's single Size spinner takes."""
    return {
        "parameters": [
            {"name": "size", "type": "float", "default": DEFAULT_SIZE},
        ],
    }


def describe_ui(params=None, **kwargs):
    """The Create/Modify panel rollout: the Size spinner, bound to the slot-held `size`."""
    return ui.build(
        ui.VBox(
            ui.Label("Cartridge System"),
            ui.Spacer(),
            ui.Field("Size:", ui.Spinner(value=_size(params), minimum=0.01, maximum=100000.0,
                                         step=0.1, edit_type="universe", autoscale=True,
                                         param="size")),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """The spinner moved. The slot has already saved it; `invalidate` asks it for new lines."""
    outcome = ui.dispatch(control_id, value)
    return {
        "invalidate": True,
        "rebuild": bool(outcome.get("rebuild")),
        "updates": outcome.get("updates") or [],
    }


def describe(params=None):
    return {"payload": "slot_system", "version": "0.1.0", "lane": "python",
            "example": "barebones/system", "draws": "tripod"}


def init(**env):
    """Load-time crossing: the INIT REPORT, never the greeting (see barebones/manipulator)."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The unload report. Like init, it never logs the greeting."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}
