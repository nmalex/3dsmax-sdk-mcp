"""@DISPLAY_NAME@ - an exporter cartridge. The slot walks the scene; you format the text.

WHAT AN EXPORTER CARTRIDGE IS RESPONSIBLE FOR, AND WHAT IT IS NOT.

The slot owns the scene walk, the file stream, the options dialog and every 3ds Max call. You own
FORMATTING and nothing else. You are handed plain data and you return text; the slot writes exactly
what you return, in the order it asked for it.

That split is why this file needs no 3ds Max SDK, no compiler, and no knowledge of the host.

-- THE SIX CALLS, IN THE ORDER AN EXPORT MAKES THEM -----------------------------------------------

    describe_ui(params)                    once, only when the host is showing prompts
    format_header(scene, params, slot, time)
    format_material_list(materials, params, slot, time)   only when materials were collected
    format_group_open(node, params)        before a group head and its descendants
    format_node(node, params, slot)        once per node, depth-first, pre-order
    format_group_close(node, params)       after a group's descendants

EVERY format_* FUNCTION RETURNS `{"text": "..."}` - one key, and the text INCLUDING its trailing
newline. The slot writes it verbatim and adds nothing. Return `{"text": ""}` to emit nothing.

Arguments arrive as KEYWORD arguments: the slot sends one JSON object per call and every top-level
key becomes a named parameter. Keep the defaults below so a missing key is never a TypeError.

-- WHAT format_node RECEIVES ----------------------------------------------------------------------

`node` always carries at least: name, indent, kind, handle, parent, time, tm (the node transform).
For geometry it also carries mesh data - vertices, faces, and optionally normals and texture
coordinates.

TWO THINGS THAT WILL BITE YOU IF YOU ASSUME OTHERWISE:

  * MESH DATA IS ALREADY IN WORLD SPACE. Do not multiply by `tm` again - `tm` is there for formats
    that want to write a transform, not for you to apply.
  * FACE CORNER ORDER IS ALREADY CORRECTED for negatively-scaled nodes. Do not re-wind it.

-- THE SCENE WALK ---------------------------------------------------------------------------------

Depth-first, pre-order, from the scene root. The root itself is never handed to you. A node whose
`kind` marks it a group head is bracketed: format_group_open, then the head's own format_node, then
its descendants, then format_group_close.

-- WHAT THIS TEMPLATE DOES ------------------------------------------------------------------------

It writes a readable listing - a header, then one line per node. It is deliberately not a real
format: it exists so that your FIRST export produces a file you can open and check, before any
format-specific code is in the way of reading the result. Replace the bodies; keep the shape.
"""

import mcp_bootstrap
import mcp_ui as ui


# -- the options panel ---------------------------------------------------------------------------
#
# Shown before an export when the host is prompting. Declare only options you actually honour - a
# control that does nothing is a promise the file will not keep.

def describe_ui(params=None):
    """The modal options dialog, composed the same way a modifier's rollout is."""
    return ui.build(
        ui.VBox(
            ui.Label("@DISPLAY_NAME@"),
            ui.Spacer(),
            ui.Label("Exports every node as one line."),
        )
    )


# -- the file ---------------------------------------------------------------------------------------

def format_header(scene=None, params=None, slot=None, time=0):
    """The first text in the file. Called once, before any node.

    `scene` describes what is being exported. `slot` is the facade handle - a decimal STRING, not a
    number - for payloads that need to ask the host something; this template does not.
    """
    scene = scene or {}
    return {"text": "# @DISPLAY_NAME@\n# scene: %s\n" % scene.get("name", "untitled")}


def format_material_list(materials=None, params=None, slot=None, time=0):
    """The materials the walk collected, in the order it found them.

    THAT ORDER IS THE REFERENCE NUMBERING. A node referring to material 2 means the third entry of
    this list, so do not sort it. Called only when the scene had materials.
    """
    materials = materials or []
    return {"text": "# materials: %d\n" % len(materials)}


def format_group_open(node=None, params=None):
    """A group head is about to be written. Its descendants follow, then format_group_close."""
    node = node or {}
    return {"text": "# group %s\n" % node.get("name", "")}


def format_group_close(node=None, params=None):
    """The group's descendants are done. `node` carries only the indent level here - no name."""
    return {"text": "# end group\n"}


def format_node(node=None, params=None, slot=None):
    """One node. Called once per node, depth-first, pre-order.

    Everything this template does is read a few keys and write a line. A real exporter reads the
    mesh: `node["vertices"]` is a flat list of world-space coordinates, `node["faces"]` indexes into
    it. Neither needs transforming or re-winding - see the module docstring.
    """
    node = node or {}
    name = node.get("name", "?")
    kind = node.get("kind", "?")
    verts = node.get("vertices") or []
    faces = node.get("faces") or []
    return {"text": "%s  kind=%s  verts=%d  faces=%d\n"
                    % (name, kind, len(verts) // 3, len(faces) // 3)}


def describe(params=None):
    """What this payload is, for the About rollout and for anything that asks."""
    return {"payload": "@MODULE@", "version": "0.1.0-dev", "lane": "python"}
