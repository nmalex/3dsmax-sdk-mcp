# Barebones: Texmap Container

A **texmap container** — the super-class whose objects hold texmaps for another plugin (the normal-bump
and vector-displacement maps are built on it). **This example holds no maps** and would say hello the
first time the host asks it for its class name.

**A deferred type.** `TEXMAP_CONTAINER_CLASS_ID` is an internal super-class: a bare container has no
scriptable constructor and no standalone UI action that creates one, so — like the SDK's own normal-bump
container — nothing drives its `GetClassName` for a lone instance, and the greeting cannot be reached on
its own. The slot is built and **registers** (its `.dlo` is in a live host's loaded-plugin list); it is
kept as a starting point for when a host plugin constructs one. See `docs/acceptance/intended-types.json`
(`disposition: deferred`) for the full reasoning.

## What plugin type this is

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `TEXMAP_CONTAINER_CLASS_ID` | `TexmapContainer : ReferenceTarget` | a holder of texmaps | log on class-name query (unreachable alone) | **this example** (**Cartridge Texmap Container**, internal name `Cartridge_TexContainer`, `.dlo`) |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_texcontainer.py`](python/slot_texcontainer.py) | `slot_texcontainer` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_texcontainer_native.dll` |
