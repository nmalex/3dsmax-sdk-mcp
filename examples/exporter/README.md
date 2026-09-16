# @DISPLAY_NAME@

*(Scaffolded. Replace this file's contents before opening a pull request — see
[docs/CARTRIDGE_PR.md](../../docs/CARTRIDGE_PR.md).)*

**What it does:** writes one line per node — a readable listing, not a real format. It exists so
your first export produces a file you can open and check, before any format-specific code is in the
way of reading the result.

## What to write here

- **What format it writes**, and which parts of it. "OBJ, geometry and normals; no materials" tells
  a reader more than "an OBJ exporter".
- **What it does not export.** A stated limit saves a bug report.
- **How to check it** — what to export, and what the file should contain.

## Declaring your extension

`cartridge.json` carries `exporter.ext` and `exporter.shortDesc`. They are deployed as a sidecar the
slot reads when 3ds Max builds the **File ▸ Export** type list, because an extension cannot be
compiled into a slot — one that was would host this cartridge and write the wrong file type.

Change them **before** your first export, not after: the extension is what the host offers and what
the written file is called.

## Facts worth keeping current

| | |
| --- | --- |
| Slot | `@FLAVOUR@` |
| Lane | Python — `python/@MODULE@.py` |
| Extension | see `exporter.ext` in `cartridge.json` |
| Version | see `cartridge.json`, and the row in [`../README.md`](../README.md) |

The version and that row move together on every pull request. That is not optional.
