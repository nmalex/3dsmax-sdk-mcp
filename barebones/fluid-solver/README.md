# Barebones: Fluid Solver

A fluid solver (liquid / smoke / fire) — the solver behind a fluid simulation.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI/log — and always a log line readable with
`cartridge_logs -module slot_fluidsolver`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `MAXFLUID_SOLVER_SUPERCLASS_ID` | 0x0011C0 | a fluid solver (liquid / smoke / fire) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_fluidsolver.py`](python/slot_fluidsolver.py) | `slot_fluidsolver` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_fluidsolver_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `fluid-solver` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_fluidsolver`.
