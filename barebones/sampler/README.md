# Barebones: Sampler

A sampler decides **where inside a pixel** the Standard material is shaded, asks the renderer
to shade there, and averages. It lives in the material's **SuperSampling** rollout, which gives it an
Enable box and a Quality spinner.

**This example is a stratified, jittered grid.** `grid` × `grid` positions, one per cell, jittered
inside it (`grid` 0 takes the side from Quality). Python returns the pattern once per render; the
native lane lays it out per pixel with a different jitter in each, and takes each sample with
`ShadeSampleTakeSample`. In both lanes the **slot** sums and averages what was taken, skips positions
off the fragment, and falls back to the fragment's centre when nothing was hit — so a sampler cannot
brighten the image by forgetting to average. The proof is the edges: smooth, where one centre sample
leaves them stepped.

Its Setup dialog (the rollout's **Setup** button) is the cartridge's panel; the rollout's own Quality
and Enable arrive in `params` as `quality` and `enabled`.

**Parameters:** `grid`, `jitter` (plus the rollout's `quality`, `enabled`) — declared by `describe_params()`, kept by the slot (saved with the scene,
animatable, `$.<name>`), shown in the Standard material's SuperSampling rollout, as its Setup dialog, and handed back as `params` on every call — and, in unmanaged
mode, to `Prepare` before rendering.

**Hello signal:** a log line from `SamplerRenderBegin`, once per load, readable with
`cartridge_logs -module slot_sampler`.

## Two modes — why Python never runs per sample

The renderer asks a sampler for an answer at every pixel, on its own threads, millions of times a
frame. A Python call there would be the wrong cost and would block on the interpreter, so a
Cartridge Sampler runs in one of two modes, chosen when it loads:

| Mode | Who runs per pixel | What the cartridge does |
| --- | --- | --- |
| **Managed** (default; every Python cartridge) | the slot, natively | at `SamplerRenderBegin` (main thread) it returns **a sub-pixel pattern**; the slot evaluates that by taking exactly those samples in each pixel and averaging them |
| **Unmanaged** (a native payload exporting `MaxMcpGetUnmanaged`) | the payload, through the facade | the slot pins the DLL and calls `SamplerSample` per pixel with an **opaque handle**; the payload reads the pixel through the `ShadeSample*` entries and returns floats the slot writes back |

Unmanaged mode is **not** SDK access: the native payload includes no 3ds Max header, holds no Max
pointer, and never casts the handle — see [`LAW.md`](../../LAW.md), LAW-1. It is declared by the export
alone. An unmanaged slot is native-only: it refuses the Python lane, cannot be hot-swapped (restart
3ds Max to replace the DLL), and turns a fault in `SamplerSample` into its neutral answer, reported once.

## The facade entries the native lane uses

| Entry | What it gives |
| --- | --- |
| `ShadeSampleRead` | the pixel's screen position (seeds the jitter) |
| `ShadeSampleTakeSample` | shade one sub-pixel position; the slot keeps the sum |

They are callable only inside `SamplerSample`, with the handle it was given; anywhere else they answer
`MANAGED_ONLY` or `UNBOUND`. Ask the index for the rest:

```bash
python surface/max_facade_surface.py ShadeSample
python surface/max_facade_surface.py --missing sampler
```

## See it work

1. A Standard material → *SuperSampling* → clear **Use Global Settings**, tick **Enable Local
   Supersampler**, pick **Cartridge Sampler**.
2. Render a high-contrast edge (the Texture Map barebones at a grazing angle) with `grid` 4, then
   `grid` 1: the difference is the sampler working.

## What plugin type this is

`SAMPLER_CLASS_ID`, base class `Sampler`. The slot is **Cartridge Sampler** (internal name `Cartridge_Sampler`,
`SamplerSlot.dlh`). The material-family SuperClassIDs and their barebones:

| SuperClassID | Base class | What it is | Barebones |
| --- | --- | --- | --- |
| `TEXMAP_CLASS_ID` | `Texmap` | texture map (colour, mono, bump) | [`barebones/texmap`](../texmap/README.md) |
| `MATERIAL_CLASS_ID` | `Mtl` | material | [`barebones/material`](../material/README.md) |
| `SHADER_CLASS_ID` | `Shader` | Standard-material shading model | [`barebones/shader`](../shader/README.md) |
| `SAMPLER_CLASS_ID` | `Sampler` | supersampler | **this example** |

## Lanes

| Lane | File | Mode | Deployed as |
| --- | --- | --- | --- |
| Python | [`python/slot_sampler.py`](python/slot_sampler.py) | managed | `slot_sampler` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | unmanaged | `slot_sampler_native.dll`, beside `SamplerSlot.dlh` |

Both lanes produce the same sampler. The Python lane hot-swaps; the native lane is pinned once loaded,
so deploying it means: build, put `slot_sampler_native.dll` beside `SamplerSlot.dlh`, restart 3ds Max. Remove the DLL
(and restart) to return to the Python lane. See the repository root [`README.md`](../../README.md) for
the barebones index and [`ESSENTIALS.md`](../../ESSENTIALS.md) for the SDK documentation the facade
follows.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Managed: change what `SamplerRenderBegin` returns. Unmanaged: change `SamplerSample` — it runs on render threads,
   so keep it lock-free and read parameters only from what `Prepare` stored.
3. Declare parameters in `describe_params`; the slot keeps them and hands them to both lanes.
4. When the facade lacks something you need, do not reach for the SDK — file a feature request
   ([`LAW.md`](../../LAW.md)).
