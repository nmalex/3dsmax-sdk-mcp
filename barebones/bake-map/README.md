# Barebones: Bake Map

A Bake To Texture common bake map — one bakeable channel in the Bake To Texture dialog.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is an internal super-class of
> the Bake To Texture subsystem: the id appears only at its own `#define`, and no author-facing base
> class returns it — bake maps are created by the host's Bake To Texture machinery. This example
> documents the *shape* only; it cannot run in the host. This is a fact of the 2026 SDK, not a missing
> slot, so it is not a feature request. The
> [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*, with this
> reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `COMMON_BAKE_MAP_CLASS_ID` | 0x001152 | a Bake To Texture common bake map |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bakemap.py`](python/slot_bakemap.py) | `slot_bakemap` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bakemap_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
