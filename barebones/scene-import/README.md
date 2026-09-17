# Barebones: Importer

A **scene importer** — the plugin behind **File > Import**, the sibling of the exporter: it claims a
file extension and turns a file of that type into scene content. **This example imports nothing** — it
claims a made-up `.cart` extension and touches no scene — and says hello the first time a file of its
type is imported.

**Hello signal:** a log line the first time a `.cart` file is imported (`DoImport`), readable with
`cartridge_logs -module slot_import`. That is a file action, so the greeting is behind it; the slot's
**init report** fires on load and is verified live in 3ds Max 2026: registers as `Cartridge_Importer`
under `SCENE_IMPORT_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SCENE_IMPORT_CLASS_ID` | `SceneImport` | a File > Import handler | log on import | **this example** (**Cartridge Importer**, internal name `Cartridge_Importer`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_import.py`](python/slot_import.py) | `slot_import` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_import_native.dll` |
