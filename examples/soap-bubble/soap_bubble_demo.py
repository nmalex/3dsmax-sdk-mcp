"""Soap Bubble demo scene - five bubbles drifting in front of a dark backdrop, rendered with Scanline.

WHAT IT BUILDS
    * five bubbles (spheres with mapping coordinates) sharing one Cartridge Material that runs this
      cartridge, each turned differently so their films do not look alike;
    * a dark gradient backdrop, seen through the bubbles, since a soap film is mostly transparent;
    * one light, which the film reflects as a glint (the C++ lane also reflects a soft studio window);
    * a camera, and an animation over frames 0-100: the bubbles rise and sway, and the film flows.
      The material's `phase` parameter is keyed from 0 to 3, which moves the film in both lanes; the
      C++ lane also flows with the scene time.

Then it saves the scene as <scenes>/soap_bubbles.max and renders frames 0, 50 and 100 into
<renderoutput>/soap_bubbles_f000.png and so on. Render frames 0-100 from Render Setup for the
animation.

WHY SCANLINE. The Cartridge Material runs 3ds Max's classic per-sample shading, which Scanline calls
and Arnold does not. Rendering is forced two-sided, so each bubble shows its back wall too.

WHICH LANE. The C++ lane (native/, unmanaged) is the full effect: thin-film interference for every
sample over 16 wavelengths, a reflected studio, glints, flowing swirls. With only the Python lane
deployed, the bubbles use its managed look, a lighter approximation. See README.md.

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
RENDER_FRAMES = (0, 50, 100)
RENDER_SIZE = (960, 540)

# (radius, x, y, z, spin about Z in degrees, rise over the animation)
BUBBLES = (
    (46.0, -10.0, 40.0, 10.0, 0.0, 70.0),
    (28.0, -95.0, 10.0, -25.0, 70.0, 95.0),
    (22.0, 80.0, -10.0, 40.0, 140.0, 80.0),
    (15.0, 55.0, -40.0, -45.0, 210.0, 110.0),
    (9.0, -55.0, -60.0, 45.0, 300.0, 120.0),
)


def _key(obj, prop, frame, value):
    with pymxs.animate(True):
        with pymxs.attime(frame):
            setattr(obj, prop, value)


def build():
    if not hasattr(rt, "Cartridge_Material"):
        raise RuntimeError("the Cartridge Material slot is not installed")
    if ASK_BEFORE_RESET and not rt.checkForSave():
        print("soap bubbles: cancelled - the current scene was kept")
        return None
    rt.resetMaxFile(rt.Name("noPrompt"))

    rt.renderers.production = rt.Default_Scanline_Renderer()
    rt.renderWidth, rt.renderHeight = RENDER_SIZE
    rt.rendForce2Side = True
    rt.animationRange = rt.Interval(0, 100)

    # The backdrop: a dark, screen-mapped gradient - bubbles are photographed against dark.
    backdrop = rt.Gradient()
    backdrop.color1 = rt.Color(38, 52, 92)
    backdrop.color2 = rt.Color(14, 18, 38)
    backdrop.color3 = rt.Color(4, 5, 12)
    backdrop.color2Pos = 0.5
    backdrop.coords.mappingType = 1    # environment
    backdrop.coords.mapping = 3        # screen
    rt.environmentMap = backdrop
    rt.useEnvironmentMap = True

    # One light, reflected as a glint. Two lights put two glints in every bubble, which reads as a
    # pair of eyes. Nothing here is lit diffusely.
    rt.Omnilight(name="Glint", pos=rt.Point3(260, -300, 220), multiplier=1.0)

    tgt = rt.Targetobject(name="Bubbles Camera.Target", pos=rt.Point3(0, 0, 10))
    cam = rt.Targetcamera(name="Bubbles Camera", pos=rt.Point3(0, -420, 40), target=tgt, fov=45)

    film = rt.Cartridge_Material(name="Soap Film")
    _key(film, "phase", 0, 0.0)
    _key(film, "phase", 100, 3.0)
    for radius, x, y, z, spin, rise in BUBBLES:
        bubble = rt.Sphere(name="Bubble", radius=radius, segs=64, mapcoords=True)
        bubble.rotation = rt.EulerAngles(0, 0, -spin)   # .rotation is the inverse; spin about Z only
        _key(bubble, "pos", 0, rt.Point3(x, y, z))
        _key(bubble, "pos", 50, rt.Point3(x + radius * 0.4, y, z + rise * 0.5))
        _key(bubble, "pos", 100, rt.Point3(x - radius * 0.2, y, z + rise))
        bubble.material = film

    rt.viewport.setCamera(cam)
    rt.sliderTime = 0
    scene = os.path.join(str(rt.getDir(rt.Name("scene"))), "soap_bubbles.max")
    rt.saveMaxFile(scene, quiet=True)

    renders = []
    out_dir = str(rt.getDir(rt.Name("renderoutput")))
    width, height = RENDER_SIZE
    for frame in RENDER_FRAMES:
        # The slider on the rendered frame, so the material has updated for it before the render.
        rt.sliderTime = frame
        path = os.path.join(out_dir, "soap_bubbles_f%03d.png" % frame)
        rt.render(camera=cam, frame=frame, outputwidth=width, outputheight=height, vfb=False,
                  outputfile=path)
        renders.append(path)
    rt.sliderTime = 0
    rt.redrawViews()
    print("soap bubbles: saved %s" % scene)
    for path in renders:
        print("soap bubbles: rendered %s" % path)
    return {"scene": scene, "renders": renders}


RESULT = build()
