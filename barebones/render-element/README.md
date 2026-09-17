# Barebones: Render Element

A **render element** — one output pass of a render (diffuse, z-depth, an ambient-occlusion channel, a
matte), added in **Render Setup > Render Elements** and written as its own image. **This example
outputs nothing** — it just appears in the list — and says hello the first time the render manager
asks it for its name.

**Hello signal:** a log line the first time the render manager asks the element for its name
(`ElementName`, on add), readable with `cartridge_logs -module slot_renderelement`. That is a host
action, so the greeting is behind it; the slot's **init report** fires on load and is verified live in
3ds Max 2026: registers as `Cartridge_RenderElement` under `RENDER_ELEMENT_CLASS_ID`, loads, reports.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `RENDER_ELEMENT_CLASS_ID` | `IRenderElement : SpecialFX` | a render output pass | log on name query | **this example** (**Cartridge Render Element**, internal name `Cartridge_RenderElement`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_renderelement.py`](python/slot_renderelement.py) | `slot_renderelement` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_renderelement_native.dll` |
