# Barebones: Schematic View Utility

A Schematic View utility — a tool that acts on the Schematic View graph.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI — and always a log line readable with
`cartridge_logs -module slot_svutil`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `SCHEMATICVIEW_UTILITY_CLASS_ID` | 0x001100 | a Schematic View utility |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_svutil.py`](python/slot_svutil.py) | `slot_svutil` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_svutil_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `schematicview-utility` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_svutil`.
