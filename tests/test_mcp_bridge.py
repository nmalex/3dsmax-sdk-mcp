"""The stdio bridge speaks MCP to a client and forwards to the plugin.

These exercise tools/mcp_bridge.py against a fake upstream (no 3ds Max, no sockets): the handshake,
the tools/list fallback when the plugin is down, plain forwarding, the host-not-running result, and
the destructive-call consent round-trip where the bridge relays the plugin's question to the client
and the user's answer back.

Run: python -m unittest discover -s tests -p "test_*.py"
"""

import importlib.util
import json
import os
import threading
import time
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BRIDGE_PATH = os.path.join(ROOT, "tools", "mcp_bridge.py")


def load_bridge():
    spec = importlib.util.spec_from_file_location("mcp_bridge_under_test", BRIDGE_PATH)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


bridge = load_bridge()


class FakeUpstream(object):
    """Stands in for the plugin. `script` maps a method to a canned reply or a callable."""

    def __init__(self, script=None, available=True):
        self.script = script or {}
        self.available = available
        self.calls = []

    def call(self, method, params, name=None):
        self.calls.append((method, params, name))
        if not self.available:
            raise bridge.UpstreamUnavailable("3ds Max is not running")
        entry = self.script.get(method)
        if entry is None:
            return {"jsonrpc": "2.0", "id": 1, "result": {}}
        if callable(entry):
            return entry(params)
        return entry


class Collector(object):
    """Captures what the bridge writes to stdout, one JSON message per line."""

    def __init__(self):
        self.messages = []
        self._lock = threading.Lock()

    def write(self, text):
        text = text.strip()
        if text:
            with self._lock:
                self.messages.append(json.loads(text))

    def flush(self):
        pass


def make_bridge(upstream):
    return bridge.Bridge(upstream, out=Collector())


class Handshake(unittest.TestCase):

    def test_initialize_answers_without_the_plugin(self):
        b = make_bridge(FakeUpstream(available=False))
        result = b.handle("initialize", {"protocolVersion": "2025-06-18", "capabilities": {}})
        self.assertEqual(result["protocolVersion"], "2025-06-18")
        self.assertIn("tools", result["capabilities"])
        self.assertFalse(b.client_can_elicit)

    def test_initialize_notes_client_elicitation(self):
        b = make_bridge(FakeUpstream())
        b.handle("initialize", {"capabilities": {"elicitation": {}}})
        self.assertTrue(b.client_can_elicit)

    def test_unknown_protocol_falls_back_to_supported(self):
        b = make_bridge(FakeUpstream())
        result = b.handle("initialize", {"protocolVersion": "1999-01-01", "capabilities": {}})
        self.assertIn(result["protocolVersion"], bridge.SUPPORTED_PROTOCOLS)

    def test_ping(self):
        self.assertEqual(make_bridge(FakeUpstream()).handle("ping", {}), {})


class ToolsList(unittest.TestCase):

    def test_generated_tools_are_present(self):
        self.assertGreater(len(bridge.TOOLS), 0)
        names = {t.name for t in bridge.TOOLS}
        self.assertIn("max_capabilities", names)

    def test_falls_back_to_generated_list_when_plugin_is_down(self):
        b = make_bridge(FakeUpstream(available=False))
        result = b.handle("tools/list", {})
        self.assertEqual(len(result["tools"]), len(bridge.TOOLS))
        for tool in result["tools"]:
            for key in ("name", "description", "inputSchema", "annotations"):
                self.assertIn(key, tool)

    def test_uses_the_live_list_when_the_plugin_answers(self):
        live = {"jsonrpc": "2.0", "id": 1, "result": {"tools": [{"name": "only_live"}]}}
        b = make_bridge(FakeUpstream({"tools/list": live}))
        result = b.handle("tools/list", {})
        self.assertEqual(result["tools"], [{"name": "only_live"}])


class ToolsCall(unittest.TestCase):

    def test_forwards_and_strips_transport_fields(self):
        reply = {"jsonrpc": "2.0", "id": 1, "result": {
            "content": [{"type": "text", "text": "hi"}], "resultType": "complete", "ttlMs": 5}}
        upstream = FakeUpstream({"tools/call": reply})
        b = make_bridge(upstream)
        result = b.handle("tools/call", {"name": "max_scene_state", "arguments": {}})
        self.assertEqual(result["content"], [{"type": "text", "text": "hi"}])
        self.assertNotIn("resultType", result)
        self.assertNotIn("ttlMs", result)
        self.assertEqual(upstream.calls[0][0], "tools/call")

    def test_host_down_is_an_error_result_not_a_broken_connection(self):
        b = make_bridge(FakeUpstream(available=False))
        result = b.handle("tools/call", {"name": "max_scene_state", "arguments": {}})
        self.assertTrue(result["isError"])
        self.assertIn("not running", result["content"][0]["text"])

    def test_upstream_error_is_relayed(self):
        reply = {"jsonrpc": "2.0", "id": 1, "error": {"code": -32601, "message": "no such tool"}}
        b = make_bridge(FakeUpstream({"tools/call": reply}))
        result = b.handle("tools/call", {"name": "nope", "arguments": {}})
        self.assertEqual(result["__error__"]["code"], -32601)

    def test_destructive_call_relays_consent_and_sends_the_answer(self):
        # First call: the plugin asks for consent. Second call (carrying the answer): it proceeds.
        state = {"round": 0}

        def on_call(params):
            state["round"] += 1
            if state["round"] == 1:
                self.assertNotIn("requestState", params)
                return {"jsonrpc": "2.0", "id": 1, "result": {
                    "resultType": "input_required",
                    "requestState": "token-123",
                    "inputRequests": [{"method": "elicitation/create",
                                       "params": {"message": "Reset the scene?"}}]}}
            # The bridge must echo the token and carry the user's answer.
            self.assertEqual(params["requestState"], "token-123")
            self.assertEqual(params["inputResponses"][0]["content"]["confirm"], True)
            return {"jsonrpc": "2.0", "id": 1, "result": {
                "content": [{"type": "text", "text": "done"}], "resultType": "complete"}}

        upstream = FakeUpstream({"tools/call": on_call})
        b = make_bridge(upstream)
        b.client_can_elicit = True
        b.ask_timeout = 10.0

        # The client's answer to the elicitation the bridge will raise.
        def answer_the_question():
            for _ in range(500):
                with b.pending_lock:
                    ids = list(b.pending)
                if ids:
                    b.dispatch({"jsonrpc": "2.0", "id": ids[0],
                                "result": {"action": "accept", "content": {"confirm": True}}})
                    return
                time.sleep(0.01)
        watcher = threading.Thread(target=answer_the_question)
        watcher.start()
        result = b.handle("tools/call", {"name": "max_scene_reset", "arguments": {}})
        watcher.join()

        self.assertEqual(result["content"], [{"type": "text", "text": "done"}])
        self.assertEqual(state["round"], 2)

    def test_declares_elicitation_upstream_when_the_client_can_ask(self):
        upstream = FakeUpstream({"tools/call": {"jsonrpc": "2.0", "id": 1, "result": {}}})
        b = make_bridge(upstream)
        b.client_can_elicit = True
        b.handle("tools/call", {"name": "max_scene_state", "arguments": {}})
        sent = upstream.calls[0][1]
        caps = sent["_meta"]["io.modelcontextprotocol/clientCapabilities"]
        self.assertIn("elicitation", caps)


class HeaderSafety(unittest.TestCase):

    def test_ascii_name_is_unchanged(self):
        self.assertEqual(bridge.header_safe("max_scene_reset"), "max_scene_reset")

    def test_non_ascii_name_is_encoded(self):
        self.assertTrue(bridge.header_safe("café").startswith("=?base64?"))


if __name__ == "__main__":
    unittest.main()
