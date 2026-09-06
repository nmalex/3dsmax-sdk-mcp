# Cartridges

**Every cartridge in this repository is listed here. A cartridge that is not listed does not exist.**

This is a shared, crowdsourced library: the person who reads this table is not the person who wrote
the entry. They need to know, before they spend an afternoon on it, whether a cartridge can run on
their machine and who to ask when it does not. A directory name alone answers neither.

Adding a row is part of adding a cartridge, not a follow-up —
[`tools/check-cartridges.ps1`](../tools/check-cartridges.ps1) refuses a cartridge with no row and a
row with no cartridge, and it runs on every pull request.

## The library

| Cartridge | Version | What it does | Slot | 3ds Max | Plugin | Author | Updated |
| --- | --- | --- | --- | --- | --- | --- | --- |
| *(none yet)* | | | | | | | |

## Every pull request bumps the version. This is not optional.

**A pull request that changes a cartridge and leaves its version alone is refused.** Both places
move together: `version` in that cartridge's `cartridge.json`, and the **Version** column in the
table above.

Why it is a rule rather than good practice: this library is downloaded by people who are not
watching its commits. A version is the only thing that lets them say *"I have 0.2.0 and it does the
wrong thing"* and lets you answer without an interview. Two different files both calling themselves
`0.1.0` is a bug report nobody can act on, and by the time that hurts, the history that would have
explained it is months deep.

`MAJOR.MINOR.PATCH`, and use the parts:

| Change | Bump |
| --- | --- |
| a fix, no change to what a caller sees | PATCH |
| new behaviour, existing scenes keep working | MINOR |
| existing scenes behave differently, or a parameter changed meaning | MAJOR |

**A scene saved with your cartridge is somebody's work.** That is what makes the third row a MAJOR
rather than a judgement call.

## How to add your row

One line, in the same shape, in alphabetical order:

```
| [Cool Bend](cool-bend/) | 0.1.0 | Bends geometry along an axis, with a falloff | modifier | 2026 | 0.5.0 | @yourhandle | 2026-09-06 |
```

| Column | What goes in it |
| --- | --- |
| **Cartridge** | its name, linked to its directory |
| **Version** | the cartridge's own version — **the same string as in its `cartridge.json`** |
| **What it does** | one line, in plain words. Not "a modifier cartridge" — what it does *to a scene* |
| **Slot** | which slot it occupies |
| **3ds Max** | the releases you actually ran it in. Not the ones you expect it to work in |
| **Plugin** | the plugin version you verified it against |
| **Author** | how to reach you — a handle is enough |
| **Updated** | the date of this change, `YYYY-MM-DD` — it moves with every version bump |

**The version columns record what was tested.** They match `requires` in the cartridge's own
`cartridge.json`, and they are the two things a stranger checks first. A hopeful claim here costs
somebody else an afternoon and comes back as a bug report against a cartridge that was never broken.

**Widen a claim only after running it.** If you run an existing cartridge on a release it does not
list, that is a genuinely useful pull request: one row, one line of evidence in the description.
