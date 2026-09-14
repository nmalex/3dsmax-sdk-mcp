# Barebones: Video Post Filter

A Video Post image-processing filter — runs in the Video Post queue over a rendered image.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** msgbox/log — and always a log line readable with
`cartridge_logs -module slot_flt`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `FLT_CLASS_ID` | 0x000E00 | a Video Post image-processing filter |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_flt.py`](python/slot_flt.py) | `slot_flt` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_flt_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `videopost-filter` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_flt`.
