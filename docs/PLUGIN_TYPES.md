# Plugin types — what you can build today, and how far the rest already is

**Two Cartridge kinds exist today: Modifier and Exporter.** [SLOTS.md](SLOTS.md) says this plainly
and it is not being softened here — *"these two are what you can build a Cartridge for. That is the
whole list, and it is not a policy."* [ROADMAP.md](../ROADMAP.md) lists "more kinds of plugin" under
**Later**: wanted, not scheduled.

This page answers a different question: **when a new kind lands, how much of it is already done?**
The factory behind this kit builds against the full 3ds Max SDK, and a large share of its plugin
surface has already been mechanically proven, and in three cross-cutting cases is reachable from a
Cartridge that ships today — none of it exposed as its own Cartridge template yet, all of it
removing risk from the day one is built.

## Why this is worth stating

A new Slot is real work either way — a new template, a build, a release. What this page is really
saying is where that work is **not** starting from zero: the class compiles and registers against
the live SDK today, or the harder part (a plugin whose vtable 3ds Max calls into synchronously, on
its own stack, reaching a swappable payload) is already written and architecturally sound, proven to
compile and register even where nothing has hosted it against a live payload yet. Neither of those
facts turns into a Cartridge you can occupy without a template and a release — that is the whole
reason this is a separate page from [SLOTS.md](SLOTS.md) and not a rewrite of it.

## 37 plugin superclasses, proven to compile and register

Every row below is a real 3ds Max `SuperClassID` the underlying architecture has generated a slot
for and verified against a live, headless 3ds Max — it links, it registers, `3ds Max` accepts it as
a plugin of that kind. None has a Cartridge template yet; each is one new Slot project away, built on
a mechanism that already works for the 37th time as reliably as the first.

| Plugin kind | SuperClassID | SDK header | What it is |
| --- | --- | --- | --- |
| GeomObject | `GEOMOBJECT_CLASS_ID` | `object.h` | geometry |
| CameraObject | `CAMERA_CLASS_ID` | `object.h` | camera |
| LightObject | `LIGHT_CLASS_ID` | `object.h` | light |
| ShapeObject | `SHAPE_CLASS_ID` | `object.h` | shape |
| HelperObject | `HELPER_CLASS_ID` | `object.h` | helper |
| Object | `SYSTEM_CLASS_ID` | `object.h` | system object |
| Modifier | `OSM_CLASS_ID` | `object.h` | object-space modifier — **shipping today** |
| WSModifier | `WSM_CLASS_ID` | `object.h` | world-space modifier |
| WSMObject | `WSM_OBJECT_CLASS_ID` | `object.h` | world-space modifier object |
| ReferenceTarget | `REF_TARGET_CLASS_ID` | `ref.h` | plain reference target |
| Mtl | `MATERIAL_CLASS_ID` | `imtl.h` | material |
| Texmap | `TEXMAP_CLASS_ID` | `imtl.h` | texture map |
| Shader | `SHADER_CLASS_ID` | `imtl.h` | standard-material shader |
| Atmospheric | `ATMOSPHERIC_CLASS_ID` | `imtl.h` | atmospheric effect |
| Effect | `RENDER_EFFECT_CLASS_ID` | `imtl.h` | render post-effect |
| ShadowType | `SHADOW_TYPE_CLASS_ID` | `shadgen.h` | shadow generator |
| Renderer | `RENDERER_CLASS_ID` | `Rendering/Renderer.h` | renderer |
| SceneExport | `SCENE_EXPORT_CLASS_ID` | `impexp.h` | exporter — **shipping today** |
| SceneImport | `SCENE_IMPORT_CLASS_ID` | `impexp.h` | importer |
| UtilityObj | `UTILITY_CLASS_ID` | `utilapi.h` | utility panel plugin |
| GUP | `GUP_CLASS_ID` | `gup.h` | global utility plugin |
| CustAttrib | `CUST_ATTRIB_CLASS_ID` | `custattrib.h` | custom attributes |
| IKSolver | `IK_SOLVER_CLASS_ID` | `IKSolver.h` | IK solver |
| Osnap | `OSNAP_CLASS_ID` | `osnap.h` | object snap |
| TrackViewUtility | `TRACKVIEW_UTILITY_CLASS_ID` | `iTrackViewUtility.h` | Track View utility |
| IRenderElement | `RENDER_ELEMENT_CLASS_ID` | `renderelements.h` | render output element |
| ToneOperator | `TONE_OPERATOR_CLASS_ID` | `tonemap.h` | tone operator |
| Sampler | `SAMPLER_CLASS_ID` | `imtl.h` | sampler |
| IMultiPassCameraEffect | `MPASS_CAM_EFFECT_CLASS_ID` | `object.h` | multi-pass camera effect |
| SoundObj | `SOUNDOBJ_CLASS_ID` | `soundobj.h` | sound object |
| BitmapIO | `BMM_IO_CLASS_ID` | `bitmap.h` | image file loader/saver |
| ReferenceMaker | `REF_MAKER_CLASS_ID` | `ref.h` | plain reference maker |
| BezFont | `BEZFONT_LOADER_CLASS_ID` | `bezfont.h` | bezier font loader |
| MaxBakeElement | `BAKE_ELEMENT_CLASS_ID` | `renderelements.h` | texture bake element |
| MCInputDevice | `MOT_CAP_DEV_CLASS_ID` | `mcapdev.h` | motion-capture device |
| MCDeviceBinding | `MOT_CAP_DEVBINDING_CLASS_ID` | `mcapdev.h` | motion-capture device binding |
| TexmapContainer | `TEXMAP_CONTAINER_CLASS_ID` | `imtl.h` | texmap container (materials assembly helper) |

Two of these (Modifier, Exporter) are already shipping Cartridge kinds; the other 35 are the
mechanical half of "a new kind of Slot" already done.

## Beyond compiling: 8 more hooks, at two different stages of proof

Compiling and registering is the easy half. The hard half is a plugin whose vtable 3ds Max calls
into **synchronously, on its own stack**, reaching whichever payload currently occupies it — the same
mechanism a Modifier or Exporter Cartridge already relies on. Eight more kinds of hook build on that
mechanism, and they are honestly at two different stages of proof, not one:

**Three ride on a Cartridge that already ships**, because they are cross-cutting rather than a
plugin class of their own — a payload running inside today's Modifier or Exporter Slot can reach
them right now, no new Slot required:

| Capability | What it does |
| --- | --- |
| MAXScript function interface | a payload publishes a typed, callable MAXScript interface |
| MAXScript global primitive | a payload registers a callable global MAXScript function |
| Asset accessor | a plugin's own asset references (e.g. a bitmap path) resolve through a payload |

**Five are their own plugin class, and are proven only as far as compiling and registering** — the
dispatch call chain to reach a payload is written and architecturally sound, but none of the five is
hosted by anything that currently starts a live payload for it, so none has been exercised against
one yet:

| Capability | Rides on | What it does, once hosted |
| --- | --- | --- |
| Object Snap | `Osnap` | a registered snap point provider, forwarding a live snap query to a payload |
| Viewport gizmo | `HelperObject` | an interactive on-viewport manipulator (mouse-driven editing), not just a static helper |
| IK solver | `IKSolver` | a real IK chain solve, reading joint state and writing the solved result |
| Render pipeline hook | `Renderer` / `RENDER_EFFECT_CLASS_ID` | render-open/render/apply hooks into the active render context |
| ParticleFlow operator | `HelperObject` + PF operator subclass | a real Particle Flow operator, driving `Proceed()` each simulation step |

None of the eight has a Cartridge template yet — occupying one today needs a new Slot's C++ source,
not a payload alone. What is retired for the five is the mechanical risk (does a plugin's vtable
reach the facade's dispatch spine at all) — not the remaining, real work of giving each one its own
Slot to actually run in.

## What this page is not

It is not an install target, and nothing here changes what `install`/`bootstrap` produce. If one of
these is what you are waiting for, say so in an issue — [ROADMAP.md](../ROADMAP.md) is explicit that
what people ask for is what moves next.
