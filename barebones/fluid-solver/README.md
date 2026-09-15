# Barebones: Fluid Solver

A fluid solver (liquid / smoke / fire) — the solver behind a fluid simulation.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is the internal Max fluids
> (Bifrost) solver super-class: there is no fluids SDK header, base class, interface, sample or wizard
> entry — the strings occur in exactly one SDK header, `plugapi.h` itself. It is first-party only. This
> example documents the *shape* only; it cannot run in the host. This is a fact of the 2026 SDK, not a
> missing slot, so it is not a feature request. The
> [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*, with this
> reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `MAXFLUID_SOLVER_SUPERCLASS_ID` | 0x0011C0 | a fluid solver (liquid / smoke / fire) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_fluidsolver.py`](python/slot_fluidsolver.py) | `slot_fluidsolver` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_fluidsolver_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
