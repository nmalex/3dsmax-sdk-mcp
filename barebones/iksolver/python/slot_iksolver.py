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
