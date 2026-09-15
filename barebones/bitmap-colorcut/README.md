# Barebones: Bitmap Color Cut

A bitmap color-cut method — the color-cut method used when quantizing an image.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is an internal
> bitmap-manager colour-quantization construct: same evidence as dither — the id occurs only at its
> own `#define` in the whole SDK, with no base class, sample or wizard entry. This example documents
> the *shape* only; it cannot run in the host. This is a fact of the 2026 SDK, not a missing slot, so
> it is not a feature request. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under
> *not registerable*, with this reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_COLORCUT_CLASS_ID` | 0x000B50 | a bitmap color-cut method |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmcolorcut.py`](python/slot_bmmcolorcut.py) | `slot_bmmcolorcut` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmcolorcut_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
