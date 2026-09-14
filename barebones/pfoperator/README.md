# Barebones: ParticleFlow Operator

A ParticleFlow operator acts on the particles in its event — dropped into a Particle View event, it
is called each integration step to move, colour, spawn or kill particles. This example touches none
of them on purpose: it is the smallest cartridge that proves the whole crossing (slot → interpreter →
particle event → log) before any behaviour is in the way of reading the result. Fork it and act on
the particles in `PFProceed`.

**Hello signal:** a log line on `PFProceed` — fired each integration step while the timeline plays,
guarded to announce once per load — readable with `cartridge_logs -module slot_pfoperator`.

## What plugin type this is

A **Particle View operator** (`PFSimpleOperator`). It registers under `HELPER_CLASS_ID` but its
`ClassDesc` answers `SubClassID() == PFOperatorSubClassID` and it implements `IPFAction`, which is
what makes ParticleFlow list it in the depot. Dropped into an event, it is called each integration
step to act on that event's particles; the slot forwards that as `PFProceed`.

## The SuperClassIDs a PF-operator-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `HELPER_CLASS_ID` *(as a PF operator: `SubClassID() == PFOperatorSubClassID`, implements `IPFAction`)* | `PFSimpleOperator` | a Particle View operator | Particle View + log | **this example** (`Cartridge PF Operator`, `.dlo`) |

### One SuperClassID, several plugin kinds

`HELPER_CLASS_ID` is the clearest case that **plugin type ≠ SuperClassID**. The same superclass hosts
a plain helper, a **manipulator** (see [`barebones/manipulator`](../manipulator/README.md)), and this
**ParticleFlow operator**. They are told apart only by their `ClassDesc` answers — a manipulator
answers `IsManipulator() == TRUE`, a PF operator answers `SubClassID() == PFOperatorSubClassID` — so
they are three different slots, and three different barebones, under one superclass.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_pfoperator.py`](python/slot_pfoperator.py) | `slot_pfoperator` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_pfoperator_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `PFProceed`: move, colour, spawn or kill the particles in the event.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable.
4. Add the operator to a Particle Flow event with a source emitting particles and play the timeline,
   then confirm your log line with `cartridge_logs -module slot_pfoperator`.
