# Barebones: Bitmap Storage

A bitmap storage type — how pixels are held in memory for the bitmap manager.

> **Not a third-party slot — and never will be.** This super-class is **not open to third-party
> registration**, so no slot ships for it and none is on the roadmap. It is internal to the bitmap
> manager: the storage object is `class BitmapStorage` (`bitmap.h:2399`), which has no
> `SuperClassID()`/`ClassDesc` and is created only by the bitmap manager. (The loader/saver super-class
> `BMM_IO_CLASS_ID` is a different type that **is** registerable — it is on the roadmap.) This example
> documents the *shape* only; it cannot run in the host. This is a fact of the 2026 SDK, not a missing
> slot, so it is not a feature request. The
> [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under *not registerable*, with this
> reason.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_STORAGE_CLASS_ID` | 0x000B10 | a bitmap storage type |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmstorage.py`](python/slot_bmmstorage.py) | `slot_bmmstorage` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmstorage_native.dll` |

## Using this example

There is no slot to occupy, so nothing here runs — it is documentation of the *shape* only. If a
future SDK ever opens this super-class to third-party registration, the census gate catches it and a
slot becomes possible; until then this directory is a reference, not a starting point for a working
plugin.
