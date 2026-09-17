# Barebones: TrackView Utility

A **Track View utility** — a tool in **Track View > Utilities** that can read and edit the selected
tracks, the sibling of the command-panel Utility but hosted in Track View. **This example does nothing**
to any track and says hello the first time it is opened.

**Hello signal:** a log line the first time the utility is opened in Track View (`BeginEditParams`),
readable with `cartridge_logs -module slot_tvutil`. That is a host action, so the greeting is behind it;
the slot's **init report** fires on load and is verified live in 3ds Max 2026: registers as
`Cartridge_TVUtility` under `TRACKVIEW_UTILITY_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `TRACKVIEW_UTILITY_CLASS_ID` | `TrackViewUtility` | a Track View tool | log on open | **this example** (**Cartridge TrackView Utility**, internal name `Cartridge_TVUtility`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_tvutil.py`](python/slot_tvutil.py) | `slot_tvutil` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_tvutil_native.dll` |
