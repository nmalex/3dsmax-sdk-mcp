"""Barebones Fragment (Python lane) - a viewport render-pipeline fragment that says hello.

WHAT A FRAGMENT CARTRIDGE IS. A Fragment (MaxSDK::Graphics::ViewFragment) is a node in the viewport's
graphics fragment graph - the SDK's ActiveShade uses one. It is not a scene object; 3ds Max constructs
it (it is MAXScript-creatable, like the SDK's own ActiveShadeFragment) and evaluates it inside the
display pipeline. This barebones does nothing to the frame; the first time it is created or evaluated
it says hello - the whole crossing (create, dispatch, log) with no behaviour in the way.

WHICH SLOT HOSTS IT. The payload the `Cartridge Fragment` slot loads by its fixed module name,
`slot_fragment`, registering one SuperClassID: Fragment_CLASS_ID. See this example's README.md.

THE HELLO. Logged once from `evaluate`, which the slot calls when 3ds Max constructs the fragment (a
host action a probe reaches by creating the class) and again when the viewport evaluates it. Trigger
it by creating the class, then read `cartridge_logs -module slot_fragment`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Fragment (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def evaluate(**event):
    """Called when 3ds Max constructs the fragment and when the viewport evaluates it. A real fragment
    would contribute to the rendered view here; this one says hello once and touches nothing."""
    _hello_once("evaluate (evaluate)")
    return {"ok": True}


def describe(params=None):
    return {"payload": "slot_fragment", "version": "0.1.0", "lane": "python",
            "example": "barebones/fragment", "superClassId": "Fragment_CLASS_ID"}


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
