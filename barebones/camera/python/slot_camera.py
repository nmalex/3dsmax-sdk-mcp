"""Barebones Camera (Python lane) - a 45-degree free camera.

A camera is an object you render through. The slot (a GenCamera) registers a free camera, draws its
gizmo, and asks this payload for its field of view:

    CameraState(params, time) -> {"fov": degrees}

Nothing here touches the 3ds Max SDK. Deployed as `slot_camera`; created from Create > Cameras > MCP
Cartridges. Hello on the first CameraState; read it with `cartridge_logs -module slot_camera`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def CameraState(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Camera (Python) is live; this line came from its "
                          "payload on the first CameraState, a 45-degree free camera.")
    return {"fov": 45.0}


def describe_ui(params=None, **kwargs):
    return ui.build(ui.VBox(ui.Label("Cartridge Camera"), ui.Spacer(), ui.Label("A 45-degree free camera.")))


def on_ui_event(control_id, value=None, **kwargs):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")), "updates": outcome.get("updates") or []}


def describe(params=None):
    return {"payload": "slot_camera", "version": "0.1.0", "lane": "python",
            "example": "barebones/camera", "is": "free camera"}


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
