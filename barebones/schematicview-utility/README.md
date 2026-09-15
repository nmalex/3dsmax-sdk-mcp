# Barebones: Schematic View Utility

A Schematic View utility — a tool that acts on the Schematic View graph.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is nominally a plugin
> super-class (a sibling of the registerable `TRACKVIEW_UTILITY`), but the 2026 SDK ships no base
> class, no sample, no plugin-wizard entry and no subclassing doc for it — the id appears only at its
> own `#define`. There is no discoverable registration path. This example documents the *shape* only;
> it cannot run in the host. This is a fact of the 2026 SDK, not a missing slot, so it is not a feature
> request. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*,
> with this reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `SCHEMATICVIEW_UTILITY_CLASS_ID` | 0x001100 | a Schematic View utility |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_svutil.py`](python/slot_svutil.py) | `slot_svutil` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_svutil_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
