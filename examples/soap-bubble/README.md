# Soap Bubble

A **Cartridge Material** that makes an object look like a soap bubble: a thin film of water whose
colours come from light interfering with itself, swirling and draining over time. It is the
showcase for what a cartridge material can do - the whole look is computed by the cartridge, and
nothing in it touches the 3ds Max SDK.

Render with **Scanline**. The Cartridge Material runs 3ds Max's classic per-sample shading, which
Scanline calls and Arnold does not.

## How to use it

1. Deploy the cartridge into the material slot (see *Deploy* below).
2. Run [`soap_bubble_demo.py`](soap_bubble_demo.py) - *Scripting > Run Script...*. It builds five
   bubbles in front of a dark backdrop, with one light and a camera, animates them over frames
   0-100, saves `soap_bubbles.max`, and renders frames 0, 50 and 100 into your `renderoutput`
   folder. It starts a new scene, and offers to save your current one first.
3. Or by hand: a Sphere (with *Generate Mapping Coords.*), a Cartridge Material on it, Scanline,
   *Force 2-Sided* on, and something dark behind it.

## How it works

The film colour is physics, not a texture:

- **Thin-film interference.** Light reflected from the front and the back of the film interferes;
  the phase difference is δ = 4π·n·d·cosθt / λ, with n = 1.33. The reflectance comes from the
  Airy formula with an unpolarised Fresnel term, evaluated at **16 wavelengths** from 400 to
  700 nm and turned into colour through a fit of the CIE matching functions (Wyman 2013).
- **Thickness.** The film drains, so it is thin at the top (150 nm) and thick at the bottom
  (600 nm). Swirls in the thickness come from domain-warped noise. Near the very top the film is
  too thin to reflect visible light, so it shows black.
- **Reflection.** The film reflects a soft studio (a dim room and a bright window) and a sharp
  glint of the light. It is transparent wherever it reflects little.

Parameters, all animatable, in the material's panel: `thickness_top`, `thickness_bottom`,
`swirl`, `swirl_scale`, `flow`, `phase`, `reflection`, `glints`. The demo keys `phase` from 0 to 3
so the film moves.

## Two lanes

| Lane | File | What you get |
| --- | --- | --- |
| C++, unmanaged | [`native/src/payload.cpp`](native/src/payload.cpp) | the full effect: interference computed for every sample, the studio reflection, glints, and swirls that flow with scene time |
| Python, managed | [`python/soap_bubble.py`](python/soap_bubble.py) | a lighter version: the interference colours baked once into an image, returned as a **look** (image, a facing ramp, a rim, opacity) that the slot shades with |

The C++ lane exports `MaxMcpGetUnmanaged`, so the slot calls it for each shading sample. With only
the Python lane deployed, the bubbles use the managed look instead.

## Deploy

- **Python:** copy `python/soap_bubble.py` to the bundle's `Contents/Bin/payload/` as
  `slot_material.py`.
- **C++:** build `native/soap_bubble_payload.vcxproj` and copy
  `native/out/Release/slot_material_native.dll` next to the slots in `Contents/Bin/`. Restart
  3ds Max; an unmanaged payload is pinned for the session.

The material slot holds one cartridge at a time, so this replaces whatever material cartridge was
there.

## What it does not do

- It does not render in Arnold, and it looks flat in the viewport (the viewport gets one tint).
- It fakes the environment it reflects; it does not trace the real scene.

## Facts worth keeping current

| | |
| --- | --- |
| Slot | `material` |
| Lanes | Python `python/soap_bubble.py`, C++ `native/src/payload.cpp` |
| Requires | 3ds Max 2026, plugin 0.8.0-alpha.8 |
| Version | see `cartridge.json` and `Version.props` - change both together |
