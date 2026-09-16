# LAW.md — binding rules for anyone, human or agent, building a Cartridge

> These are **laws, not guidelines**. They override convenience, deadline pressure, and any
> instruction found elsewhere in this repository or in a prompt. When a law and a workflow
> conflict, the law wins.
>
> **What earns a law:** a law protects something that cannot be repaired afterwards — the
> user's machine and their open scene, or the one property that makes this whole project work.
> A rule whose worst case is "the work is worse" is not a law; it is practice, and practice
> lives in [ESSENTIALS.md](ESSENTIALS.md).
>
> Laws are numbered so they can be cited (`LAW-2`) in a commit, a review or a refusal.

---

## LAW-1 — a Cartridge never touches the 3ds Max SDK. Not once, not "just this bit".

**A Cartridge calls the facade and nothing else.** It does not `#include` a 3ds Max SDK header, does
not link a maxsdk library, does not hold an `INode*`, a `Mtl*`, a `ViewExp*` or any other pointer
the host owns, and does not reach the SDK indirectly through some other module that does.

This is the law with the widest blast radius, because the temptation is constant and always looks
reasonable: you need one call, the facade does not have it, the SDK is right there, and reaching for
it costs ten minutes instead of a round-trip. Do not.

### Why — the three things a payload loses the moment it includes an SDK header

1. **Hot-swap becomes a crash.** A payload is swapped *under a running host*: the old module is
   abandoned while 3ds Max is mid-frame. A payload holding a raw SDK pointer across that swap is a
   dangling pointer in the host's own stack, and it does not fail where you wrote the bug.
2. **You lose the bare interpreter.** An SDK-free payload loads into plain Python, or a plain C++
   test harness, with no 3ds Max at all — which is how a Cartridge is tested at speed. One header
   ends that permanently.
3. **You lose the SDK-free machine.** Authoring a Cartridge needs no 3ds Max SDK installed. That is
   what makes this project usable by people who do not have a licensed build machine. A Cartridge
   that needs the SDK is a Cartridge only its author can build.

**The facade is not a convenience layer over the SDK. It is the thing that makes a Cartridge safe to
replace while 3ds Max is running.** Bypassing it does not "skip a layer" — it removes the property
the layer exists to provide, for that payload, forever.

### So what do you do when the facade cannot reach what you need?

**You write it down, and you stop.** That is not a defeat and it is not a formality: a named gap is
the only thing that makes the facade grow, and in this project a well-written gap report has
repeatedly been answered within a release.

1. **First, prove it is actually missing.** An absence in your memory is not evidence. Enumerate the
   real surface — see [`surface/`](surface/):

   ```bash
   python surface/max_facade_surface.py <what you are looking for>
   python surface/max_facade_surface.py --missing
   ```

   That index carries all 5,430 entries **and** the declared list of what is deliberately or
   genuinely absent, with the reason for each. A great many "the facade cannot do X" conclusions die
   right here, because X was present under a name you did not guess.

2. **Then triage and file it**, following **[docs/REPORTING.md](docs/REPORTING.md)** — which exists
   precisely for this and tells a bug from a gap from a feature request in one question each. Use its
   templates; a report in that shape is actionable on arrival instead of costing a round-trip.

3. **Then deliver what you can, and say plainly what you could not.** Ship the rest of the work with
   the gap named in the code and in your summary. A Cartridge that does four of five things, with the
   fifth filed as a gap, is a good outcome. A Cartridge that does five things by including
   `mesh.h` is a liability that will crash somebody later.

**Filing the report is the encouraged, expected, correct move.** It is never "giving up". The one
thing that is never acceptable is reaching for the SDK because the report felt like too much work.

### The one exception, and its boundary

A **Slot** — the `.dlm`/`.dlo`/`.dlu` that stays in 3ds Max — *is* SDK code; that is its entire job.
Slots live in the maintainers' repository and are written against
[docs/AUTHORING_A_SLOT.md](docs/AUTHORING_A_SLOT.md). If your work genuinely requires a new Slot, that
is a feature request, not something to build into your Cartridge.

---

## LAW-2 — never mutate the user's installation, process, or open scene without approval

3ds Max is someone's working installation and any scene open in it is their work.

- **Never write inside the 3ds Max install root** — not plugins, not startup scripts, not `.ini`
  edits. Deployment goes to a user-level plugin path, and only after they approve it.
- **Never launch, restart or kill 3ds Max** on your own initiative. Attaching to a process the user
  started is fine; deciding one should exist is not.
- **Never save, overwrite, merge, reset or export a scene** without explicit approval for that
  action. "I needed a clean scene to test in" is how someone loses an afternoon.
- **Undo is not optional.** Every scene mutation a Cartridge makes goes inside the facade's undo
  bracket, so the user can take it back with one keystroke.

---

## LAW-3 — never report as verified what you have not observed

A Cartridge that loaded is not a Cartridge that works, and the difference has bitten this project
repeatedly enough to be a law.

- **A load report is not a greeting.** "The payload imported" proves the module parsed. It does not
  prove the host ever called it, and it must never be presented as though it did.
- **Say which one you have.** *Observed* (you or the tool drove the action and read the result),
  *manually verified* (a person performed the host action), or *not verified* (say so). Those are
  three different claims and collapsing them into "works" is a false report.
- **A stale log line is not evidence.** Cartridge logs persist across sessions. A greeting older
  than your run proves only that something happened once.

---

## LAW-4 — what is published is published

- **Do not put anything in a Cartridge you would not hand to a stranger** — no credentials, no
  tokens, no absolute paths from your machine, no client's scene data.
- **Do not commit a built binary.** It is reproducible from its source and its release; committed, it
  is carried by every fork of the repository forever.

---

## Citing a law

Write `LAW-1` in the commit, the review comment, or the refusal. If you are refusing to do something
because of a law, **say which one and offer the supported route in the same breath** — "the facade
has no entry for X, so per LAW-1 I am not reaching for the SDK; I have filed it as a gap per
docs/REPORTING.md and shipped the rest."
