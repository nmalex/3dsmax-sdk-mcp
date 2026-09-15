# Barebones: Fragment

A Fragment super-class plugin — a render-pipeline fragment; works through ViewExp/GraphicsWindow.

> **Deferred — registers, but its greeting is not yet reachable.** A slot **is** built and the class
> **registers**: `Cartridge_Fragment` is enumerable in a live host, which proves the shell loads. But
> a `ViewFragment` is not a MAXScript value type (creating it returns `undefined`), and its only
> callback, `DoEvaluate`, runs inside the viewport display fragment-graph — which no scriptable path
> and no standalone manual action triggers for a bare fragment. So its `Hello World` cannot yet be
> observed. It is kept as **proof of registration** and a starting point, and graduates the day the
> slot model can drive a display-pipeline fragment. This is neither a shipping slot nor a failure — the
> one honest in-between. The [super-class census](../../docs/SUPERCLASS_CENSUS.md) lists it under
> *deferred*.

## The SuperClassID it registers under

| SuperClassID | hex | What registers here |
| --- | --- | --- |
| `Fragment_CLASS_ID` | 0x0011B0 | a Fragment super-class plugin |

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_fragment.py`](python/slot_fragment.py) | `slot_fragment` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_fragment_native.dll` |

## Using this example

The slot is built and the class registers, but its greeting is unreachable today (see above), so this
example is kept as proof of registration and a starting point rather than a runnable hello. It
graduates when the slot model can drive a display-pipeline fragment.
