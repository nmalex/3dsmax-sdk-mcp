# Barebones: Manipulator

A manipulator is a helper the user can manipulate directly in the viewport — a custom gizmo the host
asks to rebuild its shapes when displayed and to handle the mouse when dragged. This example draws
the slot's default and edits nothing on purpose: it is the smallest cartridge that proves the whole
crossing (slot → interpreter → viewport event → log) before any behaviour is in the way of reading
the result. Fork it and draw handles in `ManipUpdateShapes`.

**Hello signal:** a log line on `ManipUpdateShapes` — fired when the gizmo is displayed, guarded to
announce once per load — readable with `cartridge_logs -module slot_manipulator`.

## What plugin type this is

A **custom viewport gizmo** (`SimpleManipulator`). It registers under `HELPER_CLASS_ID` but its
`ClassDesc` answers `IsManipulator() == TRUE`, which is what makes the host treat it as a
manipulator. When it is displayed or the mouse moves over it, the host asks it to rebuild its shapes
and to handle interaction; the slot forwards those as `ManipUpdateShapes` and `ManipMouse`.

## The SuperClassIDs a manipulator-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `HELPER_CLASS_ID` *(as a manipulator: `ClassDesc::IsManipulator() == TRUE`)* | `SimpleManipulator` | a custom viewport gizmo | viewport gizmo + log | **this example** (`Cartridge Manipulator`, `.dlo`) |

### One SuperClassID, several plugin kinds

`HELPER_CLASS_ID` is the clearest case that **plugin type ≠ SuperClassID**. The same superclass hosts
a plain helper, this **manipulator**, and a **ParticleFlow operator** (see
[`barebones/pfoperator`](../pfoperator/README.md)). They are told apart only by their `ClassDesc`
answers — a manipulator answers `IsManipulator() == TRUE`, a PF operator answers
`SubClassID() == PFOperatorSubClassID` — so they are three different slots, and three different
barebones, under one superclass.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_manipulator.py`](python/slot_manipulator.py) | `slot_manipulator` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_manipulator_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `ManipUpdateShapes`: build the handles, and edit the target in `ManipMouse`.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable.
4. Create and select the manipulator helper in a viewport, then confirm your log line with
   `cartridge_logs -module slot_manipulator`.
