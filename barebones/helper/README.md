# Barebones: Helper

A plain helper: a non-rendering object that is there to be seen and picked in the viewport, like
Dummy or Point. **This example is Tetra Helper** - it draws a wireframe tetrahedron.

The cartridge answers one question, `HelperLines`, with data:

```json
{"lines": [[[x, y, z], [x, y, z]], {"points": [[x, y, z], ...], "closed": true}], "color": [r, g, b]}
```

The points are in the helper's own space. The **slot** draws them, selects the helper by them and
boxes them for zoom extents. The cartridge needs no facade and never touches the viewport. The slot
asks again only when a parameter changes, so a redraw costs no cartridge call. `color` is optional;
without it the helper uses its wire colour.

**Its one parameter, `size`,** is the edge length (default 30). It is declared by
`describe_params()`, kept by the slot (saved with the scene, animatable, `$.size`), and shown as a
Size spinner in the Create and Modify panels. **Click and drag** to create one: the click places it,
and the drag distance becomes `size`. The slot does this for any cartridge that declares a float
called `size`.

**Hello signal:** a log line on the first `HelperLines`, readable with
`cartridge_logs -module slot_helper`.

## Tetra Helper and Tetra Dummy

They draw the same shape and are different plugins:

| | Tetra Helper (this) | [Tetra Dummy](../manipulator/README.md) |
| --- | --- | --- |
| Kind | plain helper (`HelperObject`) | manipulator (`SimpleManipulator`) |
| Drawing | returns line data; the slot draws | builds the gizmo through the facade |
| Mouse | none | `ManipMouse`, in Select and Manipulate mode |
| Creation | click and drag sets `size` | a click places it |
| `size` | edge length, default 30 | half-edge, default 15 |
| Colour | wire colour | cyan |

Start from this one for a marker, a guide or a gizmo that only needs to be seen. Start from Tetra
Dummy when the user should drag handles.

## See it work

**The quickest way:** run [`../tetra_demo.py`](../tetra_demo.py) in 3ds Max. It places a Tetra
Dummy and a Tetra Helper side by side, labelled, under a camera, and saves a capture of the
viewport - the two tetras are easiest to tell apart next to each other.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `HELPER_CLASS_ID` *(the default kind)* | `HelperObject` | a helper object | viewport lines + log | **this example** (**Tetra Helper**, internal name `Cartridge_Helper`, `.dlo`) |

`HELPER_CLASS_ID` also hosts the [manipulator](../manipulator/README.md) and the
[ParticleFlow operator](../pfoperator/README.md); each is its own slot.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_helper.py`](python/slot_helper.py) | `slot_helper` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_helper_native.dll` |

Both answer `HelperLines`, `describe_params`, `describe_ui` and `on_ui_event`; the C++ lane stands
alone.
