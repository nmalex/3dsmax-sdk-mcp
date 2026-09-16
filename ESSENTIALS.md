# ESSENTIALS.md — the practice, for anyone building a Cartridge here

[LAW.md](LAW.md) is what you may never do. This is what you should do, and why. A law protects
something unrecoverable; these protect the *quality* of the work — which means you may depart from
one when you have a reason, and you should say what the reason was.

---

## 1. Python, not MAXScript — and this is not a style preference

**Use Python (`pymxs`) wherever Python can do the job. Reach for MAXScript only where Python is
genuinely helpless, and say so in a comment when you do.**

The reasons, in the order they will bite you:

- **MAXScript swallows errors.** A misspelled property is a runtime nothing; a failed call in a
  `try/catch` disappears without a line in any log. Two release rounds of this project were spent
  chasing "recipes" that silently did nothing because a class name inside a `try` was wrong. Python
  raises, and a raise has a traceback with a line number.
- **Python is the lane the Cartridge itself speaks.** Payloads are Python (or C++), the facade's
  mirror is a Python module, and the checks are Python. Mixing a third language into that means
  passing values through string quoting, which is where the errors live.
- **You get real data structures.** pymxs hands back objects you can iterate, filter and assert on.
  MAXScript hands back text you have to parse, and your parser is now a second source of bugs.
- **It is testable off-host.** Python you write is ordinary Python: it can be linted, imported and
  partly exercised without 3ds Max running. A MAXScript string can only be run by 3ds Max.
- **It composes with everything else.** Logging, JSON, `ctypes`, the standard library. MAXScript has
  none of that and every bridge back to it is hand-rolled.

**When MAXScript is the right answer.** Some corners of 3ds Max are exposed to MAXScript and not to
pymxs, or are exposed so awkwardly through pymxs that the MAXScript form is plainly clearer. In that
case use `pymxs.runtime.execute("...")` for the *smallest possible* fragment, keep everything around
it in Python, and leave a one-line comment naming what pymxs could not do. A reader must not have to
guess whether the MAXScript was necessary or merely habitual.

```python
from pymxs import runtime as rt

nodes = [n for n in rt.objects if rt.classOf(n) == rt.Sphere]   # ordinary Python, ordinary list
```

---

## 2. Read the 3ds Max SDK documentation — for awareness, never as an instruction to use it

**You should know what 3ds Max can do.** The facade is a projection of the SDK, and you cannot judge
whether something is reachable, or write a gap report worth answering, without knowing what exists on
the other side. So read the primary source:

| | |
| --- | --- |
| **3ds Max Developer Help (start here)** | <https://help.autodesk.com/view/MAXDEV/2026/ENU/> |
| **C++ SDK Reference — every class, every method** | <https://help.autodesk.com/cloudhelp/2026/ENU/MAXDEV-CPP-API-REF/index.html> |
| **Using pymxs** | <https://help.autodesk.com/cloudhelp/2026/ENU/MAXDEV-Python/files/MAXDEV_Python_using_pymxs_html.html> |
| **MAXScript Language Reference** (for the corners of §1) | <https://help.autodesk.com/cloudhelp/2026/ENU/MAXScript-Help/files/GUID-6FC81BE7-58FF-4C63-8362-0BDCFA9F904C.html> |

**Read this as a map of the territory, not as a to-do list.** Everything in that reference exists in
3ds Max. **Not all of it is in the facade**, and a Cartridge may only call the facade —
[LAW-1](LAW.md#law-1--a-cartridge-never-touches-the-3ds-max-sdk-not-once-not-just-this-bit), without
exception. Finding `INode::GetMtl` in the SDK reference tells you the capability exists in the host;
it does not authorise you to call it.

The correct sequence when the reference shows you something you want:

1. **Look it up in the facade surface** — the thing may well already be there under a different name:

   ```bash
   python surface/max_facade_surface.py Mtl
   ```

2. **Check whether it is a declared absence**, and of which kind:

   ```bash
   python surface/max_facade_surface.py --missing
   ```

   `trade` means it will never cross the facade and the reason is written down. `host` means 3ds Max
   does not offer it to a plugin at all. **`not-yet` means write the report.**

3. **File it** per [docs/REPORTING.md](docs/REPORTING.md), citing the SDK header and line you found —
   a gap report that names `include/manipulator.h:159` gets answered; one that says "there is no way
   to draw a gizmo" gets a round-trip.

---

## 3. Enumerate before you conclude

The facade is 5,430 entries across 169 families. **Nobody, and no model, holds that in their head**,
and "I do not recall an entry for X" is not evidence about X. Two commands stand between you and a
wrong conclusion:

```bash
python surface/max_facade_surface.py <pattern>     # entries matching name or purpose
python surface/max_facade_surface.py --families    # the families, to browse by noun
```

Grepping works too, from either lane — [`surface/MaxFacadeSurface.h`](surface/MaxFacadeSurface.h)
carries every name as a `MAXMCP_FACADE_HAS_<Name>` define for exactly this reason.

This index is **generated from the same declaration the facade itself is generated from**, and a
gate fails the build if the two ever disagree. So it is not documentation that might be stale — it
is the surface, restated.

---

## 4. Prefer the barebones example over inventing a shape

Every plugin kind has a worked, shipping example under [`barebones/`](barebones/) that registers,
greets, and — where the kind allows it — does something visible. `barebones/manipulator` draws a
tetrahedron in the viewport, built by the payload through the facade. Copy the example's shape before
you invent one; a Cartridge that is structured like the examples is one anybody here can read.

---

## 5. Say what you observed, not what you expect

This is [LAW-3](LAW.md#law-3--never-report-as-verified-what-you-have-not-observed) in its everyday
form. Write summaries that a reader can check:

- **Name the evidence.** "The gizmo drew, screenshot attached" and "the payload imported without
  error" are both fine to write; passing the second off as the first is not.
- **Quote the failure.** If a check failed, paste its output. A summary that says "mostly working"
  is a summary that has to be re-verified by whoever reads it.
- **Leave the gap visible.** If something is unfinished, say which thing and why, in the summary and
  in the code. A known gap costs a sentence; a hidden one costs somebody a day.
