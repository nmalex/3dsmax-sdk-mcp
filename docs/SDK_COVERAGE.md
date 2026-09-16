# SDK coverage — what a Cartridge can reach, beyond its own plugin kind

A Cartridge is not limited to what its Slot's own plugin kind implies. Every call a Modifier or
Exporter Cartridge makes goes through the **same published facade** — `include/MaxFacadeApi.h` and
`include/MaxFacadeApi.Generated.inc` — and that facade's own reach runs far wider than "what a
modifier or an exporter needs." This page is a status report on how much of the 3ds Max SDK it
already covers, so you can judge, before writing a line, whether the thing you want to touch is
already there.

**Version this reflects:** ABI 188, 5430 facade entries, current as of `v0.8.0-alpha.5`.

> **This page is prose. For the machine-readable answer, use [`surface/`](../surface/README.md)** -
> every entry by name, shape and purpose, plus the declared list of what is factually missing and
> why, generated from the same declaration the facade is generated from:
>
> ```bash
> python surface/max_facade_surface.py <what you are looking for>
> python surface/max_facade_surface.py --missing
> ```
>
> Do not conclude that something is absent from a table below. Ask the index.

## The shape of the facade, in one paragraph

Every entry is a small, named function: the payload calls it, the Slot resolves whatever SDK object
it needs by a handle the payload already holds (never a raw pointer), makes the real SDK call, and
hands back a plain value or a POD struct. Reads and writes both work this way. A refusal is always a
named code (`no such node`, `wrong kind`, `too large`, …), never a crash — the facade's whole point is
that a payload cannot hold, and cannot corrupt, anything the host owns.

## What is covered, system by system

| SDK system | What's reachable | Rough depth |
| --- | --- | --- |
| Nodes, scene graph, transforms | read/write name, transform, material, wire colour, parent/child, selection | full |
| Meshes, Editable Poly, Editable Mesh | verts, faces, normals, UVs, vertex colours, sub-object selection, chamfer/bridge/cut/turn-diagonal edit verbs | broad |
| Splines / shapes | line and spline read/write, per-knot access, closed/open, bezier handles | broad |
| Materials and maps | Standard/Multi material trees, texmaps, shaders, samplers, UV generators, the standard-material family | broad |
| Controllers and animation | keys, ranges, ORTs, IK joints and limits, the parameter-block family, the undo system | broad |
| Cameras and lights | targeted/free cameras, all standard light types, exclusion lists | broad |
| NURBS | CV surfaces and curves, the full set of dependent surface/curve types, trim/texture/set-ops, object creation | broad (a large, separate build in its own right) |
| ParticleFlow | the full per-particle read/write channel family (position, speed, orientation, shape, custom MAXScript-set channels, per-mapping UV data), channel creation, and a PF-operator dispatch hook, hosted by the shipping `Cartridge PF Operator` slot | broad |
| Rendering | the render-context argument objects (`RenderGlobalContext`, `ViewParams`, `RendParams`, default lights), Renderer and Effect dispatch hooks, hosted by the shipping `Cartridge Renderer` and `Cartridge Effect` slots | broad, for the classic render pipeline |
| Colour management (OCIO) | pipeline construction and conversion, the active colour-management mode's identity/status/config path | broad |
| IK | the full `LinkChain` solve context: joint frames, limits, an IK-solver dispatch hook, hosted by the shipping `Cartridge IK Solver` slot | broad |
| Object Snap | snap-point queries and hit recording, an Osnap dispatch hook, hosted by the shipping `Cartridge Object Snap` slot | broad |
| Manipulators (viewport gizmos) | building real interactive gizmo geometry, hosted by the shipping manipulator slot (**Tetra Dummy**) - whose barebones payload draws a wireframe tetrahedron through these entries (`barebones/manipulator`) | broad |
| Asset management | asset lookup/reference counting, path-config search directories, a working asset-accessor hook | broad |
| MAXScript integration | a payload can publish a callable global primitive or a typed function interface | full |
| Modifier/WSM pipeline | the object-space and world-space modifier stack, in both of 3ds Max's own index spaces | broad |
| Bitmaps and image I/O | pixel read/write, bitmap I/O plugin kind | broad |

"Broad" means the common, real-world shape of that system is covered end to end (read and write,
not read-only) with a documented, narrow remainder — not "the easy 20%." Where a remainder exists it
is a specific, named thing (e.g. NURBS procedural-callback generators, or the rarest overload
shapes), not a vague gap.

## What deliberately stays out of a Cartridge's reach

Four things do not fit the facade's own safety rule — a payload can be swapped live under a running
host, so it may never hold a raw pointer into the SDK across a call — and are handled as **trades**,
not gaps:

- **Per-pixel shading** (a material's own `Shade`/`EvalColor`, a shader's `Illum`, a sampler's
  `DoSample`). The call rate is too high and the object too transient for a safe handle to make
  sense. The escape hatch: assemble and drive **stock materials** (Standard, Multi, the whole
  `StdMat` family) through the facade instead of writing per-pixel math yourself — most real
  material work is exactly that.
- **A live GPU device handle** (`IDirect3DDevice9*` and similar). There is no safe, portable
  projection for a raw graphics-device pointer.
- **Direct hardware I/O** (a joystick, a MIDI controller, a raw keyboard device) for motion-capture
  input. The *plugin kind* for a motion-capture device is fully supported (see
  [PLUGIN_TYPES.md](PLUGIN_TYPES.md)) — it is specifically the raw hardware stream underneath it
  that stays outside the facade.
- **The painter/BVH internals** behind 3ds Max's own paint tools (per-stroke brush service, the
  native bounds-tree, tablet pressure) — the *consuming* side (querying an existing painter
  interface) is covered; providing a new native paint surface is not.

None of these four is a "we have not gotten to it yet." Each is a considered trade, made because the
alternative would be unsafe by the facade's own rule, not because the SDK is hard to reach.

## Where the header ends and your own Slot begins

Everything above is reachable **from a Cartridge you write today**, inside whichever Slot kind hosts
it (currently Modifier or Exporter — see [SLOTS.md](SLOTS.md)). Whether the SDK area you want *lives*
in a new plugin kind rather than being callable from an existing one is a separate question — see
[PLUGIN_TYPES.md](PLUGIN_TYPES.md) for that.
