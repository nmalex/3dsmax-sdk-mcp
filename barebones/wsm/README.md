# Barebones: WSM

A **world-space modifier (WSM)** — the sibling of the object-space modifier, evaluated in **world
space** so its effect depends on where the object sits in the scene, not on the object's own frame
(the built-in ones live in the World-Space Modifiers section of the modifier list). **This example
deforms nothing** and says hello the first time the host asks it for its class name.

**Hello signal:** a log line the first time the host asks it for its class name (`GetClassName`),
readable with `cartridge_logs -module slot_wsm`. The slot's **init report** fires on load and is
verified live in 3ds Max 2026: registers as `Cartridge_WSM` under `WSM_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `WSM_CLASS_ID` | `SimpleWSMMod2` | a world-space modifier | log on class-name query | **this example** (**Cartridge WSM**, internal name `Cartridge_WSM`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_wsm.py`](python/slot_wsm.py) | `slot_wsm` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_wsm_native.dll` |
