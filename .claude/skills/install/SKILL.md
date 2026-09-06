---
name: install
description: Set up the 3ds Max plugin on this machine end to end - find 3ds Max, check and remedy prerequisites, place the plugin, start the host, verify the endpoint answers, and connect this session to it. Use when the user says install, set up, get started, or nothing works yet.
---

# Install

Take the user from a fresh clone to a plugin that answers. Once per machine.

**Read this whole file before running anything.** The order matters more than the commands: three
of these steps are refusals that exist to stop you doing damage, and they are cheap only if they
happen before the step they guard.

## Before you start

**Check whether this is a fork.** Run `git remote -v`. If `origin` points at the upstream repository
rather than the user's own, say so once, plainly:

> This looks like a direct clone rather than your own fork. Cartridges you create are written into
> `cartridges/` in this working copy — in a fork that is your work, tracked and pushable. In a
> clone of someone else's repository it has nowhere to go.
> Fork it: https://github.com/nmalex/3dsmax-sdk-mcp/fork — or `gh repo fork --remote`

Say it once. If they want to carry on regardless, carry on; it is their machine.

## 1. Find 3ds Max

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\find-max.ps1
```

JSON out. Exit `0` a supported host was found, `3` hosts exist but none supported, `4` none at all.

- **Report every install it found, not just the supported one.** An unsupported version has a
  `reason` field — quote it. The failure this prevents is silent: the plugin installs, the host
  refuses it by its declared version range, and the user sees a plugin that simply is not there.
- The `year` decides which `tools/<year>/` folder every later step uses. **If there is no folder for
  that year, stop.** That is a release this kit ships no binary for. Point at `ROADMAP.md`; do not
  substitute another year's scripts.

## 2. Check prerequisites

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\<year>\check-prereqs.ps1
```

Rows of `id / title / state / detail / remedy`. Exit `0` if nothing **Failed**; warnings are not
failures.

**Ask which lane before you make anything of the toolchain row.** A Python payload compiles nothing.
If the user is writing Python, an absent C++ toolchain is irrelevant and you should not raise it —
sending someone to install several gigabytes they will never use is how a first session ends.

**Remedies are commands, and they are the user's to run.** Every non-Ok row carries the literal
command that fixes it. Show it. Do not run an elevated installer on their behalf, and do not offer
to. Wait for them to come back.

Two rows are common and neither is a fault:
- `max-running` — the host must be closed to install, because it holds every loaded plugin open.
- `port` — something else holds the port; the row names the process.

## 3. Install the plugin

```
powershell -NoProfile -ExecutionPolicy Bypass -File tools\<year>\install-plugin.ps1
```

It narrates eight steps, verifies the SHA-256 **before** unpacking anything, and installs per-user.
Nothing is written into the 3ds Max install root.

- Exit `3` means no release is pinned yet. That is a real state, not an error to work around: say
  so, and mention `-From <path-to-zip>` only if the user has a bundle of their own.
- Exit `2` with "already installed" means it will not replace a different version unless told:
  `-Upgrade`. Ask; do not add the flag on your own.
- Exit `4` is a hash mismatch. **Nothing was unpacked.** Do not retry it in a loop and do not
  suggest bypassing the check — report it and stop.

If the user wants to watch it themselves: `start "" "tools\<year>\install-plugin.cmd"`.

## 4. Start 3ds Max

**Ask. Do not start it yourself.** Say what you are waiting for — the server starts with the host
and listens on loopback — and wait for them to tell you it is up.

## 5. Verify the endpoint

The server answers on loopback. Check it directly before trusting any client:

```
powershell -NoProfile -Command "(Invoke-WebRequest -Uri http://127.0.0.1:3000/health -UseBasicParsing).Content"
```

Nothing listening usually means one of three things, and they look identical from outside: the host
has not finished starting, the plugin did not load, or the port is held by something else. Re-run
`check-prereqs` — its `port` row names the process holding it.

## 6. Connect this session

`.mcp.json` in this repository declares the server, so the tools appear once it answers. If the
client has not picked it up, the user may need to approve the project's MCP server or restart the
session — tell them which, do not guess on their behalf.

**Then ask the server what it can do, and trust that over any document here.** A live capabilities
answer is the only authority on what this build actually serves; every file in this repository can
lag a release.

## Done when

State plainly which of these is true, and do not round up:

- [ ] a supported 3ds Max was found, and every unsupported one was named
- [ ] no prerequisite row is Failed
- [ ] the plugin is installed, and the version reported is the version pinned
- [ ] 3ds Max is running and the endpoint answered
- [ ] this session can call the server's tools

If the last one is not true, say which step it stopped at. A half-finished install reported as done
is the failure this whole sequence exists to avoid.

**Next:** the `bootstrap` skill puts a first cartridge in a slot.
