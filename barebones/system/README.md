# Barebones: System

A **system** — a plugin that builds a structure of nodes as one unit, created from Create ▸ Systems
(Bones, Ring Array, Daylight are systems). **This example draws a wireframe gizmo** and reports
itself; a fuller system would build a node rig.

The gizmo lines come from the cartridge, like the helper slot:

```json
{"lines": [[[x, y, z], ...], ...]}
```

Nothing here touches the 3ds Max SDK.

**Hello signal:** a log line on the first display, readable with `cartridge_logs -module slot_system`.
The slot **reports itself on load** (its `init` crossing), verified live in 3ds Max 2026, both lanes.
Its greeting fires when you **create** one — MAXScript cannot construct a system object, so create it
by hand: **Create ▸ Systems ▸ MCP Cartridges ▸ Cartridge System**, then read the log.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SYSTEM_CLASS_ID` | `HelperObject` | a node-system plugin | viewport + log on create | **this example** (**Cartridge System**, internal name `Cartridge_System`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_system.py`](python/slot_system.py) | `slot_system` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_system_native.dll` |
