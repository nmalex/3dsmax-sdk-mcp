"""Barebones Exporter (Python lane) - the slot walks the scene; you format the text.

WHAT AN EXPORTER CARTRIDGE OWNS, AND WHAT IT DOES NOT. The slot owns the scene walk, the file
stream, the options dialog and every 3ds Max call. You own FORMATTING and nothing else: you are
handed plain data and you return text, and the slot writes exactly what you return. That split is
why this file needs no 3ds Max SDK.

This barebones writes a readable one-line-per-node listing - deliberately not a real format - so your
first export produces a file you can open and check before any format code is in the way. Replace the
bodies; keep the shape.

WHICH SLOT HOSTS IT, AND WHICH OTHER CLASS IDS IT COULD BEAR. This is the payload the
`Cartridge Exporter` slot loads by its fixed module name, `slot_exporter`, registering one
SuperClassID: SCENE_EXPORT_CLASS_ID. The same single-shot shape - a modal only when a person asked,
and a file written once - is what an IMPORTER is too; only the direction differs:

    SCENE_EXPORT_CLASS_ID    exporter   (this slot; writes a file)
    SCENE_IMPORT_CLASS_ID    importer   (a sibling slot; reads a file, returns scene data)

See this example's README.md for the full table.

-- THE CALLS, IN THE ORDER AN EXPORT MAKES THEM --------------------------------------------------
    describe_ui(params)                    once, only when the host is showing prompts
    format_header(scene, params, slot, time)
    format_material_list(materials, ...)   only when materials were collected
    format_group_open(node, params)        before a group head and its descendants
    format_node(node, params, slot)        once per node, depth-first, pre-order
    format_group_close(node, params)       after a group's descendants

Every format_* returns {"text": "..."} - the text INCLUDING its trailing newline. The slot writes it
verbatim. Return {"text": ""} to emit nothing.
"""

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Exporter (Python) is live; this line came from "
                          "its payload on the first %s of an export." % where)


def describe_ui(params=None, **kwargs):
    """The modal options dialog, shown before an export when the host is prompting."""
    return ui.build(
        ui.VBox(
            ui.Label("Barebones Exporter"),
            ui.Spacer(),
            ui.Label("Writes one line per node - a listing, not a real format."),
        )
    )


def format_header(scene=None, params=None, slot=None, time=0):
    """The first text in the file. Called once, before any node."""
    _hello_once("header")
    scene = scene or {}
    return {"text": "# Barebones Exporter\n# scene: %s\n" % scene.get("name", "untitled")}


def format_material_list(materials=None, params=None, slot=None, time=0):
    """One block for the scene's materials, in walk order (which IS the reference numbering)."""
    return {"text": "# materials: %d\n" % len(materials or [])}


def format_group_open(node=None, params=None):
    node = node or {}
    return {"text": "# group %s\n" % node.get("name", "")}


def format_group_close(node=None, params=None):
    return {"text": "# end group\n"}


def format_node(node=None, params=None, slot=None):
    """One line per node. `node` carries at least name, kind, and (for geometry) vertices/faces.

    MESH DATA IS ALREADY IN WORLD SPACE and face winding is already corrected - do not re-apply the
    transform or re-wind.
    """
    node = node or {}
    verts = len(node.get("vertices", [])) // 3
    faces = len(node.get("faces", [])) // 3
    return {"text": "%s  kind=%s  verts=%d  faces=%d\n"
            % (node.get("name", "?"), node.get("kind", "?"), verts, faces)}


def describe(params=None):
    """What this payload is, for anything that asks."""
    return {"payload": "slot_exporter", "version": "0.1.0", "lane": "python",
            "example": "barebones/exporter"}


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
