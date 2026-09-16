# Barebones: Shader

A shader is a shading model inside the Standard material — the entry beside Blinn, Phong,
Metal and Strauss in its **Shader** dropdown. The material textures its inputs and hands them to the
shader to light.

**This example is a tinted Lambert.** The tint is `hue` at saturation `strength`. In managed mode
Python returns that tint and the slot applies it to a plain Lambert; the native lane reads the
material's diffuse input (`ShadeSampleIllumRead`, channel 0), lights it with **wrap** lighting and
adds a `rim` term, tinted the same. A white-diffuse material renders in the tint colour — that is the
proof the shader is the one lighting it.

The shader's texture channels, by the number `ShadeSampleIllumRead` takes: **0** Diffuse Color,
**1** Specular Color, **2** Glossiness, **3** Opacity, **4** Filter Color.

**Parameters:** `hue`, `strength`, `wrap`, `rim` — declared by `describe_params()`, kept by the slot (saved with the scene,
animatable, `$.<name>`), shown in the Standard material's shader rollout: the slot's About replaces the previous shader's page, and the cartridge's panel sits beside it, and handed back as `params` on every call — and, in unmanaged
mode, to `Prepare` before rendering.

**Hello signal:** a log line from `ShaderUpdate`, once per load, readable with
`cartridge_logs -module slot_shader`.

## Two modes — why Python never runs per sample

The renderer asks a shader for an answer at every sample, on its own threads, millions of times a
frame. A Python call there would be the wrong cost and would block on the interpreter, so a
Cartridge Shader runs in one of two modes, chosen when it loads:

| Mode | Who runs per sample | What the cartridge does |
| --- | --- | --- |
| **Managed** (default; every Python cartridge) | the slot, natively | at `ShaderUpdate` (main thread) it returns **a tint**; the slot evaluates that as a Lambert term over the lights, times the tint |
| **Unmanaged** (a native payload exporting `MaxMcpGetUnmanaged`) | the payload, through the facade | the slot pins the DLL and calls `ShaderIllum` per sample with an **opaque handle**; the payload reads the sample through the `ShadeSample*` entries and returns floats the slot writes back |

Unmanaged mode is **not** SDK access: the native payload includes no 3ds Max header, holds no Max
pointer, and never casts the handle — see [`LAW.md`](../../LAW.md), LAW-1. It is declared by the export
alone. An unmanaged slot is native-only: it refuses the Python lane, cannot be hot-swapped (restart
3ds Max to replace the DLL), and turns a fault in `ShaderIllum` into its neutral answer, reported once.

## The facade entries the native lane uses

| Entry | What it gives |
| --- | --- |
| `ShadeSampleRead` | the sample: normal, view vector, lights count |
| `ShadeSampleIllumRead` | one of the material's textured inputs, by channel |
| `ShadeSampleAmbient` | the ambient light |
| `ShadeSampleLight` | one light: colour, direction, N·L |

They are callable only inside `ShaderIllum`, with the handle it was given; anywhere else they answer
`MANAGED_ONLY` or `UNBOUND`. Ask the index for the rest:

```bash
python surface/max_facade_surface.py ShadeSample
python surface/max_facade_surface.py --missing shader
```

## See it work

1. A **Standard** material, Diffuse white → *Shader Basic Parameters* → **Cartridge Shader**.
2. Assign to a Teapot and render: the teapot comes out in the tint colour.

## What plugin type this is

`SHADER_CLASS_ID`, base class `Shader`. The slot is **Cartridge Shader** (internal name `Cartridge_Shader`,
`ShaderSlot.dlb`). The material-family SuperClassIDs and their barebones:

| SuperClassID | Base class | What it is | Barebones |
| --- | --- | --- | --- |
| `TEXMAP_CLASS_ID` | `Texmap` | texture map (colour, mono, bump) | [`barebones/texmap`](../texmap/README.md) |
| `MATERIAL_CLASS_ID` | `Mtl` | material | [`barebones/material`](../material/README.md) |
| `SHADER_CLASS_ID` | `Shader` | Standard-material shading model | **this example** |
| `SAMPLER_CLASS_ID` | `Sampler` | supersampler | [`barebones/sampler`](../sampler/README.md) |

## Lanes

| Lane | File | Mode | Deployed as |
| --- | --- | --- | --- |
| Python | [`python/slot_shader.py`](python/slot_shader.py) | managed | `slot_shader` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | unmanaged | `slot_shader_native.dll`, beside `ShaderSlot.dlb` |

Both lanes produce the same shader. The Python lane hot-swaps; the native lane is pinned once loaded,
so deploying it means: build, put `slot_shader_native.dll` beside `ShaderSlot.dlb`, restart 3ds Max. Remove the DLL
(and restart) to return to the Python lane. See the repository root [`README.md`](../../README.md) for
the barebones index and [`ESSENTIALS.md`](../../ESSENTIALS.md) for the SDK documentation the facade
follows.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Managed: change what `ShaderUpdate` returns. Unmanaged: change `ShaderIllum` — it runs on render threads,
   so keep it lock-free and read parameters only from what `Prepare` stored.
3. Declare parameters in `describe_params`; the slot keeps them and hands them to both lanes.
4. When the facade lacks something you need, do not reach for the SDK — file a feature request
   ([`LAW.md`](../../LAW.md)).
