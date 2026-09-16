# Examples

Showcase cartridges: what the slots can do when a cartridge does something real, beyond the
barebones' hello. Each one is a complete cartridge with its own README.

This directory used to be `templates/`, the sources `tools/new-cartridge.ps1` filled in. The
scaffolder now copies [`barebones/<slot>`](../barebones/README.md) instead, which covers every
shipping slot and is kept working release by release.

| Example | Slot | What it shows |
| --- | --- | --- |
| [soap-bubble](soap-bubble/) | `material` | a soap film computed per sample: thin-film interference over 16 wavelengths, in C++ (unmanaged) and a lighter Python look; renders in Scanline, with a demo scene script |
| [modifier](modifier/) | `modifier` | the former modifier scaffold: a panel and a Hello World button (placeholders, not runnable as is) |
| [exporter](exporter/) | `exporter` | the former exporter scaffold (placeholders, not runnable as is) |
