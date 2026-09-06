# Roadmap

**What this project does not have yet, and whether that is a plan or a decision.**

A young repository is missing things. The useful question is never *"is it missing?"* but *"does
the maintainer know, and is it deliberate?"* — so everything below is stated outright rather than
discovered. If something you need is in **Later**, say so in an issue: what people ask for moves.

Status vocabulary, and it is short on purpose:

| | |
| --- | --- |
| **Now** | being built on a branch right now |
| **Next** | committed to, and next in line |
| **Later** | wanted, not scheduled, and not forgotten |
| **Decided against** | considered in full and rejected. These will not happen; the reason is given |

---

## Now

- **The install path.** `find-max.ps1` and `check-prereqs.ps1` are in. `install-plugin.ps1`,
  the endpoint probe, and the agent-facing `install` skill are being written.
- **The bootstrap path.** One command that produces a named cartridge with an About rollout and a
  Hello World button, deployed and visible in a running 3ds Max.
- **The first release.** No tag exists yet. Until one does there is no binary to install, which is
  the honest reason the install path cannot be run end to end today.

## Next

- **Continuous integration.** There is none today. When it lands it will run PowerShell static
  analysis over `tools/`, build the example native payload, and check that every link in the
  documentation resolves.

  **What CI here can never do, and no badge will ever claim:** it cannot build the slot binaries —
  that needs the 3ds Max SDK, which is licensed and cannot live on a public runner — and it cannot
  test against a running 3ds Max, because there is no headless 3ds Max on a hosted runner. Those
  are verified by a human on a machine that has both, and the release notes say when it was last
  done. A project that quietly let a green badge imply otherwise would be lying in the one place
  people look for reassurance.

- **Tests for a payload.** A payload is ordinary code with no 3ds Max in it — that is the whole
  point of the design — so it is testable without the host. The harness for that is not published
  yet.

- **The published code-review rules.** The standard a cartridge is held to already exists as
  documents; they ship beside the binary and are not in this repository yet.

- **Signed binaries.** Releases are unsigned today and Windows SmartScreen will say so. Every
  release publishes its asset's SHA-256 and the installer verifies the download against it, which
  is a real check and not a substitute for a signature. A certificate is wanted.

## Later

- **More 3ds Max versions.** 2026 only today. Each version needs its own binary, and shipping one
  installer that serves all of them is a packaging job that has not been done.
- **An MSI installer**, so installation is a download-and-run rather than a script.
- **More kinds of plugin.** A cartridge can be a modifier, a utility or an exporter. The list of
  what 3ds Max can be extended with is far longer — geometry objects, helpers, shapes, lights,
  cameras and more — and each needs a slot binary of its own.

- **Authoring a new *kind* of slot yourself.** Today the plugin types you can build cartridges for
  are the ones we ship slots for, so a new type is our work and you wait for it. The intended answer
  is a **slot library** — a binary and its headers, shipped like everything else here — against
  which a third party writes a new slot flavour without our sources.

  **One thing it will never remove:** a slot is a real 3ds Max plugin, deriving from SDK classes the
  host calls into directly, so writing one needs the **3ds Max SDK installed**. That is a different
  audience from a payload author, who needs none of it. The "no SDK" promise on this page is about
  writing cartridges, and it stays true for that.

  Everything else will be here: the slot headers, the slot library as a binary, and a template for
  the part you write — the class derived from the SDK's own `Modifier` / `UtilityObj` / exporter and
  its descriptor. That part is boilerplate the SDK's own samples already show; the machinery behind
  it is the binary you link and never read.
- **A published payload test harness**, so a cartridge's behaviour can be pinned without 3ds Max.

## Decided against

- **Telemetry, usage analytics, or any phone-home.** Considered in full and rejected. This plugin
  does not count launches, report sessions, or send anything anywhere. Adoption is read from stars,
  forks, contributions and bug reports — signals that cost their sender an action and mean
  something as a result.
- **Publishing the server and slot sources.** The GUP and the slots are delivered as binaries. What
  is published is everything needed to author a payload against them: the contract headers, the
  building blocks, the documents and worked examples. This is not a gap being closed later.
- **Anything that writes into the 3ds Max install root.** Installation is per-user and reversible
  by deleting one directory. Not a limitation — a rule.
- **Linux or macOS.** 3ds Max is Windows-only.

---

## How this list is kept

This is the public roadmap and it is the only forward-looking list this repository has. It is
deliberately coarse: no dates, no estimates, no burndown. An item moves when it moves, and the
release notes say what actually shipped.
