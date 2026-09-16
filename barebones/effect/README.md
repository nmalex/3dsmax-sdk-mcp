# Barebones: Render Effect

A render effect post-processes a finished frame — the host renders the image, then hands it to the
effect to read and rewrite pixels before the frame is delivered. This example changes nothing on
purpose: it is the smallest cartridge that proves the whole crossing (slot → interpreter → render
event → log) before any behaviour is in the way of reading the result. Fork it and rewrite pixels in
`EffectApply`.

**Hello signal:** a log line on the first `EffectApply` of a render — the `Apply()` the host fires at
the end of a frame, guarded to announce once per load — readable with
`cartridge_logs -module slot_effect`.

## What plugin type this is

A **render post-effect** (`Effect`, on the `SpecialFX` base). The user adds it under **Rendering ▸
Effects**. After each frame is rendered the host calls `Apply()`, which the slot forwards here as
`EffectApply`, lending the render context and the abort callback for exactly that call. It changes
the finished frame, not the scene.

## The SuperClassIDs a render-effect-shaped cartridge can bear

The rows below all descend from `SpecialFX` and share a "called at a point in the render" shape.
Which one a cartridge actually is comes from the **slot** it is deployed into, not from this payload;
the payload is interchangeable across the slots that share this contract.

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `RENDER_EFFECT_CLASS_ID` | `Effect` | render post-effect (`Effect::Apply` per frame) | UI (Rendering ▸ Effects) + log on render | **this example** (`Cartridge Effect`, `.dlv`) |
| `ATMOSPHERIC_CLASS_ID` | `Atmospheric` | atmospheric effect | UI (Environment) + log | sibling; shares the `SpecialFX` base |
| `TONE_OPERATOR_CLASS_ID` | `ToneOperator` | tone operator | UI/log | sibling; `SpecialFX` |
| `SHADOW_TYPE_CLASS_ID` | `ShadowType` | shadow generator | UI/log | sibling; `SpecialFX` |

The siblings are picked in different host windows — the Environment dialog, the exposure control —
but they are the same "the host calls you at a point in the render" shape, so the same payload serves
them when deployed into their slot.

## Its panel

The slot builds this cartridge's `describe_ui()` panel in Rendering > Environment and Effects, when the effect is selected in the Effects list, with the slot's own About (version, build, Refresh) beside it. This example declares a line and a **Hello World** button, so one click proves the crossing: read the line back with `cartridge_logs`. Values bound with `param=` reach `on_ui_event` but are not saved by this slot - see [docs/SLOTS.md](../../docs/SLOTS.md).

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_effect.py`](python/slot_effect.py) | `slot_effect` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_effect_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `EffectApply`: read the render context and rewrite pixels for that frame.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable.
4. Render a frame, and confirm your own log line with `cartridge_logs -module slot_effect`.
