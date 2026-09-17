"""3ds Max SDK MCP - stdio bridge.

The plugin serves MCP over HTTP on 127.0.0.1, inside a running 3ds Max. Some MCP clients only start
servers as a command and talk to them over stdin/stdout. This bridge is that command: it speaks MCP
over stdio to the client and forwards every call to the plugin's local endpoint.

    python tools/mcp_bridge.py [--port 3000] [--host-timeout 900]

Client configuration (the usual "mcpServers" shape):

    {"mcpServers": {"3dsmax": {"command": "python",
                               "args": ["C:/path/to/3dsmax-sdk-mcp/tools/mcp_bridge.py"]}}}

WHAT IT DOES
  * Answers the stdio handshake (initialize, ping) itself.
  * tools/list: the plugin's live list when 3ds Max is running; otherwise the tools declared below,
    so a client can still see what exists before 3ds Max starts.
  * tools/call, resources/*: forwarded to the plugin. When a call would destroy work, the plugin
    asks for the user's consent; if the client supports elicitation the bridge puts that question
    to the user and sends the answer back. A client that cannot ask gets the plugin's refusal -
    the bridge never answers the question itself.
  * If 3ds Max is not running, a call returns an error result saying so, rather than failing the
    connection.

Standard library only; Python 3.8 or newer. Nothing leaves this machine: the bridge talks only to
127.0.0.1 (see SECURITY.md and PRIVACY.md).

The tool declarations below are GENERATED from the plugin's own tools/list for each release
(docs/TOOLS.md and mcp-tools.json are the same list). Do not edit that block by hand.
"""

import argparse
import base64
import json
import queue
import sys
import threading
import urllib.error
import urllib.request

BRIDGE_NAME = "3dsmax-sdk-mcp-bridge"
BRIDGE_VERSION = "0.1.0"

# Stdio protocol revisions this bridge speaks to its client, newest first.
SUPPORTED_PROTOCOLS = ("2025-11-25", "2025-06-18", "2025-03-26", "2024-11-05")

# The plugin's HTTP revision, used when /health does not name one.
FALLBACK_UPSTREAM_PROTOCOL = "2026-07-28"

# The plugin binds 3000 and, when that is taken, the next two ports.
DEFAULT_PORT = 3000
PORT_FALLBACK = 2


class Tool(object):
    """One MCP tool the plugin serves, as declared in its tools/list."""

    def __init__(self, name, title, description, input_schema, annotations):
        self.name = name
        self.title = title
        self.description = description
        self.input_schema = input_schema
        self.annotations = annotations

    def to_mcp(self):
        return {"name": self.name, "title": self.title, "description": self.description,
                "inputSchema": self.input_schema, "annotations": self.annotations}


# --- BEGIN GENERATED TOOLS (tools/export-mcp-tools.py; do not edit) ---
TOOLS = [
    Tool(
        'cartridge_logs',
        'Read the cartridge and server logs',
        "The session's own record: what the server did as it started, every cartridge instance that opened or closed, every crossing into Python, and everything a payload printed or raised - each line timestamped and tagged with the object name and the instance GUID that produced it. This is the first place to look when a cartridge behaves unexpectedly, because it says what actually happened rather than what was supposed to. Verbose lines are suppressed unless MAXMCP_LOG_VERBOSITY says otherwise.",
        {'type': 'object', 'properties': {'module': {'type': 'string', 'description': "Which log to read. Omit to list the logs that exist. 'maxsdk-mcp' is the server's own; every other name is a cartridge's payload module, such as 'bend_cpp'."}, 'lines': {'type': 'number', 'description': 'How many lines from the end, newest last. Default 200, maximum 5000.'}, 'contains': {'type': 'string', 'description': "Keep only lines containing this text. The instance tag is '<object name>#<guid>', so an object's name narrows to one object and a GUID narrows to exactly one modifier instance."}, 'level': {'type': 'string', 'description': 'Keep only this verbosity: Error, Warning, Display, Debug or Verbose.'}, 'verbosity': {'type': 'string', 'description': 'SETS what the log records from now on, and takes effect immediately - no restart, so the session that raised the question survives to answer it. Verbose adds the per-evaluation boundary lines, which is what to turn on when a modifier is not doing what it should; it is off by default because a viewport can produce them sixty times a second. The reply always reports the level now in force.'}}, 'required': [], 'additionalProperties': False},
        {'title': 'Read the cartridge and server logs', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_capabilities',
        'What this build serves',
        'The live truth about this build: server name, the build id of the DLL actually in memory, the tools served, and the documentation resources. Trust this over any document.',
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': 'What this build serves', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_cartridge_probe',
        'Exercise a cartridge in the live host and read its hello',
        "Verifies that a deployed cartridge actually loads and SAYS HELLO, without a restart or an external harness. It instantiates the plugin its slot registers, drives it once on the main thread inside an undo wrap, and returns the log lines it produced. `ok` is true ONLY when the payload logged its own hello (helloLines) - never merely because the log grew: a delta of only Error lines is ok:false with condition `payload_raised` and the errors in errorLines, and a type whose hello fires only under an action a headless probe cannot synthesise (a render-effects pass, an IK solve, an interactive snap, a live particle sim) is ok:false with condition `needs_host_action` naming exactly what a person must do. A load-time init/shutdown report (FR-0006) is NOT a greeting and never greens the probe. Every shipped slot has a built-in recipe, so a bare `module:slot_<type>` just works: the driveable types return ok:true with their greeting, the host-action types (effect, iksolver, osnap, pfoperator, utility, colpick, flt) return ok:false/needs_host_action. Pass a 'script' only for a bespoke case. Reverts by default, so it changes nothing in the scene. Read helloLines and errorLines, then cartridge_logs for the full history.",
        {'type': 'object', 'properties': {'module': {'type': 'string', 'description': "The payload module to watch and, if no 'script' is given, to pick a built-in recipe for - e.g. 'slot_modifier'. The probe returns the log lines this module gains while the trigger runs. Omit it to watch every module that has a log (only useful with 'script')."}, 'script': {'type': 'string', 'description': 'A pymxs snippet to run on the main thread to exercise the cartridge, for a type with no built-in recipe or a bespoke case. Runs inside the same undo wrap. When given it replaces the recipe. Example: "import pymxs; rt=pymxs.runtime; rt.box()".'}, 'keep': {'type': 'boolean', 'description': 'Keep whatever the trigger built instead of undoing it. Default false: the probe reverts, so it leaves the scene exactly as it found it.'}, 'contains': {'type': 'string', 'description': "Return only new log lines containing this substring (e.g. 'Hello')."}, 'timeoutMs': {'type': 'number', 'description': 'Main-thread budget in milliseconds (default 30000, clamped to 1000-120000).'}}, 'required': [], 'additionalProperties': False},
        {'title': 'Exercise a cartridge in the live host and read its hello', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_cartridge_refresh',
        'Reload cartridge payloads from disk',
        "Re-imports the Python of the matching cartridges in place, picking up whatever is on disk now - the same thing a cartridge's Refresh control does, without needing a person at the command panel. This is how an edited payload takes effect: an interpreter caches a module for its whole life, so a changed file otherwise does nothing to an existing modifier until it is deleted and recreated, which throws away its place in the stack. Reloads every payload-directory module, not just the entry one, and reports which. With build=true (the default) it ALSO compiles, deploys and hot-swaps each matched cartridge's native payload: MSBuild out of process, structured diagnostics on failure with the old code left serving, and the swap read back from the loaded module itself. Runs on the host's main thread; if 3ds Max does not finish in time the reply is marked partial and reports what had completed rather than guessing. Put a progressToken in params._meta and each build diagnostic arrives as it is parsed instead of at the end, so a compile error is readable seconds in rather than at the finish. Closing the response stream cancels the build.",
        {'type': 'object', 'properties': {'match': {'type': 'string', 'description': 'Which cartridges to reload - matched against module, object name, tag or GUID, as in max_cartridges. Omit to reload every open cartridge, which is usually what is wanted after editing a shared framework file such as mcp_ui.py.'}, 'limit': {'type': 'number', 'description': 'How many cartridges to reload in this call. Default 25, maximum 200. Reloading re-executes Python on the thread 3ds Max draws with, so a batch is a slice by design: the reply says how many matched and how many remain, and calling again continues.'}, 'build': {'type': 'boolean', 'description': "Also compile, deploy and hot-swap the NATIVE payload of each matched cartridge that declares one (default true). The pipeline is: the shell describes its source location, MSBuild runs out of process, the fresh artifact is deployed beside the .dlm, and each instance swaps at its own sync point - reported per step, with structured compiler diagnostics on failure and the old payload left serving. The first native load of a session asks the user's consent; after that, swaps of the same modules run freely. False skips all of it and reloads Python only."}}, 'required': [], 'additionalProperties': False},
        {'title': 'Reload cartridge payloads from disk', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_cartridges',
        'List the cartridges loaded in this server',
        'Every cartridge instance currently open: its payload module, the 3ds Max object it is attached to, its own GUID, and whether its interpreter is up. A cartridge is one modifier instance with its own Python interpreter, so a scene with forty bends has forty entries sharing one module - start with summary:true to see the shape before asking for the rows. Paged: the reply says how many matched, whether it truncated and why, and carries a cursor to continue. Start here before cartridge_logs or max_cartridge_refresh; all three take the same identifying text. Enters no Python and touches no scene state, so it is safe to call at any time.',
        {'type': 'object', 'properties': {'match': {'type': 'string', 'description': "Keep only cartridges whose module, object name, instance tag or GUID contains this text. Omit for all of them. The tag is '<object name>#<guid>', the same form the log lines carry, so a string that narrows a log narrows this identically."}, 'summary': {'type': 'boolean', 'description': "Return only the per-module instance counts and stop. This is the cheap question - 'what is loaded, and how much of it' - and it costs one row per MODULE rather than one per instance, so it stays small on a scene where the full listing would not."}, 'limit': {'type': 'number', 'description': 'How many cartridges to return. Default 100, maximum 1000. Values outside that are clamped rather than refused.'}, 'after': {'type': 'number', 'description': "Continue a previous listing: pass the 'next_after' from its reply. This is a cursor over handles, not an offset, so instances created or deleted between calls cannot make the walk skip or repeat a row."}, 'payload': {'type': 'boolean', 'description': "Also describe each returned cartridge's payload lanes: whether Python is up, which native generation is loaded (version, build stamp, variant, content hash), where the canonical native DLL sits and whether a newer one is waiting to swap, and the compiled-in source locations a native build would use. Costs one main-thread crossing and a small file hash per row, so it is off by default."}}, 'required': [], 'additionalProperties': False},
        {'title': 'List the cartridges loaded in this server', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_facade',
        "What this build's host facade carries",
        "The table this server publishes to code running inside it: the facade ABI it was compiled at, the struct's own size, how many entries it declares, how many it actually serves, and the name of any it declares and does not serve. Ask this BEFORE writing code against the facade rather than discovering a gap as a refusal afterwards - the ABI is additive, so which entries exist is a property of the build and not of the protocol. Touches no scene state and needs no main thread, so it is safe to call at any time.",
        {'type': 'object', 'properties': {'entries': {'type': 'boolean', 'description': 'Also list every entry this build serves, by name. Default false: there are hundreds, and the counts plus the gaps are what a caller usually needs.'}}, 'required': [], 'additionalProperties': False},
        {'title': "What this build's host facade carries", 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_job_cancel',
        'Ask a job to stop',
        "Asks one job to stop and returns at once with state 'cancelling' - a REQUEST, not an outcome. Cancellation is cooperative: it lands between steps always, inside a loop that checks, and never inside a call already executing, so a host_exclusive job cannot be cancelled once its window has opened. Poll the status for 'cancelled'. Cancelling something already finished is not an error and reports the state it is in.",
        {'type': 'object', 'properties': {'id': {'type': 'string', 'description': 'The job to stop.'}}, 'required': ['id'], 'additionalProperties': False},
        {'title': 'Ask a job to stop', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_job_result',
        "A finished job's answer",
        "The value a completed job produced, readable for as long as its record is retained - so an answer outlives the reply that announced it. A job that has not finished is REFUSED with its current state rather than answered with nothing: 'not done yet' and 'done, and empty' are different facts and a caller that cannot tell them apart will conclude the wrong one.",
        {'type': 'object', 'properties': {'id': {'type': 'string', 'description': 'The completed job whose answer you want.'}}, 'required': ['id'], 'additionalProperties': False},
        {'title': "A finished job's answer", 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_job_start',
        'Start a job',
        "Starts work and returns a HANDLE, not an answer - the job runs after this reply. Everything you know about tool calls changes here: poll max_job_status for progress, and polling is also how this server learns you still want the job (one nobody asks about parks itself); cancel is a request with a 'cancelling' state to read rather than assume; progress may honestly report an unknown total until the work discovers it; and a job's main-thread windows compete with your own calls for 3ds Max. Refused with a named condition when the concurrency ceiling is already reached, rather than queued behind work you cannot see. The FIRST start of a kind that runs code this session wrote asks the user, once per 3ds Max session; later ones do not.",
        {'type': 'object', 'properties': {'kind': {'type': 'string', 'description': 'Which kind of work. max_jobs with kinds:true lists them.'}, 'params': {'type': 'object', 'description': "The kind's own arguments, passed through verbatim. For kind 'python': either 'source' (Python to run) or 'tool' (a workspace tool named by max_tools) but never both, plus optional 'args' and 'allowMutation'."}, 'description': {'type': 'string', 'description': 'What this run is FOR, in a phrase. Shown in every listing, so a page of jobs reads as work rather than as identifiers.'}, 'idempotencyKey': {'type': 'string', 'description': 'Repeat the same key to get the SAME job back rather than a second one. A dropped reply is a transport failure, not a request to do the work twice.'}, 'taskLimit': {'type': 'number', 'description': "Stop after this many tasks and PAUSE with reason 'limit', which turns any job into a probe. Omit for no stop point."}}, 'required': ['kind'], 'additionalProperties': False},
        {'title': 'Start a job', 'readOnlyHint': False, 'destructiveHint': True, 'idempotentHint': False, 'openWorldHint': False},
    ),
    Tool(
        'max_job_status',
        'How a job is going',
        "One job's state, and the three questions a poll should answer: how far (units done and total, where a total of -1 means honestly not known yet), what now (the task running), and what so far (a bounded page of outcomes, with the number that fell off it counted rather than hidden). Also reports how many main-thread windows this job has taken and for how long, which is where a stuttering viewport is explained. Calling this resets the job's orphan timer: polling IS the signal that you still want it.",
        {'type': 'object', 'properties': {'id': {'type': 'string', 'description': 'The job id max_job_start returned.'}}, 'required': ['id'], 'additionalProperties': False},
        {'title': 'How a job is going', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_jobs',
        'The jobs running, and the kinds that can be started',
        "Every job this session has started, oldest first, with its state, progress, current task and a bounded page of outcomes - or, with kinds:true, the kinds available and which verbs each supports. Reading this list does NOT count as asking about a job: only max_job_status resets a job's orphan timer, so a monitor cannot keep an abandoned job alive. Touches no scene state.",
        {'type': 'object', 'properties': {'kinds': {'type': 'boolean', 'description': 'List the job KINDS this build serves and what each one can do, instead of the jobs themselves. Default false.'}}, 'required': [], 'additionalProperties': False},
        {'title': 'The jobs running, and the kinds that can be started', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_python_probe',
        'Prove an isolated interpreter works',
        'Creates a sub-interpreter that owns its GIL, runs a fixed built-in script in it, and destroys it. Reports what that interpreter saw. It does not run anything a caller sends; the script is compiled into this binary.',
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': 'Prove an isolated interpreter works', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_python_status',
        'The embedded Python runtime',
        "Whether this plugin's own CPython is running, which version it is, and where it was loaded from. This is not the interpreter 3ds Max bundles: both live in this process, they share nothing, and pymxs belongs to the host's.",
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': 'The embedded Python runtime', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_quit',
        'Quit 3ds Max',
        'Ends the 3ds Max session, and with it this server. Defaults to save false and prompt false: it exits at once and discards unsaved work. The reply is an acknowledgement rather than an outcome, because no reply can be sent after the host is gone - the port going quiet is the confirmation.',
        {'type': 'object', 'properties': {'save': {'type': 'boolean', 'description': 'Save over the current file before exiting. Default false, which discards unsaved work. Refused when the scene has never been saved.'}, 'prompt': {'type': 'boolean', 'description': 'Let 3ds Max ask about unsaved changes. Default false, which exits without asking. When true the user may cancel and the host may keep running.'}}, 'additionalProperties': False},
        {'title': 'Quit 3ds Max', 'readOnlyHint': False, 'destructiveHint': True, 'idempotentHint': False, 'openWorldHint': False},
    ),
    Tool(
        'max_restart',
        'Restart 3ds Max and reopen the scene',
        "Closes 3ds Max and starts it again with the same scene file. Needed after any change to a native plugin, because 3ds Max cannot unload one - a cartridge's Python can be reloaded live, but its C++ shell cannot. Refuses when the scene has never been saved, since there would be nothing to reopen. The reply is an acknowledgement: this server goes down with the host and comes back with it. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.",
        {'type': 'object', 'properties': {'save': {'type': 'boolean', 'description': 'Save the scene before restarting. Default TRUE - the opposite of max_quit, because a restart is meant to come back to the same session and losing it would defeat that.'}}, 'additionalProperties': False},
        {'title': 'Restart 3ds Max and reopen the scene', 'readOnlyHint': False, 'destructiveHint': True, 'idempotentHint': False, 'openWorldHint': False},
    ),
    Tool(
        'max_scene_open',
        'Open a scene file',
        'Loads a .max file, discarding whatever is open. The path is resolved on the machine running 3ds Max, must be absolute, and must name a .max file. Destroys unsaved work in the current scene without asking when prompt is false. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.',
        {'type': 'object', 'properties': {'path': {'type': 'string', 'description': 'Absolute path to a .max file on the machine running 3ds Max. Required unless prompt is true.'}, 'prompt': {'type': 'boolean', 'description': "Show the host's own open dialog and let the user choose. Default false. Cannot be combined with a path, which the dialog would ignore."}}, 'additionalProperties': False},
        {'title': 'Open a scene file', 'readOnlyHint': False, 'destructiveHint': True, 'idempotentHint': False, 'openWorldHint': False},
    ),
    Tool(
        'max_scene_reset',
        'Reset the scene',
        "Discards the open scene for an empty one. With prompt false this cannot be undone and does not ask. Call max_scene_state first, and get the user's word before throwing away a scene with unsaved changes. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.",
        {'type': 'object', 'properties': {'prompt': {'type': 'boolean', 'description': 'Let 3ds Max ask the user first. Default false, which resets without asking. When true the call returns as soon as the dialog is raised and cannot report the answer.'}}, 'additionalProperties': False},
        {'title': 'Reset the scene', 'readOnlyHint': False, 'destructiveHint': True, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_scene_save',
        'Save the scene',
        'Saves the scene over the file it came from. Refuses when the scene has never been saved, because the host would answer that with a dialog nobody can see; use max_scene_save_as instead. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.',
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': 'Save the scene', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_scene_save_as',
        'Save the scene to a file',
        'Writes the scene to a named .max file, which becomes the current one. Refuses to replace an existing file unless overwrite is set. This call can take minutes. Put a progressToken in params._meta and it reports while it waits: how long it has been, and whether 3ds Max has begun the work. That is NOT a claim that the host is pumping tasks - a modal dialog looks the same from here.',
        {'type': 'object', 'properties': {'path': {'type': 'string', 'description': 'Absolute path to write, ending in .max. Its directory must already exist.'}, 'overwrite': {'type': 'boolean', 'description': 'Permit replacing an existing file. Default false, which refuses rather than overwrite. Ask the user before setting this: the file being replaced is theirs and the replacement cannot be undone.'}}, 'required': ['path'], 'additionalProperties': False},
        {'title': 'Save the scene to a file', 'readOnlyHint': False, 'destructiveHint': False, 'idempotentHint': False, 'openWorldHint': False},
    ),
    Tool(
        'max_scene_state',
        'What scene is open',
        'The file the open scene came from and whether it has unsaved changes. Call this before any tool that resets, opens or quits: those destroy what this reports, and saveRequired null means the flag could not be read, not that there is nothing to lose.',
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': 'What scene is open', 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
    Tool(
        'max_tools',
        "The Python tools in this session's workspace",
        "Every tool in the workspace, as a TREE: namespace, its tools, their schemas, and anything that failed to parse - listed BY NAME with the reason, because a file that vanishes when it breaks is a file nobody can fix. A tool is one .py declaring TOOL = {name, description, inputSchema} and a run(args); adding one is adding a file, with no restart and no registration. This server never writes the workspace - the namespace is derived from the path, so it cannot drift. Listing PARSES the manifest and executes nothing. Run a tool with max_job_start, kind 'python', params.tool set to the qualified name.",
        {'type': 'object', 'properties': {}, 'additionalProperties': False},
        {'title': "The Python tools in this session's workspace", 'readOnlyHint': True, 'destructiveHint': False, 'idempotentHint': True, 'openWorldHint': False},
    ),
]
# --- END GENERATED TOOLS ---


class UpstreamUnavailable(Exception):
    """3ds Max, or the plugin's endpoint inside it, is not answering."""


class Upstream(object):
    """The plugin's HTTP endpoint on 127.0.0.1."""

    def __init__(self, port, timeout):
        self.ports = [port] if port != DEFAULT_PORT else [DEFAULT_PORT + i for i in range(PORT_FALLBACK + 1)]
        self.timeout = timeout
        self.base = None
        self.protocol = FALLBACK_UPSTREAM_PROTOCOL

    def _get(self, url, timeout):
        request = urllib.request.Request(url, headers={"Accept": "application/json"})
        with urllib.request.urlopen(request, timeout=timeout) as response:
            return json.loads(response.read().decode("utf-8"))

    def locate(self):
        """Find the plugin: /health answers with server 'maxsdk-mcp'."""
        for port in self.ports:
            base = "http://127.0.0.1:%d" % port
            try:
                health = self._get(base + "/health", 3)
            except (OSError, ValueError):
                continue
            if health.get("server") == "maxsdk-mcp":
                self.base = base
                self.protocol = health.get("protocolVersion") or FALLBACK_UPSTREAM_PROTOCOL
                return
        self.base = None
        raise UpstreamUnavailable(
            "3ds Max is not running, or the 3ds Max SDK MCP plugin is not loaded: nothing answered "
            "on 127.0.0.1 port %s. Start 3ds Max 2026 with the plugin installed, then try again."
            % "/".join(str(p) for p in self.ports))

    def call(self, method, params, name=None):
        """One JSON-RPC request to the plugin. Returns the reply object."""
        if self.base is None:
            self.locate()
        params = dict(params or {})
        meta = dict(params.get("_meta") or {})
        meta["io.modelcontextprotocol/protocolVersion"] = self.protocol
        params["_meta"] = meta
        body = json.dumps({"jsonrpc": "2.0", "id": 1, "method": method, "params": params})
        headers = {
            "Content-Type": "application/json",
            # JSON only: the plugin streams a call only to a client that accepts an event stream.
            "Accept": "application/json",
            "MCP-Protocol-Version": self.protocol,
            "Mcp-Method": method,
        }
        if name is not None:
            headers["Mcp-Name"] = header_safe(name)
        request = urllib.request.Request(self.base + "/mcp", data=body.encode("utf-8"),
                                         headers=headers, method="POST")
        try:
            with urllib.request.urlopen(request, timeout=self.timeout) as response:
                return json.loads(response.read().decode("utf-8"))
        except urllib.error.HTTPError as error:
            # An error status still carries a JSON-RPC error worth passing on.
            try:
                return json.loads(error.read().decode("utf-8"))
            except ValueError:
                raise UpstreamUnavailable("the plugin answered HTTP %d" % error.code)
        except (OSError, ValueError) as error:
            self.base = None
            raise UpstreamUnavailable("the plugin stopped answering: %s" % error)


def header_safe(value):
    """A tool name or URI outside printable ASCII travels as =?base64?...?=, as the plugin expects."""
    if all(32 <= ord(c) <= 126 for c in value):
        return value
    return "=?base64?" + base64.b64encode(value.encode("utf-8")).decode("ascii") + "?="


def error_result(text):
    return {"content": [{"type": "text", "text": text}], "isError": True}


class Bridge(object):
    """MCP over stdio to the client, HTTP to the plugin."""

    def __init__(self, upstream, out=None, ask_timeout=300.0):
        self.upstream = upstream
        self.out = out or sys.stdout
        self.write_lock = threading.Lock()
        self.client_can_elicit = False
        self.pending = {}
        self.pending_lock = threading.Lock()
        self.next_id = 0
        # How long to wait for the user's answer to a confirmation before treating it as no.
        self.ask_timeout = ask_timeout

    # -- stdio ------------------------------------------------------------------------------------

    def send(self, message):
        text = json.dumps(message, ensure_ascii=False)
        with self.write_lock:
            self.out.write(text + "\n")
            self.out.flush()

    def ask_client(self, method, params, timeout=None):
        """A request from the bridge to the client (elicitation). Blocks until it answers."""
        with self.pending_lock:
            self.next_id += 1
            request_id = "bridge-%d" % self.next_id
            waiter = queue.Queue(maxsize=1)
            self.pending[request_id] = waiter
        self.send({"jsonrpc": "2.0", "id": request_id, "method": method, "params": params})
        try:
            return waiter.get(timeout=timeout)
        finally:
            with self.pending_lock:
                self.pending.pop(request_id, None)

    def serve(self, stream):
        for line in stream:
            line = line.strip()
            if not line:
                continue
            try:
                message = json.loads(line)
            except ValueError:
                self.send({"jsonrpc": "2.0", "id": None,
                           "error": {"code": -32700, "message": "Parse error"}})
                continue
            self.dispatch(message)

    def dispatch(self, message):
        if "method" not in message:
            # A reply to a question the bridge asked.
            with self.pending_lock:
                waiter = self.pending.get(message.get("id"))
            if waiter is not None:
                waiter.put(message)
            return
        if "id" not in message:
            return   # a notification: initialized, cancelled - nothing to answer
        # Calls can take long (a render, a restart), so each request runs on its own thread and
        # the reader stays free to deliver elicitation answers.
        threading.Thread(target=self.answer, args=(message,), daemon=True).start()

    def answer(self, message):
        request_id = message.get("id")
        try:
            result = self.handle(message.get("method"), message.get("params") or {})
            if isinstance(result, dict) and "__error__" in result:
                self.send({"jsonrpc": "2.0", "id": request_id, "error": result["__error__"]})
            else:
                self.send({"jsonrpc": "2.0", "id": request_id, "result": result})
        except Exception as error:   # the connection must outlive any one request
            self.send({"jsonrpc": "2.0", "id": request_id,
                       "error": {"code": -32603, "message": "Bridge error: %s" % error}})

    # -- methods ----------------------------------------------------------------------------------

    def handle(self, method, params):
        if method == "initialize":
            return self.initialize(params)
        if method == "ping":
            return {}
        if method == "tools/list":
            return self.tools_list()
        if method == "tools/call":
            return self.tools_call(params)
        if method in ("resources/list", "resources/read", "resources/templates/list"):
            return self.forward(method, params, name=params.get("uri"))
        return {"__error__": {"code": -32601, "message": "Method not found: %s" % method}}

    def initialize(self, params):
        wanted = params.get("protocolVersion")
        version = wanted if wanted in SUPPORTED_PROTOCOLS else SUPPORTED_PROTOCOLS[0]
        self.client_can_elicit = "elicitation" in ((params.get("capabilities") or {}))
        return {
            "protocolVersion": version,
            "capabilities": {"tools": {"listChanged": False}, "resources": {}},
            "serverInfo": {"name": BRIDGE_NAME, "title": "3ds Max SDK MCP (stdio bridge)",
                           "version": BRIDGE_VERSION},
            "instructions": "Tools run inside the user's running 3ds Max 2026. If a call reports "
                            "that 3ds Max is not running, ask the user to start it.",
        }

    def tools_list(self):
        try:
            reply = self.upstream.call("tools/list", {})
            if "result" in reply:
                return {"tools": reply["result"].get("tools", [])}
        except UpstreamUnavailable:
            pass
        return {"tools": [tool.to_mcp() for tool in TOOLS]}

    def forward(self, method, params, name=None):
        try:
            reply = self.upstream.call(method, params, name=name)
        except UpstreamUnavailable as error:
            return {"__error__": {"code": -32002, "message": str(error)}}
        if "error" in reply:
            return {"__error__": reply["error"]}
        return clean_result(reply.get("result") or {})

    def tools_call(self, params):
        name = params.get("name")
        upstream_params = {"name": name, "arguments": params.get("arguments") or {}}
        if self.client_can_elicit:
            upstream_params["_meta"] = {
                "io.modelcontextprotocol/clientCapabilities": {"elicitation": {}}}
        for _round in range(3):
            try:
                reply = self.upstream.call("tools/call", upstream_params, name=name)
            except UpstreamUnavailable as error:
                return error_result(str(error))
            if "error" in reply:
                return {"__error__": reply["error"]}
            result = reply.get("result") or {}
            if result.get("resultType") != "input_required":
                return clean_result(result)
            # The plugin wants the user's word before it destroys anything. Ask them.
            responses = []
            for question in result.get("inputRequests") or []:
                try:
                    answer = self.ask_client(question.get("method", "elicitation/create"),
                                             question.get("params") or {}, timeout=self.ask_timeout)
                except queue.Empty:
                    # The client never answered. Treat silence as no, so a destructive call cannot
                    # proceed on it, and nothing is left hanging.
                    return error_result("The confirmation was not answered; nothing was changed.")
                responses.append(answer.get("result") or {"action": "cancel"})
            upstream_params = dict(upstream_params)
            upstream_params["requestState"] = result.get("requestState")
            upstream_params["inputResponses"] = responses
        return error_result("The plugin kept asking for input; nothing was changed.")


def clean_result(result):
    """The plugin's result, minus fields a stdio client does not expect."""
    return {k: v for k, v in result.items()
            if k not in ("resultType", "ttlMs", "cacheScope", "requestState", "inputRequests")}


def main(argv=None):
    parser = argparse.ArgumentParser(description="MCP stdio bridge to the 3ds Max SDK MCP plugin.")
    parser.add_argument("--port", type=int, default=DEFAULT_PORT,
                        help="the plugin's port (default 3000; 3000-3002 are tried)")
    parser.add_argument("--host-timeout", type=float, default=900.0,
                        help="seconds to wait for one call inside 3ds Max (default 900)")
    args = parser.parse_args(argv)
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", newline="\n")
        sys.stdin.reconfigure(encoding="utf-8")
    Bridge(Upstream(args.port, args.host_timeout)).serve(sys.stdin)
    return 0


if __name__ == "__main__":
    sys.exit(main())
