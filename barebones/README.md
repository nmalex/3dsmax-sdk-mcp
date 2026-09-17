# Barebones — a hello-world cartridge for every plugin type

**This is the starting point.** Each folder here is the smallest cartridge for one 3ds Max plugin
type. For the twenty-nine types with a shipping slot it **registers, appears where that type appears, and
says hello** — a log line (and, for single-shot types, a message box) you read back with
`cartridge_logs`; it does nothing else, on purpose, so an inert cartridge proves the whole crossing
works *before* your behaviour is in the way of reading the result. A handful of other folders document
the *shape* of a type that has no slot (and cannot get one) — the
[super-class census](../docs/SUPERCLASS_CENSUS.md) is the authoritative map of which is which.

Fork one and start writing. Every example is written to be copied.

## For an agent picking a starting point

Find the row whose **plugin type** matches what you were asked to build, open its **example**, and
fork the lane you want. Each example's own `README.md` carries the full table of **SuperClassIDs it
can bear** — a cartridge of one shape is often valid under several superclass ids, and the README
says which. The rule underneath every row: **a cartridge does not choose its SuperClassID — the Slot
it is deployed into does.** You pick the type by picking the slot; the payload shape is what these
examples give you.

The `Verified` column reports how each example's hello is confirmed. `✅` — the probe drove the
example and saw its hello. `🔵` — the example **reports alive on load** (its `init` is logged the
moment 3ds Max loads the slot) and its greeting fires under a named host action (listed below). Both
ship and run; read either with `cartridge_logs -module <deployedAs>`.

## The gallery

| Plugin type | Base class | Hello surface | SuperClassIDs it bears | Python | C++ | Verified |
| --- | --- | --- | --- | --- | --- | :-: |
| Geometry | `SimpleObject2` | mesh + log on evaluation | `GEOMOBJECT_CLASS_ID` | [geometry/python](geometry/python/slot_geometry.py) | [geometry/native](geometry/native/src/payload.cpp) | ✅ |
| Shape | `SimpleSpline` | spline + log on build | `SHAPE_CLASS_ID` | [shape/python](shape/python/slot_shape.py) | [shape/native](shape/native/src/payload.cpp) | ✅ |
| Light | `GenLight` | gizmo + log on state | `LIGHT_CLASS_ID` | [light/python](light/python/slot_light.py) | [light/native](light/native/src/payload.cpp) | ✅ |
| System | `HelperObject` | viewport + log on create | `SYSTEM_CLASS_ID` | [system/python](system/python/slot_system.py) | [system/native](system/native/src/payload.cpp) | 🔵 |
| Camera | `GenCamera` | gizmo + log on state | `CAMERA_CLASS_ID` | [camera/python](camera/python/slot_camera.py) | [camera/native](camera/native/src/payload.cpp) | ✅ |
| Modifier | `Modifier` | UI panel + log | `OSM_CLASS_ID` (·`WSM_CLASS_ID`) | [modifier/python](modifier/python/slot_modifier.py) | [modifier/native](modifier/native/src/payload.cpp) | ✅ |
| Exporter | `SceneExport` | message box + log | `SCENE_EXPORT_CLASS_ID` (·`SCENE_IMPORT_CLASS_ID` ·`BMM_IO_CLASS_ID`) | [exporter/python](exporter/python/slot_exporter.py) | [exporter/native](exporter/native/src/payload.cpp) | ✅ |
| Utility | `UtilityObj` | UI panel + log | `UTILITY_CLASS_ID` (·`TRACKVIEW_UTILITY_CLASS_ID`) | [utility/python](utility/python/slot_utility.py) | [utility/native](utility/native/src/payload.cpp) | 🔵 |
| Render effect | `Effect` | UI + log on render | `RENDER_EFFECT_CLASS_ID` (·`ATMOSPHERIC_CLASS_ID` ·`TONE_OPERATOR_CLASS_ID` ·`SHADOW_TYPE_CLASS_ID`) | [effect/python](effect/python/slot_effect.py) | [effect/native](effect/native/src/payload.cpp) | 🔵 |
| Renderer | `Renderer` | UI + log on render | `RENDERER_CLASS_ID` | [renderer/python](renderer/python/slot_renderer.py) | [renderer/native](renderer/native/src/payload.cpp) | ✅ |
| IK solver | `IKSolver` | log on solve | `IK_SOLVER_CLASS_ID` | [iksolver/python](iksolver/python/slot_iksolver.py) | [iksolver/native](iksolver/native/src/payload.cpp) | 🔵 |
| Object snap | `Osnap` | log on snap | `OSNAP_CLASS_ID` | [osnap/python](osnap/python/slot_osnap.py) | [osnap/native](osnap/native/src/payload.cpp) | 🔵 |
| Manipulator | `SimpleManipulator` | viewport gizmo + log | `HELPER_CLASS_ID` *(as a manipulator)* | [manipulator/python](manipulator/python/slot_manipulator.py) | [manipulator/native](manipulator/native/src/payload.cpp) | ✅ |
| Helper | `HelperObject` | viewport lines + log | `HELPER_CLASS_ID` | [helper/python](helper/python/slot_helper.py) | [helper/native](helper/native/src/payload.cpp) | ✅ |
| ParticleFlow operator | `PFSimpleOperator` | Particle View + log | `HELPER_CLASS_ID` *(as a PF operator)* | [pfoperator/python](pfoperator/python/slot_pfoperator.py) | [pfoperator/native](pfoperator/native/src/payload.cpp) | 🔵 |

`·` marks a sibling SuperClassID the same payload shape can serve when deployed into that slot. All
fifteen slots above **ship and run**. A `🔵` in *Verified* means the example reports its `init` on load —
proof it is alive — while its `Hello World` **greeting** fires only under a host action a headless
probe cannot synthesise, so that is the step to run by hand:

- **effect** — the greeting fires in a full render-effects pass (render with the effect, F9);
- **iksolver** — once a chain is bound to this solver and solved;
- **osnap** — during interactive snapping;
- **pfoperator** — inside an active Particle Flow with particles;
- **utility** — when it is opened in the Utilities panel.

A `🔵` is a property of the plugin kind, never a failure. Each example's README says exactly how to
make its greeting fire by hand.

### One SuperClassID, several plugin kinds

`HELPER_CLASS_ID` is the clearest case that **plugin type ≠ SuperClassID**: a plain helper, a
**manipulator**, and a **ParticleFlow operator** are all `HELPER_CLASS_ID`, distinguished only by
extra interfaces and `ClassDesc` answers (`IsManipulator()`, `SubClassID() == PFOperatorSubClassID`).
They are three different slots — three different barebones — under one superclass. [`tetra_demo.py`](tetra_demo.py) puts the helper and the manipulator side by side. The `manipulator`
and `pfoperator` examples are that story.

## The rest of the census — the other plugin types

The fifteen above are the core gallery, but **thirty slots ship and run** in all. The other
thirteen shipping types have a barebones here too — `controller`, `uv-generator`, `xyz-generator`,
`texture-output`, `aa-filter-kernel`, `radiosity`, `datachannel-engine`, `color-picker`,
`videopost-filter`, and the four per-sample kinds below — each with its own `README.md` and both
lanes.

### The per-sample kinds — they draw something real

A material, a texture map, a Standard-material shader and a sampler are called by the renderer at
every sample, so their barebones do not stop at hello: each renders something you can check. The
Python lane runs **managed** (it returns data at update time, the slot evaluates it per sample); the
C++ lane runs **unmanaged** (pinned, called per sample through an opaque handle and the
`ShadeSample*` facade entries — still no SDK). See [`docs/SLOTS.md`](../docs/SLOTS.md).

| Plugin type | SuperClassID | What it renders | Python | C++ |
| --- | --- | --- | --- | --- |
| Texture map | `TEXMAP_CLASS_ID` | a checker | [texmap/python](texmap/python/slot_texmap.py) | [texmap/native](texmap/native/src/payload.cpp) |
| Material | `MATERIAL_CLASS_ID` | a lit colour (+ rim, native) | [material/python](material/python/slot_material.py) | [material/native](material/native/src/payload.cpp) |
| Shader | `SHADER_CLASS_ID` | a tinted Lambert (wrap + rim, native) | [shader/python](shader/python/slot_shader.py) | [shader/native](shader/native/src/payload.cpp) |
| Sampler | `SAMPLER_CLASS_ID` | a stratified, jittered supersample | [sampler/python](sampler/python/slot_sampler.py) | [sampler/native](sampler/native/src/payload.cpp) |

**Test all four in one scene: [`material_family_demo.py`](material_family_demo.py).** Run it in 3ds Max
(*Scripting > Run Script…*) and it builds a new scene — offering to save yours first — with:

- a floor carrying the Texture Map;
- a teapot with the Material, and one with the Shader;
- two long checkered strips with a low camera looking down them, one plain and one using the Sampler;
- a three-frame animation (frames 0–2) keyed on each cartridge's own parameters.

It sets Scanline as the renderer, saves `cartridge_demo.max`, and renders the three frames plus the
sampler view into your render-output folder. What you should see:

- **Frame 0 → 1 → 2:** the material goes red → green → blue, the shader tint goes
  orange → cyan → magenta, and the floor checker goes from 4 to 8 to 12 tiles.
- **Sampler view:** the plain strip breaks into moiré toward the horizon, while the Cartridge
  Sampler strip settles to grey.

It uses only parameters both lanes declare, so the same scene tests the Python lane (managed) and,
with the native DLLs deployed, the C++ lane (unmanaged). Render it once each way and compare.

The barebones directory also carries an example for plugin types that do **not** ship a slot, so the
shape is documented whatever its state. The [super-class census](../docs/SUPERCLASS_CENSUS.md) is the
authoritative map and sorts every type into three states:

- **Has a slot — ships and runs.** The thirty above.
- **Registerable, slot on the roadmap.** Real types a third party can register a plugin under, whose
  slot is not built yet — a legitimate roadmap request. These have no directory here; the census
  lists them.
- **Not registerable.** `bake-map`, `bake-map-operator`, `bitmap-storage`, `bitmap-filter`,
  `bitmap-dither`, `bitmap-colorcut`, `schematicview-utility`, `fluid-solver` — the SDK does not let a
  third party register a plugin under these at all, so no slot will ever ship. Their directories
  document the *shape* only, stay marked `template: true`, and each README carries the exact
  SDK-checked reason. Plus **`fragment`**, *deferred*: its slot is built and the class registers, but
  its greeting is not yet reachable.

See [`docs/SUPERCLASS_CENSUS.md`](../docs/SUPERCLASS_CENSUS.md) for the full map, including every
not-registerable type with its reason.

## How to run one

1. **Deploy** the payload as its `deployedAs` module name (see the example's `cartridge.json`) into
   the plugin's `Bin/payload` directory — or scaffold a copy with `tools/new-cartridge.ps1`.
2. **Use** the plugin in 3ds Max the way its type is used (apply the modifier, run the export, …).
3. **Read the hello:** `cartridge_logs -module <deployedAs>` — the line the payload logged is proof
   the whole path works.

## The shape every example follows

- `README.md` — what the plugin type is, and the table of SuperClassIDs it can bear.
- `cartridge.json` — the author's record: name, slot, version, and the module the slot loads.
- `python/<module>.py` — the Python lane. The hello is logged from a **dispatched** function (never
  at import: only a call the slot dispatched has its output captured into `cartridge_logs`).
- `native/` — the C++ lane, where the type warrants one. No 3ds Max SDK; links `mcpjson.lib` only.
- `Version.props` — the version the native lane stamps into its binary.
