# MCP tools

The tools the 3ds Max SDK MCP server serves, as the server itself lists them (`tools/list`).
**Generated** from maxsdk-mcp 0.8.0-alpha.8 (protocol 2026-07-28) by the release; do not edit by hand. The same list, machine-readable, is [`mcp-tools.json`](../mcp-tools.json).

Ask a running server for the live list at any time - `tools/list` over MCP, or `max_capabilities` for everything the build serves.

| Tool | What it does | Hints |
| --- | --- | --- |
| [`cartridge_logs`](#cartridge_logs) | Read the cartridge and server logs | idempotent |
| [`max_capabilities`](#max_capabilities) | What this build serves | read-only, idempotent |
| [`max_cartridge_probe`](#max_cartridge_probe) | Exercise a cartridge in the live host and read its hello | idempotent |
| [`max_cartridge_refresh`](#max_cartridge_refresh) | Reload cartridge payloads from disk | idempotent |
| [`max_cartridges`](#max_cartridges) | List the cartridges loaded in this server | read-only, idempotent |
| [`max_facade`](#max_facade) | What this build's host facade carries | read-only, idempotent |
| [`max_job_cancel`](#max_job_cancel) | Ask a job to stop | idempotent |
| [`max_job_result`](#max_job_result) | A finished job's answer | read-only, idempotent |
| [`max_job_start`](#max_job_start) | Start a job | **changes or discards scene/session state** |
| [`max_job_status`](#max_job_status) | How a job is going | read-only, idempotent |
| [`max_jobs`](#max_jobs) | The jobs running, and the kinds that can be started | read-only, idempotent |
| [`max_python_probe`](#max_python_probe) | Prove an isolated interpreter works | read-only, idempotent |
| [`max_python_status`](#max_python_status) | The embedded Python runtime | read-only, idempotent |
| [`max_quit`](#max_quit) | Quit 3ds Max | **changes or discards scene/session state** |
| [`max_restart`](#max_restart) | Restart 3ds Max and reopen the scene | **changes or discards scene/session state** |
| [`max_scene_open`](#max_scene_open) | Open a scene file | **changes or discards scene/session state** |
| [`max_scene_reset`](#max_scene_reset) | Reset the scene | **changes or discards scene/session state**, idempotent |
| [`max_scene_save`](#max_scene_save) | Save the scene | idempotent |
| [`max_scene_save_as`](#max_scene_save_as) | Save the scene to a file | - |
| [`max_scene_state`](#max_scene_state) | What scene is open | read-only, idempotent |
| [`max_tools`](#max_tools) | The Python tools in this session's workspace | read-only, idempotent |

## cartridge_logs

**Read the cartridge and server logs.**

The session's own record: what the server did as it started, every cartridge instance that opened or closed, every crossing into Python, and everything a payload printed or raised - each line timestamped and tagged with the object name and the instance GUID that produced it. This is the first place to look when a cartridge behaves unexpectedly, because it says what actually happened rather than what was supposed to. Verbose lines are suppressed unless MAXMCP_LOG_VERBOSITY says otherwise.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `module` | string | no | Which log to read. Omit to list the logs that exist. 'maxsdk-mcp' is the server's own; every other name is a cartridge's payload module, such as 'bend_cpp'. |
| `lines` | number | no | How many lines from the end, newest last. Default 200, maximum 5000. |
| `contains` | string | no | Keep only lines containing this text. The instance tag is '<object name>#<guid>', so an object's name narrows to one object and a GUID narrows to exactly one modifier instance. |
| `level` | string | no | Keep only this verbosity: Error, Warning, Display, Debug or Verbose. |
| `verbosity` | string | no | SETS what the log records from now on, and takes effect immediately - no restart, so the session that raised the question survives to answer it. Verbose adds the per-evaluation boundary lines, which is what to turn on when a modifier is not doing what it should; it is off by default because a viewport can produce them sixty times a second. The reply always reports the level now in force. |

## max_capabilities

**What this build serves.**

The live truth about this build: server name, the build id of the DLL actually in memory, the tools served, and the documentation resources. Trust this over any document.

No arguments.

## max_cartridge_probe

**Exercise a cartridge in the live host and read its hello.**

Verifies that a deployed cartridge actually loads and SAYS HELLO, without a restart or an external harness. It instantiates the plugin its slot registers, drives it once on the main thread inside an undo wrap, and returns the log lines it produced. `ok` is true ONLY when the payload logged its own hello (helloLines) - never merely because the log grew: a delta of only Error lines is ok:false with condition `payload_raised` and the errors in errorLines, and a type whose hello fires only under an action a headless probe cannot synthesise (a render-effects pass, an IK solve, an interactive snap, a live particle sim) is ok:false with condition `needs_host_action` naming exactly what a person must do. A load-time init/shutdown report (FR-0006) is NOT a greeting and never greens the probe. Every shipped slot has a built-in recipe, so a bare `module:slot_<type>` just works: the driveable types return ok:true with their greeting, the host-action types (effect, iksolver, osnap, pfoperator, utility, colpick, flt) return ok:false/needs_host_action. Pass a 'script' only for a bespoke case. Reverts by default, so it changes nothing in the scene. Read helloLines and errorLines, then cartridge_logs for the full history.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `module` | string | no | The payload module to watch and, if no 'script' is given, to pick a built-in recipe for - e.g. 'slot_modifier'. The probe returns the log lines this module gains while the trigger runs. Omit it to watch every module that has a log (only useful with 'script'). |
| `script` | string | no | A pymxs snippet to run on the main thread to exercise the cartridge, for a type with no built-in recipe or a bespoke case. Runs inside the same undo wrap. When given it replaces the recipe. Example: "import pymxs; rt=pymxs.runtime; rt.box()". |
| `keep` | boolean | no | Keep whatever the trigger built instead of undoing it. Default false: the probe reverts, so it leaves the scene exactly as it found it. |
| `contains` | string | no | Return only new log lines containing this substring (e.g. 'Hello'). |
| `timeoutMs` | number | no | Main-thread budget in milliseconds (default 30000, clamped to 1000-120000). |

## max_cartridge_refresh

**Reload cartridge payloads from disk.**

Re-imports the Python of the matching cartridges in place, picking up whatever is on disk now - the same thing a cartridge's Refresh control does, without needing a person at the command panel. This is how an edited payload takes effect: an interpreter caches a module for its whole life, so a changed file otherwise does nothing to an existing modifier until it is deleted and recreated, which throws away its place in the stack. Reloads every payload-directory module, not just the entry one, and reports which. With build=true (the default) it ALSO compiles, deploys and hot-swaps each matched cartridge's native payload: MSBuild out of process, structured diagnostics on failure with the old code left serving, and the swap read back from the loaded module itself. Runs on the host's main thread; if 3ds Max does not finish in time the reply is marked partial and reports what had completed rather than guessing. Put a progressToken in params._meta and each build diagnostic arrives as it is parsed instead of at the end, so a compile error is readable seconds in rather than at the finish. Closing the response stream cancels the build.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `match` | string | no | Which cartridges to reload - matched against module, object name, tag or GUID, as in max_cartridges. Omit to reload every open cartridge, which is usually what is wanted after editing a shared framework file such as mcp_ui.py. |
| `limit` | number | no | How many cartridges to reload in this call. Default 25, maximum 200. Reloading re-executes Python on the thread 3ds Max draws with, so a batch is a slice by design: the reply says how many matched and how many remain, and calling again continues. |
| `build` | boolean | no | Also compile, deploy and hot-swap the NATIVE payload of each matched cartridge that declares one (default true). The pipeline is: the shell describes its source location, MSBuild runs out of process, the fresh artifact is deployed beside the .dlm, and each instance swaps at its own sync point - reported per step, with structured compiler diagnostics on failure and the old payload left serving. The first native load of a session asks the user's consent; after that, swaps of the same modules run freely. False skips all of it and reloads Python only. |

## max_cartridges

**List the cartridges loaded in this server.**

Every cartridge instance currently open: its payload module, the 3ds Max object it is attached to, its own GUID, and whether its interpreter is up. A cartridge is one modifier instance with its own Python interpreter, so a scene with forty bends has forty entries sharing one module - start with summary:true to see the shape before asking for the rows. Paged: the reply says how many matched, whether it truncated and why, and carries a cursor to continue. Start here before cartridge_logs or max_cartridge_refresh; all three take the same identifying text. Enters no Python and touches no scene state, so it is safe to call at any time.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `match` | string | no | Keep only cartridges whose module, object name, instance tag or GUID contains this text. Omit for all of them. The tag is '<object name>#<guid>', the same form the log lines carry, so a string that narrows a log narrows this identically. |
| `summary` | boolean | no | Return only the per-module instance counts and stop. This is the cheap question - 'what is loaded, and how much of it' - and it costs one row per MODULE rather than one per instance, so it stays small on a scene where the full listing would not. |
| `limit` | number | no | How many cartridges to return. Default 100, maximum 1000. Values outside that are clamped rather than refused. |
| `after` | number | no | Continue a previous listing: pass the 'next_after' from its reply. This is a cursor over handles, not an offset, so instances created or deleted between calls cannot make the walk skip or repeat a row. |
| `payload` | boolean | no | Also describe each returned cartridge's payload lanes: whether Python is up, which native generation is loaded (version, build stamp, variant, content hash), where the canonical native DLL sits and whether a newer one is waiting to swap, and the compiled-in source locations a native build would use. Costs one main-thread crossing and a small file hash per row, so it is off by default. |

## max_facade

**What this build's host facade carries.**

The table this server publishes to code running inside it: the facade ABI it was compiled at, the struct's own size, how many entries it declares, how many it actually serves, and the name of any it declares and does not serve. Ask this BEFORE writing code against the facade rather than discovering a gap as a refusal afterwards - the ABI is additive, so which entries exist is a property of the build and not of the protocol. Touches no scene state and needs no main thread, so it is safe to call at any time.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `entries` | boolean | no | Also list every entry this build serves, by name. Default false: there are hundreds, and the counts plus the gaps are what a caller usually needs. |

## max_job_cancel

**Ask a job to stop.**

Asks one job to stop and returns at once with state 'cancelling' - a REQUEST, not an outcome. Cancellation is cooperative: it lands between steps always, inside a loop that checks, and never inside a call already executing, so a host_exclusive job cannot be cancelled once its window has opened. Poll the status for 'cancelled'. Cancelling something already finished is not an error and reports the state it is in.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `id` | string | yes | The job to stop. |

## max_job_result

**A finished job's answer.**

The value a completed job produced, readable for as long as its record is retained - so an answer outlives the reply that announced it. A job that has not finished is REFUSED with its current state rather than answered with nothing: 'not done yet' and 'done, and empty' are different facts and a caller that cannot tell them apart will conclude the wrong one.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `id` | string | yes | The completed job whose answer you want. |

## max_job_start

**Start a job.**

Starts work and returns a HANDLE, not an answer - the job runs after this reply. Everything you know about tool calls changes here: poll max_job_status for progress, and polling is also how this server learns you still want the job (one nobody asks about parks itself); cancel is a request with a 'cancelling' state to read rather than assume; progress may honestly report an unknown total until the work discovers it; and a job's main-thread windows compete with your own calls for 3ds Max. Refused with a named condition when the concurrency ceiling is already reached, rather than queued behind work you cannot see. The FIRST start of a kind that runs code this session wrote asks the user, once per 3ds Max session; later ones do not.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `kind` | string | yes | Which kind of work. max_jobs with kinds:true lists them. |
| `params` | object | no | The kind's own arguments, passed through verbatim. For kind 'python': either 'source' (Python to run) or 'tool' (a workspace tool named by max_tools) but never both, plus optional 'args' and 'allowMutation'. |
| `description` | string | no | What this run is FOR, in a phrase. Shown in every listing, so a page of jobs reads as work rather than as identifiers. |
| `idempotencyKey` | string | no | Repeat the same key to get the SAME job back rather than a second one. A dropped reply is a transport failure, not a request to do the work twice. |
| `taskLimit` | number | no | Stop after this many tasks and PAUSE with reason 'limit', which turns any job into a probe. Omit for no stop point. |

## max_job_status

**How a job is going.**

One job's state, and the three questions a poll should answer: how far (units done and total, where a total of -1 means honestly not known yet), what now (the task running), and what so far (a bounded page of outcomes, with the number that fell off it counted rather than hidden). Also reports how many main-thread windows this job has taken and for how long, which is where a stuttering viewport is explained. Calling this resets the job's orphan timer: polling IS the signal that you still want it.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `id` | string | yes | The job id max_job_start returned. |

## max_jobs

**The jobs running, and the kinds that can be started.**

Every job this session has started, oldest first, with its state, progress, current task and a bounded page of outcomes - or, with kinds:true, the kinds available and which verbs each supports. Reading this list does NOT count as asking about a job: only max_job_status resets a job's orphan timer, so a monitor cannot keep an abandoned job alive. Touches no scene state.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `kinds` | boolean | no | List the job KINDS this build serves and what each one can do, instead of the jobs themselves. Default false. |

## max_python_probe

**Prove an isolated interpreter works.**

Creates a sub-interpreter that owns its GIL, runs a fixed built-in script in it, and destroys it. Reports what that interpreter saw. It does not run anything a caller sends; the script is compiled into this binary.

No arguments.

## max_python_status

**The embedded Python runtime.**

Whether this plugin's own CPython is running, which version it is, and where it was loaded from. This is not the interpreter 3ds Max bundles: both live in this process, they share nothing, and pymxs belongs to the host's.

No arguments.

## max_quit

**Quit 3ds Max.**

Ends the 3ds Max session, and with it this server. Defaults to save false and prompt false: it exits at once and discards unsaved work. The reply is an acknowledgement rather than an outcome, because no reply can be sent after the host is gone - the port going quiet is the confirmation.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `save` | boolean | no | Save over the current file before exiting. Default false, which discards unsaved work. Refused when the scene has never been saved. |
| `prompt` | boolean | no | Let 3ds Max ask about unsaved changes. Default false, which exits without asking. When true the user may cancel and the host may keep running. |

## max_restart

**Restart 3ds Max and reopen the scene.**

Closes 3ds Max and starts it again with the same scene file. Needed after any change to a native plugin, because 3ds Max cannot unload one - a cartridge's Python can be reloaded live, but its C++ shell cannot. Refuses when the scene has never been saved, since there would be nothing to reopen. The reply is an acknowledgement: this server goes down with the host and comes back with it. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `save` | boolean | no | Save the scene before restarting. Default TRUE - the opposite of max_quit, because a restart is meant to come back to the same session and losing it would defeat that. |

## max_scene_open

**Open a scene file.**

Loads a .max file, discarding whatever is open. The path is resolved on the machine running 3ds Max, must be absolute, and must name a .max file. Destroys unsaved work in the current scene without asking when prompt is false. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `path` | string | no | Absolute path to a .max file on the machine running 3ds Max. Required unless prompt is true. |
| `prompt` | boolean | no | Show the host's own open dialog and let the user choose. Default false. Cannot be combined with a path, which the dialog would ignore. |

## max_scene_reset

**Reset the scene.**

Discards the open scene for an empty one. With prompt false this cannot be undone and does not ask. Call max_scene_state first, and get the user's word before throwing away a scene with unsaved changes. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `prompt` | boolean | no | Let 3ds Max ask the user first. Default false, which resets without asking. When true the call returns as soon as the dialog is raised and cannot report the answer. |

## max_scene_save

**Save the scene.**

Saves the scene over the file it came from. Refuses when the scene has never been saved, because the host would answer that with a dialog nobody can see; use max_scene_save_as instead. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.

No arguments.

## max_scene_save_as

**Save the scene to a file.**

Writes the scene to a named .max file, which becomes the current one. Refuses to replace an existing file unless overwrite is set. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.

| Argument | Type | Required | Meaning |
| --- | --- | --- | --- |
| `path` | string | yes | Absolute path to write, ending in .max. Its directory must already exist. |
| `overwrite` | boolean | no | Permit replacing an existing file. Default false, which refuses rather than overwrite. Ask the user before setting this: the file being replaced is theirs and the replacement cannot be undone. |

## max_scene_state

**What scene is open.**

The file the open scene came from and whether it has unsaved changes. Call this before any tool that resets, opens or quits: those destroy what this reports, and saveRequired null means the flag could not be read, not that there is nothing to lose.

No arguments.

## max_tools

**The Python tools in this session's workspace.**

Every tool in the workspace, as a TREE: namespace, its tools, their schemas, and anything that failed to parse - listed BY NAME with the reason, because a file that vanishes when it breaks is a file nobody can fix. A tool is one .py declaring TOOL = {name, description, inputSchema} and a run(args); adding one is adding a file, with no restart and no registration. This server never writes the workspace - the namespace is derived from the path, so it cannot drift. Listing PARSES the manifest and executes nothing. Run a tool with max_job_start, kind 'python', params.tool set to the qualified name.

No arguments.
