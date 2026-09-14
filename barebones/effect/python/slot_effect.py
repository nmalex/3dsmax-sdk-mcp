"""Barebones Render Effect (Python lane) - post-processes a rendered frame; here, changes nothing.

WHAT A RENDER EFFECT CARTRIDGE IS. The user adds it under Rendering > Effects. After each frame is
rendered, 3ds Max calls the slot's Apply() and the slot forwards it here as `EffectApply`, lending
the render context and the abort callback for exactly that call. A real effect reads the frame and
changes pixels through the facade; this one leaves the frame untouched and only says hello, which is
the honest thing for an inert example to do.

WHICH SLOT HOSTS IT, AND WHICH OTHER CLASS IDS IT COULD BEAR. This is the payload the
`Cartridge Effect` slot loads by its fixed module name, `slot_effect`, registering one SuperClassID:
RENDER_EFFECT_CLASS_ID. Several other kinds share the same `SpecialFX` base and a similar
"called at a point in the render" shape:

    RENDER_EFFECT_CLASS_ID    render post-effect  (this slot; Effect::Apply per frame)
    ATMOSPHERIC_CLASS_ID      atmospheric effect  (Atmospheric::Shade along a ray)
    TONE_OPERATOR_CLASS_ID    tone operator       (ToneOperator::ScaledToRGB per sample)
    SHADOW_TYPE_CLASS_ID      shadow generator    (ShadowType)

See this example's README.md for the full table.

THE HELLO. Logged once from the dispatched function, never at import (only a dispatched call's
output is captured into cartridge_logs). `EffectApply` fires once per frame at the end of a render;
the guard makes the announcement once-per-load. Trigger it by rendering any frame with this effect
active, then read `cartridge_logs -module slot_effect`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Render Effect (Python) is live; this line came "
                          "from its payload on the first %s." % where)


def EffectApply(**event):
    """Called once per frame after the render, with the render context lent for this call.

    `event` carries the callback fields (time, and handles into the render context reachable through
    the facade). This barebones reads none of them and changes no pixels - it only announces itself.
    To make a real effect, read the frame and write it back through the render-context facade.
    """
    _hello_once("render (EffectApply)")
    return {"changed": False, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_effect", "version": "0.1.0", "lane": "python",
            "example": "barebones/effect"}
