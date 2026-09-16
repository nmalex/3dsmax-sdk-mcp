# Barebones: Controller

An animation controller (Control base) — assigned to a track; the same shape serves every CTRL_* value type.

> **Ships today — runs in the host.** A slot ships for this type, so this example loads, registers,
> and runs — it is not a template. It reports its `init` the moment 3ds Max loads the slot, and its
> **`Hello World` greeting is driven automatically**: the probe exercises the plugin and sees it.
> The [super-class census](../../docs/SUPERCLASS_CENSUS.md) is the authoritative map of where this
> type sits among all plugin types.

**Hello surface:** UI (Track View)/log — read the log line with `cartridge_logs -module slot_controller`.

## The SuperClassIDs a controller-shaped cartridge can bear

A controller derives from `Control`; the SDK enumerates each animatable **value type** as its own
super-class ID. One controller family serves each - the base is the same, the value it drives differs.

| SuperClassID | hex | Value it controls |
| --- | --- | --- |
| `CTRL_FLOAT_CLASS_ID` | 0x9003 | float (this example's slot) |
| `CTRL_POSITION_CLASS_ID` | 0x900B | position (Point3) |
| `CTRL_ROTATION_CLASS_ID` | 0x900C | rotation (Quat) |
| `CTRL_SCALE_CLASS_ID` | 0x900D | scale (Point3) |
| `CTRL_POINT3_CLASS_ID` | 0x9005 | Point3 |
| `CTRL_POINT4_CLASS_ID` | 0x9012 | Point4 |
| `CTRL_MATRIX3_CLASS_ID` | 0x9008 | Matrix3 (transform) |
| `CTRL_MORPH_CLASS_ID` | 0x900E | morph |
| `CTRL_FRGBA_CLASS_ID` | 0x9013 | floating-point RGBA |

Specializations under `Control`: `DRIVERBLOCK_SUPER_CLASS_ID` (0x9011),
`POINTCTRLCONTAINER_SUPERCLASS_ID` (0x9010). Six older value types (`CTRL_SHORT`, `CTRL_INTEGER`,
`CTRL_POINT2`, `CTRL_COLOR`, `CTRL_COLOR24`, `CTRL_USERTYPE`) the SDK marks obsolete.

## Its panel

The slot builds this cartridge's `describe_ui()` panel in Track View: right-click the track > **Properties** (a modal dialog); the Motion panel shows it for a transform controller, with the slot's own About (version, build, Refresh) beside it. This example declares a line and a **Hello World** button, so one click proves the crossing: read the line back with `cartridge_logs`. Values bound with `param=` reach `on_ui_event` but are not saved by this slot - see [docs/SLOTS.md](../../docs/SLOTS.md).

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_controller.py`](python/slot_controller.py) | `slot_controller` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_controller_native.dll` |

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in the payload; log your hello from a dispatched function so it lands in
   `cartridge_logs -module slot_controller`.
