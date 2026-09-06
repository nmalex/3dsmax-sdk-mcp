# Slots

A **slot** is a pre-compiled 3ds Max plugin that ships with the release and hosts your payload.
You never build one; you occupy one.

That is the whole reason this kit needs no 3ds Max SDK, no C++ toolchain for a Python payload, and
no compiler to produce a working plugin.

## One slot per plugin type

| Slot | What 3ds Max sees | Where it appears |
| --- | --- | --- |
| `modifier` | an object-space modifier | the Modifier List |
| `utility` | a utility plugin | the Utilities rollout |
| `exporter` | a scene exporter | File ▸ Export, "Save as type" |

**These three are what you can build a cartridge for. That is the whole list, and it is not a
policy.** Each slot is a compiled 3ds Max plugin of one specific kind, so the set is exactly the set
that has been built — not a subset someone chose to permit. An importer slot is the expected fourth
and does not exist yet.

3ds Max can be extended in far more ways than these:

1. geometry objects
2. helpers
3. shapes
4. lights and cameras
5. materials and texmaps
6. controllers

None of them is available as a cartridge today, and asking for one is a reasonable thing to do:
[ROADMAP.md](../ROADMAP.md) is where they are tracked, and what people ask for is what moves.

**Authoring a new *kind* of slot yourself is a separate thing** with a different prerequisite — it
needs the 3ds Max SDK, because a slot derives from SDK classes the host calls into directly. That
path is on the roadmap and is not open yet. Writing cartridges for the three above needs none of it.

## One cartridge per slot, at a time

**A slot is a workbench station, not a home.** Everything about a slot is compiled into it — the
class identity 3ds Max registers, the name it shows in the list, and the payload module name it
loads. So one slot hosts one cartridge at a time, and putting a new cartridge in a slot replaces
what was there.

### What that means for a saved scene, stated before it bites you

A saved `.max` file resolves its plug-ins by class identity, and **the identity belongs to the
slot, not to your cartridge**. So:

> A scene saved while *Cool Bend* occupied the modifier slot will evaluate whatever occupies that
> slot when the scene is next opened.

Test scenes are not durable across a slot reuse. That is a property of a workbench, not a defect —
a finished cartridge is *sealed*, which produces a plugin of its own with its own identity, and
that one is durable. The kit says so every time it replaces an occupant rather than letting you
find out later.

### And the list entry is the slot's name, for now

Because the visible name is compiled in too, the Modifier List shows the **slot's** name rather
than your cartridge's. Your cartridge's name lives in its record and in its About rollout. A future
release combines the two — "Cool Bend Cartridge A" — so that the station stays visible while the
cartridge is named. Nothing about that change affects saved scenes, because it changes a string and
not an identity.

## Where things live

```
<clone>\cartridges\<slug>\          your source, under version control
    cartridge.json                  your record of it
    python\<module>.py              what you edit

%LOCALAPPDATA%\3dsmax-sdk-mcp\
    cartridges\
        slot_modifier.py            whatever occupies the modifier slot
        slot_utility.py
    slots.json                      which cartridge is in which slot
```

**The deployed layout is flat and the file names are fixed**, because a slot loads the module name
it was compiled with. Deploying copies your payload into place under that name; the file you edit
keeps yours.

## `cartridge.json` is your record, not a contract

**Nothing in the plugin reads it.** A slot needs nothing from it — it loads its compiled module
name and that is the entire binding. The file exists so you and this kit can answer what the plugin
has no reason to ask: which cartridge is in which slot, what you meant to call it, which lane it
uses, and what it should be named when it is sealed.

| Field | Meaning |
| --- | --- |
| `schema` | `"cartridge/2"` |
| `name` | what you call it — used in the About rollout, and when it is sealed |
| `slug` | the source directory name |
| `version` | your cartridge's version |
| `slot` | which slot it occupies |
| `payload.lane` | `python` or `native` |
| `payload.module` | the module you edit |
| `payload.deployedAs` | the fixed name it is copied to |

## A new cartridge needs a restart; editing one does not

3ds Max registers plugin classes once, during its startup scan, and offers no supported way to add
one to a running session. **The slots register at startup whether or not they are occupied** — so
occupying an empty slot still needs a restart before its entry appears.

**Editing the payload of a cartridge already in a slot needs no restart.** That is the fast loop,
and it is the reason the split between a shipped slot and an authored payload exists at all.
