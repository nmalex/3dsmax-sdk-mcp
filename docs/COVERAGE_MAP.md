# Coverage map — every authored plugin type, and why each is where it is

This kit authors a hello‑world barebone for **33** 3ds Max plugin types (the super‑class census, FR‑0002).
Not all 33 receive a runnable slot, and that is a **deliberate, evidence‑based** outcome, not a gap: a
slot can only exist for a super‑class a third party can register a `ClassDesc` under, and only ships
once its hello is verifiable. This page accounts for all 32 so you never have to wonder why one is
missing — every row is classified, and the classification is pinned to the super-class census and enforced by an anti-drift
check in the factory, which fails the build if any of this drifts.

**33 = 24 slots + 8 shelved (not third‑party registerable) + 1 deferred (registers, hello unreachable).**

---

## 24 types with a shipped slot

Each registers a real plugin under its super‑class. **Every one of the 24 reports itself on load**: the
slot calls its cartridge’s `init(env)` the moment 3ds Max loads the slot — handing over the environment
it alone can see (the running Max release, the slot’s own version, the cartridge ABI, whether the server
is present) — and calls `shutdown` on unload. So a freshly installed host shows all 22 cartridges having
logged their init report before any host action; `init` reports init and `shutdown` reports unload — the
`Hello World` **greeting** is logged only by the cartridge’s own behaviour, never by init, so a load
report is never mistaken for the plugin actually working.

On top of that load‑time proof, the greeting itself is checked two ways. **15 are greeting‑verified
automatically** — the probe drives the plugin and sees its own `Hello World`. **7 have their greeting
behind a host/UI action** a headless probe cannot synthesise (a render pass, an IK solve, an interactive
snap, a live particle sim, a panel, a modal, a Video Post execute); those ship **verified alive on load**
(their init report was observed) and carry the exact step to fire the greeting:

| Type | Super‑class | Verification |
|---|---|:-:|
| geometry | `GEOMOBJECT_CLASS_ID` | ✅ greeting driven |
| modifier | `OSM_CLASS_ID` | ✅ greeting driven || exporter | `SCENE_EXPORT_CLASS_ID` | ✅ greeting driven |
| renderer | `RENDERER_CLASS_ID` | ✅ greeting driven |
| manipulator | `HELPER_CLASS_ID` (Manipulator) | ✅ greeting driven |
| helper | `HELPER_CLASS_ID` (plain) | ✅ greeting driven |
| controller | `CTRL_FLOAT_CLASS_ID` | ✅ greeting driven |
| uv‑generator | `UVGEN_CLASS_ID` | ✅ greeting driven |
| xyz‑generator | `XYZGEN_CLASS_ID` | ✅ greeting driven |
| texture‑output | `TEXOUTPUT_CLASS_ID` | ✅ greeting driven |
| aa‑filter‑kernel | `FILTER_KERNEL_CLASS_ID` | ✅ greeting driven |
| radiosity | `RADIOSITY_CLASS_ID` | ✅ greeting driven |
| datachannel‑engine | `DATACHANNELENGINE_SUPER_CLASS_ID` | ✅ greeting driven |
| texmap | `TEXMAP_CLASS_ID` | ✅ greeting driven |
| material | `MATERIAL_CLASS_ID` | ✅ greeting driven |
| shader | `SHADER_CLASS_ID` | ✅ greeting driven |
| sampler | `SAMPLER_CLASS_ID` | ✅ greeting driven |
| effect | `RENDER_EFFECT_CLASS_ID` | 🔵 alive on load · greeting: render with the effect |
| iksolver | `IK_SOLVER_CLASS_ID` | 🔵 alive on load · greeting: solve a chain |
| osnap | `OSNAP_CLASS_ID` | 🔵 alive on load · greeting: interactive snap |
| pfoperator | `HELPER_CLASS_ID` (Particle Flow) | 🔵 alive on load · greeting: run a sim |
| utility | `UTILITY_CLASS_ID` | 🔵 alive on load · greeting: open in Utilities panel |
| color‑picker | `COLPICK_CLASS_ID` | 🔵 alive on load · greeting: pick a colour |
| videopost‑filter | `FLT_CLASS_ID` | 🔵 alive on load · greeting: Video Post |

The 🔵 kinds are never falsely reported as having driven their greeting: their init report proves the
cartridge loaded and is alive, and the exact action to fire the greeting is recorded beside each so a
person can run it. Nothing ships claiming a greeting it did not produce.

---

## 8 types shelved — the super‑class is not open to a third‑party plugin

These barebones exist as documentation of the *shape*, but no slot ships, because 3ds Max does not let a
third party register a `ClassDesc` under the super‑class. Each verdict is checked against the 2026 SDK
headers, not assumed (FR‑0003 N5). Shelving them is the honest alternative to shipping a slot that would
never load.

| Type | Super‑class | Why it is not a third‑party slot |
|---|---|---|
| **schematicview‑utility** | `SCHEMATICVIEW_UTILITY_CLASS_ID` | Nominally a plug‑in super‑class (a sibling of the registerable `TRACKVIEW_UTILITY`), but the 2026 SDK ships **no base class, no sample, no plugin‑wizard entry and no subclassing doc** for it — the identifier appears only at its own `#define`. There is no discoverable path to register one. |
| **bake‑map** | `COMMON_BAKE_MAP_CLASS_ID` | An **internal super‑class of the Bake To Texture subsystem**. The id appears only at its `#define`; no author‑facing base class returns it. Bake maps are created by the host’s Bake To Texture machinery, not registered by third parties. |
| **bake‑map‑operator** | `COMMON_BAKE_MAP_OPERATOR_CLASS_ID` | The operator half of the same internal Bake To Texture subsystem — same evidence: id only at its `#define`, no author base class. |
| **bitmap‑storage** | `BMM_STORAGE_CLASS_ID` | **Internal to the bitmap manager.** The storage object is `class BitmapStorage` (`bitmap.h:2399`), which has no `SuperClassID()`/`ClassDesc` and is created only by the bitmap manager. (Contrast `BMM_IO_CLASS_ID`, the *loader/saver* super‑class, which IS registerable and is covered elsewhere.) |
| **bitmap‑dither** | `BMM_DITHER_CLASS_ID` | Internal bitmap‑manager dithering construct; the id occurs only at its own `#define` in the whole SDK — no base class, sample or wizard entry. |
| **bitmap‑colorcut** | `BMM_COLORCUT_CLASS_ID` | Internal bitmap‑manager colour‑quantization construct; same evidence as dither. |
| **bitmap‑filter** | `BMM_FILTER_CLASS_ID` | **Not a `ClassDesc` super‑class at all.** The image‑viewer it names loads by **DLL replacement** — a module exporting `ViewFileCreate` / `ViewFileDestroy` C functions (`viewfile.h:29‑56`) — not by registering a `SuperClassID`. Autodesk’s plugin wizard hardcodes the id, but the actual mechanism is DLL replacement, so a `ClassDesc` slot is the wrong tool. |
| **fluid‑solver** | `MAXFLUID_SOLVER_SUPERCLASS_ID` | The **internal Max fluids (Bifrost) solver** super‑class. The strings “MAXFLUID”/“Fluid” occur in exactly one SDK header — `plugapi.h` itself; there is no fluids SDK header, base class, interface, sample or wizard entry. First‑party only. |

If a future SDK opens any of these to third‑party registration, its census bucket moves to registerable,
`slot_coverage` immediately demands a slot for it, and it graduates from this table — the gate makes the
transition impossible to miss.

---

## 1 type deferred — registers, but its hello is unreachable

**fragment** (`Fragment_CLASS_ID`). A slot **is built** (`ClassDesc2` + `ViewFragment`, modeled on the
SDK’s own `ActiveShadeFragment`) and the class **registers** — `Cartridge_Fragment` is enumerable in a
live host, proving the shell loads. But a `ViewFragment` is not a MAXScript value type (creating it
returns undefined), so construction cannot fire the hello, and its only callback, `DoEvaluate`, runs
inside the viewport display fragment‑graph — which no scriptable path and no standalone manual action
triggers for a bare fragment. So the payload’s hello cannot be observed by the certifier, and rather
than ship it as “verified” when it is not, it is deferred with the built slot kept as proof of
registration and a starting point. It graduates the day the slot model can drive a display‑pipeline
fragment.

---

*The authoritative source for the registerable/shelved split is the super‑class census; this page is
its per‑authored‑type view.*
