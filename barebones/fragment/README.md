# Barebones: Fragment

A Fragment super-class plugin — a render-pipeline fragment; works through ViewExp/GraphicsWindow.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** log — and always a log line readable with
`cartridge_logs -module slot_fragment`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `Fragment_CLASS_ID` | 0x0011B0 | a Fragment super-class plugin |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_fragment.py`](python/slot_fragment.py) | `slot_fragment` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_fragment_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `fragment` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_fragment`.
