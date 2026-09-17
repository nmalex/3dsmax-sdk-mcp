# Barebones: Bake Element

A **texture-bake element** — one output of **Render To Texture** (a baked diffuse map, a normal map, a
complete map, an ambient-occlusion map), chosen in the Render To Texture dialog and written to a file.
**This example bakes nothing** — it just appears in the output list — and says hello the first time the
host asks it for its name.

**Hello signal:** a log line the first time the host asks the element for its name (`ElementName`, on
add), readable with `cartridge_logs -module slot_bakeelement`. That is a host action, so the greeting
is behind it; the slot's **init report** fires on load and is verified live in 3ds Max 2026: registers
as `Cartridge_BakeElement` under `BAKE_ELEMENT_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `BAKE_ELEMENT_CLASS_ID` | `MaxBakeElement : MaxRenderElement` | a Render To Texture output | log on name query | **this example** (**Cartridge Bake Element**, internal name `Cartridge_BakeElement`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_bakeelement.py`](python/slot_bakeelement.py) | `slot_bakeelement` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_bakeelement_native.dll` |
