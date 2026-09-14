# Barebones: Utility

A utility is a tool the user runs from the **Utilities** panel (the hammer icon) — it belongs to no
object, saves nothing in the scene, and does its work through a rollout and its button handlers. This
example does nothing on purpose: it shows one labelled line and a *Hello World* button, the smallest
cartridge that proves the whole crossing (slot → interpreter → panel → event → log) before any
behaviour is in the way of reading the result. Fork it and put your tool behind the button.

**Hello signal:** a log line on the first `describe_ui` (built when the panel opens) and on the
panel's *Hello World* button, readable with `cartridge_logs -module slot_utility`.

## What plugin type this is

A **Utilities-panel tool** (`UtilityObj`). It appears under the Utilities panel (the hammer icon);
when the user opens it, the slot builds its rollout from `describe_ui` and runs its button handlers.
A utility does not belong to any object and saves nothing in the scene — it is a tool you run, not a
thing you place.

## The SuperClassIDs a utility-shaped cartridge can bear

The *shape* below — a panel and some actions, holding nothing in the scene — is the same for both
rows. Which one a cartridge actually is comes from the **slot** it is deployed into, not from this
payload; only the host window it opens in differs.

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `UTILITY_CLASS_ID` | `UtilityObj` | a Utilities-panel tool (the hammer icon) | UI panel + log | **this example** (`Cartridge Utility`, `.dlu`) |
| `TRACKVIEW_UTILITY_CLASS_ID` | `TrackViewUtility` | a Track View tool | UI/log | sibling slot; same "a panel and some actions" shape |

A Track View utility is the same shape in a different host window — it opens from Track View rather
than the command panel — so the same payload serves it when deployed into that slot.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_utility.py`](python/slot_utility.py) | `slot_utility` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_utility_native.dll` |

The Python lane owns composition (the rollout, and the button handlers); the native lane serves the
same calls and can leave `describe_ui` to Python. See the repository root
[`README.md`](../../README.md) for the full barebones index and [`docs/SLOTS.md`](../../docs/SLOTS.md)
for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Build your panel in `describe_ui`, and put your tool's work in the button handlers.
3. Declare any parameter in `describe_params` — the slot keeps it across opens of the panel.
4. Open the utility in the Utilities panel, then confirm your log line with
   `cartridge_logs -module slot_utility`.
