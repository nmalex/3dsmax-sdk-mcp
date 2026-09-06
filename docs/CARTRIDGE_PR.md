# Opening a cartridge pull request

**Read this before creating or changing a cartridge.** It is a checklist, not an essay — do the
things in order. Every item is enforced by
[`tools/check-cartridges.ps1`](../tools/check-cartridges.ps1), which runs on every pull request, so
a skipped step is a red build rather than a comment.

> This document evolves. The check is the authority on what is currently enforced; when the two
> disagree, the check is right and this page is stale — say so.

## Always, before anything else

- [ ] **Work on a branch.** `<type>/<slug>` — see [CONTRIBUTING.md](../CONTRIBUTING.md). Never commit
      to `main`.
- [ ] **Install the plugin first.** A cartridge scaffolded before installing records
      `"plugin": "unknown"`, and the check refuses that. It is fine to experiment; it is not fine to
      contribute.

## Creating a new cartridge

- [ ] **Scaffold it, do not hand-write it.**
      `tools\new-cartridge.ps1 -Name "<name>" -Flavour <slot>` produces the shape the check expects.
- [ ] **Claim the name against the running host's class list.** Not the module inventory alone —
      that cannot see stock modifiers, so "Bending" passes beside "Bend". If you could not get the
      class list, say so in the pull request instead of implying a pass.
- [ ] **Check no cartridge here already has that name.** The check compares case- and
      punctuation-insensitively, because "Poly Count" and "polycount" are one name to a reader.
- [ ] **Write `README.md` in the cartridge's directory.** What it does and why it exists. A heading
      alone is refused.
- [ ] **Add a row to [`cartridges/README.md`](../cartridges/README.md)**, alphabetically.
- [ ] **Record what you actually ran it against** in `requires` — the 3ds Max releases and the plugin
      version. Not what you expect to work. A hopeful claim costs a stranger an afternoon and comes
      back as a bug report against something that was never broken.

## Updating an existing cartridge

- [ ] **Bump `version` in its `cartridge.json`. This is not optional.** PATCH for a fix, MINOR for
      new behaviour that leaves existing scenes working, MAJOR when a saved scene would behave
      differently. A scene saved with a cartridge is somebody's work — that is what makes the last
      one a rule rather than a judgement call.
- [ ] **Update the Version column in `cartridges/README.md` to the same string.** The two disagreeing
      means one of them is lying to somebody: a reader trusts the table, a tool trusts the manifest.
- [ ] **Update the Updated column** to today.
- [ ] **Widen `requires` only if you ran it there.** Adding a release you tested is a good pull
      request on its own; adding one you assume is a defect.

## Never

- [ ] **Never commit build output** — no `.dll`, `.lib`, `.obj`, `.pdb`, no `out/`, no `__pycache__`.
      Refused, and it lands in every fork's history permanently.
- [ ] **Never put an absolute path in `cartridge.json`.** It works on exactly one machine.
- [ ] **Never rename a cartridge's directory without renaming its `slug`**, and vice versa. Two names
      for one thing means tools disagree about which is real.
- [ ] **Never change someone else's cartridge's version to fix a merge.** Rebase and bump yours.

## Before you open it

- [ ] **Run the check.** It is the same one CI runs:

```bash
powershell -NoProfile -ExecutionPolicy Bypass -File tools\check-cartridges.ps1 -Since main -Human
```

- [ ] **Say what you ran it in.** The pull request description names the 3ds Max release and plugin
      version you tested on — the same two facts the row claims. "Verified" means it was run, not
      that it compiled.
- [ ] **One cartridge per pull request.** A branch does one thing.

## What the reviewer is checking

Not style. Three things:

1. **Does the claim match the evidence** — do `requires`, the table row and the description agree.
2. **Is it legible to a stranger** — the README says what it does, the name says what it is.
3. **Did the version move**, and by the right amount for what changed.
