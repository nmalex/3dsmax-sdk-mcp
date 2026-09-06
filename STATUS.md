# Status

`0.4.0-alpha.2`.

**Alpha means what it says.** This has been exercised on exactly one machine, and things will change. Every public build from here bumps the alpha
counter, so no two are ever the same version.

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
| The release asset it installs | `0.4.0-alpha.2` — the modifier Slot renders its Cartridge's panel ([#2](https://github.com/nmalex/3dsmax-sdk-mcp/issues/2)) |
| The `bootstrap` skill | works — interview, name claim, Slot, scaffold, verify |
| Declared parameters | **not in a release yet** — `describe_params()` lands in `0.4.0-alpha.3` ([#7](https://github.com/nmalex/3dsmax-sdk-mcp/issues/7)); the kit's template and [docs/SLOTS.md](docs/SLOTS.md) already teach it |

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
