# Barebones: XYZ Generator

An XYZ coordinate generator (3D map input) — supplies the object/world XYZ a 3D texmap samples in.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI (Material Editor) — and always a log line readable with
`cartridge_logs -module slot_xyzgen`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `XYZGEN_CLASS_ID` | 0x000C30 | an XYZ coordinate generator (3D map input) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_xyzgen.py`](python/slot_xyzgen.py) | `slot_xyzgen` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_xyzgen_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `xyz-generator` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_xyzgen`.
