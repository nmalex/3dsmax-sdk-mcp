# Contributing

**These rules bind everyone who commits here, the maintainer included.** A rule the owner is
exempt from is not a rule — it is a preference other people are asked to observe, and the first
time it is inconvenient it stops existing. There is no exception for "just this once", for a
one-line fix, or for the person who created the repository.

They are written here rather than remembered so that a contributor, the maintainer and an agent
driving this repository all read the same text.

**Make the machine enforce it.** Habit is not a mechanism: turn on branch protection for `main`
(require a pull request, block direct pushes, block force-pushes). Then the rule below is not
something anyone has to keep choosing.

## Branches

```
<type>/<slug>
```

- **`<type>`** is one of `feat`, `fix`, `docs`, `chore`, `refactor`, `ci` — the Conventional
  Commits vocabulary, so a branch name, a PR title and a changelog line all speak one language.
- **`<slug>`** is kebab-case, two to four words, naming **what the branch delivers** — never how it
  works, never who is writing it, never when.

Good: `feat/install-and-bootstrap`, `fix/port-owner-report`, `docs/quickstart`.
Not: `first-release` (an event, not a deliverable), `nmalex-wip`, `v0.5`, `bugfix2`.

**A version is never a branch name.** Version identity lives in annotated tags `vX.Y.Z`, and a tag
never moves — SemVer's own rule, which is why a released version's contents cannot be edited and
any change is a new version.

There are exactly two long-lived branches:

| | |
| --- | --- |
| **`main`** | always releasable. Advanced **only** by a merged pull request — never by a direct commit, including the first one. |
| **`release/X.Y`** | cut **only** when a shipped line needs a fix after `main` has moved on. Never cut in advance, and never as a staging area. |

Four rules that keep this from rotting:

1. **A branch does one thing.** A second purpose is a second branch.
2. **A branch is deleted when its PR merges.** A stale branch is a claim that work is in flight.
3. **PRs squash-merge**, so `main` reads as one commit per delivered thing and a tag has something
   meaningful to point at.
4. **No internal issue ids in branch names.** An id nobody who forked this repository can resolve
   is noise in the one place everybody reads.

## One folder per 3ds Max release, and the duplication is deliberate

Version-dependent scripts live in `tools/<year>/` — a **complete** script per release, not a thin
wrapper over a shared implementation.

**Do not refactor these into one script that branches on the version.** The duplication is the
design. What differs between 3ds Max releases is which MSVC toolset the SDK pins, which series range
the bundle declares, and which asset carries the binaries — and those differences are *almost* the
same, release to release. "Almost" is where the surprises live. A shared script with a wrong branch
does not fail loudly: it reports a machine as ready to build a binary that 3ds Max will silently
refuse to load, and the failure surfaces hours later somewhere else entirely.

Two copies that drift on purpose beat one copy that is subtly wrong for every release but the one it
was written against. Adding a release is copying a folder and correcting its facts.

**The folder name is which 3ds Max you are running.** A release this kit has never been tested
against has no folder, and that absence *is* the support statement — see `ROADMAP.md`. Each script
also prints its target release, because a file copied out of its folder loses the only other clue.

Scripts that legitimately span every release — `find-max.ps1`, which exists to report *all* of them
including unsupported ones, and `list-plugins.ps1`, which takes an install root — stay in `tools/`
and are never suffixed. Suffixing those would contradict what they are for.

## Scripts, and the console rule

Every script here comes in two forms, and the split is deliberate:

- **`<name>.ps1`** — for an agent. JSON on stdout, meaningful exit codes, no prompts, no pauses.
- **`<name>.cmd`** — for a person. Opens a visible console, prints the human-readable form, and
  **pauses at the end, always** — on success and on failure alike.

**Everything a script does must be visible in that console, and the console must never close on its
own.** Not a summary at the end: every action as it happens — what is being downloaded and from
where, the checksum being verified, each file written, each refusal and its reason. A window that
closes takes the remedy with it, and the run that most needs reading is the one that failed.

An agent never runs the `.cmd` — it would block on `pause`. To open one for a user without waiting:
`start "" "tools\<name>.cmd"`.

## Contributing a cartridge

`cartridges/` is a shared, crowdsourced library — the person who reads an entry is not the person
who wrote it. So a cartridge is held to a shape, and the shape is enforced rather than requested:
[`tools/check-cartridges.ps1`](tools/check-cartridges.ps1) runs on every pull request.

**[docs/CARTRIDGE_PR.md](docs/CARTRIDGE_PR.md) is the checklist. Read it before creating or changing
a cartridge.** The three rules it exists to make unmissable:

1. **Every cartridge is announced in [`cartridges/README.md`](cartridges/README.md).** A cartridge
   that is not listed does not exist.
2. **Every pull request that changes a cartridge bumps its version** — in `cartridge.json` *and* in
   the table. Not optional. Two different files both calling themselves `0.1.0` is a bug report
   nobody can act on.
3. **`requires` records what you ran it against**, not what you expect to work. A hopeful claim
   costs a stranger an afternoon and returns as a bug against something that was never broken.

## Commits

Conventional Commits for the subject line: `type(scope): what changed`, imperative, no trailing
period. The body says **why**, because the diff already says what — and a reader six months out
needs the reason, which the diff cannot carry.

## Pull requests

One PR per branch, its title in the same Conventional Commits form, its body explaining the change
and how it was verified. **"Verified" means it was run**, not that it compiled — this project's
whole discipline is that a green build is not evidence of behaviour.

## Releasing

1. Work lands on `main` by PR.
2. `main` passes the acceptance run — a clean clone, install, bootstrap, and a Hello World cartridge
   visible in 3ds Max.
3. The release commit drops the `-dev` pre-release marker, the changelog heading is finalised, and
   an annotated tag `vX.Y.Z` is placed on that commit. **The tag is the promotion.**
4. The next commit restores `-dev` on the way to the next version.

A fix to a released line, once `main` has moved on: cut `release/X.Y` from the tag, branch
`fix/<slug>` off it, PR into it, tag `vX.Y.(Z+1)`. **A sealed release is never edited.**
