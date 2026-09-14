# Barebones: Modifier

A modifier reads an object as it flows down the stack and hands it back — usually changed. This
example changes nothing on purpose: it is the smallest cartridge that proves the whole crossing
(slot → interpreter → panel → event → log) before any behaviour is in the way. Fork it and put your
deformation in `deform`.

**Hello signal:** a log line on load and on the panel's *Hello World* button, readable with
`cartridge_logs -module slot_modifier`.

## What plugin type this is

An **object-space modifier** (`Modifier`). The host applies it in the object's own local space,
before the node's world transform. It appears in the **Modifier List** and stacks like any stock
modifier.

## The SuperClassIDs a modifier-shaped cartridge can bear

The *shape* below — a payload handed the mesh that hands it back — is the same for both rows. Which
one a cartridge actually is comes from the **slot** it is deployed into, not from this payload; the
payload is interchangeable across the slots that share this contract.

| SuperClassID | Base class | What it is | Space it runs in | Slot |
| --- | --- | --- | --- | --- |
| `OSM_CLASS_ID` | `Modifier` | object-space modifier | object-local, before the node transform | **this example** (`Cartridge Modifier`, `.dlm`) |
| `WSM_CLASS_ID` | `WSModifier` | world-space modifier | world space, after the node transform | sibling slot; same `deform` contract |

A world-space modifier is minted by a **WSM object** (`WSM_OBJECT_CLASS_ID`, a gizmo you create in
the viewport) — that gizmo is an *object*, not a modifier, so it is a different barebones
(`barebones/wsm-object`, when its slot ships), not a row here.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_modifier.py`](python/slot_modifier.py) | `slot_modifier` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_modifier_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `deform`: modify `points` in place and return `"changed": True`.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable.
4. Deploy, and confirm your own log line with `cartridge_logs -module slot_modifier`.
