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

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_radiosity.py`](python/slot_radiosity.py) | `slot_radiosity` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_radiosity_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_radiosity`.
