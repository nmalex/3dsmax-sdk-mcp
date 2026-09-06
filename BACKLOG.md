# Backlog

The working list for **this repository** — the kit: the scripts, the templates, the skills, the
documents and the release plumbing. Every wanted feature, fix or improvement gets an entry; an item
that is not written here does not exist.

For direction and for what is deliberately absent, see [ROADMAP.md](ROADMAP.md). This file is the
work; that one is the promise.

## What belongs here, and what never appears here

This repository is the kit. **The plugin's own internals — the server, the slots, how either is
built — are developed elsewhere and are not described here, in any amount of detail.** That is not
secrecy for its own sake: the published contract is what an author needs, and a contract stays
honest only while nobody is working from the implementation behind it.

| Belongs here | Never appears here |
| --- | --- |
| scripts, templates, skills, tests, CI | the server's or a slot's internal design |
| documents an author reads | anything about how either is built |
| the release and install plumbing | issue ids, plans or schedules from anywhere else |

**Ids are `CTG-###`, and the sequence has no gaps.** It is its own numbering rather than a slice of
someone else's on purpose: a public list with holes in it advertises exactly how much private work
sits between the numbers, which is a leak that costs nothing to avoid.

When this repository is blocked on a capability that has to arrive in a plugin release, the item
says so as **a dependency on a released capability** — never as a description of the work behind it.

## Entry format

```
### CTG-001 - [Feature] Short imperative title
Status: Backlog | In Progress | Blocked | Done
Type:   Feature | Bug | Improvement | Task
Priority: High | Medium | Low

Why: the problem or the value, in a sentence or two.

Done when:
- a concrete, checkable outcome
```

No estimates, no points, no dates, no assignees. Ordering carries the priority.

---

## Items

### CTG-001 - [Feature] install-plugin.ps1 - fetch, verify and place the bundle
Status: In Progress
Type:   Feature
Priority: High

Why: there is no way to install the plugin. This is the step between a clone and anything working,
and it is the one place a user meets a downloaded binary, so it has to be visible and checkable.

Done when:
- Downloads the release asset for a pinned version, named from `(version, year)` with no lookup.
- **Verifies the SHA-256 before unpacking anything**, and refuses on a mismatch without writing.
- Unpacks byte-for-byte into the per-user bundle directory; no rearranging at install time.
- Refuses while 3ds Max is running, by name, rather than half-copying over a held file.
- Narrates every step in a console that never closes on its own (`CONTRIBUTING.md`).
- Verifies the artifact afterwards - manifest, binaries, docs present - not the exit code.
- Prints the uninstall: delete one directory.

### CTG-002 - [Feature] The `install` skill, so a clone drives the whole setup
Status: Backlog
Type:   Feature
Priority: High

Why: the promise on the front page is "clone it, open it in an agent, ask it to install". That is
one document away from being true.

Done when:
- `.claude/skills/install/` drives find-max, prerequisites, remedies, install, and verification.
- `.mcp.json` declares the local endpoint so the tools appear once the server answers.
- `CLAUDE.md` carries the rules an agent must not break, since a fork has no other source for them.
- Every remedy is offered as a command, and nothing elevated runs without an explicit yes.

### CTG-003 - [Feature] The `bootstrap` skill - interview, claim, scaffold, verify
Status: Backlog
Type:   Feature
Priority: High

Why: the scaffolder exists but nothing drives the conversation that should precede it - what are you
building, which kind of plugin can host it, and is the name a good one.

Done when:
- Asks what the user wants to build and offers only the kinds a slot can host today, naming the
  rest as not-yet rather than staying silent.
- Claims the name against the running host's registered classes, not just the module inventory.
- Scaffolds, deploys, and walks the user to the entry in the Modifier List.
- States the restart plainly rather than letting it be discovered.

### CTG-004 - [Task] Ask the class list from the running host
Status: Backlog
Type:   Task
Priority: High

Why: `claim-cartridge-name.ps1` is only as good as its inventory, and the module list provably
misses the case the check exists for - "Bending" beside "Bend" passes, because the stock modifier
lives inside a shared module and no file is named for it.

Done when:
- A documented way to get `modifierPlugin.classes` and its siblings out of the running host and into
  the JSON array the claim already accepts.
- `bootstrap` uses it, and a modules-only claim is reported as the weaker answer it is.

### CTG-013 - [Feature] A probe that proves the endpoint serves MCP, not just that it answers
Status: Backlog
Type:   Feature
Priority: High

Why: **the kit can tell that something is listening and cannot tell that it works.** The install
skill's verification step is a `GET /health`, which is an ordinary web request needing no protocol
knowledge at all. Everything past that point - whether the server actually speaks the protocol,
whether the tools are there - is unverified, and "it answered" is exactly the kind of signal that
looks like proof and is not.

Found by running the install end to end (2026-09-06). Health answered in ~45 seconds and looked like
success; listing the tools then failed with `400` twice before it worked, because a request needs
three things nothing here documents:

- `MCP-Protocol-Version` as a header **and** the same value inside `params._meta`, under the key
  `io.modelcontextprotocol/protocolVersion` - a mismatch is refused with `-32020`, which is a good
  refusal and only helps someone who already knew to send both;
- an `Accept` that allows `application/json` **and** `text/event-stream`;
- `Mcp-Method` naming the method.

Nobody working from this repository can discover that. It was recovered by reading a tool that is
not published, which is precisely the dependency the kit is supposed not to have.

Done when:
- `tools\probe-endpoint.ps1` performs the survey - health, then `tools/list` - with the header and
  `_meta` pairing already right, and reports what answered.
- It reads the protocol version from `/health` rather than carrying a constant, so a protocol bump
  does not turn the script into a liar.
- The install skill's verification uses it, and "the endpoint answered" is replaced by "the server
  listed its tools".
- A refusal is reported with its JSON-RPC error intact - the body carries the reason and the status
  code alone does not.

Notes: raised by the first end-to-end install. The `-32020` refusal is the server being helpful; the
gap is that this repository never says what to send.

### CTG-005 - [Feature] Templates for the utility and exporter kinds
Status: Backlog
Type:   Feature
Priority: Medium

Why: `new-cartridge.ps1` offers three kinds and can scaffold one. The other two exit with a clear
"not written yet", which is honest and is still a gap.

Done when:
- `templates/utility/` and `templates/exporter/` scaffold a working Hello World of their kind.
- Each is exercised the same way: created, deployed, seen in the host, clicked.

### CTG-012 - [Feature] The kit carries what a native payload compiles and links against
Status: Backlog
Type:   Feature
Priority: Medium

Why: **there is no `src/` in this repository.** Everything here is the Python lane, and a native
payload cannot be written at all until the headers and the library it builds against are present.
CTG-006 describes scaffolding that lane and quietly assumes this; it is a separate deliverable and
it blocks that one.

What has to arrive, and in which form - decided, and recorded here so the shape is not re-argued:

| | Form | Why not the other way |
| --- | --- | --- |
| the host contract header | header only | it declares a table of function pointers handed over at runtime; there is nothing to link, so a library would be empty |
| the JSON the payload uses | `.h` + a static `.lib` | the header declares and the library defines; shipping it compiled hides the implementation and still links |
| the building blocks | `.h` + a static `.lib` | same split |
| the worked example payloads | prebuilt `.dll`, plus their source | so a reader with no compiler still has something that runs to compare against |
| the slot library, later | `.h` + a static `.lib` | for authoring a new *kind* of slot — a different and much smaller audience, and the only one that also needs the 3ds Max SDK. Not in the first delivery |

**A static library and not a DLL, and that is not a preference.** The types crossing these APIs are
C++ values holding strings and vectors. Across a DLL boundary they are allocated by one runtime and
freed by another, which is a crash that appears when someone's toolchain differs from ours. A static
library has no boundary to get wrong. The host contract header avoids the problem the other way, by
being plain C over opaque handles.

**The layout is this repository's own, not a mirror of anywhere else:**

```
include\      every header a native payload compiles against
lib\          the static libraries it links
```

That is possible because nothing here is compiled from a relative path reaching into another tree —
the JSON and the blocks arrive already built. An export that had to preserve someone else's
directory shape would break every example the first time that shape changed; this one cannot.

**They are RELEASE ARTIFACTS, delivered by installing, and are not committed here.** Both
directories are git-ignored except their READMEs. Two reasons, and the second is the one that
decides it: a committed `.lib` is carried by every fork forever; and a header committed here would
version *independently* of the installed plugin, so the contract compiled against and the binary
called could disagree while both looked current. Arriving together makes that impossible.

Done when:
- The release carries them, and installing places them in `include\` and `lib\`.
- The example projects reference those paths and reach outside this repository for nothing.
- Uninstalling removes them, the same way it removes everything else it placed.
- `include\README.md` and `lib\README.md` stop saying "not delivered yet".
- **A native payload builds from a fresh clone of this repository alone** - not compiled, built, and
  loaded. A build that finds its headers through a path into somewhere else proves nothing.
- The prebuilt example payload runs beside its source, so the native lane is something a reader
  sees working before deciding whether to install a compiler.
- The pinned toolset is what builds it, and the prerequisite check's toolchain row is what gates it.

Notes: blocks CTG-006. Nothing here changes the Python lane, which needs none of it.

### CTG-006 - [Feature] The native payload lane, scaffolded
Status: Backlog
Type:   Feature
Priority: Medium

Why: a Python payload is the entry path and a native one is where a hot loop ends up. Today the
native lane refuses with a pointer to the roadmap.

Done when:
- `-Lane native` scaffolds a payload project that builds with the pinned toolset and nothing else.
- The prerequisite check's toolchain row is what gates it, and it stays a warning for Python users.

### CTG-007 - [Task] Tests for the scaffolder and the name claim
Status: Backlog
Type:   Task
Priority: Medium

Why: two scripts now make permanent decisions - a Class_ID that a saved scene resolves by, and a
name every user reads - and neither has a test. Both bugs found so far were found by hand.

Done when:
- The claim's tiers are pinned by fixtures: exact, mangled, same-stem, near-miss, clear.
- The scaffolder is pinned for refusing a conflict, refusing a confusable, honouring `-Force`, and
  never reusing a Class_ID.

### CTG-008 - [Task] Publish provenance with every release
Status: Backlog
Type:   Task
Priority: Medium

Why: the binaries are unsigned, so the only thing a stranger can check is what we give them to check
with. A checksum proves the download is intact; provenance proves where it came from.

Done when:
- Each release publishes the SHA-256 of every asset.
- The release workflow attests build provenance, and the README says the one command that verifies it.

### CTG-009 - [Improvement] Offer to remove the stale cartridge directory entry
Status: Backlog
Type:   Improvement
Priority: Low

Why: an earlier arrangement needed a `[Directories]` line in the user's `Plugin.UserSettings.ini`
pointing at the cartridge folder. Nothing needs it now, and a stale line is a claim on disk about
where something lives.

Done when:
- Install notices the line and **offers** to remove it, with the file's UTF-16LE encoding preserved.
- It is never removed without the user saying so: it is their configuration file.

### CTG-010 - [Task] Fill the README quickstart from a run that actually happened
Status: Backlog
Type:   Task
Priority: Medium

Why: the front page currently describes the intended flow and a status table. It becomes a quickstart
the day someone performs the steps on a clean machine and writes down what happened.

Done when:
- A clean clone, on a machine that is not the one this was written on, goes from clone to a Hello
  World cartridge visible in 3ds Max - and the transcript is what the README says.

### CTG-011 - [Task] CI: check every documentation link resolves
Status: Backlog
Type:   Task
Priority: Low

Why: this repository is mostly documents that point at each other, and a dead link in a README is
the first impression a stranger gets.

Done when:
- A CI job resolves every relative link in every Markdown file and fails on a miss.
