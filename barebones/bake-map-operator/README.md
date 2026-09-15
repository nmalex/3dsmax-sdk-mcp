# Barebones: Bake Map Operator

A Bake To Texture bake-map operator — an operator over a common bake map.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is the operator half of the
> same internal Bake To Texture subsystem as `bake-map`: same evidence — the id appears only at its own
> `#define`, and no author-facing base class returns it. This example documents the *shape* only; it
> cannot run in the host. This is a fact of the 2026 SDK, not a missing slot, so it is not a feature
> request. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*,
> with this reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `COMMON_BAKE_MAP_OPERATOR_CLASS_ID` | 0x001153 | a Bake To Texture bake-map operator |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bakemapop.py`](python/slot_bakemapop.py) | `slot_bakemapop` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bakemapop_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
