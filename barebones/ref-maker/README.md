# Barebones: Ref Maker

A **reference maker** — the raw base of the reference system: something that holds references to other objects but is not itself referenceable. **This example makes no references.**

**A deferred type.** `REF_MAKER_CLASS_ID` is the raw base of the reference system; a bare reference maker has no scriptable constructor and no standalone UI action, so its `GetClassName` greeting cannot be reached on its own. The slot is built and **registers** (its `.dlo` is in a live host's loaded-plugin list); kept as proof-of-registration.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `REF_MAKER_CLASS_ID` | `ReferenceMaker` | the raw base of the reference system: something that holds references to other objects but is not itself referenceable. **This example makes no references.** | log on class-name query (unreachable alone) | **this example** (**Cartridge Ref Maker**, internal name `Cartridge_RefMaker`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_refmaker.py`](python/slot_refmaker.py) | `slot_refmaker` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_refmaker_native.dll` |
