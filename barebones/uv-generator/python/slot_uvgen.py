"""Barebones UV Generator (Python lane) - a texmap sub-component that says hello.

WHAT THIS CARTRIDGE IS. A UV Generator (2D map input - the UV coordinates a 2D texmap samples in). 3ds Max creates it as part of a texmap and,
the first time it does, resets it - which is where this barebones says hello: the whole crossing
(create, reset, log) with no behaviour in the way. A real one would compute coordinates or filter a
colour; this one is inert on purpose, a proof the pipe is connected.

WHICH SLOT HOSTS IT. The payload the `Cartridge UV Generator` slot loads by its fixed module name,
`slot_uvgen`, registering one SuperClassID: UVGEN_CLASS_ID. See this example's README.md.

THE HELLO. Logged once from `reset`, which the slot calls when 3ds Max creates and resets the
generator. Trigger it by creating the class (it is a public creatable), then read
`cartridge_logs -module slot_uvgen`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones UV Generator (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def reset(**event):
    """Called when 3ds Max creates and resets this sub-component. A real one would clear its state
    to defaults here; this one says hello once and holds nothing."""
    _hello_once("reset (reset)")
    return {"ok": True}


def describe(params=None):
    return {"payload": "slot_uvgen", "version": "0.1.0", "lane": "python",
            "example": "barebones/uv-generator", "superClassId": "UVGEN_CLASS_ID"}


def init(**env):
    """Load-time crossing (FR-0006). The slot calls this at 3ds Max startup (NOTIFY_SYSTEM_STARTUP),
    before any host action, handing the environment only the slot can see. This is the INIT REPORT: it
    records that the cartridge loaded and the world it loaded into. It is deliberately NOT the
    cartridge's greeting - the greeting is logged only by the cartridge's own behaviour (the body
    above), so a load report is never mistaken for the thing working. `env` carries: maxRelease, slotName,
    slotVersion, cartridgeAbi, gup."""
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
