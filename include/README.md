# `include/`

The headers a **native payload** compiles against. Everything a cartridge needs to be written in
C++ lands here, and nothing else does.

> **These are release artifacts and arrive with the plugin — they are not committed here.** This
> directory is empty in a fresh clone and fills when you install; only this README is tracked.
> Tracked in [BACKLOG.md](../BACKLOG.md) as `CTG-012`. The Python lane needs nothing from here and
> works today.

## Why they ship with the plugin instead of living in this repository

**So that the contract you compile against and the binary you call cannot disagree.** A header
committed here would version independently of the plugin you installed: both would look current,
and the mismatch would surface as a refused load or, worse, as behaviour that is subtly wrong.
Arriving together makes that impossible — the headers on your disk are, by construction, the ones
that came with the binary on your disk.

The second reason is the same one that keeps the plugin itself out of git: a compiled library
committed to a repository is carried by every fork of it, forever, and is reproducible from its
release anyway.

## What lands here, and what does not

| | |
| --- | --- |
| **here** | the payload contract a native cartridge implements |
| **here** | the host contract a payload calls back through |
| **here** | the building blocks — panels, batching, refusals, sub-objects |
| **here** | the JSON this project speaks |
| **never here** | anything that includes the 3ds Max SDK |
| **never here** | anything belonging to a slot |

**A payload is SDK-free, and that is the architecture rather than a convenience.** It is what lets
the same payload load into a bare interpreter for testing, what makes hot-swapping it safe, and why
authoring a cartridge needs no 3ds Max SDK on your machine at all. A header here that reached the
SDK would quietly take all three away.

## `include/` and `lib/` are a pair

Headers declare; the definitions ship compiled beside them in `lib/`. So a native payload's build is:

```
compile   your payload source
include   include\
link      lib\
```

**Static libraries, not DLLs, and that is not a preference.** The types crossing these APIs are C++
values holding strings and vectors. Across a DLL boundary they are allocated by one runtime and
freed by another, which becomes a crash on the first machine whose toolchain differs from the one
that built them. A static library has no boundary to get wrong. The host contract avoids the problem
from the other side, by being plain C over opaque handles — which is also why it is a header with
nothing to link.

## The toolset is not yours to choose

A native payload is built with the toolset the host dictates, and `tools/<year>/check-prereqs.ps1`
names the exact component. A different toolset does not fail to compile — it produces a binary that
is wrong, and the failure arrives much later and somewhere else.

## Versioning

The headers here and the plugin you have installed are two artifacts that move independently. The
contracts carry their own version and a payload built against the wrong one is refused at load with
a named reason rather than crashing — so an update to either is a refusal you can read, not a
mystery you have to bisect.
