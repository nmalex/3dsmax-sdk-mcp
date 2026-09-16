# Slots

A **Slot** is a pre-compiled 3ds Max plugin that ships with the release and hosts your payload.
You never build one; you occupy one.

That is the whole reason this kit needs no 3ds Max SDK, no C++ toolchain for a Python payload, and
no compiler to produce a working plugin.

## The Slots that ship — 22 today

Each Slot is a compiled 3ds Max plugin of one specific kind. **Twenty-two** ship today, so you can build
a Cartridge for any of these:

| Slot | What 3ds Max sees | Where it appears |
| --- | --- | --- |
| `modifier` | an object-space modifier | the Modifier List |
| `exporter` | a scene exporter | File ▸ Export, "Save as type" |
| `renderer` | a renderer | the Render Setup dialog |
| `manipulator` | a viewport manipulator | a helper, editable on the viewport gizmo |
| `controller` | an animation controller | Track View / Assign Controller |
| `uv-generator` | a UV coordinate generator | a texmap's Coordinates |
| `xyz-generator` | an XYZ coordinate generator | a texmap's Coordinates |
| `texture-output` | a texture output filter | a texmap's Output rollout |
| `aa-filter-kernel` | an anti-aliasing filter kernel | the renderer's AA filter list |
| `radiosity` | an advanced-lighting / radiosity plugin | the Advanced Lighting dialog |
| `datachannel-engine` | a Data Channel modifier engine | the Data Channel modifier |
| `effect` | a render effect | the Environment & Effects dialog |
| `iksolver` | an IK solver | the IK solver list |
| `osnap` | an object snap | the Snaps settings |
| `pfoperator` | a Particle Flow operator | Particle View |
| `utility` | a Utilities-panel tool | the Utilities panel |
| `color-picker` | a colour picker | the colour selector |
| `videopost-filter` | a Video Post image filter | the Video Post queue |
| `texmap` | a texture map (**Cartridge Texture Map**) | the Material/Map Browser, under *MCP Cartridges* |
| `material` | a material (**Cartridge Material**) | the Material/Map Browser, under *MCP Cartridges* |
| `shader` | a Standard-material shading model (**Cartridge Shader**) | the Standard material's Shader list |
| `sampler` | a supersampler (**Cartridge Sampler**) | the Standard material's SuperSampling rollout |

`manipulator` and `pfoperator` are two different Slots that both register under `HELPER_CLASS_ID` — a
super-class is a property of the class a Slot registers, not a bucket that owns Slots, so two Slots
sharing one is normal. [docs/SUPERCLASS_CENSUS.md](SUPERCLASS_CENSUS.md) is the complete map of every
plugin type the SDK declares — which have a Slot, which are registerable with a Slot on the roadmap,
and which can never be a third-party Slot and why; [docs/COVERAGE_MAP.md](COVERAGE_MAP.md) is the
per-type accounting of how each of the 22 is verified.

**The install is the check, and you can run it.** The release asset stages one module file per Slot
into `Contents\Bin` — the modifier as `ModifierSlot.dlm`, the exporter as `ExporterSlot.dle`, and the
rest under their own fixed names (the texture map as `TexmapSlot.dlt`, the material as
`MaterialSlot.dlt`, the shader as `ShaderSlot.dlb`, the sampler as `SamplerSlot.dlh`) — so `tools\list-plugins.ps1` against your install enumerates the
Slots you actually have rather than trusting this page. If your disk and this list ever disagree, the
disk is right and this is a bug worth [reporting](../README.md#reporting-a-bug) — a document that
lists a Slot nobody built sends you looking for a bug in your payload.

**More kinds are the roadmap, not the whole list.** 3ds Max can be extended in far more ways than the
22 above — geometry objects, cameras, lights, shapes, atmospherics, more controller value types, and
others. Those are **real, registerable types whose Slots are simply not built yet**, not a
door that is closed: each is tracked in [docs/SUPERCLASS_CENSUS.md](SUPERCLASS_CENSUS.md) and on
[ROADMAP.md](../ROADMAP.md), and asking for one is a legitimate request — what people ask for is what
moves. (A handful of super-class IDs can *never* be a third-party Slot because the SDK does not let
anyone register one; the census lists those separately, with the reason for each, so the two are never
confused.)

**Authoring a new *kind* of Slot yourself is a separate thing** with a different prerequisite — it
needs the 3ds Max SDK, because a Slot derives from SDK classes the host calls into directly. That
path is on the roadmap and is not open yet. Writing Cartridges for the Slots above needs none of it.

## One Cartridge per Slot, at a time

**A Slot is a workbench station, not a home.** Everything about a Slot is compiled into it — the
class identity 3ds Max registers, the name it shows in the list, and the payload module name it
loads. So one Slot hosts one Cartridge at a time, and putting a new Cartridge in a Slot replaces
what was there.

### What that means for a saved scene, stated before it bites you

A saved `.max` file resolves its plug-ins by class identity, and **the identity belongs to the
Slot, not to your Cartridge**. So:

> A scene saved while *Cool Bend* occupied the modifier Slot will evaluate whatever occupies that
> Slot when the scene is next opened.

Test scenes are not durable across a Slot reuse. That is a property of a workbench, not a defect —
a finished Cartridge is *sealed*, which produces a plugin of its own with its own identity, and
that one is durable. The kit says so every time it replaces an occupant rather than letting you
find out later.

### And the list entry is the Slot's name, for now

Because the visible name is compiled in too, the Modifier List shows the **Slot's** name rather
than your Cartridge's. Your Cartridge's name lives in its record and in its About rollout. A future
release combines the two — "Cool Bend Cartridge A" — so that the station stays visible while the
Cartridge is named. Nothing about that change affects saved scenes, because it changes a string and
not an identity.

## Where things live

```
<clone>\cartridges\<slug>\          your source, under version control
    cartridge.json                  your record of it
    python\<module>.py              what you edit

%LOCALAPPDATA%\3dsmax-sdk-mcp\
    cartridges\
        slot_modifier.py            whatever occupies the modifier Slot
        slot_exporter.py            whatever occupies the exporter Slot
        ...                         one fixed file name per Slot you occupy
    slots.json                      which Cartridge is in which Slot
```

**The deployed layout is flat and the file names are fixed**, because a Slot loads the module name
it was compiled with. Deploying copies your payload into place under that name; the file you edit
keeps yours.

## What your Slot actually calls, and what it does not

**A payload function nothing calls is not a payload function.** A Slot is compiled, so the set of
names it asks your payload for was fixed when the binary was built — you cannot add one, and
defining a function the Slot has never heard of does nothing at all. There is no error, because
there is no call.

This is the table to check first when something you wrote does not appear to run. It is also the
table whose absence caused [#2](https://github.com/nmalex/3dsmax-sdk-mcp/issues/2): a scaffolded
`describe_ui()` did nothing, every payload-side signal was green, and the reason was that the
modifier Slot of that release did not call it.

### Every slot with a UI place builds your panel there

Since `0.8.0-alpha.5` this is not a modifier privilege. **Every Slot whose plugin kind has a UI place
in 3ds Max builds your `describe_ui()` panel in that place**, with the Slot's own About (version,
build, which lanes are loaded, Refresh) beside it. The same controls, the same events, the same
`params`; only the place differs:

| Slot | Where your panel appears | `on_ui_event` | Keeps `describe_params()` values |
| --- | --- | --- | --- |
| `modifier` | the Modify panel | yes | **yes** — saved, animatable, `$.modifiers[1].name` |
| `manipulator` (Tetra Dummy) | the Create and Modify panels | yes | **yes** — saved, animatable, `$.size` |
| `utility` | the Utilities panel | yes | no |
| `pfoperator` | Particle View's parameter panel | yes | no |
| `datachannel-engine` | the Data Channel modifier's engine panel | yes | no |
| `controller` | Track View > right-click > **Properties** (a modal dialog), and the Motion panel for a transform | yes | no |
| `effect` | Rendering > Environment and Effects | yes | no |
| `radiosity` | Rendering > Advanced Lighting | yes | no |
| `aa-filter-kernel` | Render Setup, under the anti-aliasing filter | yes | no |
| `renderer` | Render Setup (not the in-render progress dialog) | yes | no |
| `texture-output`, `uv-generator`, `xyz-generator` | the Material Editor | yes | no |
| `texmap` | the Material Editor, below the map's **Coordinates** rollout | yes | **yes** — saved, animatable, `$.<name>` |
| `material` | the Material Editor, as the material's own rollout | yes | **yes** — saved, animatable, `$.<name>` |
| `shader` | the Standard material's shader rollout: the Slot's About replaces the previous shader's page, your panel sits beside it | yes | **yes** — saved, animatable, `$.<name>` |
| `sampler` | the Standard material's SuperSampling rollout, as its **Setup** dialog (modal); the rollout's Quality and Enable arrive in `params` as `quality` and `enabled` | yes | **yes** — saved, animatable, `$.<name>` |
| `videopost-filter` | Video Post's **Setup** button (a modal dialog); **About** shows the Slot's facts | yes | no |
| `exporter` | File > Export's options dialog; **About** shows the Slot's facts | **no** — see below | no |
| `color-picker`, `osnap`, `iksolver`, `fragment` | **no UI place** — the picker *is* the dialog; a snap is listed by name; the SDK gives a solver no UI hook; a render fragment has no UI | — | — |

**"Keeps values: no"** means a control bound with `param=` still reaches `on_ui_event` with its new
value, but the Slot does not save it with the scene. Only the Slots marked **yes** hold a parameter
block today. A cartridge in any other Slot that needs a saved value is a feature request, not a
workaround — see [REPORTING.md](REPORTING.md).

**No `describe_ui` is still a legal answer**: that Slot then shows only its About.

### The functions each Slot calls

| Function | `modifier` | `manipulator` | `texmap` `material` `shader` `sampler` | other UI slots (above) | `exporter` | When it is called |
| --- | --- | --- | --- | --- | --- | --- |
| `describe_ui(params)` | yes | yes | yes | yes | yes | when the panel opens, and on every Refresh. Exporter: opening the export options dialog |
| `on_ui_event(control_id, value, ctrl, shift, alt, settled, params)` | yes | yes | yes | yes | **no** | when a control on your panel changed |
| `describe_params()` | yes | yes | yes | no | **no** | on load / creation and on every Refresh — declares parameters the Slot then keeps. Needs `0.4.0-alpha.3` (modifier) / `0.8.0-alpha.5` (manipulator) / `0.8.0-alpha.6` (material family) or newer |
| `deform(points, box, tm, params)` | yes | — | — | — | — | every evaluation of the modifier stack |
| `ManipUpdateShapes(event, slot, params)` | — | yes | — | — | — | whenever the gizmo is rebuilt (display, a parameter change). `params` since `0.8.0-alpha.5` |
| `ManipMouse(event, slot, params)` | — | yes | — | — | — | pressing / dragging / releasing the gizmo in **Select and Manipulate** mode. **Not** the creation click — the Slot places the helper where you click |
| `TexmapUpdate` / `MtlUpdate` / `ShaderUpdate` / `SamplerRenderBegin` | — | — | yes, one each | — | — | on the main thread, before sampling — the managed answer; see [the table below](#managed-and-unmanaged-per-sample-slots) |
| `format_header` / `format_node` / `format_group_open` / `format_group_close` / `format_material_list` | — | — | — | — | yes | once per export, per node, per group, per scene |
| `declare_callbacks()` | yes | **no** | **no** | **no** | **no** | modifier only, on load and on every Refresh — how a payload subscribes to host notifications |

**Every callback carries `slot`** — the facade table's address, for `mcp_facade.from_address(slot)` —
and the ones marked above also carry `params`. `slot` means the facade address in every entry point;
the load-time `init(**env)` calls the Slot's name `slotName` for that reason.

**Absent is a legal answer to all of them.** A Slot that asks for `describe_ui` and finds none does
not fault; it concludes you want no panel. That is deliberate, and it is why a *missing* function
and a *misspelled* one behave identically — check the spelling before you check anything else.

**`max_cartridge_refresh` names the exports it actually found.** Call it and read the list: a
function you wrote that is not in it never made it into the module, and a function that is in it but
never runs is not being asked for. Those are two different bugs and this is what separates them.

### Managed and unmanaged per-sample slots

The four material-family Slots — `texmap`, `material`, `shader`, `sampler` — are asked for an answer at
every shading sample (every pixel, for a sampler), on the renderer's own threads, millions of times a
frame. A Python call there would be the wrong cost and would block on the interpreter, so **Python
never runs per sample**. Each of these Slots runs in one of two modes, chosen when it loads:

- **Managed** — the default, and the mode of every Python cartridge. At its update call, on the main
  thread, the cartridge returns **data**, and the Slot evaluates that data natively per sample.
- **Unmanaged** — a native payload that exports `MaxMcpGetUnmanaged`. The Slot calls the payload per
  sample with an **opaque handle**; the payload reads the sample through the facade's `ShadeSample*`
  entries (`ShadeSampleRead`, `ShadeSampleUVW`, `ShadeSampleAmbient`, `ShadeSampleLight`,
  `ShadeSampleIllumRead`, `ShadeSampleTakeSample`) and returns floats the Slot writes back. Those
  entries answer only inside the per-sample call, with the handle it was given.

| Slot | Managed call | What it returns | How the Slot evaluates it | Unmanaged per-sample call |
| --- | --- | --- | --- | --- |
| `texmap` | `TexmapUpdate` | `image` — `{width, height, rgb[]}` | nearest texel by UV, tiled | `TexmapColor` / `TexmapMono` / `TexmapBump` |
| `material` | `MtlUpdate` | a **look** (below); the simplest is `color` — `[r, g, b]` | the look per sample; a bare colour is lit by the lights plus ambient | `MtlShade` |
| `shader` | `ShaderUpdate` | a **look** (below); the simplest is `tint` — `[r, g, b]` | the look on the material's diffuse input; a bare tint multiplies a Lambert term | `ShaderIllum` |
| `sampler` | `SamplerRenderBegin` | `pattern` — `[[x, y], ...]`, up to 64 positions | takes exactly those samples in each pixel and averages | `SamplerSample` |

**Unmanaged is not SDK access.** The payload includes no 3ds Max header, holds no Max pointer and never
casts the handle — [LAW.md](../LAW.md) applies unchanged. What unmanaged changes:

- the native payload is **pinned** once loaded — no hot swap; restart 3ds Max to replace or remove it;
- the Python lane is **refused** for that Slot while the native payload is there;
- the native lane must itself answer `describe_params`, `describe_ui` and `on_ui_event`;
- a fault in the per-sample call becomes the Slot's neutral answer, reported once.

Both modes are verified live in 3ds Max 2026 with the Scanline renderer. The barebones for each Slot
([texmap](../barebones/texmap/README.md), [material](../barebones/material/README.md),
[shader](../barebones/shader/README.md), [sampler](../barebones/sampler/README.md)) ship one lane in
each mode and say which `ShadeSample*` entries the native lane uses.

#### A managed look — what a Python material or shader can return

Since `0.8.0-alpha.8` the `material` and `shader` Slots take a whole **look** from their update call,
not just one colour. The Slot evaluates it for every sample, natively. Every key is optional:

```python
def MtlUpdate(**event):
    return {
        "ok": True,
        "color": [1.0, 0.9, 0.8],                      # base colour ("tint" also works for a shader)
        "image": {"width": w, "height": h, "rgb": [...]},   # base colour by UV (channel 1), tiled
        "ramp": {
            "by": "light",                             # facing | light | u | v | height
            "colors": [[0.1, 0.1, 0.3], [0.4, 0.4, 0.8], [0.9, 0.9, 1.0]],   # 2..256 stops
            "range": [0.0, 1.0],                       # the input mapped onto the stops
            "smooth": False,                           # False = hard bands
        },
        "lit": True,                                   # False = the base as is
        "rim": {"color": [1, 1, 1], "power": 3.0},     # added where the surface turns away
        "emit": [0.0, 0.0, 0.2],                       # added after lighting
        "opacity": 1.0,                                # material only; 0..1
    }
```

How the Slot shades a sample:

1. **Base colour.** The product of whichever of `color`, the `image` texel under the sample's UV, and
   the `ramp` colour are given. A shader starts from the Standard material's diffuse input, so
   `color` acts as a tint.
2. **Lighting.**
   - A ramp `"by": "light"` replaces the lighting term: the ramp is looked up at the amount of light
     the sample receives, plus the ambient light. With `"smooth": False` this is **toon shading**.
   - Otherwise, when `lit` is true (the default), the base is lit by the scene's lights plus the
     ambient light.
3. **Additions.** `rim` adds its colour at grazing angles, weighted by (1 − facing)^power. `emit` is
   added last.
4. **Opacity.** `opacity` below 1 makes the material transparent. A shader ignores it, because its
   transparency is the Standard material's own Opacity.

What a ramp can read, each value mapped through `range` and clamped to 0..1:

| `by` | the value |
| --- | --- |
| `facing` | 1 where the surface faces the camera, 0 edge-on |
| `light` | the brightness of the light the sample receives (ambient not included) |
| `u`, `v` | the UVs of map channel 1 |
| `height` | the sample's world Z |

**Compatibility and errors**
- A reply with only `color` (or `tint`) still shades exactly as in `0.8.0-alpha.6`.
- A reply with no base key (`color`, `image` or `ramp`) means "no look". The Slot then shades its
  neutral default.
- A look the Slot can't use is **refused whole**, never half-applied. The reason is logged once, as a
  warning, in the cartridge's log, for example:
  `MtlUpdate: the look was refused - 'color' must be [r, g, b] with three finite numbers`.
- Limits: images up to 1024×1024; ramps of 2 to 256 stops.

### The exporter has a panel, but no events

Your `describe_ui()` builds the export options dialog and the controls in it are real. The exporter
Slot then **never calls `on_ui_event`**. It reads the control values when it needs them and hands
them to every other call as `params` — `format_header`, `format_node` and the rest all receive the
options as they stood when the export ran.

So the two kinds of control behave very differently, and only one of them works:

1. **A control that holds a value** — a checkbox, a spinner, a dropdown — works exactly as you would
   expect. You do not get told it changed; you read it out of `params`.
2. **A control that only fires** — a button — does nothing. Its handler is never reached, because
   nothing is listening for the event.

Put a `Button` in an exporter panel and you get the same silence [#2](https://github.com/nmalex/3dsmax-sdk-mcp/issues/2)
was about: the payload is loaded, the function is exported, and no call arrives. This is that same
trap in the column next door, which is why it is written down rather than left to be discovered.

### `describe()` is not called by anything today

The scaffolded payload defines `describe()` and describes it as what the About rollout would show
about your Cartridge. **It does not.** The About rollout carries only what was compiled into the
Slot — the Slot's name, its version, its build stamp, and which lanes are loaded. Nothing reads a
payload's `describe()`.

Keep it anyway: it is the entry point the "a Slot shows the Cartridge's name" work will read, it
costs nothing, and it is a useful place to record which version of your own payload is running when
you are answering that question by hand. Just do not expect it on screen yet.

## Parameters: your Cartridge names them, the Slot keeps them

**A value your payload stores in a Python global is a value your user loses.** The interpreter is
recreated on every Refresh, so a module-level variable does not survive one — and it is not saved
with the scene, cannot be keyed, and cannot be read or written by a script. That is not a payload
bug you can fix in the payload; there is nowhere in it for a durable value to live.

So you **declare** parameters and the Slot holds them:

```python
def describe_params():
    return {
        "parameters": [
            {"name": "scaleX", "type": "float", "default": 0.75},
            {"name": "scaleY", "type": "float", "default": 0.75},
            {"name": "scaleZ", "type": "float", "default": 0.75},
            {"name": "uniform", "type": "bool", "default": False},
        ],
    }
```

Each entry becomes one parameter of the modifier itself, which means all four of these at once:

- it is **saved with the scene** — and it loads on a machine that has neither your Cartridge nor
  the plugin, because the value belongs to the Slot rather than to your payload;
- it is **animatable** — a keyable track in Track View, under the name you gave it;
- it is **scriptable** — `$.modifiers[1].scaleX = 2.0`;
- it arrives as **`params`** on every call your Slot makes, sampled at the time being evaluated.

`describe_params()` is asked for when your Cartridge opens and again on every Refresh. Like every
other payload function it is optional: a Cartridge that does not define it declares no parameters
and behaves exactly as it did before.

### Reading and writing one

Never store the value. Read it out of `params`, and let a control write it by naming it:

```python
def describe_ui(params=None):
    p = params or {}
    return ui.build(
        ui.Field("X:", ui.Spinner(value=p.get("scaleX", 0.75),
                                  minimum=-1000.0, maximum=1000.0, step=0.01,
                                  param="scaleX")),
    )

def deform(points, box=None, tm=None, params=None):
    x = (params or {}).get("scaleX", 0.75)
    ...
```

`param="scaleX"` is the whole binding. The Slot writes the value when the control changes —
**before** `on_ui_event` runs, so a handler that reads `params` sees the new truth — and the whole
drag lands in the undo stack as one entry. Your payload never holds a copy, and nothing in it needs
a handler at all unless the change is structural.

### The four types, and where a range goes

| `type` | Bound by | Keyable |
| --- | --- | --- |
| `float` | a spinner or a slider | yes |
| `int` | a spinner, or a radio group through its `param_value` | yes |
| `bool` | a checkbox | yes |
| `string` | an edit box | no — 3ds Max has no controller for one |

A colour swatch is the one control with no parameter type yet; it is the gap to know about.

**A range belongs on the CONTROL, not on the parameter** — `minimum` and `maximum` on the spinner
above. A declaration that carries `min`, `max` or `range` is **refused**, with that sentence, rather
than half-honoured: the Slot cannot clamp one parameter differently from the next, and a spinner you
believed was clamped and is not would be worse than being told.

Two more rules worth knowing before they surprise you:

- **`default` applies once**, when the parameter first appears. It is what the value STARTS at, not
  what it returns to — re-applying it on every Refresh would overwrite what your user set every time
  you saved the file you are editing.
- **A parameter you stop declaring is kept, not deleted.** Its value and its animation are your
  user's work, and a Cartridge being edited is not permission to discard them. It stops appearing in
  `params` and stays in the scene.

**A whole declaration is refused or applied — never half of it.** One bad entry refuses the lot, and
says which entry and why. That is deliberate: applying the good half would leave your own
`params.get("scaleY", 0.75)` quietly answering its fallback for the parameter that did not make it,
which is a Cartridge that looks like it works and silently drops one axis. Refusals go to the log.

### What MAXScript shows, which is not quite what you would guess

Reading and writing by name work as you would expect:

```maxscript
$.modifiers[1].scaleX = 2.0        -- moves the mesh, and the panel's spinner
```

**`getPropNames` does not list your names.** It answers about a plugin CLASS, and your parameters
belong to one modifier, so what it returns is the Slot's own storage — `mcpFloat`, `mcpFloatName`
and their siblings. To enumerate what a modifier declares, read the names beside the values:

```maxscript
$.modifiers[1].mcpFloatName        -- #("scaleX", "scaleY", "scaleZ")
$.modifiers[1].mcpBoolName         -- #("uniform")
```

Those are read-only. Track View is the other way round and shows exactly what you declared, because
a track's name is asked per modifier rather than per class.

Names are MAXScript identifiers: a letter or underscore, then letters, digits and underscores, at
most 64 characters. `mcp` is reserved as a prefix, for the storage above. A name that cannot be
typed is refused rather than accepted and left unreachable.

## `cartridge.json` is your record, not a contract

**Nothing in the plugin reads it.** A Slot needs nothing from it — it loads its compiled module
name and that is the entire binding. The file exists so you and this kit can answer what the plugin
has no reason to ask: which Cartridge is in which Slot, what you meant to call it, which lane it
uses, and what it should be named when it is sealed.

| Field | Meaning |
| --- | --- |
| `schema` | `"cartridge/2"` |
| `name` | what you call it — used in the About rollout, and when it is sealed |
| `slug` | the source directory name |
| `version` | your Cartridge's version |
| `slot` | which Slot it occupies |
| `payload.lane` | `python` or `native` |
| `payload.module` | the module you edit |
| `payload.deployedAs` | the fixed name it is copied to |

## A new Cartridge needs a restart; editing one does not

3ds Max registers plugin classes once, during its startup scan, and offers no supported way to add
one to a running session. **The Slots register at startup whether or not they are occupied** — so
occupying an empty Slot still needs a restart before its entry appears.

**Editing the payload of a Cartridge already in a Slot needs no restart.** That is the fast loop,
and it is the reason the split between a shipped Slot and an authored payload exists at all.
