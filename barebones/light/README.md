# Barebones: Light

A **light** — an object that illuminates the scene (Omni/Spot/Direct). **This example is a warm-white
omni light.** The slot (a `GenLight`) registers an omnidirectional light, draws its gizmo, and asks
the cartridge for the two numbers a hello-world light needs:

```json
{"color": [r, g, b], "intensity": f}
```

The cartridge returns numbers; the slot fills the SDK's light state. Nothing here touches the 3ds Max
SDK.

**Hello signal:** a log line on the first `LightState`, readable with `cartridge_logs -module
slot_light`. Verified live in 3ds Max 2026, both lanes: registers as `Cartridge_Light` under
`LIGHT_CLASS_ID`, greets, and saves/reloads.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `LIGHT_CLASS_ID` | `GenLight` | an omni light | gizmo + log on first state | **this example** (**Cartridge Light**, internal name `Cartridge_Light`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_light.py`](python/slot_light.py) | `slot_light` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_light_native.dll` |
