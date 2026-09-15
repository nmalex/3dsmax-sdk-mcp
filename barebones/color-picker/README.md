# Barebones: Color Picker

A color picker — the modal color chooser the host opens when a swatch is clicked.

> **Ships today — runs in the host.** A slot ships for this type, so this example loads, registers,
> and runs — it is not a template. It reports its `init` the moment 3ds Max loads the slot, proving
> it is alive; its **`Hello World` greeting fires under a host action** — pick a colour — which a
> headless probe cannot synthesise, so that is the step to run by hand. That is a property of the
> plugin kind, not a failure. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) is the
> authoritative map of where this type sits among all plugin types.

**Hello surface:** UI/msgbox — read the log line with `cartridge_logs -module slot_colpick`.

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

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_colpick`.
