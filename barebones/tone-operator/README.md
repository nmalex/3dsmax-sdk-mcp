# Barebones: Tone Operator

A **tone operator** (exposure control) — the plugin that maps a render's raw light energy to
displayable RGB, picked in **Rendering > Exposure Control**. **This example maps nothing** — it is
the identity operator — and says hello when you open its rollout.

**Hello signal:** a log line the first time its panel is opened (`describe_ui`), readable with
`cartridge_logs -module slot_toneop`. A tone operator has no headless render dispatch, so — like
every UI-only slot — the greeting is behind that panel action; the slot's **init report** fires on
load and is verified live in 3ds Max 2026: registers as `Cartridge_ToneOperator` under
`TONE_OPERATOR_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `TONE_OPERATOR_CLASS_ID` | `ToneOperator : SpecialFX` | an exposure control | log on panel open | **this example** (**Cartridge Tone Operator**, internal name `Cartridge_ToneOperator`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_toneop.py`](python/slot_toneop.py) | `slot_toneop` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_toneop_native.dll` |
