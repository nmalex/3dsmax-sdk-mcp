# Barebones: Multi-Pass Effect

A **multi-pass camera effect** — the plugin that renders a camera several times and blends the frames
(motion blur and depth-of-field are the two 3ds Max ships), picked in a camera's **Multi-Pass Effect**
dropdown. **This example blends nothing** — one pass, the frame as the camera saw it — and says hello
the first time the host checks it against a camera.

**Hello signal:** a log line the first time the host asks whether the effect is compatible with the
camera (`IsCompatible`, on selection), readable with `cartridge_logs -module slot_mpass`. That is a
host action, so — like every UI-driven slot — the greeting is behind it; the slot's **init report**
fires on load and is verified live in 3ds Max 2026: registers as `Cartridge_MpassEffect` under
`MPASS_CAM_EFFECT_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `MPASS_CAM_EFFECT_CLASS_ID` | `IMultiPassCameraEffect` | a multi-pass camera effect | log on compatibility check | **this example** (**Cartridge Multi-Pass Effect**, internal name `Cartridge_MpassEffect`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_mpass.py`](python/slot_mpass.py) | `slot_mpass` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_mpass_native.dll` |
