# Barebones: Bake Map Operator

A Bake To Texture bake-map operator — an operator over a common bake map.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** UI/log — and always a log line readable with
`cartridge_logs -module slot_bakemapop`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `COMMON_BAKE_MAP_OPERATOR_CLASS_ID` | 0x001153 | a Bake To Texture bake-map operator |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bakemapop.py`](python/slot_bakemapop.py) | `slot_bakemapop` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bakemapop_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `bake-map-operator` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_bakemapop`.
