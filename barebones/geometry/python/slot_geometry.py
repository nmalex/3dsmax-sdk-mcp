"""Barebones Geometry (Python lane) - a parametric cube, the smallest real geometry object.

WHAT A GEOMETRY CARTRIDGE IS. A parametric renderable object - the Box/Sphere/Teapot kind. The slot
(a SimpleObject2) asks it for a mesh whenever the object is evaluated, and builds, shows, snaps,
picks and renders that mesh. This payload answers ONE question:

    BuildMesh(params, time) -> {"verts": [[x, y, z], ...], "faces": [[a, b, c], ...]}

The faces are triangles of 0-based vertex indices. The mesh is in the object's own space; the slot
handles the rest. This one returns a cube whose edge is the `size` parameter - a real solid you can
render and convert to an editable mesh, described entirely in Python, touching no 3ds Max SDK.

WHICH SLOT HOSTS IT. The geometry slot loads this payload by its fixed module name, `slot_geometry`.
In Create > Geometry > MCP Cartridges it is **Cartridge Geometry**; its internal name is
`Cartridge_Geometry`. Create it by click-and-drag: the click places it, the drag sets `size`.

ITS ONE PARAMETER, `size` - the cube's edge, saved with the scene, animatable, `$.size`.

THE HELLO. Logged once from `BuildMesh`, the first time the object is evaluated. Create a Cartridge
Geometry and read `cartridge_logs -module slot_geometry`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False

# The cube's edge, in system units - the declared DEFAULT, the answer for a params dict that has not
# arrived. Never a second copy of the value, which lives in the slot.
DEFAULT_SIZE = 30.0

# The eight corners of a unit cube (half-edge 1), and its twelve triangles (two per face, wound
# outward so the normals face out).
_CORNERS = ((-1, -1, -1), (1, -1, -1), (1, 1, -1), (-1, 1, -1),
            (-1, -1, 1), (1, -1, 1), (1, 1, 1), (-1, 1, 1))
_TRIS = ((0, 2, 1), (0, 3, 2), (4, 5, 6), (4, 6, 7), (0, 1, 5), (0, 5, 4),
         (1, 2, 6), (1, 6, 5), (2, 3, 7), (2, 7, 6), (3, 0, 4), (3, 4, 7))


def _size(params):
    """The declared size from the slot's params, or the default when none has arrived."""
    try:
        return float((params or {}).get("size", DEFAULT_SIZE))
    except (TypeError, ValueError):
        return DEFAULT_SIZE


def BuildMesh(params=None, **_event):
    """The cube's vertices and triangle faces, in object space."""
    global _said_hello
    size = _size(params)
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Geometry (Python) is live; this line came from its "
                          "payload on the first evaluation (BuildMesh), a cube of edge %g." % size)
    half = size * 0.5
    verts = [[c[0] * half, c[1] * half, c[2] * half] for c in _CORNERS]
    return {"verts": verts, "faces": [list(t) for t in _TRIS]}


def describe_params():
    """One float: the cube's edge, the shape a Box's own single spinner takes."""
    return {
        "parameters": [
            {"name": "size", "type": "float", "default": DEFAULT_SIZE},
        ],
    }


def describe_ui(params=None, **kwargs):
    """The Create/Modify panel rollout: the Size spinner, bound to the slot-held `size`."""
    return ui.build(
        ui.VBox(
            ui.Label("Cartridge Geometry"),
            ui.Spacer(),
            ui.Field("Size:", ui.Spinner(value=_size(params), minimum=0.01, maximum=100000.0,
                                         step=0.1, edit_type="universe", autoscale=True,
                                         param="size")),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    """The spinner moved. The slot has already saved it; `invalidate` asks it to rebuild the mesh."""
    outcome = ui.dispatch(control_id, value)
    return {
        "invalidate": True,
        "rebuild": bool(outcome.get("rebuild")),
        "updates": outcome.get("updates") or [],
    }


def describe(params=None):
    return {"payload": "slot_geometry", "version": "0.1.0", "lane": "python",
            "example": "barebones/geometry", "builds": "cube"}


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
