# Barebones: Data Channel Engine

A Data Channel modifier engine (IDataChannelEngine) — one operator in the Data Channel modifier's stack.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** log/UI — and always a log line readable with
`cartridge_logs -module slot_dcengine`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `DATACHANNELENGINE_SUPER_CLASS_ID` | 0x11992AC | a Data Channel modifier engine (IDataChannelEngine) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_dcengine.py`](python/slot_dcengine.py) | `slot_dcengine` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_dcengine_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `datachannel-engine` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_dcengine`.
