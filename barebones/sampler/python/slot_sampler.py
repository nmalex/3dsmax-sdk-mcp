"""Barebones Sampler (Python lane) - a stratified, jittered supersampler. Python lays out the
pattern; the slot takes those samples in every pixel.

WHAT A SAMPLER CARTRIDGE IS. A supersampler in the Standard material's SuperSampling rollout (enable
"Use Global Settings" off, then pick "Cartridge Sampler"). For every pixel the renderer asks it where
to shade inside the pixel; it asks the renderer to shade there, and the results are averaged. The
rollout gives it an Enable checkbox and a Quality spinner; its Setup dialog is this panel.

PER-PIXEL WORK IS NEVER A PYTHON CALL. So the slot runs in one of two modes:

  * MANAGED - this file. When a render begins (main thread), `SamplerRenderBegin` returns a PATTERN:
    `grid` x `grid` positions inside the pixel (0..1 each), one per cell, jittered within it. The slot
    takes exactly those samples in every pixel, natively, skips any off the fragment, and averages
    them. This payload also declares the parameters (the slot keeps them) and builds the Setup panel.
    `params` also carries the rollout's own `quality` (0..1) and `enabled`.
  * UNMANAGED - ../native/src/payload.cpp. A native payload that exports MaxMcpGetUnmanaged is pinned
    and called per pixel; it lays out the same grid, jittered differently in every pixel, and takes
    each sample with ShadeSampleTakeSample - with no 3ds Max SDK header. The SLOT sums and averages
    what it took. In that mode this Python lane is refused.

HOW TO SEE IT WORK. Render a thin, high-contrast edge (a checker at a grazing angle) with the
material's SuperSampling set to Cartridge Sampler, grid 4: the edges are smooth, where the single
centre sample leaves them stair-stepped.

WHICH SLOT HOSTS IT. The payload the `Cartridge Sampler` slot loads by its fixed module name,
`slot_sampler`, registering SAMPLER_CLASS_ID. See README.md.

THE HELLO. Logged once from `SamplerRenderBegin`, which the slot calls on the main thread when a
render is about to use it. Read it with `cartridge_logs -module slot_sampler`.
"""

import random

import mcp_bootstrap
import mcp_ui as ui

_said_hello = False


def _p(params):
    p = params or {}
    return {"grid": int(p.get("grid", 0)), "jitter": bool(p.get("jitter", True)),
            "quality": float(p.get("quality", 0.5)), "enabled": bool(p.get("enabled", True))}


def _hello_once(where):
    global _said_hello
    if not _said_hello:
        _said_hello = True
        mcp_bootstrap.log("display",
                          "Hello World - Barebones Sampler (Python) is live; this line came from its "
                          "payload on the first %s." % where)


def describe_params():
    """grid: samples per side (0 = from the rollout's Quality). jitter: shift each within its cell."""
    return {
        "parameters": [
            {"name": "grid", "type": "int", "default": 0},
            {"name": "jitter", "type": "bool", "default": True},
        ],
    }


def describe_ui(params=None, **kwargs):
    p = _p(params)
    return ui.build(
        ui.VBox(
            ui.Label("Stratified grid"),
            ui.Spacer(),
            ui.Field("Grid:", ui.Spinner(value=p["grid"], minimum=0, maximum=8, step=1,
                                         numeric="int", param="grid")),
            ui.CheckBox("Jitter within each cell", checked=p["jitter"], param="jitter"),
        )
    )


def on_ui_event(control_id, value=None, ctrl=False, shift=False, alt=False, settled=True,
                params=None):
    outcome = ui.dispatch(control_id, value)
    return {"invalidate": True, "rebuild": bool(outcome.get("rebuild")),
            "updates": outcome.get("updates") or []}


def _side(p):
    """Samples per side: `grid`, or from the rollout's Quality when `grid` is 0. The slot takes 64 at most."""
    side = p["grid"] if p["grid"] > 0 else 1 + int(3.0 * min(1.0, max(0.0, p["quality"])))
    return max(1, min(8, side))


def _pattern(p):
    """One position per grid cell, at its centre or jittered inside it. Seeded, so a re-render matches."""
    side = _side(p)
    rng = random.Random(1)
    points = []
    for y in range(side):
        for x in range(side):
            ox, oy = (rng.random(), rng.random()) if p["jitter"] else (0.5, 0.5)
            points.append([(x + ox) / side, (y + oy) / side])
    return points


def SamplerRenderBegin(**event):
    """A render is about to use this sampler. Main thread. Returns the PATTERN the slot takes per pixel."""
    _hello_once("render (SamplerRenderBegin)")
    p = _p(event.get("params"))
    pattern = _pattern(p)
    # One line per render (main thread, not per pixel): which pattern this render takes.
    mcp_bootstrap.log("display", "SamplerRenderBegin: %d sub-pixel sample(s) per pixel (%dx%d, jitter %s)."
                      % (len(pattern), _side(p), _side(p), "on" if p["jitter"] else "off"))
    return {"ok": True, "lane": "python", "mode": "managed", "params": p, "pattern": pattern}


def describe(params=None):
    return {"payload": "slot_sampler", "version": "0.1.0", "lane": "python",
            "example": "barebones/sampler"}


def init(**env):
    """Load-time crossing: the INIT REPORT, never the greeting."""
    mcp_bootstrap.log(
        "display",
        "%s payload (Python) init on load. Environment: 3ds Max %s, slot v%s, cartridge ABI %s, "
        "gup present=%s. This is the init report, not the cartridge greeting."
        % (env.get("slotName"), env.get("maxRelease"), env.get("slotVersion"),
           env.get("cartridgeAbi"), env.get("gup")))
    return {"ok": True, "acknowledged": dict(env)}


def shutdown(**_env):
    """The UNLOAD REPORT - never the greeting."""
    mcp_bootstrap.log("display",
                      "%s payload (Python) shutdown on slot unload. This is the unload report."
                      % (_env.get("slotName") or "cartridge"))
    return {"ok": True}
