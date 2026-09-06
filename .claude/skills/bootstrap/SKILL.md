---
name: bootstrap
description: Create a new cartridge from scratch - work out what the user wants to build, which kind of 3ds Max plugin can host it, agree a good name, put it in a slot, deploy it, and verify it works in the running host. Use when the user wants to make a plugin, start a cartridge, add a modifier or utility or exporter, or says they have an idea for 3ds Max.
---

# Bootstrap

From "I want 3ds Max to do X" to a working plugin the user can click, in one sitting.

**This is a conversation before it is a command.** The scaffolder takes one line to run; the
decisions in front of it — what kind of plugin, what it is called — are the ones that are expensive
to change later. Do not skip to step 5.

## Before you start

The plugin must be installed and the host running. If it is not, run the `install` skill first —
without a running host the name check falls back to its weak answer, and you cannot verify anything
at the end.

## 1. Ask what they want to build, in their words

Ask first. **Do not open with a menu of plugin types** — the menu is derived from their answer, and
leading with it makes people pick the first plausible row instead of describing what they want.

Then map what they said onto what a slot can host:

| They describe | Slot | Where it shows up |
| --- | --- | --- |
| changing geometry as the object evaluates — bend, twist, smooth, displace | `modifier` | the Modifier List |
| a panel that inspects or acts on the scene — count, report, batch-rename | `utility` | the Utilities rollout |
| writing the scene out in their own format | `exporter` | File ▸ Export, "Save as type" |

**Say the mapping back and check it.** "That sounds like a modifier — it changes the mesh as the
stack evaluates. Does that match what you pictured?" People describe outcomes; the slot is a
mechanism, and the two do not always line up the way you assume.

**If it fits nothing above, say so plainly and name what is missing.** Geometry objects, helpers,
shapes, lights, cameras and materials are not available yet — each needs a slot of its own. Point at
`ROADMAP.md`. An honest "not yet, and here is where it is tracked" is a better answer than bending
their idea into a modifier because a modifier is what exists.

## 2. Choose the lane

**Default to Python.** It compiles nothing, needs no toolchain, and has the faster loop. Suggest a
native payload only when the user has a reason — a hot inner loop over a large mesh — and never as
the starting point.

Do not raise the C++ toolchain prerequisite at all if the answer is Python.

## 3. Agree the name — consult, do not decide

**Get the authoritative list first.** Ask the running server for what 3ds Max has registered —
`modifierPlugin.classes` and its siblings for the other kinds — and write the names to a JSON array.
Ask the server what it offers rather than assuming a tool name; the live capability answer is the
authority.

Then:

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\claim-cartridge-name.ps1 `
    -Name "<proposed>" -Flavour <slot> -ClassesJson <file> -Human
```

**Without that list the check is the weak answer and says so.** A file inventory cannot see the
stock modifiers — they live inside shared modules, so nothing on disk is called `bend` — and
"Bending" beside "Bend" sails through. If you could not get the class list, tell the user the check
was partial. Do not present it as a pass.

What to do with each verdict:

| Verdict | What it means | What you do |
| --- | --- | --- |
| `clear` | nothing collides, nothing reads as a near-duplicate | go |
| `confusable` | works, but a person could not tell it apart — "Bending" beside "Bend" | **put it to the user.** Their call, not yours. `-Force` records that they decided |
| `conflict` | exact or mangled collision | **do not ship it.** Offer the lane-suffix convention the tool prints |

**Style findings are advice and never a blocker.** They are measured against the host's own names —
short and revealing is what stock plugins look like — but a longer name that is genuinely clearer
wins, and the tool says so itself.

**Explain why the name matters even though the list will show the slot's name.** The Modifier List
entry carries the slot's compiled name for now (`docs/SLOTS.md`). The name being agreed here is what
the cartridge is *called* — in its About rollout, in its record, and when it is sealed into a plugin
of its own. That is the moment a collision becomes permanent and public, which is why it is worth
five minutes now.

## 4. Check the slot is free — and if it is not, this is a real decision

One slot per plugin type, one cartridge per slot. If the slot is occupied, the scaffolder refuses
and names the occupant. **Do not add `-Replace` on your own initiative.** Put it to the user with
the consequence stated:

> A saved scene resolves by the *slot's* identity, not by the cartridge in it. Any test scene saved
> while `<occupant>` was in this slot will evaluate `<new>` instead once you replace it. The
> occupant's source is not touched — it stays in `cartridges/<slug>`.

## 5. Create it — one step

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\new-cartridge.ps1 `
    -Name "<agreed>" -Flavour <slot> -ClassesJson <file> -Human
```

It runs the name claim again itself, scaffolds the source into `cartridges/<slug>/`, deploys the
payload into the slot, and records what went where. Exit `3` means that kind or that lane has no
template yet — that is a real answer, not something to work around.

## 6. Restart 3ds Max — and ask

**Do not restart it yourself.** Classes register once during the host's startup scan, so the entry
does not appear until 3ds Max restarts. Say that plainly, say why, and wait.

This is the one seam in "one step". It is not hidden and should not be apologised for — it is a
property of how the host loads plugins.

## 7. Verify in the host, not in the log

Walk the user to it: find the slot's entry, apply it, click **Hello World**.

**When that line appears, six things have just been proven at once** — worth telling them, because it
reframes an inert scaffold as the milestone it is:

```
the slot registered            ->  the plugin loaded and the host knows the class
the payload was found          ->  the deployed file is where the slot looks
the interpreter loaded it      ->  the panel was built from your code
a real control was clicked     ->  the event crossed back into the payload
the log line arrived           ->  the display channel works end to end
```

Everything after this is editing a system already known to be connected. That is worth far more than
a scaffold that does something clever and leaves them guessing which half is broken.

**If nothing appears**, do not start changing the payload. In order: did the host actually restart;
does the deployed file exist where the record says; is this the right slot's entry. A payload problem
and a registration problem look identical from the Modifier List, and only one of them is fixed by
editing code.

## 8. If this is going to be contributed, say what that costs now

`cartridges/` is a shared library. If the user intends to open a pull request — now or later — tell
them the three obligations before they are attached to the work, not after:

- the cartridge is **announced** in `cartridges/README.md`, or it does not exist;
- every pull request that touches it **bumps its version**, in two places;
- `requires` states the 3ds Max release and plugin version it was **actually run against**.

[docs/CARTRIDGE_PR.md](../../../docs/CARTRIDGE_PR.md) is the checklist, and
`tools/check-cartridges.ps1` enforces it. A cartridge scaffolded before the plugin was installed
carries `"plugin": "unknown"` and the check refuses it — fine while experimenting, and something to
fix before contributing.

## 9. Hand over the loop

Tell them the fast loop before they go looking for it: **edit the payload, refresh, see it — no
restart.** The restart was for registering the class, and that is done. Point at the payload file by
path, and at `describe()` as the place to say what this cartridge is so the About rollout can report
it.

## Done when

- [ ] the user described what they wanted, and the slot was agreed rather than assumed
- [ ] the name was checked against the running host's class list, or the user was told it was not
- [ ] a `confusable` verdict was put to the user, not decided for them
- [ ] the cartridge is in a slot, and any replacement was the user's call
- [ ] 3ds Max was restarted **by the user**
- [ ] the entry was found, applied, and Hello World appeared
- [ ] they know where the payload is and that editing it needs no restart

If Hello World did not appear, say which step it stopped at. A cartridge reported as working because
the files are in the right place is exactly the claim this last step exists to replace.
