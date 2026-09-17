"""The Python cartridge payloads keep the payload contract.

Every Python payload in barebones/ and examples/ is loaded here the way a Slot loads it, but with
stand-ins for the modules the installed plugin provides (mcp_bootstrap, mcp_ui, mcp_facade). No
3ds Max is needed, so this runs on a hosted runner. Each payload must:

  * import without 3ds Max, and never import 3ds Max's own Python modules (LAW-1: a cartridge
    reaches the host through the facade, never directly);
  * answer describe() with a dict naming its payload module and its lane;
  * answer describe_params(), where it declares parameters, with well-formed declarations;
  * answer init() and shutdown() with ok - and never log the cartridge greeting from them. The
    greeting ("Hello World") proves the cartridge's own behaviour ran; a load report that said it
    would make every probe pass on load alone.

Run: python -m unittest discover -s tests -p "test_*.py"
"""

import glob
import importlib.util
import io
import json
import os
import re
import sys
import types
import unittest
from unittest import mock

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# 3ds Max's own Python modules. A payload importing any of these has bypassed the facade.
HOST_MODULES = ("pymxs", "MaxPlus", "qtmax")

PARAM_TYPES = {"float", "int", "bool", "string", "color", "point3", "node", "angle", "percent",
               "worldunits", "enum"}


def payload_files():
    files = glob.glob(os.path.join(ROOT, "barebones", "*", "python", "*.py"))
    files += glob.glob(os.path.join(ROOT, "examples", "*", "python", "*.py"))
    return sorted(files)


def manifest_for(path):
    """The cartridge.json two levels up, or None - also for a scaffold template whose manifest
    still holds @PLACEHOLDER@ values and is not JSON yet."""
    manifest = os.path.join(os.path.dirname(os.path.dirname(path)), "cartridge.json")
    if not os.path.isfile(manifest):
        return None
    try:
        return json.load(io.open(manifest, encoding="utf-8-sig"))
    except ValueError:
        return None


class Host(object):
    """Stand-ins for the modules the installed plugin puts on the payload's path."""

    def __init__(self):
        self.lines = []
        bootstrap = types.ModuleType("mcp_bootstrap")
        bootstrap.log = lambda level, message: self.lines.append((level, str(message)))
        self.modules = {
            "mcp_bootstrap": bootstrap,
            # The panel builder: any call answers, so a payload can describe its UI.
            "mcp_ui": mock.MagicMock(name="mcp_ui"),
            # No facade lane: payloads must cope with its absence (ImportError).
            "mcp_facade": None,
        }

    def load(self, path):
        name = "payload_under_test_%d" % abs(hash(path))
        spec = importlib.util.spec_from_file_location(name, path)
        module = importlib.util.module_from_spec(spec)
        with mock.patch.dict(sys.modules, self.modules):
            spec.loader.exec_module(module)
        return module

    def call(self, module, function, *args, **kwargs):
        with mock.patch.dict(sys.modules, self.modules):
            return getattr(module, function)(*args, **kwargs)


class PayloadContract(unittest.TestCase):

    def test_there_are_payloads_to_check(self):
        self.assertGreater(len(payload_files()), 20)

    def test_no_payload_imports_3ds_max_directly(self):
        pattern = re.compile(r"^\s*(?:import|from)\s+(%s)\b" % "|".join(HOST_MODULES), re.M)
        for path in payload_files():
            with self.subTest(payload=os.path.relpath(path, ROOT)):
                source = io.open(path, encoding="utf-8").read()
                self.assertIsNone(pattern.search(source), "imports a 3ds Max module directly")

    def test_every_payload_imports_without_3ds_max(self):
        for path in payload_files():
            with self.subTest(payload=os.path.relpath(path, ROOT)):
                Host().load(path)

    def test_describe_names_the_payload_and_its_lane(self):
        for path in payload_files():
            host = Host()
            module = host.load(path)
            if not hasattr(module, "describe"):
                continue
            with self.subTest(payload=os.path.relpath(path, ROOT)):
                answer = host.call(module, "describe")
                self.assertIsInstance(answer, dict)
                self.assertEqual(answer.get("lane"), "python")
                payload = ((manifest_for(path) or {}).get("payload") or {})
                known = {payload.get("module"), payload.get("deployedAs")} - {None}
                if known and "payload" in answer:
                    self.assertIn(answer["payload"], known,
                                  "describe() names a module cartridge.json does not")

    def test_declared_parameters_are_well_formed(self):
        for path in payload_files():
            host = Host()
            module = host.load(path)
            if not hasattr(module, "describe_params"):
                continue
            with self.subTest(payload=os.path.relpath(path, ROOT)):
                answer = host.call(module, "describe_params")
                params = answer.get("parameters")
                self.assertIsInstance(params, list)
                names = [p.get("name") for p in params]
                self.assertEqual(len(names), len(set(names)), "a parameter is declared twice")
                for param in params:
                    self.assertRegex(param.get("name", ""), r"^[A-Za-z_][A-Za-z0-9_]*$")
                    self.assertIn(param.get("type"), PARAM_TYPES)
                    self.assertIn("default", param)

    def test_init_and_shutdown_report_without_greeting(self):
        env = {"slotName": "TestSlot", "maxRelease": 28000, "slotVersion": "0.0.0",
               "cartridgeAbi": 8, "gup": True}
        for path in payload_files():
            host = Host()
            module = host.load(path)
            for function in ("init", "shutdown"):
                if not hasattr(module, function):
                    continue
                with self.subTest(payload=os.path.relpath(path, ROOT), function=function):
                    answer = host.call(module, function, **env)
                    self.assertIsInstance(answer, dict)
                    self.assertTrue(answer.get("ok"))
            with self.subTest(payload=os.path.relpath(path, ROOT), check="no greeting on load"):
                for _level, line in host.lines:
                    self.assertNotIn("Hello World", line)


if __name__ == "__main__":
    unittest.main()
