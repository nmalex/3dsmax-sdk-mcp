# Barebones: MoCap Device

A **motion-capture input device** — a live input source (a joystick, a MIDI device) the Motion Capture
utility drives an animation from. **This example reads nothing and makes no bindings** and says hello
when the host asks it for its name.

**Hello signal:** a log line the first time the host asks the device for its name (`DeviceName`, when
it is listed in the Motion Capture utility), readable with `cartridge_logs -module slot_mcdev`. The
slot's **init report** fires on load and is verified live in 3ds Max 2026: registers as
`Cartridge_McDevice` under `MOT_CAP_DEV_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `MOT_CAP_DEV_CLASS_ID` | `MCInputDevice` | a mocap input device | log on device-name query | **this example** (**Cartridge MoCap Device**, internal name `Cartridge_McDevice`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_mcdev.py`](python/slot_mcdev.py) | `slot_mcdev` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_mcdev_native.dll` |
