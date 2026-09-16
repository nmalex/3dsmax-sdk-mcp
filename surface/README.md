# `surface/` — what the facade actually reaches, enumerable from this checkout

Two generated files that let you answer **"can a Cartridge do X?"** without installing anything,
without guessing, and without a round-trip.

| | |
| --- | --- |
| [`max_facade_surface.py`](max_facade_surface.py) | importable and runnable: every entry, its shape, its purpose, and the declared gaps |
| [`MaxFacadeSurface.h`](MaxFacadeSurface.h) | the same names as an X-macro list and one `MAXMCP_FACADE_HAS_<Name>` define each, for grep and for `#ifdef` |

```bash
python surface/max_facade_surface.py                 # counts, by family
python surface/max_facade_surface.py gizmo           # every entry matching 'gizmo'
python surface/max_facade_surface.py --missing       # what is factually missing, and why
python surface/max_facade_surface.py --families      # the family names
```

```python
import max_facade_surface as S

S.has("GizmoShapeAppendPolyline")    # True
S.get("NodeTransformRead").signature
S.find("nurbs")                      # [Entry, ...]
S.missing("manipulator")             # [Missing, ...] - the declared gaps in that area
```

## Why this exists

The facade's real contract — `MaxFacadeApi.h` and its generated `.inc` — **ships with the installed
plugin and is deliberately not committed here**, so that the header you compile against and the
binary you call can never be different versions. See [`../include/README.md`](../include/README.md)
for that argument, which still stands.

The cost of it, found the hard way, is that anyone holding only this repository could not enumerate
the facade **at all**. They would grep, find nothing, and conclude the capability was absent — which
is how feature requests arrived asking for things that had been shipping for months. An absence
cannot tell you which of four things it means:

- present, under a name you did not guess
- **not in this build**, present in a newer one
- **a trade** — it may never cross the facade, and the reason is written down
- **not yet written** — which is a feature request, and a welcome one

So the contract still ships with the binary, and this **index** is committed. It is not compilable,
carries no ABI offsets, and nothing in it is callable. It is the list of names, shapes, purposes and
declared absences — the half of the contract that answers questions rather than linking.

## It cannot go stale

Both files are **generated from the same declaration the facade itself is generated from**, and
`generate.py --check` runs in the maintainers' `check-all`. If an entry is added, removed or
re-shaped and these files are not regenerated, that build fails. Correspondence is by construction,
not by anybody remembering to update a document.

That is also why neither file should ever be edited by hand — both say so in their own first lines.

## What "missing" means here

Every record in `--missing` carries a `kind`:

| kind | what it means | what to do |
| --- | --- | --- |
| `trade` | it may not cross the facade — a payload is swapped under a running host, so it may never hold a raw pointer into the SDK | nothing; the supported route is named in `instead` |
| `host` | 3ds Max itself does not offer it to a plugin | nothing a facade entry could fix |
| `not-yet` | genuinely absent, wanted, unwritten | **file it** — see [`../docs/REPORTING.md`](../docs/REPORTING.md) |

An entry can never be listed as both present and missing: the two lists are generated into one
document from one declaration, and a `not-yet` is deleted the moment its entry appears.

## Related

- [`../LAW.md`](../LAW.md) — LAW-1: a Cartridge calls the facade and never the 3ds Max SDK
- [`../ESSENTIALS.md`](../ESSENTIALS.md) — how to use this index before concluding anything
- [`../docs/SDK_COVERAGE.md`](../docs/SDK_COVERAGE.md) — the same ground in prose, system by system
- [`../docs/REPORTING.md`](../docs/REPORTING.md) — bug, gap or feature request, and the templates
