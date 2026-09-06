# Authoring a slot

**A slot is a 3ds Max plugin that hosts cartridges.** This page is how you write one — for any
plugin type 3ds Max supports, including types nothing here ships yet.

> **This is the advanced path and most people never need it.** If you want to *write behaviour*, you
> want a cartridge: see [SLOTS.md](SLOTS.md) and use the `bootstrap` skill. A cartridge needs no
> SDK, no compiler for the Python lane, and no page this long. Come here only when the plugin
> **type** you need does not exist yet.

## What you need, and the one thing that cannot be removed

| | |
| --- | --- |
| Windows, 3ds Max | as for everything here |
| **The 3ds Max SDK** | **required, and permanently so** |
| Visual Studio, pinned toolset | `tools\<year>\check-prereqs.ps1` names the exact component |
| `include\` and `lib\` from your install | the slot headers and the slot library |

**Why the SDK cannot be removed.** A slot derives from a 3ds Max SDK class — `Modifier`,
`UtilityObj`, `SceneExport`, and so on — and hands the host a `ClassDesc` whose vtable those headers
define. 3ds Max loads your binary and calls into that vtable itself. No library can stand between
those two things. Every other page here promises you need no SDK; that promise is about writing
cartridges and it is true. It does not extend to this page.

## The two halves, and which one is yours

| **The thin half — you write it** | **The machinery — you link it** |
| --- | --- |
| a class derived from the SDK type you want | finding and loading a payload |
| its `ClassDesc` and the answers it gives | the hot swap, and abandoning a generation |
| the four `Lib*` exports and the `.def` | the payload ABI and every refusal it returns |
| a fixed `Class_ID`, name, and payload module name | the panel bridge, logging, the server crossing |

The thin half is boilerplate against the SDK; its own `samples\` directory demonstrates the same
shape a few dozen times. The machinery is `lib\mcpslot.lib`, which you link and never read.

## What you write

Six headers, included by plain name from `include\`:

```cpp
#include "CartridgeApi.h"           // reaching the server
#include "CartridgeNativeHost.h"    // the payload loader and hot swap
#include "MaxFacade.h"              // installing the slot side of the facade
#include "CartridgePayloadApi.h"    // the ABI a payload implements
#include "CartridgeUi.h"            // panel shapes, if your type has a panel
#include "Json.h"                   // the JSON everything here speaks
```

Three constants decide what your slot *is*, and all three are compiled in:

```cpp
const Class_ID   MySlotClassId(0x........, 0x........);   // generate once, then never change it
const char* const PayloadModule = "slot_myflavour";       // the cartridge this slot loads
                                 ClassName() -> "Cartridge <Kind>"   // what a user reads
```

### The `Class_ID` is permanent from the first saved scene

A saved `.max` resolves plug-ins by `(SuperClassID, Class_ID)`. Generate it from a cryptographic
RNG — never choose it, never derive it from a name, two people who pick the same obvious name
collide and neither finds out until a scene fails to load on the other's machine.

**And it belongs to the slot, not to the cartridge in it.** A scene saved while one cartridge
occupied your slot will evaluate whatever occupies it later. That is a property of slots, not a
defect; say it in your slot's README.

### The display name becomes a MAXScript global

Spaces become underscores and `+` characters are **dropped**. `Bend ++` mangles to `Bend`, collides
with the stock modifier, and 3ds Max resolves it silently by appending the superclass — producing a
name that depends on plugin load order and that nothing can script against. Keep to letters and
spaces, and check it with:

```bash
powershell -File tools\claim-cartridge-name.ps1 -Name "Cartridge Whatever" -ClassesJson <file> -Human
```

## Building it

Mirror the settings of the slot you can see building — the pinned toolset above all. **A slot built
with a different toolset does not fail to compile. It produces a binary that is wrong**, and the
failure arrives later and somewhere else.

```
include        include\
link           lib\mcpslot.lib   + the maxsdk libs your plugin type needs
toolset        the pinned one, and no other
runtime        /MD, matching the library and the host
extension      the one 3ds Max expects for your type - .dlm modifier, .dlu utility,
               .dle exporter, .dli importer, .dlo object
```

## Making 3ds Max load it

A slot goes in the plugin bundle beside the others and needs **its own `<ComponentEntry>`** in the
manifest.

> **This is the failure that will cost you an afternoon.** A module sitting in the bundle's `Bin`
> directory *without* a `ComponentEntry` loads at the DLL level, is never asked for its classes, and
> reports nothing at all. No error, no log line, no entry in the host. It looks exactly like a slot
> that failed to compile something. If your slot is not in the host, check the manifest **first**.

## How you know it works

**Verify in the host, never in the build log.** A green build says the compiler was satisfied; it
says nothing about registration, which is where slots fail.

1. Restart 3ds Max. Classes register once during the startup scan — there is no way to add one to a
   running session, so nothing you do will make it appear without this.
2. Find your slot where its type appears — Modifier List, Utilities rollout, "Save as type".
3. Deploy a cartridge under your `PayloadModule` name and apply it.
4. Click through to something the payload does, and see the result **in 3ds Max**.

**When that works, six things are proven at once:** the manifest declared your module, the host
registered your class, the machinery found your payload, the interpreter loaded it, an event crossed
into it, and its answer came back. Until step 4, none of them is established.

**If nothing appears, in this order:** is it declared in the manifest; did the host actually
restart; is the extension right for the type; is your `Class_ID` colliding. Only after all four is
it worth suspecting your code.

## What is supported, and what is not

**Supported:** authoring a slot for any plugin type the 3ds Max SDK exposes, using the published
headers and library.

**Not supported, and not silently:**

- **Anything requiring the machinery's source.** It ships as a binary. If you cannot do what you
  need through the published headers, that is a gap worth reporting — open an issue rather than
  working around it, because a workaround becomes something you maintain forever.
- **A different toolset.** Not "discouraged" — the result is a binary that is wrong.
- **Replacing a shipped slot's `Class_ID`,** or reusing one. Both break saved scenes.

**How to find out what is currently true rather than trusting this page:** ask the running server
for its capabilities. That answer is live and this page can lag a release; when they disagree, the
server is right.

## Before you open a pull request

A slot is a bigger change than a cartridge, so it is held to the same rules and two more.

Everything in [CARTRIDGE_PR.md](CARTRIDGE_PR.md) applies — announced, versioned, `requires` records
what you ran it against. In addition:

- [ ] **Say which plugin type it is and why it needs a slot.** A type that could have been a
      cartridge on an existing slot should be one.
- [ ] **State the evidence.** Which 3ds Max, which plugin version, and that you saw a cartridge run
      in it — not that it built.
- [ ] **Include the `Class_ID` you generated** and confirm it collides with nothing.
- [ ] **Say what you could not test.** A slot nobody but you can exercise is one nobody but you can
      review, and saying so is worth more than a claim that reads clean.

## If you are an agent doing this

Read [CLAUDE.md](../CLAUDE.md) first — it carries the rules that protect the user's machine. Then:
this page tells you what to do, `check-prereqs` tells you whether you can, the host tells you
whether it worked, and `CARTRIDGE_PR.md` tells you when you are done. **None of those four is
replaceable by reasoning about the code.**
