# Barebones: Ref Target

A **reference target** — the root kind of scene-persistent, referenceable object (materials, modifiers and controllers all specialise it). **This example holds nothing** and says hello the first time the host asks it for its class name.

**Hello signal:** a log line the first time the host asks it for its class name (`GetClassName`, on create), readable with `cartridge_logs -module slot_reftarget`. Verified live in 3ds Max 2026 via createInstance: registers as `Cartridge_RefTarget` under `REF_TARGET_CLASS_ID`.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `REF_TARGET_CLASS_ID` | `ReferenceTarget` | the root kind of scene-persistent, referenceable object (materials, modifiers and controllers all specialise it). **This example holds nothing** | log on class-name query | **this example** (**Cartridge Ref Target**, internal name `Cartridge_RefTarget`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_reftarget.py`](python/slot_reftarget.py) | `slot_reftarget` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_reftarget_native.dll` |
