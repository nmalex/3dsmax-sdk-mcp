# Barebones: UV Generator

A UV coordinate generator (2D map input) — supplies the UV coordinates a 2D texmap samples in.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI (Material Editor) — and always a log line readable with
`cartridge_logs -module slot_uvgen`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `UVGEN_CLASS_ID` | 0x000C20 | a UV coordinate generator (2D map input) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_uvgen.py`](python/slot_uvgen.py) | `slot_uvgen` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_uvgen_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `uv-generator` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_uvgen`.
