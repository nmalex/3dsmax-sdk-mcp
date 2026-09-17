# Barebones: Global Utility

A **Global Utility Plugin (GUP)** — an always-loaded service 3ds Max starts at boot and stops at exit.
This MCP server is itself a GUP. **This example runs nothing** and says hello once the system has
finished starting.

**Hello signal:** a log line at startup, once the system is up (`NOTIFY_SYSTEM_STARTUP`), readable with
`cartridge_logs -module slot_gup`. The greeting is deferred there because at `Start()` time — during
boot — the payload's Python runtime is not up yet. Verified live in 3ds Max 2026: registers as a GUP
under `GUP_CLASS_ID`, starts, and greets on its own after boot (no user action).

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `GUP_CLASS_ID` | `GUP` | an always-loaded service | log at startup (auto) | **this example** (**Cartridge Global Utility**, internal name `Cartridge_GlobalUtility`, `.gup`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_gup.py`](python/slot_gup.py) | `slot_gup` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_gup_native.dll` |
