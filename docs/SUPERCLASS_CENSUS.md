# The super-class census — every plugin type 3ds Max defines

This is the complete list of **super-class IDs** the 3ds Max SDK declares (in `plugapi.h`), each
assigned to exactly one bucket. It is generated from the header, not hand-curated, and a build gate
fails if a new SDK super-class ever appears without a decision — so "every plugin type" can never
quietly drift from a stale list.

Read this to answer *"what are all the plugin types, and which can I write a cartridge for today?"*
Each type's [`barebones/`](../barebones/) example is the shape you start from.

- **Runnable ✅** — a slot ships, so the barebones loads and says hello (verify with
  `cartridge_logs`).
- **Template ◻** — a real registerable type with an example authored, but **no slot ships yet**;
  the example is the shape for when its slot is built.
- **Excluded** — not an author-facing plugin type; listed *with the reason* so completeness is
  checkable.

## Bucket A — registerable, the original set (37)

The types the kit was first built around. Eight have runnable slots today; the rest are real types
whose slots are the ongoing programme.

| Type | SuperClassID | Barebones | Status |
| --- | --- | --- | :-: |
| Object-space modifier | `OSM_CLASS_ID` | [modifier](../barebones/modifier/) | ✅ |
| Scene exporter | `SCENE_EXPORT_CLASS_ID` | [exporter](../barebones/exporter/) | ✅ |
| Renderer | `RENDERER_CLASS_ID` | [renderer](../barebones/renderer/) | ✅ |
| Render effect | `RENDER_EFFECT_CLASS_ID` | [effect](../barebones/effect/) | ✅ |
| IK solver | `IK_SOLVER_CLASS_ID` | [iksolver](../barebones/iksolver/) | ✅ |
| Object snap | `OSNAP_CLASS_ID` | [osnap](../barebones/osnap/) | ✅ |
| Manipulator *(helper variant)* | `HELPER_CLASS_ID` | [manipulator](../barebones/manipulator/) | ✅ |
| ParticleFlow operator *(helper variant)* | `HELPER_CLASS_ID` | [pfoperator](../barebones/pfoperator/) | ✅ |
| Utility | `UTILITY_CLASS_ID` | [utility](../barebones/utility/) | ◻ |
| Geometry object | `GEOMOBJECT_CLASS_ID` | — | ◻ |
| Camera / Light / Shape / Helper / System | `CAMERA/LIGHT/SHAPE/HELPER/SYSTEM_CLASS_ID` | — | ◻ |
| World-space modifier / WSM object | `WSM_CLASS_ID` / `WSM_OBJECT_CLASS_ID` | — | ◻ |
| Scene importer | `SCENE_IMPORT_CLASS_ID` | — | ◻ |
| Image loader/saver | `BMM_IO_CLASS_ID` | — | ◻ |
| Material / Texmap / Shader / Sampler | `MATERIAL/TEXMAP/SHADER/SAMPLER_CLASS_ID` | — | ◻ |
| Atmospheric / Shadow / Tone operator | `ATMOSPHERIC/SHADOW_TYPE/TONE_OPERATOR_CLASS_ID` | — | ◻ |
| Render element / Bake element / Multi-pass camera effect | `RENDER_ELEMENT/BAKE_ELEMENT/MPASS_CAM_EFFECT_CLASS_ID` | — | ◻ |
| Reference maker / target | `REF_MAKER_CLASS_ID` / `REF_TARGET_CLASS_ID` | — | ◻ |
| Custom attributes | `CUST_ATTRIB_CLASS_ID` | — | ◻ |
| Track View utility | `TRACKVIEW_UTILITY_CLASS_ID` | — | ◻ |
| GUP | `GUP_CLASS_ID` | — | ◻ |
| Sound object / Bezier font loader | `SOUNDOBJ_CLASS_ID` / `BEZFONT_LOADER_CLASS_ID` | — | ◻ |
| Motion-capture device / binding | `MOT_CAP_DEV_CLASS_ID` / `MOT_CAP_DEVBINDING_CLASS_ID` | — | ◻ |
| Texmap container *(from `imtl.h`)* | `TEXMAP_CONTAINER_CLASS_ID` | — | ◻ |

## Bucket B — registerable, and newly covered (17)

Real super-class IDs the SDK declares that the original set missed. Each now has a **template**
barebones (author shape; slot pending).

| Type | SuperClassID | Barebones |
| --- | --- | --- |
| Video Post image filter | `FLT_CLASS_ID` | [videopost-filter](../barebones/videopost-filter/) |
| Anti-aliasing filter kernel | `FILTER_KERNEL_CLASS_ID` | [aa-filter-kernel](../barebones/aa-filter-kernel/) |
| Bitmap storage | `BMM_STORAGE_CLASS_ID` | [bitmap-storage](../barebones/bitmap-storage/) |
| Bitmap filter | `BMM_FILTER_CLASS_ID` | [bitmap-filter](../barebones/bitmap-filter/) |
| Bitmap dither | `BMM_DITHER_CLASS_ID` | [bitmap-dither](../barebones/bitmap-dither/) |
| Bitmap color cut | `BMM_COLORCUT_CLASS_ID` | [bitmap-colorcut](../barebones/bitmap-colorcut/) |
| UV coordinate generator | `UVGEN_CLASS_ID` | [uv-generator](../barebones/uv-generator/) |
| XYZ coordinate generator | `XYZGEN_CLASS_ID` | [xyz-generator](../barebones/xyz-generator/) |
| Texture output filter | `TEXOUTPUT_CLASS_ID` | [texture-output](../barebones/texture-output/) |
| Color picker | `COLPICK_CLASS_ID` | [color-picker](../barebones/color-picker/) |
| Schematic View utility | `SCHEMATICVIEW_UTILITY_CLASS_ID` | [schematicview-utility](../barebones/schematicview-utility/) |
| Bake To Texture — bake map | `COMMON_BAKE_MAP_CLASS_ID` | [bake-map](../barebones/bake-map/) |
| Bake To Texture — bake-map operator | `COMMON_BAKE_MAP_OPERATOR_CLASS_ID` | [bake-map-operator](../barebones/bake-map-operator/) |
| Advanced lighting / radiosity | `RADIOSITY_CLASS_ID` | [radiosity](../barebones/radiosity/) |
| Fragment | `Fragment_CLASS_ID` | [fragment](../barebones/fragment/) |
| Data Channel engine | `DATACHANNELENGINE_SUPER_CLASS_ID` | [datachannel-engine](../barebones/datachannel-engine/) |
| Fluid solver | `MAXFLUID_SOLVER_SUPERCLASS_ID` | [fluid-solver](../barebones/fluid-solver/) |

## Bucket C — controllers (the value-type matrix)

One controller family (`Control` base) serves every animatable value type; each value type is its own
super-class ID. See the [controller](../barebones/controller/) barebones for the full table. Active:
`CTRL_FLOAT/POINT3/POINT4/MATRIX3/POSITION/ROTATION/SCALE/MORPH/FRGBA`. Specializations:
`DRIVERBLOCK`, `POINTCTRLCONTAINER`. Six older value types are marked obsolete by the SDK.

## Bucket D — shared-superclass variants

Not new super-class IDs — distinct plugin *kinds* that register under a Bucket-A/C id with an extra
interface, so each needs its own slot. `plugin type ≠ SuperClassID`.

| Variant | Registers under | Distinguished by |
| --- | --- | --- |
| Manipulator | `HELPER_CLASS_ID` | `IsManipulator()` |
| ParticleFlow operator | `HELPER_CLASS_ID` | `SubClassID() == PFOperatorSubClassID` |
| Painter | `REF_TARGET_CLASS_ID` | `IPainterInterface_V*` |
| Behavior (character studio) | `REF_TARGET_CLASS_ID` | behavior interface |
| DriverBlock controller | `CTRL_FLOAT_CLASS_ID` | derives `Control` |

## Bucket E — excluded, with the reason

Not author-facing plugin types. Listed so "we cover everything" is checkable rather than asserted.

| SuperClassID | Why it is excluded |
| --- | --- |
| `DEFORM_OBJ` / `MAPPABLE_OBJ` / `GENERIC_SHAPE` / `ANY_OBJECT` | pseudo super-classes — modifier `InputType` matching only, never registered |
| `MR_SHADER_CLASS_ID_DEFUNCT` | defunct — kept only for file compatibility |
| `TEMP_OBJECT_SUPERCLASSID` | internal — the temporary merge-node object |
| `DUMMYCHANNEL_CLASS_ID` | internal — a parameter-block marker (its superclass is `CTRL_USERTYPE`) |
| `MULTI_CLASS_ID` | not a super-class — the Multi/Sub-Object material's own Class_ID |
