# Barebones: IK Solver

An IK solver reads a bone chain and a goal and computes the joint angles that reach it — the host
calls it whenever the goal moves or the frame changes. This example solves nothing on purpose: it is
the smallest cartridge that proves the whole crossing (slot → interpreter → solve event → log) before
any behaviour is in the way of reading the result. Fork it and put your kinematics in `IKSolve`.

**Hello signal:** a log line on `IKSolve` — fired when the chain needs solving, guarded to announce
once per load — readable with `cartridge_logs -module slot_iksolver`.

## What plugin type this is

An **IK solver** (`IKSolver`). The user assigns it to a bone chain under **Animation ▸ IK Solvers**.
When the chain needs solving — the goal moves, or time changes — the host calls the solver and the
slot forwards it here as `IKSolve`. It writes joint transforms back onto the chain; it does not own
the bones or the goal.

## The SuperClassIDs an IK-solver-shaped cartridge can bear

| SuperClassID | Base class | What it is | Hello surface | Slot |
| --- | --- | --- | --- | --- |
| `IK_SOLVER_CLASS_ID` | `IKSolver` | solves an IK bone chain (Animation ▸ IK Solvers) | log on solve | **this example** (`Cartridge IK Solver`, `.dlc`) |

A solver has no panel of its own to say hello from — it is driven, not opened — so its only honest
hello is the log line on `IKSolve`. That is enough to prove the solver is assigned and being called
before any inverse kinematics is written.

## Lanes

| Lane | File | Deployed as |
| --- | --- | --- |
| Python | [`python/slot_iksolver.py`](python/slot_iksolver.py) | `slot_iksolver` |
| C++ (native) | [`native/src/payload.cpp`](native/src/payload.cpp) | `slot_iksolver_native.dll` |

Both lanes are behaviourally identical; pick Python for fast iteration and hot-swap, C++ when you
need native speed. See the repository root [`README.md`](../../README.md) for the full barebones
index and [`docs/SLOTS.md`](../../docs/SLOTS.md) for how a slot loads a payload by module name.

## Fork it

1. Copy this directory to `cartridges/<your-name>/` (or scaffold with `tools/new-cartridge.ps1`).
2. Put your behaviour in `IKSolve`: compute joint angles that reach the goal and write them back.
3. Declare any parameter in `describe_params` — the slot keeps it, saved and animatable.
4. Assign the solver to a two-bone chain and move the goal, then confirm your log line with
   `cartridge_logs -module slot_iksolver`.
