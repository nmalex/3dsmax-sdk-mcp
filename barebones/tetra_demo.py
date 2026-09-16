"""Tetra demo scene - Tetra Dummy and Tetra Helper side by side, to see how the two differ.

One script for both barebones/helper and barebones/manipulator, linked from each README: each of
the two tetras is best understood next to the other.

WHAT IT BUILDS
    * a Tetra Dummy (barebones/manipulator) on the left: a MANIPULATOR. Its cartridge builds the
      gizmo through the facade and colours it cyan. `size` is the half-edge (default 15);
    * a Tetra Helper (barebones/helper) on the right: a PLAIN HELPER. Its cartridge returns line
      data and the slot draws it in the object's wire colour (orange here). `size` is the edge
      length (default 30);
    * a text label under each, and a "Tetra Camera" framing both, set as the viewport.

Then it selects nothing and redraws, and saves a capture of the viewport as
<renderoutput>/tetra_demo.png. Nothing is rendered: helpers do not render.

WHAT TO TRY AFTER
    * Create > Helpers > MCP Cartridges: create a Tetra Helper by click-and-drag (the drag is its
      size) and a Tetra Dummy by a click;
    * turn on Select and Manipulate (main toolbar) to see which of the two is a manipulator;
    * change Size on either in the Modify panel.

WHICH LANE IT TESTS. Whatever is deployed for `slot_helper` and `slot_manipulator`, Python or C++.
With either slot's cartridge missing, that tetra is skipped and the script says so.

HOW TO RUN
    * 3ds Max: Scripting > Run Script... > this file; or
    * over MCP: max_cartridge_probe {"script": <this file's text>, "keep": true}
      (set ASK_BEFORE_RESET = False first - a probe cannot answer a save prompt).

It starts a NEW scene. With ASK_BEFORE_RESET on, 3ds Max first offers to save unsaved work, and the
script stops if you cancel.
"""

import os

import pymxs

rt = pymxs.runtime

ASK_BEFORE_RESET = True

# (MAXScript class, label, x position, wire colour or None for the cartridge's own colour)
TETRAS = (
    ("Cartridge_Manipulator", "Tetra Dummy\rmanipulator", -40.0, None),
    ("Cartridge_Helper", "Tetra Helper\rplain helper", 40.0, (255, 160, 40)),
)

# The view: from the front and raised, framing both tetras and their labels.
CAMERA_POS = (0.0, -190.0, 70.0)
CAMERA_TARGET = (0.0, -15.0, 0.0)
CAMERA_FOV = 45.0


def build():
    if ASK_BEFORE_RESET and not rt.checkForSave():
        print("tetra demo: cancelled - the current scene was kept")
        return None
    rt.resetMaxFile(rt.Name("noPrompt"))

    placed = []
    for class_name, label, x, wire in TETRAS:
        if not hasattr(rt, class_name):
            print("tetra demo: %s is not installed - skipped" % class_name)
            continue
        node = getattr(rt, class_name)(pos=rt.Point3(x, 0, 0))
        if wire is not None:
            node.wirecolor = rt.Color(*wire)
        # Flat on the ground in front of its tetra, which the raised camera reads head-on.
        text = rt.Text(text=label, size=8, pos=rt.Point3(x, -45, 0))
        text.wirecolor = rt.Color(230, 230, 230)
        placed.append("%s: %s, size %s" % (label.replace("\r", ", "), node.name, node.size))

    # A camera in front and a little above, so both tetras read as solids and the labels face it.
    target = rt.Targetobject(name="Tetra Camera.Target", pos=rt.Point3(*CAMERA_TARGET))
    camera = rt.Targetcamera(name="Tetra Camera", pos=rt.Point3(*CAMERA_POS), target=target,
                             fov=CAMERA_FOV)
    rt.viewport.setLayout(rt.Name("layout_1"))
    rt.viewport.setCamera(camera)
    rt.clearSelection()
    rt.completeRedraw()

    capture = os.path.join(str(rt.getDir(rt.Name("renderoutput"))), "tetra_demo.png")
    image = rt.gw.getViewportDib()
    image.filename = capture
    rt.save(image)
    rt.close(image)

    for line in placed:
        print("tetra demo: placed %s" % line)
    print("tetra demo: viewport saved as %s" % capture)
    return {"placed": placed, "capture": capture}


RESULT = build()
