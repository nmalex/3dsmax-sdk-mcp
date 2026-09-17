# Barebones: Shape

A **spline shape** — the Line/Circle/Rectangle kind: polylines that draw in the viewport, render as a
thin tube when made renderable, and can be extruded or lofted. **This example builds a pentagon.**

The cartridge answers one question, and the slot (a `SimpleSpline`) builds a `BezierShape` from it:

```json
{"polylines": [{"points": [[x, y, z], ...], "closed": true}, ...]}
```

Each polyline is a run of straight (corner) segments. The cartridge returns numbers and never touches
the 3ds Max SDK; the slot gives display, hit-testing, rendering and conversion to an Editable Spline.
When no cartridge answers, the slot builds a placeholder square.

**Hello signal:** a log line on the first `BuildShape`, readable with `cartridge_logs -module
slot_shape`. Verified live in 3ds Max 2026, both lanes: registers as `Cartridge_Shape` under
`SHAPE_CLASS_ID`, greets, and converts to an Editable Spline (1 spline, 5 knots, closed).

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `SHAPE_CLASS_ID` | `SimpleSpline` | a spline shape | viewport + log on first build | **this example** (**Cartridge Shape**, internal name `Cartridge_Shape`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_shape.py`](python/slot_shape.py) | `slot_shape` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_shape_native.dll` |
