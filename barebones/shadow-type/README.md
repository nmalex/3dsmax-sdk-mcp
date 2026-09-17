# Barebones: Shadow

A **shadow type** — the plugin a light uses to cast shadows (shadow-map, ray-traced, area and
third-party generators all register here), picked in a light's **Shadow** dropdown. **This example
casts no shadow** — its generator returns fully lit everywhere — and says hello the first time the
renderer asks it for a generator.

**Hello signal:** a log line the first time the renderer asks this type for a shadow generator
(`CreateShadowGenerator`), readable with `cartridge_logs -module slot_shadow`. That is a render-time
action, so — like every render-path slot — the greeting is behind it; the slot's **init report**
fires on load and is verified live in 3ds Max 2026: registers as `Cartridge_Shadow` under
`SHADOW_TYPE_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SHADOW_TYPE_CLASS_ID` | `ShadowType` (+ `ShadowGenerator`) | a light's shadow generator | log on generator request | **this example** (**Cartridge Shadow**, internal name `Cartridge_Shadow`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_shadow.py`](python/slot_shadow.py) | `slot_shadow` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_shadow_native.dll` |
