# 3ds Max SDK MCP

A 3ds Max plugin that serves a local [Model Context Protocol](https://modelcontextprotocol.io/)
server from inside a running 3ds Max — and the kit for building **Cartridges**: your own 3ds Max
plugins, written as a payload and hosted by a Slot that ships as a binary.

## How it works

### The server lives inside a running 3ds Max

The plugin loads when 3ds Max starts and stays for the whole session. It serves an MCP endpoint on
`127.0.0.1` — your machine only. Nothing is exposed to the network.

That endpoint is how a coding agent reaches your 3ds Max. Claude Code, Codex, anything that speaks
the protocol.

### The agent does the work, not you

The agent does not hand you a script to paste and run. Point it at your fork and it will:

1. write the payload
2. deploy it into the running 3ds Max
3. call it there, on your actual scene
4. read back what happened — the return value, the error, the log
5. fix it, and go round again

You say what the plugin should do. **The agent is the one finding out whether it does.** Each lap
takes seconds, and not one of them restarts 3ds Max.

### A 3ds Max plugin is normally one thing. Here it is two

Writing a plugin for 3ds Max normally means C++, the 3ds Max SDK, the exact compiler the host was
built with, and a restart of 3ds Max to see each change.

This kit splits that plugin in half:

1. the **Slot** — the half 3ds Max deals with: a real compiled plugin holding all the SDK machinery,
   built once and shipped as a binary
2. the **Cartridge** — the half you write: behaviour, and nothing else

The Slot loads your Cartridge and calls it. Your code never touches the 3ds Max SDK.

### Why it was split that way

Four things fall out of the split, and they are the whole point:

1. **No SDK, and no compiler at all in the Python lane.** The hard requirements live in the Slot,
   and the Slot is already built.
2. **Seconds, not minutes.** Edit the payload, refresh, look. No rebuild. No restart.
3. **A mistake is cheaper.** A Python payload raises an exception and tells you. SDK code with a bad
   pointer takes 3ds Max down with it.
4. **An agent can write one.** It is ordinary Python or C++ against a small, written contract — no
   SDK to learn, no build environment, no host to hold in your head.

The last one is why this exists. You cannot reasonably hand a coding agent the 3ds Max SDK. You can
hand it a payload contract.

### What you end up with is a real plugin

Not a script somebody has to remember to run. A registered 3ds Max plugin — an entry in the Modifier
List, a file type in the Export dialog — that behaves like anything else shipped with the host.

| | MaxScript | 3ds Max Python | This kit |
| --- | --- | --- | --- |
| Extends 3ds Max with a plugin | yes, a scripted plugin | no — it drives 3ds Max, it does not extend it | yes, through a compiled Slot |
| Language you write | MaxScript | Python | Python **or** C++ |
| The host-side code is | interpreted | interpreted | native C++, already built |
| Needs the 3ds Max SDK | no | no | no |
| An AI agent writing it | weak — a niche language, thin training data | strong | strong |

MaxScript can do a good deal of this, and has for twenty years. The difference is what you are left
holding, and who is able to write it.

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

Then open your clone in an MCP-capable coding agent and ask it to **install**. It:

1. finds your 3ds Max
2. checks what is missing, and tells you the command that fixes it
3. places the plugin, verifying the download before it unpacks anything
4. waits while you start 3ds Max, then checks the endpoint answers
5. connects itself to it

Then ask it to **bootstrap** a Cartridge, and you have a working plugin in the host — with a panel
and a button — before you have written a line.

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

`cartridges/` is **shared** — it is where contributed Cartridges land, so an update brings other
people's work as well as this kit's changes. That is the point rather than a side effect: the
library is the reason to pull. Your own Cartridge sits beside theirs and is only ever in the way if
two of you picked the same name, which the naming check exists to prevent.

If you have written something worth having, push your branch and open a pull request — see
[CONTRIBUTING.md](CONTRIBUTING.md).

## What you need

To write a Cartridge in **Python**, you need:

1. Windows
2. 3ds Max 2026

That is the whole list. No compiler. No SDK.

To write one in **C++**, add Visual Studio with this exact component:

```
Microsoft.VisualStudio.Component.VC.14.38.17.8.x86.x64
```

**You never need the 3ds Max SDK.** Not for Python, not for C++. Nothing you write links against it.

### 3ds Max 2026 only

This release ships one binary, and it was built for 2026. It will not load in any other version.

3ds Max refuses it on purpose — a plugin built against one version of the SDK must not load into
another. So you will not get a broken plugin. You will get no plugin.

You will not be left guessing either: `check-prereqs` tells you before you install.

## The three verbs

**install** — once per machine:

1. find 3ds Max
2. check prerequisites
3. place the plugin
4. start 3ds Max
5. verify the endpoint answers
6. connect your agent to it

**bootstrap** — once per Cartridge. A named new Cartridge with a default About rollout and a
Hello World button, deployed and proven in the running host.

**author** — the loop after that: edit the payload, refresh, see it. No restart.

## Cartridge

A Cartridge is a payload — a Python module, or a native DLL. It is not a compiled 3ds Max plugin,
and you do not build a Slot. You occupy one.

**One Slot per plugin type. One Cartridge per Slot.** A Slot is a workbench station, not a home.
Two things follow, and both matter for your test scenes:

1. the entry you see in 3ds Max carries the **Slot's** name, not your Cartridge's
2. a saved scene resolves by the **Slot** — so it loads whichever Cartridge occupies it later

[docs/SLOTS.md](docs/SLOTS.md) explains both.

Two lanes, one behaviour:

| | Python payload | Native payload |
| --- | --- | --- |
| Needs a compiler | no | yes, the pinned toolset |
| Edit-to-see loop | refresh | build, then refresh |
| Where it goes | `python/<module>.py` | `native/` |

## Limitations

- **3ds Max 2026 only.** Other versions need a binary that does not exist yet.
- **The binaries are unsigned.** Windows SmartScreen will warn. Every release publishes the
  SHA-256 of its asset and the installer verifies what it downloaded against it.
- **Windows only**, which is where 3ds Max is.
- **The Slot sources are not published.** The plugin and its Slots are delivered as binaries; what is
  published is everything needed to author a payload against them.

## Documentation

The plugin serves its own documentation over MCP once installed — an agent driving it can read
every rule over the protocol alone. The copies in `docs/` ship beside the binary.

## Status

`0.4.0-alpha.1` — the first pre-release. [STATUS.md](STATUS.md) says which parts work today and
which do not; [ROADMAP.md](ROADMAP.md) says what is missing on purpose.

## Contributing

Read [CONTRIBUTING.md](CONTRIBUTING.md) first. Branch naming, commit form, the pull-request flow and
the release ritual are written there, and they bind everyone including the maintainer.

[BACKLOG.md](BACKLOG.md) is the work in flight; [ROADMAP.md](ROADMAP.md) is the direction and what
is deliberately absent.

## Licence

MIT — see [LICENSE](LICENSE).
