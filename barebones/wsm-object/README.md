# Barebones: Space Warp

A **space warp** — a field object you bind to scene objects to deform them (Bomb, Wind, Ripple). It
is a **pair**: the object you create in Create ▸ Space Warps, and the modifier it puts on each bound
object. **This example is a box gizmo with a no-op force** — a hello-world space warp is its gizmo.

The object's gizmo mesh comes from the cartridge, like the geometry slot:

```json
{"verts": [[x, y, z], ...], "faces": [[a, b, c], ...]}
```

The companion binding modifier deforms nothing. Nothing here touches the 3ds Max SDK.

**Hello signal:** a log line on the first `BuildMesh`, readable with `cartridge_logs -module
slot_wsmobject`. Verified live in 3ds Max 2026, both lanes: registers as `Cartridge_SpaceWarp` under
`WSM_OBJECT_CLASS_ID`, greets, and **binds** to an object (adding the `Cartridge_Space_Warp_Binding`
modifier).

## What plugin type this is

This is a **multi-class slot**: it registers two classes that belong together — the space-warp object
(`WSM_OBJECT_CLASS_ID`) and its binding modifier (`WSM_CLASS_ID`).

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `WSM_OBJECT_CLASS_ID` | `SimpleWSMObject2` | a space-warp object | gizmo + log on build | **this example** (**Cartridge Space Warp**, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_wsmobject.py`](python/slot_wsmobject.py) | `slot_wsmobject` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_wsmobject_native.dll` |
