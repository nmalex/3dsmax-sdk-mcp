# Barebones: Font

A **Bezier-font loader** — the plugin that turns a font into the bezier outlines the Text shape
extrudes (the built-in TrueType loader is one). **This example offers a single font, "Cartridge Font",
and builds no glyphs** — and says hello the first time a Text shape opens that font.

**Hello signal:** a log line the first time a Text shape opens the `Cartridge Font` font (`OpenFont`),
readable with `cartridge_logs -module slot_bezfont`. That is a host action, so the greeting is behind
it; the slot's **init report** fires on load and is verified live in 3ds Max 2026: registers as
`Cartridge_BezFont` under `BEZFONT_LOADER_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `BEZFONT_LOADER_CLASS_ID` | `BezFont` | a Text-shape font loader | log on font open | **this example** (**Cartridge Font**, internal name `Cartridge_BezFont`, `.dlf`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bezfont.py`](python/slot_bezfont.py) | `slot_bezfont` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bezfont_native.dll` |
