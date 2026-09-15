# Barebones: Texture Output

A texture output filter — the output curve/level filter on a texmap.

> **Ships today — runs in the host.** A slot ships for this type, so this example loads, registers,
> and runs — it is not a template. It reports its `init` the moment 3ds Max loads the slot, and its
> **`Hello World` greeting is driven automatically**: the probe exercises the plugin and sees it.
> The [super-class census](../../docs/SUPERCLASS_CENSUS.md) is the authoritative map of where this
> type sits among all plugin types.

**Hello surface:** UI (Material Editor) — read the log line with `cartridge_logs -module slot_texoutput`.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `TEXOUTPUT_CLASS_ID` | 0x000C40 | a texture output filter |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_texoutput.py`](python/slot_texoutput.py) | `slot_texoutput` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_texoutput_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_texoutput`.
