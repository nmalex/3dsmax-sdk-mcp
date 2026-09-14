# Barebones: Renderer

A renderer is the plugin that turns the scene into an image — the user picks it in Render Setup, and
the host opens it, asks it to render each frame, and closes it. This example renders nothing on
purpose: it is the smallest cartridge that proves the whole crossing (slot → interpreter → render
event → log) before any behaviour is in the way of reading the result. Fork it and produce an image
in `RenderRender`.

**Hello signal:** a log line on `RenderOpen` — fired when a render begins, guarded to announce once
per load — readable with `cartridge_logs -module slot_renderer`.

## What plugin type this is

A **Choose-Renderer plugin** (`Renderer`). The user picks it in **Render Setup ▸ Renderer** (Choose
Renderer). When a render runs the host opens the renderer, asks it to render each frame, and closes
it; the slot forwards those as `RenderOpen` and `RenderRender`. It owns the whole image, not a pass
over a finished one.

## The SuperClassIDs a renderer-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `RENDERER_CLASS_ID` | `Renderer` | a Choose-Renderer plugin (Render Setup) | UI + log on render | **this example** (`Cartridge Renderer`, `.dlr`) |

A renderer is its own slot, deliberately separate from the render **effect** (see
[`barebones/effect`](../effect/README.md)): a renderer *makes* the image, an effect *reworks* one the
renderer already made. They are different plugin kinds the user picks in different places — Render
Setup's Renderer rollout versus the Effects dialog — so they are different slots and different
barebones, not two rows here.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_renderer.py`](python/slot_renderer.py) | `slot_renderer` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_renderer_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `RenderRender`: produce pixels for each frame between `RenderOpen` and close.
3. Declare any parameter in `describe_params` — the slot keeps it, saved with the render settings.
4. Start a render with this renderer chosen, and confirm your log line with
   `cartridge_logs -module slot_renderer`.
