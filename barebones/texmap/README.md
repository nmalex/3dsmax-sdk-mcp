# Barebones: Texture Map

A texture map is what goes in a material's map slot — Diffuse, Bump, Opacity — and answers
a colour (and a mono value, and a bump perturbation) for every shading sample.

**This example is a checker.** `tiles` × `tiles` squares of `bright` and `dark` over the object's
UVs. The Python lane *bakes* it — one texel per tile — and the slot samples that image; the native
lane computes it from the sample's UV directly. Both give the same picture, and the picture is the
proof: a map that did nothing would render a flat neutral grey.

**Parameters:** `tiles`, `bright`, `dark` — declared by `describe_params()`, kept by the slot (saved with the scene,
animatable, `$.<name>`), shown in the Material Editor, below the map's standard **Coordinates** rollout, and handed back as `params` on every call — and, in unmanaged
mode, to `Prepare` before rendering.

**Hello signal:** a log line from `TexmapUpdate`, once per load, readable with
`cartridge_logs -module slot_texmap`.

## Two modes — why Python never runs per sample

The renderer asks a texture map for an answer at every sample, on its own threads, millions of times a
frame. A Python call there would be the wrong cost and would block on the interpreter, so a
Cartridge Texture Map runs in one of two modes, chosen when it loads:

| Mode | Who runs per sample | What the cartridge does |
| --- | --- | --- |
| **Managed** (default; every Python cartridge) | the slot, natively | at `TexmapUpdate` (main thread) it returns **an image**; the slot evaluates that per sample by UV (nearest texel, tiled) |
| **Unmanaged** (a native payload exporting `MaxMcpGetUnmanaged`) | the payload, through the facade | the slot pins the DLL and calls `TexmapColor` per sample with an **opaque handle**; the payload reads the sample through the `ShadeSample*` entries and returns floats the slot writes back |

Unmanaged mode is **not** SDK access: the native payload includes no 3ds Max header, holds no Max
pointer, and never casts the handle — see [`LAW.md`](../../LAW.md), LAW-1. It is declared by the export
alone. An unmanaged slot is native-only: it refuses the Python lane, cannot be hot-swapped (restart
3ds Max to replace the DLL), and turns a fault in `TexmapColor` into its neutral answer, reported once.

## The facade entries the native lane uses

| Entry | What it gives |
| --- | --- |
| `ShadeSampleRead` | the sample: position, normal, view, time, material id, lights count |
| `ShadeSampleUVW` | the UVW of a map channel and its derivatives |

They are callable only inside `TexmapColor`, with the handle it was given; anywhere else they answer
`MANAGED_ONLY` or `UNBOUND`. Ask the index for the rest:

```bash
python surface/max_facade_surface.py ShadeSample
python surface/max_facade_surface.py --missing texmap
```

## See it work

1. Material Editor → a material's **Diffuse** map button → *MCP Cartridges* → **Cartridge
   Texture Map**. The sample sphere turns into a checker.
2. Or from Python/MAXScript: `renderMap (Cartridge_Texture_Map()) size:[64,64]` — alternate
   texels come back `bright` and `dark`.

## What plugin type this is

`TEXMAP_CLASS_ID`, base class `Texmap`. The slot is **Cartridge Texture Map** (internal name `Cartridge_Texture_Map`,
`TexmapSlot.dlt`). The material-family SuperClassIDs and their barebones:

| SuperClassID | Base class | What it is | Barebones |
| --- | --- | --- | --- |
| `TEXMAP_CLASS_ID` | `Texmap` | texture map (colour, mono, bump) | **this example** |
| `MATERIAL_CLASS_ID` | `Mtl` | material | [`barebones/material`](../material/README.md) |
| `SHADER_CLASS_ID` | `Shader` | Standard-material shading model | [`barebones/shader`](../shader/README.md) |
| `SAMPLER_CLASS_ID` | `Sampler` | supersampler | [`barebones/sampler`](../sampler/README.md) |

## Lanes

| Lane | File | Mode | Deployed as |
| --- | --- | --- | --- |
| Python | [`python/slot_texmap.py`](python/slot_texmap.py) | managed | `slot_texmap` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | unmanaged | `slot_texmap_native.dll`, beside `TexmapSlot.dlt` |

Both lanes produce the same texture map. The Python lane hot-swaps; the native lane is pinned once loaded,
so deploying it means: build, put `slot_texmap_native.dll` beside `TexmapSlot.dlt`, restart 3ds Max. Remove the DLL
(and restart) to return to the Python lane. See the repository root [`README.md`](../../README.md) for
the barebones index and [`ESSENTIALS.md`](../../ESSENTIALS.md) for the SDK documentation the facade
follows.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Managed: change what `TexmapUpdate` returns. Unmanaged: change `TexmapColor` — it runs on render threads,
   so keep it lock-free and read parameters only from what `Prepare` stored.
3. Declare parameters in `describe_params`; the slot keeps them and hands them to both lanes.
4. When the facade lacks something you need, do not reach for the SDK — file a feature request
   ([`LAW.md`](../../LAW.md)).
