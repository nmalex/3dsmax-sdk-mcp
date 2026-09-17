# Barebones: Bitmap IO

A **bitmap I/O plugin** — the loader/saver behind an image file format (the `.tga`, `.png`, `.exr`
handlers are all BitmapIO plugins). **This example claims a made-up `.cbmp` extension and reads
nothing** — and says hello the first time the host inspects an image of its type.

**Hello signal:** a log line the first time an image of its format is inspected or read
(`GetImageInfo` / `Load`), readable with `cartridge_logs -module slot_bmio`. That is a file action, so
the greeting is behind it; the slot's **init report** fires on load and is verified live in 3ds Max
2026: registers as `Cartridge_BitmapIO` under `BMM_IO_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `BMM_IO_CLASS_ID` | `BitmapIO` | an image-format loader/saver | log on inspect/read | **this example** (**Cartridge Bitmap IO**, internal name `Cartridge_BitmapIO`, `.bmi`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bmio.py`](python/slot_bmio.py) | `slot_bmio` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bmio_native.dll` |
