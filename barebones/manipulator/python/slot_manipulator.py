"""Barebones Manipulator (Python lane) - a viewport gizmo that draws REAL geometry.

WHAT A MANIPULATOR CARTRIDGE IS. It is a helper the user can manipulate directly in the viewport -
a custom gizmo. When it is displayed or the mouse moves over it, 3ds Max asks it to rebuild its
shapes and to handle mouse interaction; the slot forwards those as `ManipUpdateShapes` and
`ManipMouse`. This barebones draws a wireframe TETRAHEDRON, built edge by edge by this payload
through the facade - not by the slot. That is the point of the example: the geometry you see in the
viewport was described by Python, in a cartridge, and nothing here touches the 3ds Max SDK.

WHICH SLOT HOSTS IT, AND THE ONE-SUPERCLASS-MANY-KINDS STORY. The payload the `Cartridge Manipulator`
slot loads by its fixed module name, `slot_manipulator`. It registers under HELPER_CLASS_ID - the
same SuperClassID as a plain helper and a ParticleFlow operator - and is told apart from them only by
its ClassDesc answering `IsManipulator() == TRUE`. That is why a manipulator is its own slot and its
own barebones even though it shares a superclass. See this example's README.md.

HOW THE PAYLOAD REACHES THE FACADE FROM A CALLBACK. Every callback event carries `slot`, the facade
table's address as a decimal string - the same key, meaning the same thing, as in every other entry
point. `mcp_facade.from_address(slot)` turns it into the callable table. Without that address a
callback-driven cartridge could read its event and nothing else, so if `slot` is ever missing here,
that is the bug to report - not a reason to reach for the SDK.

THE GIZMO-BUILD ENTRIES USED BELOW, all of which are in the published facade:
  ManipCurrentGizmoBuild   - the empty GizmoShape the slot borrowed for this callback's span
  GizmoShapeAppendPolyline - one open or closed run of points
  GizmoBuildSetAppearance  - the unselected colour and the gizmo flags
There are more (StartNewLine, AppendPoint, MakeCircle, MakeRect); `mcp_facade.has()` will tell you
what this build actually carries.

THE HELLO. Logged once from `ManipUpdateShapes`, which fires when the gizmo is displayed. Trigger it
by creating this manipulator helper and selecting it, then read
`cartridge_logs -module slot_manipulator`.
"""

import ctypes

import mcp_bootstrap

try:
    import mcp_facade
except ImportError:      # a build without the Python facade lane still loads and still greets
    mcp_facade = None

_said_hello = False
_said_drew = False

# Half-edge of the tetrahedron, in 3ds Max system units. Four alternate corners of a cube.
SIZE = 15.0

_APEX = (SIZE, SIZE, SIZE)
_BASE = [(SIZE, -SIZE, -SIZE), (-SIZE, SIZE, -SIZE), (-SIZE, -SIZE, SIZE)]

# Cyan, so it reads as "the cartridge drew this" rather than as the slot's own fallback circle.
_COLOR = (0.2, 0.8, 1.0)


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Manipulator (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def _points(vectors):
    """A ctypes array of MaxMcpPoint3, which is what every geometry entry takes."""
    array = (mcp_facade.MaxMcpPoint3 * len(vectors))()
    for i, (x, y, z) in enumerate(vectors):
        array[i].x, array[i].y, array[i].z = float(x), float(y), float(z)
    return array


def _draw_tetrahedron(api, builder):
    """Four polylines: the closed base triangle, then one edge up to the apex from each corner.

    Returns the number of runs appended, or refuses by returning 0 - a barebones never raises into
    the host.
    """
    ok = mcp_facade.MAXMCP_FACADE_OK
    runs = 0

    base = _points(_BASE)
    if api.GizmoShapeAppendPolyline(api.Context, builder, base, len(base), 1) == ok:
        runs += 1

    for corner in _BASE:
        edge = _points([_APEX, corner])
        if api.GizmoShapeAppendPolyline(api.Context, builder, edge, len(edge), 0) == ok:
            runs += 1

    color = _points([_COLOR])
    api.GizmoBuildSetAppearance(api.Context, builder, color, 0)
    return runs


def ManipUpdateShapes(**event):
    """Called to (re)build the gizmo's handles. This one builds a wireframe tetrahedron."""
    _hello_once("display (ManipUpdateShapes)")

    if mcp_facade is None:
        return {"shapes": [], "lane": "python", "why": "no facade lane in this build"}

    api = mcp_facade.from_address(event.get("slot"))
    if api is None:
        mcp_bootstrap.log("warning",
                          "Barebones Manipulator: the callback carried no facade address, so it can "
                          "draw nothing. The slot falls back to its own circle.")
        return {"shapes": [], "lane": "python", "why": "no facade address"}

    needed = ("ManipCurrentGizmoBuild", "GizmoShapeAppendPolyline", "GizmoBuildSetAppearance")
    if not mcp_facade.has_all(api, needed):
        return {"shapes": [], "lane": "python", "why": "build lacks the gizmo-build entries"}

    active = ctypes.c_int32(0)
    builder = ctypes.c_uint64(0)
    if api.ManipCurrentGizmoBuild(api.Context, ctypes.byref(active),
                                  ctypes.byref(builder)) != mcp_facade.MAXMCP_FACADE_OK:
        return {"shapes": [], "lane": "python", "why": "no gizmo build in progress"}
    if not active.value or not builder.value:
        return {"shapes": [], "lane": "python", "why": "gizmo build not active"}

    runs = _draw_tetrahedron(api, builder.value)

    # Said ONCE, on the first gizmo actually built. A drawing is evidence only to somebody looking
    # at the viewport; this line is the same fact in the log, where a verifier can read it.
    global _said_drew
    if not _said_drew:
        _said_drew = True
        mcp_bootstrap.log("display",
                          "Barebones Manipulator drew a wireframe tetrahedron: %d polyline run(s) "
                          "appended to the borrowed GizmoShape through the facade, from Python."
                          % runs)
    return {"shapes": ["tetrahedron"], "runs": runs, "lane": "python"}


def ManipMouse(**event):
    """Called on mouse interaction with the gizmo. A real one edits a target; this one does nothing."""
    _hello_once("mouse (ManipMouse)")
    return {"handled": False, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_manipulator", "version": "0.2.0", "lane": "python",
            "example": "barebones/manipulator", "draws": "tetrahedron"}


def init(**env):
    """Load-time crossing (FR-0006). The slot calls this at 3ds Max startup (NOTIFY_SYSTEM_STARTUP),
    before any host action, handing the environment only the slot can see. This is the INIT REPORT: it
    records that the cartridge loaded and the world it loaded into. It is deliberately NOT the
    cartridge's greeting - the greeting is logged only by the cartridge's own behaviour (the body
    above), so a load report is never mistaken for the thing working. `env` carries: maxRelease,
    slotName, slotVersion, cartridgeAbi, gup. Note slotName, not slot: `slot` is reserved everywhere
    in the payload contract for the facade table's address."""
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
