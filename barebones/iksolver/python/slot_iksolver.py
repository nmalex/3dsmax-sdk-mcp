"""Barebones IK Solver (Python lane) - solves an IK chain; here, leaves the chain as it is.

WHAT AN IK-SOLVER CARTRIDGE IS. The user assigns it to a bone chain (Animation > IK Solvers). When
the chain needs solving - the goal moves, or the frame changes - 3ds Max calls the solver and the
slot forwards it here as `IKSolve`. A real solver computes joint angles that reach the goal; this
barebones computes nothing and says hello, so you can prove the solver is assigned and driven before
writing any inverse kinematics.

WHICH SLOT HOSTS IT. The payload the `Cartridge IK Solver` slot loads by its fixed module name,
`slot_iksolver`, registering one SuperClassID: IK_SOLVER_CLASS_ID.

THE HELLO. Logged once from `IKSolve`. Trigger it by assigning this solver to a two-bone chain and
moving the goal (or scrubbing time), then read `cartridge_logs -module slot_iksolver`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones IK Solver (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def IKSolve(**event):
    """Called when the chain needs solving. A real solver returns joint rotations; this one does not."""
    _hello_once("solve (IKSolve)")
    return {"solved": False, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_iksolver", "version": "0.1.0", "lane": "python",
            "example": "barebones/iksolver"}


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
