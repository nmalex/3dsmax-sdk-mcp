# Barebones: Custom Attributes

A **custom-attributes** plugin — a block of parameters you attach to any object, material or modifier,
showing up as an extra rollout with its own. **This example carries just a name** and says hello; a
fuller one would carry a parameter block the panel edits.

**Hello signal:** a log line the first time the attribute is asked to describe itself (as soon as it
is created or attached), readable with `cartridge_logs -module slot_custattrib`. Verified live in
3ds Max 2026, both lanes: registers as `Cartridge_CustAttrib` under `CUST_ATTRIB_CLASS_ID`, greets.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `CUST_ATTRIB_CLASS_ID` | `CustAttrib` | a custom-attributes block | log on describe | **this example** (**Cartridge Custom Attributes**, internal name `Cartridge_CustAttrib`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_custattrib.py`](python/slot_custattrib.py) | `slot_custattrib` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_custattrib_native.dll` |
