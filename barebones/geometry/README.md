# Barebones: Geometry

A **parametric geometry object** — the Box/Sphere/Teapot kind: an object built from parameters into
a mesh, shown shaded in the viewport, snapped, picked and rendered like any primitive. **This example
builds a cube** whose edge is the `size` parameter.

The cartridge answers one question, and the slot does the rest:

```json
{"verts": [[x, y, z], ...], "faces": [[a, b, c], ...]}
```

`faces` are triangles of 0-based vertex indices; the mesh is in the object's own space. The **slot**
(a `SimpleObject2`) fills its `Mesh` from that and provides display, hit-testing, bounding boxes, the
render mesh, ray intersection and conversion to an Editable Mesh — all for free. The cartridge returns
numbers and never touches the 3ds Max SDK. When no cartridge answers, the slot builds a small
placeholder cube, so an empty slot is still a visible, selectable object.

**Its one parameter, `size`,** is the cube's edge (default 30). It is declared by `describe_params()`,
kept by the slot (saved with the scene, animatable, `$.size`), and shown as a Size spinner. **Click
and drag** to create one: the click places it, the drag sets `size`.

**Hello signal:** a log line on the first `BuildMesh` (the first time the object is evaluated),
readable with `cartridge_logs -module slot_geometry`. Verified live in 3ds Max 2026, both lanes: the
object registers, converts to an Editable Mesh (8 verts, 12 faces), sizes and saves/reloads.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `GEOMOBJECT_CLASS_ID` | `SimpleObject2` | a parametric renderable object | mesh + log on first evaluation | **this example** (**Cartridge Geometry**, internal name `Cartridge_Geometry`, `.dlo`) |

`GEOMOBJECT_CLASS_ID` is the super-class of every 3ds Max primitive. Fork this to build a real
parametric object — a gear, a stair, a torus knot — by returning its vertices and faces.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_geometry.py`](python/slot_geometry.py) | `slot_geometry` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_geometry_native.dll` |

Both answer `BuildMesh`, `describe_params`, `describe_ui` and `on_ui_event`; the C++ lane stands alone.
