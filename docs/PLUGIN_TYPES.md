# Plugin types — what you can build today, and how far the rest already is

**Eighteen Cartridge kinds ship today.** [SLOTS.md](SLOTS.md) lists the Slots and how each appears in
3ds Max; [SUPERCLASS_CENSUS.md](SUPERCLASS_CENSUS.md) maps *every* plugin type the SDK declares into
three states — has a Slot, registerable with a Slot on the roadmap, or not registerable at all (with
the reason); [COVERAGE_MAP.md](COVERAGE_MAP.md) is the per-type accounting of how the 18 are verified.

The 18 that ship:

`modifier` · `exporter` · `renderer` · `manipulator` · `controller` · `uv-generator` ·
`xyz-generator` · `texture-output` · `aa-filter-kernel` · `radiosity` · `datachannel-engine` ·
`effect` · `iksolver` · `osnap` · `pfoperator` · `utility` · `color-picker` · `videopost-filter`.

This page answers a different question: **for a kind that does not ship yet, how much of it is already
done?** A large share of the 3ds Max plugin surface beyond these 18 is already mechanically proven,
which is what turns "why isn't type X covered?" into "type X is on the roadmap and most of the risk is
already retired."

## Why this is worth stating

A new Slot is real work either way — a new template, a build, a release. What this page is really
saying is where that work is **not** starting from zero: for many of the types that do not ship yet,
the class already compiles and registers against the live SDK, so building the Slot is the remaining
step rather than the whole job. **None of that turns a type into a Cartridge you can occupy** without
its own Slot and a release — that is the whole reason this is a separate page from [SLOTS.md](SLOTS.md)
and not a rewrite of it.

## Registerable, slot on the roadmap — proven to compile and register

Every row below is a real 3ds Max `SuperClassID` a third party **can** register a plugin under, whose
Slot is simply **not built yet**. None has a Cartridge template today; each is one new Slot project
away. A feature request for any of them is legitimate and belongs on [ROADMAP.md](../ROADMAP.md) —
what people ask for is what moves.

| Plugin kind | `SuperClassID` | SDK header | What it is |
| --- | --- | --- | --- |
| GeomObject | `GEOMOBJECT_CLASS_ID` | `object.h` | geometry |
| CameraObject | `CAMERA_CLASS_ID` | `object.h` | camera |
| LightObject | `LIGHT_CLASS_ID` | `object.h` | light |
| ShapeObject | `SHAPE_CLASS_ID` | `object.h` | shape |
| HelperObject | `HELPER_CLASS_ID` | `object.h` | plain helper *(manipulator & pfoperator already ship under this id)* |
| Object | `SYSTEM_CLASS_ID` | `object.h` | system object |
| WSModifier | `WSM_CLASS_ID` | `object.h` | world-space modifier |
| WSMObject | `WSM_OBJECT_CLASS_ID` | `object.h` | world-space modifier object |
| Mtl | `MATERIAL_CLASS_ID` | `imtl.h` | material |
| Texmap | `TEXMAP_CLASS_ID` | `imtl.h` | texture map |
| Shader | `SHADER_CLASS_ID` | `imtl.h` | standard-material shader |
| Atmospheric | `ATMOSPHERIC_CLASS_ID` | `imtl.h` | atmospheric effect |
| ShadowType | `SHADOW_TYPE_CLASS_ID` | `shadgen.h` | shadow generator |
| SceneImport | `SCENE_IMPORT_CLASS_ID` | `impexp.h` | importer |
| CustAttrib | `CUST_ATTRIB_CLASS_ID` | `custattrib.h` | custom attributes |
| TrackViewUtility | `TRACKVIEW_UTILITY_CLASS_ID` | `iTrackViewUtility.h` | Track View utility |
| IRenderElement | `RENDER_ELEMENT_CLASS_ID` | `renderelements.h` | render output element |
| ToneOperator | `TONE_OPERATOR_CLASS_ID` | `tonemap.h` | tone operator |
| Sampler | `SAMPLER_CLASS_ID` | `imtl.h` | sampler |
| IMultiPassCameraEffect | `MPASS_CAM_EFFECT_CLASS_ID` | `object.h` | multi-pass camera effect |
| SoundObj | `SOUNDOBJ_CLASS_ID` | `soundobj.h` | sound object |
| BitmapIO | `BMM_IO_CLASS_ID` | `bitmap.h` | image file loader/saver |
| BezFont | `BEZFONT_LOADER_CLASS_ID` | `bezfont.h` | bezier font loader |
| MaxBakeElement | `BAKE_ELEMENT_CLASS_ID` | `renderelements.h` | texture bake element |
| MCInputDevice | `MOT_CAP_DEV_CLASS_ID` | `mcapdev.h` | motion-capture device |
| MCDeviceBinding | `MOT_CAP_DEVBINDING_CLASS_ID` | `mcapdev.h` | motion-capture device binding |
| TexmapContainer | `TEXMAP_CONTAINER_CLASS_ID` | `imtl.h` | texmap container (materials assembly helper) |

**The controller value-type matrix** is more of the same: `CTRL_FLOAT_CLASS_ID` ships as the
`controller` Slot today, and the other value types — position, rotation, scale, `Point3`, `Point4`,
`Matrix3`, `FRGBA`, morph — are each their own registerable super-class a controller Slot could target
next. **Reference maker / target and GUP** (`REF_MAKER_CLASS_ID`, `REF_TARGET_CLASS_ID`,
`GUP_CLASS_ID`) are base/infrastructure super-classes rather than author-facing plugin templates; the
[census](SUPERCLASS_CENSUS.md) explains why.

## The hooks that graduated

An earlier version of this page listed five plugin kinds as "proven only as far as compiling and
registering, not yet hosted against a live payload" — Object Snap, the viewport manipulator, the IK
solver, the render-effect pipeline hook, and the Particle Flow operator. **All five now ship as Slots**
(they are `osnap`, `manipulator`, `iksolver`, `effect` and `pfoperator` among the 18), which is the
transition this page describes actually happening: a kind proven to register becomes a kind you can
occupy once its Slot is built and released. The [coverage map](COVERAGE_MAP.md) records how each is
verified — several of them report alive on load and fire their `Hello World` under a host action a
headless probe cannot synthesise, which is a property of the plugin kind and not a defect.

## What this page is not

It is not an install target, and nothing here changes what `install`/`bootstrap` produce. If one of
the roadmap types above is what you are waiting for, say so in an issue — [ROADMAP.md](../ROADMAP.md)
is explicit that what people ask for is what moves next.
