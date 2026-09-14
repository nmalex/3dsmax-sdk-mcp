# Reporting back: a bug, a gap, or a feature request

You are an agent (or a person) driving a Cartridge through this facade, and you have hit something.
This page exists so that what you send back is **actionable on arrival** — precise enough that the
maintainer, or an agent running the coverage program, can act on it without a round-trip asking you
what you meant.

There are exactly three things you can be holding, and they are handled by three different machines.
**Naming it wrong sends it to the wrong machine**, where it stalls. So the first job is triage, and
it takes one question each.

## Triage — which of the three is this?

Ask them in order and stop at the first "yes":

1. **Does a facade entry that already exists do the wrong thing?** It crashed, returned a wrong
   value, refused with the wrong code, or a write silently did nothing. → **[BUG](#a-bug).**
2. **Does the 3ds Max SDK expose a function you need, that the facade has no entry for?** The call
   plainly exists in the SDK headers; there is simply no wrapper for it yet. → **[GAP](#a-gap).**
3. **Do you want something the SDK does not hand you as one call** — a new kind of Slot or plugin, a
   new capability, a design change, "I am building X and need the facade to grow to fit it"? →
   **[FEATURE REQUEST](#a-feature-request).**

If you are unsure between a gap and a feature request, it is **almost always a gap** — a specific
missing wrapper is the common case, and a gap that turns out to need design is easy to promote. A
feature request that is really just one missing call wastes a triage cycle.

One line tells bug from gap: **a bug is a wrapper that lies; a gap is a wrapper that is absent.**

---

## A bug

### What a bug is here

The facade makes exactly one promise, and a bug is that promise broken. The promise:

- **A refusal is a named code, never a crash.** `no such node`, `wrong kind`, `too large` — the
  payload cannot hold or corrupt anything the host owns, so a fault comes back as a value.
- **A pass-through promises only that it made the call.** It reaches the object by the handle you
  gave, refuses cleanly if that handle is stale, makes the real SDK call, and hands back the result.

So a bug is one of: **a crash** (the one thing that must never happen); **a wrong value** returned
from a read; **a wrong or missing refusal** (it accepted a stale handle, or refused a valid one, or
returned the wrong code); or **a write that did not take** (the mutator returned success and nothing
changed).

### What is *not* a bug

- **The SDK did something surprising, and the facade faithfully passed it through.** A pass-through
  guarantees it *called* the SDK — not that the SDK's own behaviour matches your expectation. If the
  wrapper resolved the right object, forwarded your arguments unchanged, and returned what the SDK
  returned, the surprise is the SDK's, and this is not a facade bug. (If the wrapper resolved the
  *wrong* object, dropped an argument, or mistranslated a type — that *is* a bug.)
- **There is no entry for what you called.** That is a [gap](#a-gap), not a bug.

### What to send

Enough for someone to reproduce it without you:

- **The entry name**, exactly — from the published `include/MaxFacadeApi.Generated.inc` or
  `payload/mcp_facade.py`.
- **The exact call**: every argument value, and the handle you resolved it against.
- **Expected vs actual**: what you thought you would get, and what came back — the literal wrong
  value, or the refusal code, verbatim.
- **The server version**, as the running server reports it on the wire (it is read from the loaded
  binary, not from the source tree — so report what the *server* says, not what a file says).
- **The 3ds Max version** you are running against.
- **The smallest sequence** that shows it. A repro that needs your whole scene is a repro nobody will
  run.

The README's **Reporting a bug** section carries the full issue template (an agent can fill every
field), the privacy rules for what never goes in an issue, and the expected-vs-actual discipline —
use it for the specifics. File it as a **Bug** issue.

---

## A gap

**This is the common one** — the user's most frequent real feedback is "the SDK clearly has this
function, and the facade does not wrap it." The coverage program is built to consume exactly this,
*mechanically*, so a precise gap report is close to a work order.

### What a gap is

The 3ds Max SDK declares a callable function or method, and the facade has **no entry** that wraps
it, and you need it to write your Cartridge. Before you file, spend two minutes confirming both
halves — absent *and* needed:

1. **Confirm it is absent.** Search the published `include/MaxFacadeApi.Generated.inc` for a
   plausible name (the facade names are `Family` + `Method`, e.g. a `SplineShape` method
   `SetUIParam` becomes `SplineSetUIParam`). Then read [docs/SDK_COVERAGE.md](SDK_COVERAGE.md) — it
   is a system-by-system status of what is already reachable, written from what was *tested*, not
   presumed. Your thing may already be there under a name you did not guess.
2. **Confirm the SDK really exposes it** — that it is a public, callable method, not something the
   header only appears to offer.

### What to send — the SDK citation is the whole report

The one thing that turns a gap into a work order is a **precise SDK citation**:

- **The exact declaration**: the return type, the name, and the full parameter list, copied from the
  SDK header — e.g. `void SplineShape::DoChamfer()` or
  `void SplineShape::SetUIParam(splineUIParam uiCode, int val)`.
- **The header and line** it is declared in — e.g. `splshape.h:625`.
- **The class or interface** it is a member of.
- **One sentence on why you need it** — the Cartridge you are writing and the operation you cannot
  currently perform.

With that, the maintainer's map classifies the declaration and, if it is a clean case, an agent
writes and ships the wrapper. Vague gaps ("splines feel incomplete") cannot be actioned; a citation
can.

### Know this before you file: not every SDK declaration can be wrapped

A gap report is not a promise that the wrapper will be written — some SDK declarations are
**terminal**, and a good report survives learning that its target is one of them. The map will return
one of these verdicts, and none is a brush-off:

- **not-exported** — the method is declared `CoreExport` in the header but the SDK library does not
  actually export the symbol, so *nothing* can link a call to it. This is invisible in the header
  (the declaration looks exported); only the linker reveals it. `SplineShape::DoChamfer` is a real
  example — it looks perfectly wrappable and cannot be wrapped at all.
- **non-public** — the method is `protected` or `private`. Not callable from outside; not a gap that
  can be closed.
- **collision / overload / nested-enum / constructor / operator / too-many-arguments** — mechanically
  ineligible or needing a hand-authored, non-mechanical decision (the "advanced" tier). These may
  still be done, but not as a simple pass-through.

If your gap comes back with one of these, that *is* the answer — the SDK, not the facade, is the
limit. File it anyway: recording the verdict against the citation is how the map stops re-examining
the same declaration forever.

File it as a **Gap** issue.

---

## A feature request

### What a feature request is

You want the facade or the kit to **grow a capability**, beyond wrapping one existing SDK call:

- a **new Slot kind or plugin type** (you are writing a plugin kind the kit does not host yet — see
  [docs/PLUGIN_TYPES.md](PLUGIN_TYPES.md) and [docs/SLOTS.md](SLOTS.md) for what exists);
- a **new arena or design change** in how the facade projects the SDK;
- a goal stated as an outcome — *"I am building a Cartridge A for super-class B, and I need
  operations C and D that the SDK describes as `C0` and `D0`"* — which the maintainer will
  **decompose**: the C/D calls become [gaps](#a-gap), and any Slot or arena work around them is the
  feature.

### What to send

- **The goal**: what you are building, and what you cannot do today. Outcome first — not a guessed
  implementation.
- **The plugin kind / super-class** it concerns, if it is one.
- **The specific SDK functions it needs, if you know them** — each with the header/line citation from
  the [gap](#a-gap) section. Naming them up front lets the request be split into work immediately.
- **What "done" looks like** — the smallest thing that, if it worked, would close this.

### How it is handled

A feature request is triaged against the surface map, its missing endpoints are run through the
create-and-validate program, the result is built and tested, and — if it clears — shipped as a minor
version. A request that decomposes cleanly into gaps moves fast; one that needs a new plugin kind or
a design decision is a larger conversation, which is exactly why it is a feature request and not a
gap.

File it as a **Feature request** issue.

---

## In short

| You are holding | The test | Send, above all |
| --- | --- | --- |
| **Bug** | an existing entry lies | the entry name + a minimal repro + both versions |
| **Gap** | a wrapper is absent | the exact SDK declaration + `header:line` |
| **Feature request** | a capability is missing | the outcome you want + any SDK calls it needs |

A report that names the wrong one still gets read — but the fastest path is the right machine on the
first try.
