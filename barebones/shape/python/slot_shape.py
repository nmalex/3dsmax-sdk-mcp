"""Barebones Shape (Python lane) - a pentagon, the smallest real spline shape.

A shape is a spline object - the Line/Circle/Rectangle kind. The slot (a SimpleSpline) asks this
payload for its polylines and builds a BezierShape from them:

    BuildShape(params, time) -> {"polylines": [{"points": [[x, y, z], ...], "closed": true}, ...]}

This one returns a closed regular pentagon. Nothing here touches the 3ds Max SDK. Deployed as
`slot_shape`; created from Create > Shapes > MCP Cartridges. Hello on the first BuildShape; read it
with `cartridge_logs -module slot_shape`.
"""

import math

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False
RADIUS = 30.0
SIDES = 5


def BuildShape(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Shape (Python) is live; this line came from its "
                          "payload on the first BuildShape, a %d-sided polygon." % SIDES)
    points = []
    for i in range(SIDES):
        a = math.pi / 2 + i * 2 * math.pi / SIDES
        points.append([RADIUS * math.cos(a), RADIUS * math.sin(a), 0.0])
    return {"polylines": [{"points": points, "closed": True}]}


def describe_ui(params=None, **kwargs):
    return ui.build(ui.VBox(ui.Label("Cartridge Shape"), ui.Spacer(),
                            ui.Label("A %d-sided polygon." % SIDES)))


def on_ui_event(control_id, value=None, **kwargs):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")), "updates": outcome.get("updates") or []}


def describe(params=None):
    return {"payload": "slot_shape", "version": "0.1.0", "lane": "python",
            "example": "barebones/shape", "builds": "pentagon"}


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
