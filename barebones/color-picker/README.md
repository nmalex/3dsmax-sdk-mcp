# Barebones: Color Picker

A color picker — the modal color chooser the host opens when a swatch is clicked.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI/msgbox — and always a log line readable with
`cartridge_logs -module slot_colpick`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `COLPICK_CLASS_ID` | 0x0010C0 | a color picker |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_colpick.py`](python/slot_colpick.py) | `slot_colpick` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_colpick_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `color-picker` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_colpick`.
