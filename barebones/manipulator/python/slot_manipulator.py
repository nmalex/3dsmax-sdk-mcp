"""Barebones Manipulator (Python lane) - a viewport gizmo; here, an inert one.

WHAT A MANIPULATOR CARTRIDGE IS. It is a helper the user can manipulate directly in the viewport -
a custom gizmo. When it is displayed or the mouse moves over it, 3ds Max asks it to rebuild its
shapes and to handle mouse interaction; the slot forwards those as `ManipUpdateShapes` and
`ManipMouse`. A real manipulator draws handles and edits a target when they are dragged; this
barebones draws the slot's default and says hello, so you can prove the gizmo is registered and
driven before writing any interaction.

WHICH SLOT HOSTS IT, AND THE ONE-SUPERCLASS-MANY-KINDS STORY. The payload the `Cartridge Manipulator`
slot loads by its fixed module name, `slot_manipulator`. It registers under HELPER_CLASS_ID - the
same SuperClassID as a plain helper and a ParticleFlow operator - and is told apart from them only by
its ClassDesc answering `IsManipulator() == TRUE`. That is why a manipulator is its own slot and its
own barebones even though it shares a superclass. See this example's README.md.

THE HELLO. Logged once from `ManipUpdateShapes`, which fires when the gizmo is displayed. Trigger it
by creating this manipulator helper and selecting it, then read
`cartridge_logs -module slot_manipulator`.
"""

import mcp_bootstrap

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Manipulator (Python) is live; this line came from "
                          "its payload on the first %s." % where)


def ManipUpdateShapes(**event):
    """Called to (re)build the gizmo's handles. A real one adds shapes; this one adds none."""
    _hello_once("display (ManipUpdateShapes)")
    return {"shapes": [], "lane": "python"}


def ManipMouse(**event):
    """Called on mouse interaction with the gizmo. A real one edits a target; this one does nothing."""
    _hello_once("mouse (ManipMouse)")
    return {"handled": False, "lane": "python"}


def describe(params=None):
    return {"payload": "slot_manipulator", "version": "0.1.0", "lane": "python",
            "example": "barebones/manipulator"}
