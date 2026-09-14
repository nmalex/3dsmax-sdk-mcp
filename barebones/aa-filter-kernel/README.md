# Barebones: AA Filter Kernel

An anti-aliasing filter kernel — the reconstruction kernel a renderer samples with.

> **Template — slot pending.** This plugin type is in the [super-class census](../../docs/SUPERCLASS_CENSUS.md)
> (Bucket B/C) but **no slot ships for it yet**, so this example cannot run in the host today. It is
> the shape an author starts from, and what its slot will host once built. The runnable, live-verified
> examples are the ones marked ✅ in [`../README.md`](../README.md).

**Hello surface (when the slot ships):** log — and always a log line readable with
`cartridge_logs -module slot_filterkernel`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `FILTER_KERNEL_CLASS_ID` | 0x0010A0 | an anti-aliasing filter kernel |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_filterkernel.py`](python/slot_filterkernel.py) | `slot_filterkernel` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_filterkernel_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` once a `aa-filter-kernel` slot ships (track it in the
   census / ROADMAP).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_filterkernel`.
