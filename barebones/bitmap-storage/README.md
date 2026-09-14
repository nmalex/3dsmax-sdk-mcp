# Barebones: Bitmap Storage

A bitmap storage type — how pixels are held in memory for the bitmap manager.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** log — and always a log line readable with
`cartridge_logs -module slot_bmmstorage`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_STORAGE_CLASS_ID` | 0x000B10 | a bitmap storage type |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmstorage.py`](python/slot_bmmstorage.py) | `slot_bmmstorage` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmstorage_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `bitmap-storage` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_bmmstorage`.
