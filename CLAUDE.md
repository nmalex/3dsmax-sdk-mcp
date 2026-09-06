# Working in this repository

This is the cartridge authoring kit for 3ds Max. A **cartridge** is a payload you write; a **slot**
is a pre-compiled plugin that ships with the release and hosts it. You never build a slot, and
nothing here needs the 3ds Max SDK.

Three verbs, and they mean different things:

| | |
| --- | --- |
| **install** | once per machine — find 3ds Max, check prerequisites, place the plugin, verify it answers |
| **bootstrap** | once per cartridge — a named cartridge in a slot, with a panel and a Hello World button |
| **author** | the loop after that — edit the payload, refresh, see it. No restart |

## Rules that are not negotiable

These protect the user's machine and their work. Each one exists because breaking it cannot be
undone by a later command.

- **Never write into the 3ds Max install root.** Everything installs per-user. Nothing here needs
  elevation, and anything that seems to is a bug, not a reason to elevate.
- **Never start, restart or kill 3ds Max on your own initiative.** Attaching to a host the user
  started is fine; deciding one should exist is not. Ask.
- **Never open, merge, import or save a scene** unless the user asked for that specific file in that
  message. Reading a file to analyse it is always fine.
- **Never run an elevated installer on the user's behalf.** Prerequisite remedies are printed as
  commands for the user to run. Show the command; wait for a yes.
- **Never push, and never open a pull request, without being asked in that message.** Committing
  locally is fine. See [CONTRIBUTING.md](CONTRIBUTING.md) for branch and PR rules — they bind
  everyone.
- **Never delete a cartridge's source.** Removing a deployed copy is not deleting someone's code.

## How to run things here

**Run the `.ps1`, never the `.cmd`.** Every tool comes in two forms:

- `<name>.ps1` — for you. JSON on stdout, meaningful exit codes, no prompts.
- `<name>.cmd` — for a person. Opens a console and **blocks on `pause`**. If you run it, you hang.

To open one for the user without waiting: `start "" "tools\<name>.cmd"`.

**Version-specific tools live in `tools/<year>/`.** Those folders are complete, duplicated scripts,
not wrappers — see CONTRIBUTING for why that duplication is deliberate. A year with no folder is a
3ds Max release this kit has no binary for; say so and point at [ROADMAP.md](ROADMAP.md) rather than
substituting another year's script.

`tools/find-max.ps1` and `tools/list-plugins.ps1` are version-agnostic by design — the first reports
*every* install including unsupported ones, the second takes an install root.

## What the tools are

```
tools/find-max.ps1               every installed 3ds Max, as JSON
tools/list-plugins.ps1           every installed plugin module, from the directories Max searches
tools/claim-cartridge-name.ps1   is a proposed name taken, confusable, or poor style
tools/new-cartridge.ps1          scaffold a cartridge into a slot and deploy it
tools/<year>/check-prereqs.ps1   readiness rows, each with a remedy
tools/<year>/install-plugin.ps1  fetch, verify, place
tools/<year>/uninstall-plugin.ps1
```

## Before you create or change a cartridge

**Read [docs/CARTRIDGE_PR.md](docs/CARTRIDGE_PR.md).** It is a checklist and it is enforced by
`tools/check-cartridges.ps1` on every pull request, so a skipped step is a red build rather than a
review comment. Three things it will not let you forget:

- every cartridge is announced in `cartridges/README.md` — one that is not listed does not exist;
- every change to a cartridge bumps its version, in `cartridge.json` **and** in that table;
- `requires` records the 3ds Max releases and plugin version it was actually run against.

Run the check before you say you are done:

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\check-cartridges.ps1 -Since main -Human
```

## Things that are true and easy to get wrong

- **A new or newly-occupied slot needs a 3ds Max restart.** Classes register once, during the
  startup scan; the host offers no supported way to add one to a running session. Editing an
  existing cartridge's payload needs no restart — that is the fast loop.
- **The Modifier List entry carries the slot's name, not the cartridge's.** See
  [docs/SLOTS.md](docs/SLOTS.md); it is not a bug and it is being changed later.
- **A saved scene resolves by the slot's identity.** Replacing a slot's occupant means scenes saved
  with the previous one will evaluate the new one. Say this before replacing, not after.
- **A name check without the running host's class list is the weak answer**, and says so: the stock
  modifiers live inside shared modules, so a file inventory alone cannot see them.
- **`pause` in a `.cmd` is deliberate.** A window that closes takes the remedy with it, and the run
  that most needs reading is the one that failed.

## Reporting

Prefer the tools' JSON over re-deriving anything. When a tool refuses, relay its remedy verbatim —
the code that found the problem is the code that knows the fix, and paraphrasing loses the command.
