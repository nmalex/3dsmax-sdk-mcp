"""Barebones Light (Python lane) - a warm-white omni light.

A light illuminates the scene. The slot (a GenLight) registers an omnidirectional light, draws its
gizmo, and asks this payload for the two numbers a hello-world light needs:

    LightState(params, time) -> {"color": [r, g, b], "intensity": f}

Nothing here touches the 3ds Max SDK. Deployed as `slot_light`; created from Create > Lights > MCP
Cartridges. Hello on the first LightState; read it with `cartridge_logs -module slot_light`.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def LightState(params=None, **_event):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Light (Python) is live; this line came from its "
                          "payload on the first LightState, a warm-white omni light.")
    return {"color": [1.0, 0.9, 0.75], "intensity": 1.0}


def describe_ui(params=None, **kwargs):
    return ui.build(ui.VBox(ui.Label("Cartridge Light"), ui.Spacer(),
                            ui.Label("A warm-white omni light.")))


def on_ui_event(control_id, value=None, **kwargs):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")), "updates": outcome.get("updates") or []}


def describe(params=None):
    return {"payload": "slot_light", "version": "0.1.0", "lane": "python",
            "example": "barebones/light", "is": "omni light"}


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
