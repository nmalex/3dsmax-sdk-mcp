# Barebones: Bitmap Filter

An image (bitmap) filter — a filter the bitmap manager applies when sampling an image.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** log — and always a log line readable with
`cartridge_logs -module slot_bmmfilter`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `BMM_FILTER_CLASS_ID` | 0x000B20 | an image (bitmap) filter |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmmfilter.py`](python/slot_bmmfilter.py) | `slot_bmmfilter` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmmfilter_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `bitmap-filter` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_bmmfilter`.
