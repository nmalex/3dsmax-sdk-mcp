# Status

`0.8.0-alpha.7`.

**A pre-release means what it says.** This has been exercised on exactly one machine, and things will change. Every public build bumps its pre-release
identifier, so no two are ever the same version.

This is being built in the open and the parts land in order. What is true **today**:

| | |
| --- | --- |
| `tools/find-max.ps1` | works — finds every installed 3ds Max, reports JSON |
| `tools/list-plugins.ps1` | works — every installed plugin module, from the directories 3ds Max searches |
| `tools/2026/check-prereqs.ps1` | works — readiness rows with a remedy on each |
| `tools/new-cartridge.ps1` | works — scaffolds and deploys a Cartridge |
| `tools/claim-cartridge-name.ps1` | works — conflict, confusable and style verdicts on a proposed name |
| `tools/2026/install-plugin.ps1` | works — fetch, verify the hash, place, verify again |
| `tools/2026/uninstall-plugin.ps1` | works — removes what was installed; your Cartridges are kept |
| The `install` skill and `.mcp.json` | works — a fork drives its own setup |
| The release asset it installs | `0.8.0-alpha.7` — every binary in it carries the release's own identifier; declared parameters arrived in [alpha.3](https://github.com/nmalex/3dsmax-sdk-mcp/releases/tag/v0.4.0-alpha.3) ([#7](https://github.com/nmalex/3dsmax-sdk-mcp/issues/7)) |
| Slots shipping | 22 — a slot for every registerable plugin type it targets; every one reports itself on load (see [docs/SLOTS.md](docs/SLOTS.md), [docs/SUPERCLASS_CENSUS.md](docs/SUPERCLASS_CENSUS.md)) |
| [`surface/`](surface/README.md) | works - all 5436 facade entries and every declared gap, enumerable from this checkout (`python surface/max_facade_surface.py --missing`), generated from the facade's own declaration and gated against drift |
| [LAW.md](LAW.md) / [ESSENTIALS.md](ESSENTIALS.md) | the binding rules and the practice - read both before writing a Cartridge |
| The `bootstrap` skill | works — interview, name claim, Slot, scaffold, verify |
| Cartridge panels | works — every slot whose plugin kind has a UI place builds your `describe_ui()` panel there, with the slot's About beside it; see the table in [docs/SLOTS.md](docs/SLOTS.md) |
| Declared parameters | works — `describe_params()` gives a Cartridge durable, animatable, scriptable parameters; see [docs/SLOTS.md](docs/SLOTS.md); the modifier and the manipulator (Tetra Dummy) keep them |
| Material-family slots | works — texture map, material, shader and sampler ship; a Python cartridge runs **managed** (returns data once, the slot evaluates it per sample), a native payload exporting `MaxMcpGetUnmanaged` runs **unmanaged** (called per sample, reads the sample through the facade's `ShadeSample*` entries); verified in 3ds Max 2026 with Scanline in both modes. Since alpha.7 the viewport follows animated parameters, including while the time slider is dragged, and the shader's Standard parameters are animatable. Known limit: the High Quality viewport draws a Standard material with the Cartridge Shader flat white (use the Standard preset). [`barebones/material_family_demo.py`](barebones/material_family_demo.py) builds a scene that tests all four — see [docs/SLOTS.md](docs/SLOTS.md#managed-and-unmanaged-per-sample-slots) |

Nothing in that table is written from how something is presumed to work.

## What is missing, and why

[ROADMAP.md](ROADMAP.md) has the list:

1. continuous integration
2. signed binaries
3. more 3ds Max versions
4. more kinds of plugin

along with the things that were considered and deliberately rejected. Nothing on that list is an
oversight.

[BACKLOG.md](BACKLOG.md) is the work in flight.
