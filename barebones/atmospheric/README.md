# Barebones: Atmosphere

An **atmospheric** plugin — a whole-scene render effect (fog, volume light, a haze) added in
**Rendering > Environment and Effects**. **This example adds nothing** — its `Shade` is a no-op — and
says hello when you open its rollout.

**Hello signal:** a log line the first time its panel is opened (`describe_ui`), readable with
`cartridge_logs -module slot_atmospheric`. The atmosphere has no headless render dispatch, so — like
every UI-only slot — the greeting is behind that panel action; the slot's **init report** fires on
load and is verified live in 3ds Max 2026: registers as `Cartridge_Atmosphere` under
`ATMOSPHERIC_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `ATMOSPHERIC_CLASS_ID` | `Atmospheric : SpecialFX` | a whole-scene atmosphere | log on panel open | **this example** (**Cartridge Atmosphere**, internal name `Cartridge_Atmosphere`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_atmospheric.py`](python/slot_atmospheric.py) | `slot_atmospheric` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_atmospheric_native.dll` |
