# Barebones: Bitmap Filter

An image (bitmap) filter — a filter the bitmap manager applies when sampling an image.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is not a `ClassDesc`
> super-class at all: the image-viewer it names loads by **DLL replacement** — a module exporting
> `ViewFileCreate` / `ViewFileDestroy` C functions (`viewfile.h:29-56`) — not by registering a
> `SuperClassID`. The plugin wizard hardcodes the id, but the mechanism is DLL replacement, so a
> `ClassDesc` slot is the wrong tool. This example documents the *shape* only; it cannot run in the
> host. This is a fact of the 2026 SDK, not a missing slot, so it is not a feature request. The
> [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*, with this
> reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_FILTER_CLASS_ID` | 0x000B20 | an image (bitmap) filter |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmfilter.py`](python/slot_bmmfilter.py) | `slot_bmmfilter` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmfilter_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
