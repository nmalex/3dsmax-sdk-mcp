# Barebones: Video Post Filter

A Video Post image-processing filter — runs in the Video Post queue over a rendered image.

> **Ships today — runs in the host.** A slot ships for this type, so this example loads, registers,
> and runs — it is not a template. It reports its `init` the moment 3ds Max loads the slot, proving
> it is alive; its **`Hello World` greeting fires under a host action** — run it in Video Post —
> which a headless probe cannot synthesise, so that is the step to run by hand. That is a property of
> the plugin kind, not a failure. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) is the
> authoritative map of where this type sits among all plugin types.

**Hello surface:** msgbox/log — read the log line with `cartridge_logs -module slot_flt`.

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

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_flt`.
