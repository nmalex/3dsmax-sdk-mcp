# `lib/`

The static libraries a **native payload** links. The definitions behind the headers in
[`include/`](../include/README.md).

> **These are release artifacts and arrive with the plugin — they are not committed here.** This
> directory is empty in a fresh clone and fills when you install; only this README is tracked.
> Tracked in [BACKLOG.md](../BACKLOG.md) as `CTG-012`. The Python lane needs nothing from here.

## Static libraries, never DLLs

The types crossing these APIs are C++ values holding strings and vectors. Across a DLL boundary such
a value is allocated by one runtime and freed by another — which is not a warning, it is a crash on
the first machine whose toolchain differs from the one that built it, and it arrives far from its
cause. A static library has no boundary to get wrong.

The host contract solves the same problem from the other side, by being plain C over opaque handles.
That is why it is a header with nothing to link at all.

## They are built with the toolset the host dictates

Not the newest one, and not yours to choose. `tools/<year>/check-prereqs.ps1` names the exact
component to install. Linking a static library built with a different toolset is the failure that
looks like a linker complaining about something unrelated — or worse, links cleanly and misbehaves
at runtime.

One configuration ships. The 3ds Max SDK sets that precedent for its own import libraries, and a
payload is built against the release binaries in every case that matters.
