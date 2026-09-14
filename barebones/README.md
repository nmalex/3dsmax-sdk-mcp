# Barebones — a hello-world cartridge for every plugin type

**This is the starting point.** Each folder here is the smallest working cartridge for one 3ds Max
plugin type: it registers, it appears where that type appears, and it says **hello** — a log line
(and, for single-shot types, a message box) you can read back with `cartridge_logs`. It does nothing
else, on purpose: an inert cartridge proves the whole crossing works *before* your behaviour is in
the way of reading the result.

Fork one and start writing. Every example is written to be copied.

## For an agent picking a starting point

Find the row whose **plugin type** matches what you were asked to build, open its **example**, and
fork the lane you want. Each example's own `README.md` carries the full table of **SuperClassIDs it
can bear** — a cartridge of one shape is often valid under several superclass ids, and the README
says which. The rule underneath every row: **a cartridge does not choose its SuperClassID — the Slot
it is deployed into does.** You pick the type by picking the slot; the payload shape is what these
examples give you.

The `Verified` column means the example's hello was observed in a live 3ds Max via
`cartridge_logs -module <deployedAs>`, not merely that it compiles.

## The gallery

| Plugin type | Base class | Hello surface | SuperClassIDs it bears | Python | C++ | Verified |
| --- | --- | --- | --- | --- | --- | :-: |
| Modifier | `Modifier` | UI panel + log | `OSM_CLASS_ID` (·`WSM_CLASS_ID`) | [modifier/python](modifier/python/slot_modifier.py) | [modifier/native](modifier/native/src/payload.cpp) | ✅ |
| Exporter | `SceneExport` | message box + log | `SCENE_EXPORT_CLASS_ID` (·`SCENE_IMPORT_CLASS_ID` ·`BMM_IO_CLASS_ID`) | [exporter/python](exporter/python/slot_exporter.py) | [exporter/native](exporter/native/src/payload.cpp) | ✅ |
| Utility | `UtilityObj` | UI panel + log | `UTILITY_CLASS_ID` (·`TRACKVIEW_UTILITY_CLASS_ID`) | [utility/python](utility/python/slot_utility.py) | [utility/native](utility/native/src/payload.cpp) | ◻ |
| Render effect | `Effect` | UI + log on render | `RENDER_EFFECT_CLASS_ID` (·`ATMOSPHERIC_CLASS_ID` ·`TONE_OPERATOR_CLASS_ID` ·`SHADOW_TYPE_CLASS_ID`) | [effect/python](effect/python/slot_effect.py) | [effect/native](effect/native/src/payload.cpp) | ◻ |
| Renderer | `Renderer` | UI + log on render | `RENDERER_CLASS_ID` | [renderer/python](renderer/python/slot_renderer.py) | [renderer/native](renderer/native/src/payload.cpp) | ✅ |
| IK solver | `IKSolver` | log on solve | `IK_SOLVER_CLASS_ID` | [iksolver/python](iksolver/python/slot_iksolver.py) | [iksolver/native](iksolver/native/src/payload.cpp) | ◻ |
| Object snap | `Osnap` | log on snap | `OSNAP_CLASS_ID` | [osnap/python](osnap/python/slot_osnap.py) | [osnap/native](osnap/native/src/payload.cpp) | ◻ |
| Manipulator | `SimpleManipulator` | viewport gizmo + log | `HELPER_CLASS_ID` *(as a manipulator)* | [manipulator/python](manipulator/python/slot_manipulator.py) | [manipulator/native](manipulator/native/src/payload.cpp) | ✅ |
| ParticleFlow operator | `PFSimpleOperator` | Particle View + log | `HELPER_CLASS_ID` *(as a PF operator)* | [pfoperator/python](pfoperator/python/slot_pfoperator.py) | [pfoperator/native](pfoperator/native/src/payload.cpp) | ◻ |

`·` marks a sibling SuperClassID the same payload shape can serve when deployed into that slot. A `◻`
in *Verified* means the example is authored against the slot's dispatch contract (the function the
slot forwards its work to) and compiles, but its hello has not yet been confirmed in the test host
because the plugin's work only happens under conditions a boot script cannot cheaply create:

- **effect** — `EffectApply` fires only in a full render-effects pass;
- **iksolver** — `IKSolve` fires only once a chain is bound to this solver and driven;
- **osnap** — `OsnapSnap` fires only during interactive snapping;
- **pfoperator** — `PFProceed` fires only inside an active Particle Flow with particles;
- **utility** — its slot (`UTILITY_CLASS_ID`) does not ship yet (see the roadmap / defect D1).

Each example's README says exactly how to make its hello fire by hand.

### One SuperClassID, several plugin kinds

`HELPER_CLASS_ID` is the clearest case that **plugin type ≠ SuperClassID**: a plain helper, a
**manipulator**, and a **ParticleFlow operator** are all `HELPER_CLASS_ID`, distinguished only by
extra interfaces and `ClassDesc` answers (`IsManipulator()`, `SubClassID() == PFOperatorSubClassID`).
They are three different slots — three different barebones — under one superclass. The `manipulator`
and `pfoperator` examples are that story.

## The rest of the census — templates, slot pending

The nine above **run** (a slot ships for each). The [super-class census](../docs/SUPERCLASS_CENSUS.md)
lists *every* plugin type the SDK declares, and the registerable ones it turned up that had no example
now have a **template** barebones — the author shape for when its slot is built. They are marked
`template: true` in their `cartridge.json` and cannot run in the host yet.

- **Bucket B (17)** — registerable types the original set missed: `videopost-filter`,
  `aa-filter-kernel`, `bitmap-storage`, `bitmap-filter`, `bitmap-dither`, `bitmap-colorcut`,
  `uv-generator`, `xyz-generator`, `texture-output`, `color-picker`, `schematicview-utility`,
  `bake-map`, `bake-map-operator`, `radiosity`, `fragment`, `datachannel-engine`, `fluid-solver`.
- **Bucket C** — [`controller`](controller/): one family for the whole `CTRL_*` value-type matrix.

See [`docs/SUPERCLASS_CENSUS.md`](../docs/SUPERCLASS_CENSUS.md) for the full bucketed list, including
the types deliberately excluded (with reasons).

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
