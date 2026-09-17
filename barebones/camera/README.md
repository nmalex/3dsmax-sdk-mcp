# Barebones: Camera

A **camera** — an object you render through. **This example is a 45-degree free camera.** The slot
(a `GenCamera`) registers a free camera, draws its gizmo, and asks the cartridge for its field of view:

```json
{"fov": degrees}
```

The cartridge returns a number; the slot fills the SDK's camera state. Nothing here touches the
3ds Max SDK.

**Hello signal:** a log line on the first `CameraState`, readable with `cartridge_logs -module
slot_camera`. Verified live in 3ds Max 2026, both lanes: registers as `Cartridge_Camera` under
`CAMERA_CLASS_ID`, greets, and saves/reloads.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `CAMERA_CLASS_ID` | `GenCamera` | a free camera | gizmo + log on first state | **this example** (**Cartridge Camera**, internal name `Cartridge_Camera`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_camera.py`](python/slot_camera.py) | `slot_camera` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_camera_native.dll` |
