# The super-class census — every plugin type 3ds Max defines

This is the complete map of the **super-class IDs** the 3ds Max SDK declares (in `plugapi.h`), each
assigned to exactly one state. It is generated from the header — 78 super-class IDs in the 2026 SDK —
not hand-curated, and a build gate fails if a new SDK super-class ever appears without a decision, so
"every plugin type" can never quietly drift from a stale list.

Read this to answer *"what are all the plugin types, which can I occupy today, and — if I cannot — is
that a roadmap item or a fact of the SDK?"* That last distinction is the one that matters most, and it
is spelled out below so a missing type is never mistaken for an oversight. For the per-type
verification detail behind the 22 that ship, see [COVERAGE_MAP.md](COVERAGE_MAP.md).

## `Class_ID` vs `SuperClassID` — the two numbers, and why people conflate them

Every 3ds Max plugin carries two identifiers, and they are not the same kind of thing:

- A **`SuperClassID`** names the *kind* of plugin — "a modifier", "an exporter", "a texture map". It
  is chosen from the fixed set 3ds Max defines; you do not invent one. It is the bucket 3ds Max sorts
  a plugin into so it knows where the plugin belongs — the Modifier List, the Export dialog, the
  material browser.
- A **`Class_ID`** names *one specific plugin* — your particular modifier, distinct from every other
  modifier ever written. You *do* invent this one (a pair of random 32-bit numbers), and a saved scene
  resolves a plugin by it.

So a `SuperClassID` is a property of the **one class a slot registers**, not a bucket that owns slots.
Two different plugin *kinds* can register under the **same** `SuperClassID` and still be different
plugins: the `manipulator` and the `pfoperator` slots both register under `HELPER_CLASS_ID` but are
told apart by an extra interface. Two slots sharing one super-class id is normal, not a clash.

## The three states a super-class can be in

Every `SuperClassID` below is in exactly one of three states. **Telling the second from the third is
the whole point of this page** — from the outside they look alike (no different, "no slot ships" for
either) but they are opposite in meaning.

- **Has a slot — ✅ / 🔵** — a slot ships, so its [`barebones/`](../barebones/) example loads into
  3ds Max and reports itself (read the greeting with `cartridge_logs`). **Twenty-two** types are here.
- **Registerable, slot on the roadmap — ◻** — a real super-class a third party *can* register a
  plugin under, whose slot is simply **not built yet**. A feature request for one of these is
  **legitimate** and belongs on the [roadmap](../ROADMAP.md); it is work not yet done, not a door that
  is closed.
- **Not registerable — ✕** — 3ds Max does **not** let a third party register a plugin under this
  super-class at all: it is internal, pseudo, or obsolete. No slot will ever ship for it, and each is
  listed *with the SDK-checked reason* so "why not this type?" is answered before it is asked.

**Conflating the middle state with the last is what generates "why isn't type X covered?" requests.**
A roadmap type is a promise the SDK can keep; a not-registerable type is one the SDK refuses. Wherever
this page could be ambiguous, it says which of the two a type is.

---

## Has a slot — the 22 that run today

Each row registers a real plugin under its super-class; the [`barebones/`](../barebones/) example is
the payload it loads. **Every one of the 22 reports itself on load:** the slot calls its cartridge's
`init(env)` the moment 3ds Max loads the slot — handing over the running Max release, the slot's own
version, the cartridge ABI, and whether the server is present — and calls `shutdown` on unload. So
`init` reports init and `shutdown` reports unload; the **`Hello World` greeting** is logged only by
the cartridge's own behaviour, so a load report is never mistaken for the plugin actually working.
(Because 3ds Max caches plugin classes and demand-loads slot DLLs, "on load" means "when 3ds Max loads
the slot": a freshly installed host loads every slot and shows all 22 reporting on load; on a later
restart a demand-loaded slot reports when the host next loads it.)

On top of that load-time proof the greeting is checked two ways, and **neither marker is a failure**:

- **✅ greeting driven** — the automated probe drives the plugin and sees its own `Hello World`.
- **🔵 alive on load** — the cartridge's init report was observed (so it is proven loaded and alive),
  but its `Hello World` fires only under a host/UI action a headless probe cannot synthesise (a render
  pass, an IK solve, an interactive snap, a live particle sim, a panel, a colour pick, a Video Post
  execute). The exact step to fire the greeting is recorded beside the row. This is a property of that
  plugin *kind*, not a defect.

| Type | `SuperClassID` | Barebones | Verification |
| --- | --- | --- | :-: |
| modifier | `OSM_CLASS_ID` | [modifier](../barebones/modifier/) | ✅ greeting driven |
| exporter | `SCENE_EXPORT_CLASS_ID` | [exporter](../barebones/exporter/) | ✅ greeting driven |
| renderer | `RENDERER_CLASS_ID` | [renderer](../barebones/renderer/) | ✅ greeting driven |
| manipulator *(helper variant)* | `HELPER_CLASS_ID` | [manipulator](../barebones/manipulator/) | ✅ greeting driven |
| controller | `CTRL_FLOAT_CLASS_ID` | [controller](../barebones/controller/) | ✅ greeting driven |
| uv-generator | `UVGEN_CLASS_ID` | [uv-generator](../barebones/uv-generator/) | ✅ greeting driven |
| xyz-generator | `XYZGEN_CLASS_ID` | [xyz-generator](../barebones/xyz-generator/) | ✅ greeting driven |
| texture-output | `TEXOUTPUT_CLASS_ID` | [texture-output](../barebones/texture-output/) | ✅ greeting driven |
| aa-filter-kernel | `FILTER_KERNEL_CLASS_ID` | [aa-filter-kernel](../barebones/aa-filter-kernel/) | ✅ greeting driven |
| radiosity | `RADIOSITY_CLASS_ID` | [radiosity](../barebones/radiosity/) | ✅ greeting driven |
| datachannel-engine | `DATACHANNELENGINE_SUPER_CLASS_ID` | [datachannel-engine](../barebones/datachannel-engine/) | ✅ greeting driven |
| texmap | `TEXMAP_CLASS_ID` | [texmap](../barebones/texmap/) | ✅ greeting driven |
| material | `MATERIAL_CLASS_ID` | [material](../barebones/material/) | ✅ greeting driven |
| shader | `SHADER_CLASS_ID` | [shader](../barebones/shader/) | ✅ greeting driven |
| sampler | `SAMPLER_CLASS_ID` | [sampler](../barebones/sampler/) | ✅ greeting driven |
| effect | `RENDER_EFFECT_CLASS_ID` | [effect](../barebones/effect/) | 🔵 alive on load · greeting: render with the effect (F9) |
| iksolver | `IK_SOLVER_CLASS_ID` | [iksolver](../barebones/iksolver/) | 🔵 alive on load · greeting: assign to a bone chain and solve |
| osnap | `OSNAP_CLASS_ID` | [osnap](../barebones/osnap/) | 🔵 alive on load · greeting: interactive snap while moving |
| pfoperator *(helper variant)* | `HELPER_CLASS_ID` | [pfoperator](../barebones/pfoperator/) | 🔵 alive on load · greeting: run a particle sim |
| utility | `UTILITY_CLASS_ID` | [utility](../barebones/utility/) | 🔵 alive on load · greeting: open in the Utilities panel |
| color-picker | `COLPICK_CLASS_ID` | [color-picker](../barebones/color-picker/) | 🔵 alive on load · greeting: pick a colour |
| videopost-filter | `FLT_CLASS_ID` | [videopost-filter](../barebones/videopost-filter/) | 🔵 alive on load · greeting: run it in Video Post |

**Fifteen greeting driven, seven alive on load.** The four material-family slots (`texmap`,
`material`, `shader`, `sampler`) run in a managed or an unmanaged mode — see
[SLOTS.md](SLOTS.md#managed-and-unmanaged-per-sample-slots). Note that `manipulator` and `pfoperator` register
under the **same** `HELPER_CLASS_ID` and are different plugin kinds (manipulator via the Manipulator
interface; pfoperator via `IPFAction` + the PFOperator sub-class) — the clearest proof that a
super-class is a property of the one class a slot registers, not a bucket that owns slots.

---

## Deferred — registers, but its greeting is not yet reachable (1)

| Type | `SuperClassID` | Barebones | State |
| --- | --- | --- | --- |
| fragment | `Fragment_CLASS_ID` | [fragment](../barebones/fragment/) | slot built, class registers, greeting unreachable |

A slot **is built** and the class **registers** — `Cartridge_Fragment` is enumerable in a live host,
proving the shell loads. But a `ViewFragment` is not a MAXScript value type (creating it returns
`undefined`), and its only callback, `DoEvaluate`, runs inside the viewport display fragment-graph,
which no scriptable path and no standalone manual action triggers for a bare fragment — so its greeting
cannot yet be observed. It is kept as **proof of registration** and a starting point, and graduates
into the table above the day the slot model can drive a display-pipeline fragment. It is neither a
shipping slot nor a failure: it is the one honest in-between, called out so it is not miscounted as
either.

---

## Registerable, slot on the roadmap — ◻

These are real super-class IDs a third party **can** register a plugin under; the SDK provides the base
class. Their slots are **simply not built yet**, so there is no `barebones/` example to occupy. This is
the **ongoing programme** — [ROADMAP.md](../ROADMAP.md) tracks it, and a request for any of these is a
legitimate roadmap item, not a type that was refused. What people ask for is what moves.

| Type | `SuperClassID` |
| --- | --- |
| Geometry object | `GEOMOBJECT_CLASS_ID` |
| Camera | `CAMERA_CLASS_ID` |
| Light | `LIGHT_CLASS_ID` |
| Shape | `SHAPE_CLASS_ID` |
| Helper *(plain — note `manipulator` & `pfoperator` already ship under this id)* | `HELPER_CLASS_ID` |
| System plugin | `SYSTEM_CLASS_ID` |
| World-space modifier | `WSM_CLASS_ID` |
| World-space modifier object | `WSM_OBJECT_CLASS_ID` |
| Scene importer | `SCENE_IMPORT_CLASS_ID` |
| Image loader/saver | `BMM_IO_CLASS_ID` |
| Atmospheric effect | `ATMOSPHERIC_CLASS_ID` |
| Shadow generator | `SHADOW_TYPE_CLASS_ID` |
| Tone operator | `TONE_OPERATOR_CLASS_ID` |
| Track View utility | `TRACKVIEW_UTILITY_CLASS_ID` |
| Sound object | `SOUNDOBJ_CLASS_ID` |
| Multi-pass camera effect | `MPASS_CAM_EFFECT_CLASS_ID` |
| Motion-capture device | `MOT_CAP_DEV_CLASS_ID` |
| Motion-capture device binding | `MOT_CAP_DEVBINDING_CLASS_ID` |
| Bezier font loader | `BEZFONT_LOADER_CLASS_ID` |
| Custom attributes | `CUST_ATTRIB_CLASS_ID` |
| Render element | `RENDER_ELEMENT_CLASS_ID` |
| Texture-bake output element | `BAKE_ELEMENT_CLASS_ID` |
| Texmap container | `TEXMAP_CONTAINER_CLASS_ID` |

### Controllers — the value-type matrix (roadmap)

One controller family (`Control` base) serves every animatable value type, and **each value type is
its own super-class ID**. `CTRL_FLOAT_CLASS_ID` is the one that ships as a slot today (in the 22
above). The other value-type super-classes are registerable and a controller slot could target them —
they are on the roadmap, not excluded:

`CTRL_POSITION_CLASS_ID`, `CTRL_ROTATION_CLASS_ID`, `CTRL_SCALE_CLASS_ID`, `CTRL_POINT3_CLASS_ID`,
`CTRL_POINT4_CLASS_ID`, `CTRL_MATRIX3_CLASS_ID`, `CTRL_FRGBA_CLASS_ID`, `CTRL_MORPH_CLASS_ID`.

See the [controller](../barebones/controller/) barebones for the full table. Six older value types are
marked obsolete by the SDK and are not open to new plugins (see *Not registerable*, below).

### Infrastructure / base super-classes

`REF_MAKER_CLASS_ID`, `REF_TARGET_CLASS_ID` and `GUP_CLASS_ID` are base/infrastructure super-classes
rather than author-facing plugin *templates*: most real plugins derive from a reference maker or
target as their foundation, and a GUP (global utility plugin) is a background service rather than a
plugin that appears in a type list. They are registerable in the SDK sense, but no `barebones/` shape
targets them directly, and none is planned as a first-class slot.

### Shared-superclass variants

Not new super-class IDs — distinct plugin *kinds* that register under one of the ids above with an
extra interface, so each needs **its own slot**. `plugin type ≠ SuperClassID`.

| Variant | Registers under | Distinguished by | State |
| --- | --- | --- | --- |
| Manipulator | `HELPER_CLASS_ID` | `IsManipulator()` | **has a slot** |
| ParticleFlow operator | `HELPER_CLASS_ID` | `SubClassID() == PFOperatorSubClassID` | **has a slot** |
| Painter | `REF_TARGET_CLASS_ID` | `IPainterInterface_V*` | roadmap |
| Behavior (character studio) | `REF_TARGET_CLASS_ID` | behavior interface | roadmap |

---

## Not registerable — excluded, with the reason (✕)

3ds Max does **not** let a third party register a plugin under these super-classes. They are internal,
pseudo, or obsolete, and each verdict is checked against the 2026 SDK headers rather than assumed.
Listing them *with the reason* is what makes "we cover everything registerable" checkable instead of
merely asserted — and it is what preempts "why not type Y?" for a type that can never be a slot.

| `SuperClassID` | Why it is not a third-party slot |
| --- | --- |
| `SCHEMATICVIEW_UTILITY_CLASS_ID` | Nominally a plugin super-class (a sibling of the registerable `TRACKVIEW_UTILITY`), but the 2026 SDK ships **no base class, no sample, no plugin-wizard entry and no subclassing doc** for it — the id appears only at its own `#define`. There is no discoverable registration path. |
| `COMMON_BAKE_MAP_CLASS_ID` | **Internal super-class of the Bake To Texture subsystem.** The id appears only at its `#define`; no author-facing base class returns it. Bake maps are created by the host's Bake To Texture machinery. |
| `COMMON_BAKE_MAP_OPERATOR_CLASS_ID` | The operator half of the same internal Bake To Texture subsystem — same evidence: id only at its `#define`, no author-facing base class. |
| `BMM_STORAGE_CLASS_ID` | **Internal to the bitmap manager.** The storage object is `class BitmapStorage` (`bitmap.h:2399`), which has no `SuperClassID()`/`ClassDesc` and is created only by the bitmap manager. (Contrast `BMM_IO_CLASS_ID`, the loader/saver super-class, which **is** registerable — it is on the roadmap above.) |
| `BMM_DITHER_CLASS_ID` | Internal bitmap-manager dithering construct; the id occurs only at its own `#define` in the whole SDK — no base class, sample or wizard entry. |
| `BMM_COLORCUT_CLASS_ID` | Internal bitmap-manager colour-quantization construct; same evidence as dither. |
| `BMM_FILTER_CLASS_ID` | **Not a `ClassDesc` super-class at all.** The image-viewer it names loads by **DLL replacement** — a module exporting `ViewFileCreate` / `ViewFileDestroy` C functions (`viewfile.h:29-56`) — not by registering a `SuperClassID`. The plugin wizard hardcodes the id, but the mechanism is DLL replacement, so a `ClassDesc` slot is the wrong tool. |
| `MAXFLUID_SOLVER_SUPERCLASS_ID` | The **internal Max fluids (Bifrost) solver** super-class. There is no fluids SDK header, base class, interface, sample or wizard entry — the strings occur in exactly one SDK header, `plugapi.h` itself. First-party only. |
| `ANY_OBJECT_CLASS_ID` / `DEFORM_OBJ_CLASS_ID` / `GENERIC_SHAPE_CLASS_ID` / `MAPPABLE_OBJ_CLASS_ID` | **Pseudo super-classes** used only for modifier `InputType` matching — never registered by a plugin. |
| `USERDATATYPE_CLASS_ID` | Marked **obsolete** by the SDK; not open to new author plugins. |
| `MR_SHADER_CLASS_ID_DEFUNCT` | **Defunct** — the mental ray shader super-class, kept only for file compatibility. |
| `TEMP_OBJECT_SUPERCLASSID` | **Internal** — the temporary merge-node object. |
| `DUMMYCHANNEL_CLASS_ID` | Internal — a parameter-block marker (its superclass is `CTRL_USERTYPE`). |
| `MULTI_CLASS_ID` | Not a super-class at all — the Multi/Sub-Object material's own `Class_ID` (the two-numbers distinction at the top of this page, in the wild). |

If a future SDK ever opens one of these to third-party registration, the census gate flags it, its
state moves to *registerable, slot on the roadmap*, and it graduates from this table — the transition
is impossible to miss, because the census is regenerated from `plugapi.h` and fails the build on any
undecided id.
