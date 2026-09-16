# Barebones: Manipulator

A manipulator is a helper the user can manipulate directly in the viewport — a custom gizmo the host
asks to rebuild its shapes when displayed and to handle the mouse when dragged.

**This example draws a wireframe tetrahedron**, built edge by edge by the payload through the
facade — four polyline runs into the `GizmoShape` the slot lends it for the span of the callback.
Nothing in either lane touches the 3ds Max SDK. It is here because a barebones that drew nothing was
read, repeatedly, as proof that a cartridge *could not* draw: an inert example is an argument, and it
was making the wrong one.

It still edits nothing in `ManipMouse`, on purpose — that is where your behaviour goes. `ManipMouse` fires when the gizmo is dragged in **Select and Manipulate** mode, not on the creation click: the slot places a new Tetra Dummy where you click.

**Its one parameter, `size`,** is declared by `describe_params()`, kept by the slot (saved with the scene, animatable, `$.size`), shown as a Size spinner in the Create and Modify panels, and handed back as `params` on every call.

**Hello signal:** a log line on `ManipUpdateShapes` — fired when the gizmo is displayed, guarded to
announce once per load — readable with `cartridge_logs -module slot_manipulator`. A second line
reports the draw: *"drew a wireframe tetrahedron: 4 polyline run(s)…"*, so the geometry is verifiable
from the log and not only by looking.

## See it work

**The quickest way:** run [`../tetra_demo.py`](../tetra_demo.py) in 3ds Max. It places a Tetra
Dummy and a Tetra Helper side by side, labelled, under a camera, and saves a capture of the
viewport - the two tetras are easiest to tell apart next to each other.

## How each lane reaches the facade

This is the clearest example in the kit of the one real difference between the lanes:

| Lane | How it is given the facade |
| --- | --- |
| **C++** | the shell hands the table straight over, once, through `SetFacade`. There is no address to look up. |
| **Python** | every callback event carries **`slot`** — the table's address as a decimal string — and `mcp_facade.from_address(slot)` turns it back into the callable table. |

Same table, same entries, same tetrahedron. `slot` means the facade address in **every** payload
entry point; the load-time `init(**env)` calls the slot's name `slotName` for exactly that reason.

## The facade entries it uses

| Entry | What it does |
| --- | --- |
| `ManipCurrentGizmoBuild` | the empty `GizmoShape` the slot borrowed for this callback's span |
| `GizmoShapeAppendPolyline` | one open or closed run of points |
| `GizmoBuildSetAppearance` | the unselected colour and the gizmo flags |

There are more (`StartNewLine`, `AppendPoint`, `MakeCircle`, `MakeRect`). Ask the index rather than
guessing:

```bash
python surface/max_facade_surface.py Gizmo
python surface/max_facade_surface.py --missing manipulator
```

That last one is honest about the remainder: a gizmo cannot yet set its own **tooltip**, append a
**mesh**, or append a point **marker**. Those are `not-yet` records — which is to say, feature
requests worth making.

## What plugin type this is

A **custom viewport gizmo** (`SimpleManipulator`). It registers under `HELPER_CLASS_ID` but its
`ClassDesc` answers `IsManipulator() == TRUE`, which is what makes the host treat it as a
manipulator. When it is displayed or the mouse moves over it, the host asks it to rebuild its shapes
and to handle interaction; the slot forwards those as `ManipUpdateShapes` and `ManipMouse`.

## The SuperClassIDs a manipulator-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `HELPER_CLASS_ID` *(as a manipulator: `ClassDesc::IsManipulator() == TRUE`)* | `SimpleManipulator` | a custom viewport gizmo | viewport gizmo + log | **this example** (**Tetra Dummy**, internal name `Cartridge_Manipulator`, `.dlo`) |

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

Both lanes are behaviourally identical - both draw the same tetrahedron. Pick Python for fast
iteration and hot-swap, C++ when you need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `ManipUpdateShapes`: replace the tetrahedron with your handles, and edit
   the target in `ManipMouse`.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable, and hands
   it back as `params` to `ManipUpdateShapes`, `ManipMouse` and the panel. This example's
   `size` is exactly that: drag the Size spinner and the tetrahedron follows; `$.size = 30` works
   from MAXScript; the value survives a save.
4. Create and select the **Tetra Dummy** helper (Create > Helpers) in a viewport, then confirm your
   log line with
   `cartridge_logs -module slot_manipulator`.
