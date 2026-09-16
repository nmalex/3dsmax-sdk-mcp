# Barebones: Material

A material is what the user assigns to an object; the renderer asks it to shade every
sample it sees — colour and transparency.

**This example is a coloured, lit material.** The colour is `hue` at brightness `base`. In managed
mode Python returns that colour and the slot lights it; the native lane lights it itself (walking the
lights with `ShadeSampleLight`) and adds a `rim` term at grazing angles. Either way the teapot comes
out in *your* colour, shaded — not the flat grey a material with no cartridge answers.

**Parameters:** `hue`, `base`, `rim`, `lit` — declared by `describe_params()`, kept by the slot (saved with the scene,
animatable, `$.<name>`), shown in the Material Editor, as the material's own rollout, and handed back as `params` on every call — and, in unmanaged
mode, to `Prepare` before rendering.

**Hello signal:** a log line from `MtlUpdate`, once per load, readable with
`cartridge_logs -module slot_material`.

## Two modes — why Python never runs per sample

The renderer asks a material for an answer at every sample, on its own threads, millions of times a
frame. A Python call there would be the wrong cost and would block on the interpreter, so a
Cartridge Material runs in one of two modes, chosen when it loads:

| Mode | Who runs per sample | What the cartridge does |
| --- | --- | --- |
| **Managed** (default; every Python cartridge) | the slot, natively | at `MtlUpdate` (main thread) it returns **a colour**; the slot evaluates that lit by the scene's lights plus ambient (Lambert) |
| **Unmanaged** (a native payload exporting `MaxMcpGetUnmanaged`) | the payload, through the facade | the slot pins the DLL and calls `MtlShade` per sample with an **opaque handle**; the payload reads the sample through the `ShadeSample*` entries and returns floats the slot writes back |

Unmanaged mode is **not** SDK access: the native payload includes no 3ds Max header, holds no Max
pointer, and never casts the handle — see [`LAW.md`](../../LAW.md), LAW-1. It is declared by the export
alone. An unmanaged slot is native-only: it refuses the Python lane, cannot be hot-swapped (restart
3ds Max to replace the DLL), and turns a fault in `MtlShade` into its neutral answer, reported once.

## The facade entries the native lane uses

| Entry | What it gives |
| --- | --- |
| `ShadeSampleRead` | the sample: normal, view vector, lights count |
| `ShadeSampleAmbient` | the ambient light at the sample |
| `ShadeSampleLight` | one light: colour, direction, N·L, diffuse coefficient, lit or not |

They are callable only inside `MtlShade`, with the handle it was given; anywhere else they answer
`MANAGED_ONLY` or `UNBOUND`. Ask the index for the rest:

```bash
python surface/max_facade_surface.py ShadeSample
python surface/max_facade_surface.py --missing material
```

## Beyond one colour

This barebones returns the simplest look: one colour. `MtlUpdate` can return a whole **look** instead:
- an image by UV;
- a colour ramp by facing, light, u, v or world height (a banded ramp by light is toon shading);
- a rim glow and emission;
- opacity.

The Slot shades it per sample, natively. See
[docs/SLOTS.md — A managed look](../../docs/SLOTS.md#a-managed-look--what-a-python-material-or-shader-can-return).

## See it work

**The quickest way:** run [`../material_family_demo.py`](../material_family_demo.py) in 3ds Max. It
builds one scene that uses all four material-family cartridges, animates them over three frames,
and renders the result. See [the barebones index](../README.md) for what to look for. To try this
one by hand:

1. Material Editor → *MCP Cartridges* → **Cartridge Material**; assign it to a Teapot.
2. Render (Scanline): the teapot is the `hue` colour, bright where it faces the light. Move `hue`
   and re-render — the colour follows.

## What plugin type this is

`MATERIAL_CLASS_ID`, base class `Mtl`. The slot is **Cartridge Material** (internal name `Cartridge_Material`,
`MaterialSlot.dlt`). The material-family SuperClassIDs and their barebones:

| SuperClassID | Base class | What it is | Barebones |
| --- | --- | --- | --- |
| `TEXMAP_CLASS_ID` | `Texmap` | texture map (colour, mono, bump) | [`barebones/texmap`](../texmap/README.md) |
| `MATERIAL_CLASS_ID` | `Mtl` | material | **this example** |
| `SHADER_CLASS_ID` | `Shader` | Standard-material shading model | [`barebones/shader`](../shader/README.md) |
| `SAMPLER_CLASS_ID` | `Sampler` | supersampler | [`barebones/sampler`](../sampler/README.md) |

## Lanes

| Lane | File | Mode | Deployed as |
| --- | --- | --- | --- |
| Python | [`python/slot_material.py`](python/slot_material.py) | managed | `slot_material` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | unmanaged | `slot_material_native.dll`, beside `MaterialSlot.dlt` |

Both lanes produce the same material. The Python lane hot-swaps; the native lane is pinned once loaded,
so deploying it means: build, put `slot_material_native.dll` beside `MaterialSlot.dlt`, restart 3ds Max. Remove the DLL
(and restart) to return to the Python lane. See the repository root [`README.md`](../../README.md) for
the barebones index and [`ESSENTIALS.md`](../../ESSENTIALS.md) for the SDK documentation the facade
follows.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Managed: change what `MtlUpdate` returns. Unmanaged: change `MtlShade` — it runs on render threads,
   so keep it lock-free and read parameters only from what `Prepare` stored.
3. Declare parameters in `describe_params`; the slot keeps them and hands them to both lanes.
4. When the facade lacks something you need, do not reach for the SDK — file a feature request
   ([`LAW.md`](../../LAW.md)).
