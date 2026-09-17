# Barebones: Sound

A **sound object** — the scene's soundtrack plugin, one per scene, driven by the transport (play,
scrub, stop) so a soundtrack can play in sync with the animation. **This example plays nothing** and
says hello the first time the host asks it for its class name.

**Hello signal:** a log line the first time the host asks the object for its class name
(`GetClassName`, on create), readable with `cartridge_logs -module slot_sound`. The slot's **init
report** fires on load and is verified live in 3ds Max 2026: registers as `Cartridge_Sound` under
`SOUNDOBJ_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SOUNDOBJ_CLASS_ID` | `SoundObj : ReferenceTarget` | the scene soundtrack | log on class-name query | **this example** (**Cartridge Sound**, internal name `Cartridge_Sound`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_sound.py`](python/slot_sound.py) | `slot_sound` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_sound_native.dll` |
