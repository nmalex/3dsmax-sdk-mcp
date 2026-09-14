# Barebones: Exporter

An exporter is a single-shot plugin: the user picks it in **File ▸ Export**, the host walks the
scene and hands each node to the cartridge, and the cartridge returns text that the slot writes to a
file. This example writes a readable one-line-per-node listing — deliberately not a real format — so
your first export produces a file you can open and check. Fork it and format real output.

**Hello signal:** a log line on the first `format_header` of an export, readable with
`cartridge_logs -module slot_exporter`. A message box is *also* honest for a single-shot type when a
person drove it, but it must never be the only signal — an agent driving the host over JSON-RPC
cannot see a modal, so everything also logs.

## What plugin type this is

A **scene exporter** (`SceneExport`). Its file extension is **not** compiled into the slot — a slot
with one baked in would host your OBJ cartridge and write the wrong type — so you declare it in
`cartridge.json` (`exporter.ext` / `exporter.shortDesc`), deployed as a sidecar the slot reads when
the host builds the **Save as type** list.

## The SuperClassIDs a single-shot cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SCENE_EXPORT_CLASS_ID` | `SceneExport` | scene exporter (writes a file) | message box + log | **this example** (`Cartridge Exporter`, `.dle`) |
| `SCENE_IMPORT_CLASS_ID` | `SceneImport` | scene importer (reads a file) | message box + log | sibling slot; `Create()` returns `new` always, virtual destructor |
| `BMM_IO_CLASS_ID` | `BitmapIO` | image file loader/saver | message box / log | sibling slot; per-image, not per-scene |

An importer looks like an exporter mirrored, but differs in two ways the SDK enforces: its `Create()`
must always return `new` (it has a virtual destructor and the host deletes what `Create` returns),
and it reads rather than writes.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_exporter.py`](python/slot_exporter.py) | `slot_exporter` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_exporter_native.dll` |

The Python lane owns composition (the options panel, and closures over the format state); the native
lane serves the `format_*` calls and can leave `describe_ui` to Python. See the repository root
[`README.md`](../../README.md) for the barebones index.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Set `exporter.ext` and `exporter.shortDesc` in `cartridge.json` **before** your first export.
3. Replace the `format_*` bodies; keep the shape and the trailing newlines.
4. Export, and confirm your own log line with `cartridge_logs -module slot_exporter`.
