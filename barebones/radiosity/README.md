# Barebones: Radiosity

An advanced-lighting / global-illumination plugin — the advanced-lighting engine in Render Setup.

> **Ships today — runs in the host.** A slot ships for this type, so this example loads, registers,
> and runs — it is not a template. It reports its `init` the moment 3ds Max loads the slot, and its
> **`Hello World` greeting is driven automatically**: the probe exercises the plugin and sees it.
> The [super-class census](../../docs/SUPERCLASS_CENSUS.md) is the authoritative map of where this
> type sits among all plugin types.

**Hello surface:** UI (Render Setup) — read the log line with `cartridge_logs -module slot_radiosity`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `RADIOSITY_CLASS_ID` | 0x001170 | an advanced-lighting / global-illumination plugin |

## Its panel

The slot builds this cartridge's `describe_ui()` panel in Rendering > Advanced Lighting, when this solution is chosen, with the slot's own About (version, build, Refresh) beside it. This example declares a line and a **Hello World** button, so one click proves the crossing: read the line back with `cartridge_logs`. Values bound with `param=` reach `on_ui_event` but are not saved by this slot - see [docs/SLOTS.md](../../docs/SLOTS.md).

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_radiosity.py`](python/slot_radiosity.py) | `slot_radiosity` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_radiosity_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_radiosity`.
