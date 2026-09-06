# 3ds Max SDK MCP

A 3ds Max plugin that serves a local [Model Context Protocol](https://modelcontextprotocol.io/)
server from inside a running 3ds Max — and the kit for building **cartridges**: your own 3ds Max
plugins, written as a payload and hosted by a slot that ships as a binary.

## Fork it, don't clone it

[**Fork this repository**](https://github.com/nmalex/3dsmax-sdk-mcp/fork) — or `gh repo fork --remote` — then:

```
git clone https://github.com/<you>/3dsmax-sdk-mcp
```

**The fork is not a formality; it is where your work lives.** Cartridges you create are written into
`cartridges/` in your working copy, and in a fork that is *your* code — committed, pushed, backed up,
and shareable. In a clone of somebody else's repository it is a pile of untracked files in a
directory you cannot push. You also get the two things a fork is actually for: pulling updates as
this kit changes, and opening a pull request if you fix something.

Then open your clone in an MCP-capable coding agent and ask it to **install**. It finds your 3ds Max,
checks what is missing, places the plugin, verifies the endpoint answers, and connects itself to it.
Then ask it to **bootstrap** a cartridge and you have a working plugin in the host with a panel and a
button, before you have written a line.

*(Just looking? Clone it and read. The kit will mention the fork once, when it starts to matter, and
then leave you alone.)*

### Keeping your fork current

Forking a toolkit raises one fair objection — *am I now stuck on today's version?* No. Point your
fork at this one, once:

```
git remote add upstream https://github.com/nmalex/3dsmax-sdk-mcp
```

then, whenever you want what has changed here:

```
git pull upstream main
```

`cartridges/` is **shared** — it is where contributed cartridges land, so an update brings other
people's work as well as this kit's changes. That is the point rather than a side effect: the
library is the reason to pull. Your own cartridge sits beside theirs and is only ever in the way if
two of you picked the same name, which the naming check exists to prevent.

If you have written something worth having, push your branch and open a pull request — see
[CONTRIBUTING.md](CONTRIBUTING.md).

---

## Status — first pre-release

`0.4.0-alpha.1`. **Alpha means what it says**: this is the first build anyone outside has seen, it
has been exercised on exactly one machine, and things will change. Every public build from here
bumps the alpha counter, so no two are ever the same version.

This is being built in the open and the parts land in order. What is true **today**:

| | |
| --- | --- |
| `tools/find-max.ps1` | works — finds every installed 3ds Max, reports JSON |
| `tools/list-plugins.ps1` | works — every installed plugin module, from the directories 3ds Max searches |
| `tools/2026/check-prereqs.ps1` | works — readiness rows with a remedy on each |
| `tools/new-cartridge.ps1` | works — scaffolds and deploys a cartridge |
| `tools/claim-cartridge-name.ps1` | works — conflict, confusable and style verdicts on a proposed name |
| `tools/2026/install-plugin.ps1` | works — fetch, verify the hash, place, verify again |
| `tools/2026/uninstall-plugin.ps1` | works — removes what was installed; your cartridges are kept |
| The `install` skill and `.mcp.json` | works — a fork drives its own setup |
| The release asset it installs | `0.4.0-alpha.1` — the first public pre-release |
| The `bootstrap` skill | works — interview, name claim, slot, scaffold, verify |

So the flow above describes where this is going, and the table says how far it has got. Nothing here
is written from how it is presumed to work.

**What is missing and why** — CI, signing, more 3ds Max versions, more plugin kinds — is written
down in [ROADMAP.md](ROADMAP.md), along with the things that were considered and deliberately
rejected. Nothing on that list is an oversight.

## What you need

**Windows, and 3ds Max 2026.** That is the whole list for the Python lane.

This release ships a binary for **3ds Max 2026 only**. A bundle built against one Max SDK must not
load into another, and the host enforces that itself — so on any other version the plugin will not
load, and `check-prereqs` says so rather than letting you find out from a plugin that silently is
not there.

For a **native (C++) payload** you also need Visual Studio with the pinned toolset component
`Microsoft.VisualStudio.Component.VC.14.38.17.8.x86.x64`. You do **not** need the 3ds Max SDK —
not for either lane. Nothing you write links it.

## The three verbs

**install** — once per machine. Find 3ds Max, check prerequisites, place the plugin, start Max,
verify the endpoint, connect your agent to it.

**bootstrap** — once per cartridge. A named new cartridge with a default About rollout and a
Hello World button, deployed and proven in the running host.

**author** — the loop after that: edit the payload, refresh, see it. No restart.

## What a cartridge actually is

A cartridge is **a payload** — not a compiled 3ds Max plugin. The plugin half, the *slot*, ships as a
binary in the release and is the same for everyone. You do not build one; you occupy one.

That is why nothing here needs the 3ds Max SDK, why a Python cartridge needs no compiler at all,
and why the fast loop can swap a payload without restarting 3ds Max.

**One slot per plugin type, one cartridge per slot** — a slot is a workbench station, not a home.
The entry you see in 3ds Max carries the slot's name for now, and a saved scene resolves by the
slot rather than by the cartridge in it. Both facts, and what they mean for your test scenes, are in
[docs/SLOTS.md](docs/SLOTS.md).

Two lanes, one behaviour:

| | Python payload | Native payload |
| --- | --- | --- |
| Needs a compiler | no | yes, the pinned toolset |
| Edit-to-see loop | refresh | build, then refresh |
| Where it goes | `python/<module>.py` | `native/` |

## Limitations, stated up front

- **3ds Max 2026 only.** Other versions need a binary that does not exist yet.
- **The binaries are unsigned.** Windows SmartScreen will warn. Every release publishes the
  SHA-256 of its asset and the installer verifies what it downloaded against it.
- **Windows only**, which is where 3ds Max is.
- **The slot sources are not published.** The plugin and its slots are delivered as binaries; what is
  published is everything needed to author a payload against them.

## Documentation

The plugin serves its own documentation over MCP once installed — an agent driving it can read
every rule over the protocol alone. The copies in `docs/` ship beside the binary.

## Contributing

Read [CONTRIBUTING.md](CONTRIBUTING.md) first. Branch naming, commit form, the pull-request flow and
the release ritual are written there, and they bind everyone including the maintainer.

[BACKLOG.md](BACKLOG.md) is the work in flight; [ROADMAP.md](ROADMAP.md) is the direction and what
is deliberately absent.

## Licence

MIT — see [LICENSE](LICENSE).
