# Barebones: MoCap Binding

A **motion-capture device binding** — the object that ties one channel of a mocap device to a
controller, so a live input drives an animated value (a device makes them). **This example is
standalone and binds nothing** and says hello the first time the host asks it for its class name.

**Hello signal:** a log line the first time the host asks the binding for its class name
(`GetClassName`, on create), readable with `cartridge_logs -module slot_mcbind`. Verified live in
3ds Max 2026 via createInstance: registers as `Cartridge_McBinding` under `MOT_CAP_DEVBINDING_CLASS_ID`.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `MOT_CAP_DEVBINDING_CLASS_ID` | `MCDeviceBinding : ReferenceTarget` | a mocap channel binding | log on class-name query | **this example** (**Cartridge MoCap Binding**, internal name `Cartridge_McBinding`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_mcbind.py`](python/slot_mcbind.py) | `slot_mcbind` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_mcbind_native.dll` |
