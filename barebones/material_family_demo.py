"""Material-family demo scene - one scene that exercises all four per-sample barebones at once.

WHAT IT BUILDS
    * a floor with the Cartridge Texture Map (a checker) in a Standard material's Diffuse slot;
    * a teapot with the Cartridge Material;
    * a teapot with a Standard material whose Shader is the Cartridge Shader (with a checker in
      Diffuse, so you can see the shader lighting a textured input);
    * two long, finely checkered strips receding to the horizon - "no supersampling" on the left,
      the Cartridge Sampler on the right - and a low "Sampler Camera" looking down them. Without
      supersampling the far checker breaks into moire; with the sampler it settles to grey;
    * yellow labels, two lights, a "Demo Camera", Scanline as the production renderer;
    * a THREE-FRAME animation (frames 0-2) keyed on every cartridge's own parameters:
        material hue      red -> green -> blue
        floor tiles       4 -> 8 -> 12      (and its dark level 0.2 -> 0.0 -> 0.5)
        shader hue        orange -> cyan -> magenta (strength 0.7 -> 1.0 -> 1.0)

THEN it saves the scene as <scenes>\\cartridge_demo.max and renders frames 0, 1 and 2 of the Demo
Camera, plus frame 0 of the Sampler Camera, into <renderoutput>\\cartridge_demo_*.png.

WHICH LANE IT TESTS. Whatever is deployed: with only the Python payloads the slots run MANAGED; with
the native DLLs beside the slots (see each barebones README) they run UNMANAGED. The script touches
only parameters both lanes declare, so the same scene tests both. Compare the two renders.

WHY SCANLINE. The Cartridge Material, Shader and Sampler implement 3ds Max's classic per-sample
shading, which only the Scanline renderer calls. Other renderers (Arnold, for one) hide them from the
Material/Map Browser and do not render them. The Texture Map is accepted more widely.

VIEWPORT PRESETS. Use the Standard preset: the High Quality preset draws the shader teapot flat white,
as 3ds Max draws any Standard material whose shader it does not ship. Renders are unaffected.

ONE LIMIT THAT IS NOT OURS. The Standard material hands its sampler the Quality value only when the
value is set, not per frame - so a keyed "samplerQuality" never reaches any sampler, built-in ones
included. Quality is therefore constant here (1.0 = a 4x4 grid, since the sampler's `grid` is 0).

HOW TO RUN
    * 3ds Max: Scripting > Run Script... > this file (Python runs directly in 3ds Max 2026); or
    * over MCP: max_cartridge_probe {"script": <this file's text>, "keep": true}
      (set ASK_BEFORE_RESET = False first - a probe cannot answer a save prompt).

It starts a NEW scene. With ASK_BEFORE_RESET on, 3ds Max first offers to save unsaved work, and the
script stops if you cancel.
"""

import os

import pymxs

rt = pymxs.runtime

ASK_BEFORE_RESET = True
RENDER_FRAMES = True
RENDER_SIZE = (960, 540)


def _label(text, pos, size):
    node = rt.Text(text=text, size=size, name="Label - " + text)
    # MAXScript's .rotation is the inverse rotation: -90 here stands the text up, facing -Y.
    # Rotation FIRST: set after the position, it swings the position round the origin too.
    node.rotation = rt.EulerAngles(-90, 0, 0)
    node.pos = pos
    node.render_renderable = True
    node.render_displayRenderMesh = True
    node.render_thickness = 0.6
    node.material = rt.Standardmaterial(name="Label", diffuse=rt.Color(255, 220, 90),
                                        selfIllumAmount=100)
    return node


def _checker(tiles, bright, dark):
    checker = rt.Cartridge_Texture_Map()
    checker.tiles = tiles
    checker.bright = bright
    checker.dark = dark
    return checker


def _plane(name, length, width, pos):
    return rt.Plane(name=name, length=length, width=width, pos=pos, lengthsegs=1, widthsegs=1)


def _keys(obj, prop, values):
    with pymxs.animate(True):
        for frame, value in enumerate(values):
            with pymxs.attime(frame):
                setattr(obj, prop, value)


def _require_slots():
    missing = [name for name in ("Cartridge_Texture_Map", "Cartridge_Material")
               if not hasattr(rt, name)]
    if missing:
        raise RuntimeError("these cartridge slots are not installed: %s" % ", ".join(missing))


def build():
    _require_slots()
    if ASK_BEFORE_RESET and not rt.checkForSave():
        print("cartridge demo: cancelled - the current scene was kept")
        return None
    rt.resetMaxFile(rt.Name("noPrompt"))

    rt.renderers.production = rt.Default_Scanline_Renderer()
    rt.renderWidth, rt.renderHeight = RENDER_SIZE
    rt.animationRange = rt.Interval(0, 2)

    # -- lights and cameras ----------------------------------------------------------------------
    rt.Omnilight(name="Key Light", pos=rt.Point3(-120, -160, 180), multiplier=1.0)
    rt.Omnilight(name="Fill Light", pos=rt.Point3(160, -60, 90), multiplier=0.35)
    demo_cam = rt.Targetcamera(name="Demo Camera", pos=rt.Point3(0, -230, 95), fov=50,
                               target=rt.Targetobject(name="Demo Camera.Target",
                                                      pos=rt.Point3(0, 20, 18)))
    sampler_cam = rt.Targetcamera(name="Sampler Camera", pos=rt.Point3(0, 150, 18), fov=70,
                                  target=rt.Targetobject(name="Sampler Camera.Target",
                                                         pos=rt.Point3(0, 1200, 0)))

    # -- texture map: the floor ------------------------------------------------------------------
    floor = _plane("Floor - Cartridge Texture Map", 160, 260, rt.Point3(0, 10, 0))
    floor_mtl = rt.Standardmaterial(name="Floor (Cartridge Texture Map)")
    floor_map = _checker(4.0, 0.85, 0.2)
    floor_mtl.diffuseMap = floor_map
    floor_mtl.showInViewport = True
    floor.material = floor_mtl

    # -- material ----------------------------------------------------------------------------------
    teapot_mtl = rt.Teapot(name="Teapot - Cartridge Material", radius=22, pos=rt.Point3(-55, 0, 0))
    teapot_mtl.mapcoords = True
    material = rt.Cartridge_Material(name="Cartridge Material")
    material.rim = 0.35
    teapot_mtl.material = material

    # -- shader -----------------------------------------------------------------------------------
    teapot_sh = rt.Teapot(name="Teapot - Cartridge Shader", radius=22, pos=rt.Point3(55, 0, 0))
    # A render generates a primitive's mapping on its own; the viewport shows a map only when the
    # object carries mapping coordinates.
    teapot_sh.mapcoords = True
    shaded = rt.Standardmaterial(name="Standard + Cartridge Shader")
    shaded.shaderByName = "Cartridge Shader"
    # The colours after the shader: they are the shader's parameters, so set them on this one.
    shaded.diffuse = rt.Color(255, 255, 255)
    shaded.ambient = rt.Color(255, 255, 255)
    shaded.diffuseMap = _checker(6.0, 1.0, 0.55)
    # The viewport shows the Standard material's own Diffuse and this map - not the shader's tint,
    # which only a render shows.
    shaded.showInViewport = True
    teapot_sh.material = shaded

    # -- sampler: the same strip twice, only the supersampling differs ---------------------------------
    for name, x, supersampled in (("Strip A - no supersampling", -260, False),
                                  ("Strip B - Cartridge Sampler", 260, True)):
        strip = _plane(name, 3000, 500, rt.Point3(x, 1700, 0.2))
        mtl = rt.Standardmaterial(name=name, selfIllumAmount=100)
        mtl.diffuseMap = _checker(120.0, 1.0, 0.0)
        if supersampled:
            mtl.samplerUseGlobal = False
            mtl.samplerEnable = True
            mtl.samplerByName = "Cartridge Sampler"
            mtl.samplerQuality = 1.0
        strip.material = mtl

    # -- labels --------------------------------------------------------------------------------------
    _label("Cartridge Material", rt.Point3(-72, -10, 34), 8.0)
    _label("Cartridge Shader", rt.Point3(26, -10, 34), 8.0)
    _label("no supersampling", rt.Point3(-62, 330, 12), 8.0)
    _label("Cartridge Sampler", rt.Point3(62, 330, 12), 8.0)

    # -- three frames -----------------------------------------------------------------------------------
    _keys(material, "hue", [0.0, 0.33, 0.66])
    _keys(floor_map, "tiles", [4.0, 8.0, 12.0])
    _keys(floor_map, "dark", [0.2, 0.0, 0.5])
    _keys(shaded, "hue", [0.08, 0.5, 0.8])
    _keys(shaded, "strength", [0.7, 1.0, 1.0])

    rt.viewport.setCamera(demo_cam)
    rt.sliderTime = 0
    scene = os.path.join(str(rt.getDir(rt.Name("scene"))), "cartridge_demo.max")
    rt.saveMaxFile(scene, quiet=True)

    renders = []
    if RENDER_FRAMES:
        out_dir = str(rt.getDir(rt.Name("renderoutput")))
        width, height = RENDER_SIZE
        for frame in range(3):
            path = os.path.join(out_dir, "cartridge_demo_f%d.png" % frame)
            rt.render(camera=demo_cam, frame=frame, outputwidth=width, outputheight=height,
                      vfb=False, outputfile=path)
            renders.append(path)
        path = os.path.join(out_dir, "cartridge_demo_sampler.png")
        rt.render(camera=sampler_cam, frame=0, outputwidth=width, outputheight=height,
                  vfb=False, outputfile=path)
        renders.append(path)
    rt.redrawViews()
    print("cartridge demo: saved %s" % scene)
    for path in renders:
        print("cartridge demo: rendered %s" % path)
    return {"scene": scene, "renders": renders}


RESULT = build()
