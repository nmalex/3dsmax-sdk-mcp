# Barebones: Object Snap

An object snap contributes candidate points the cursor can lock onto — the host asks each active snap
for points of interest near the cursor while the user drags with snapping on. This example
contributes none on purpose: it is the smallest cartridge that proves the whole crossing (slot →
interpreter → snap event → log) before any behaviour is in the way of reading the result. Fork it and
return points from `OsnapSnap`.

**Hello signal:** a log line on `OsnapSnap` — fired while the cursor moves over geometry with this
snap enabled, guarded to announce once per load — readable with `cartridge_logs -module slot_osnap`.

## What plugin type this is

An **object snap** (`Osnap`). It appears in **Grid and Snap Settings** as a snap the user can enable.
While the user drags with snapping on, the host asks each active snap for candidate points near the
cursor; the slot forwards that here as `OsnapSnap`. It offers points; it does not own the object it
reads them from.

## The SuperClassIDs a snap-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `OSNAP_CLASS_ID` | `Osnap` | a snap in Grid and Snap Settings | log on snap | **this example** (`Cartridge Snap`, `.dls`) |

A snap has no panel to say hello from — it is polled during a drag, not opened — so its only honest
hello is the log line on `OsnapSnap`. That is enough to prove the snap is registered and being asked
before any geometry is computed.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_osnap.py`](python/slot_osnap.py) | `slot_osnap` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_osnap_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `OsnapSnap`: return points of interest on the object near the cursor.
3. Declare any parameter in `describe_params` — the slot keeps it, saved with the snap settings.
4. Enable the snap in Grid and Snap Settings and drag over an object, then confirm your log line with
   `cartridge_logs -module slot_osnap`.
