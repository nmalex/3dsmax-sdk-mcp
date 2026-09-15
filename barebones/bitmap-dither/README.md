# Barebones: Bitmap Dither

A bitmap dithering method — the dither applied when reducing an image's bit depth.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is an internal
> bitmap-manager dithering construct: the id occurs only at its own `#define` in the whole SDK — no
> base class, sample or wizard entry. This example documents the *shape* only; it cannot run in the
> host. This is a fact of the 2026 SDK, not a missing slot, so it is not a feature request. The
> [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*, with this
> reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_DITHER_CLASS_ID` | 0x000B40 | a bitmap dithering method |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmdither.py`](python/slot_bmmdither.py) | `slot_bmmdither` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmdither_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
