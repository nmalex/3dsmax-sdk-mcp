"""Barebones ParticleFlow Operator (Python lane) - a Particle View operator; here, an inert one.

WHAT A PF-OPERATOR CARTRIDGE IS. It appears in the Particle View depot and can be dropped into an
event. Each integration step, ParticleFlow calls the operator to act on the particles in its event;
the slot forwards that as `PFProceed`. A real operator moves, colours, spawns or kills particles;
this barebones touches none of them and says hello, so you can prove the operator is registered and
proceeding before writing any particle behaviour.

WHICH SLOT HOSTS IT, AND THE ONE-SUPERCLASS-MANY-KINDS STORY. The payload the `Cartridge PF Operator`
slot loads by its fixed module name, `slot_pfoperator`. It registers under HELPER_CLASS_ID - the same
SuperClassID as a plain helper and a manipulator - and is told apart from them by its ClassDesc
answering `SubClassID() == PFOperatorSubClassID` and implementing the `IPFAction` interface. That is
why it is its own slot and its own barebones even though it shares a superclass. See this example's
README.md.

THE HELLO. Logged once from `PFProceed`. Trigger it by adding this operator to a Particle Flow event
with a source emitting particles and playing the timeline, then read
`cartridge_logs -module slot_pfoperator`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones PF Operator (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def PFProceed(**event):
    """Called each integration step for the particles in this operator's event. Touches none of them."""
    _hello_once("proceed (PFProceed)")
    return {"handled": True, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_pfoperator", "version": "0.1.0", "lane": "python",
            "example": "barebones/pfoperator"}
