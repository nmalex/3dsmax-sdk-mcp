# Slots

A **Slot** is a pre-compiled 3ds Max plugin that ships with the release and hosts your payload.
You never build one; you occupy one.

That is the whole reason this kit needs no 3ds Max SDK, no C++ toolchain for a Python payload, and
no compiler to produce a working plugin.

## One Slot per plugin type

| Slot | Module | What 3ds Max sees | Where it appears |
| --- | --- | --- | --- |
| `modifier` | `ModifierSlot.dlm` | an object-space modifier | the Modifier List |
| `exporter` | `ExporterSlot.dle` | a scene exporter | File ▸ Export, "Save as type" |

**These two are what you can build a Cartridge for. That is the whole list, and it is not a
policy.** Each Slot is a compiled 3ds Max plugin of one specific kind, so the set is exactly the set
that has been built — not a subset someone chose to permit. A utility Slot and an importer Slot are
the expected third and fourth, and neither exists yet.

**The module column is the check, and you can run it.** The release asset stages one file per Slot
into `Contents\Bin`, so `tools\list-plugins.ps1` against your install answers this table from your
own disk rather than from this page. If they ever disagree, the disk is right and this is a bug
worth [reporting](../README.md#reporting-a-bug) — a document that lists a Slot nobody built sends
you looking for a bug in your payload.

3ds Max can be extended in far more ways than these:

1. geometry objects
2. helpers
3. shapes
4. lights and cameras
5. materials and texmaps
6. controllers

None of them is available as a Cartridge today, and asking for one is a reasonable thing to do:
[ROADMAP.md](../ROADMAP.md) is where they are tracked, and what people ask for is what moves.

**Authoring a new *kind* of Slot yourself is a separate thing** with a different prerequisite — it
needs the 3ds Max SDK, because a Slot derives from SDK classes the host calls into directly. That
path is on the roadmap and is not open yet. Writing Cartridges for the three above needs none of it.

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

| Function | `modifier` | `exporter` | When it is called |
| --- | --- | --- | --- |
| `describe_ui(params)` | yes | yes | modifier: opening the command panel, and on every Refresh. Exporter: opening the export options dialog |
| `on_ui_event(control_id, value, ctrl, shift, alt, settled, params)` | yes | **no** | modifier only, when a control on your panel changed. The exporter never calls it — see below |
| `deform(points, box, tm, params)` | yes | — | every evaluation of the modifier stack |
| `format_header` / `format_node` / `format_group_open` / `format_group_close` / `format_material_list` | — | yes | once per export, per node, per group, per scene |
| `declare_callbacks()` | yes | **no** | modifier only, on load and on every Refresh — how a payload subscribes to host notifications |

**Absent is a legal answer to all of them.** A Slot that asks for `describe_ui` and finds none does
not fault; it concludes you want no panel. That is deliberate, and it is why a *missing* function
and a *misspelled* one behave identically — check the spelling before you check anything else.

**`max_cartridge_refresh` names the exports it actually found.** Call it and read the list: a
function you wrote that is not in it never made it into the module, and a function that is in it but
never runs is not being asked for. Those are two different bugs and this is what separates them.

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
