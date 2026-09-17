"""The facade surface index answers the questions it is published to answer.

surface/max_facade_surface.py is how a person or an agent holding only this repository asks "can a
cartridge reach X?". These tests hold it to that: it loads, it counts, it finds, it reports the
declared gaps with their alternative, and its command line runs. No 3ds Max is needed.

Run: python -m unittest discover -s tests -p "test_*.py"
"""

import os
import subprocess
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SURFACE = os.path.join(ROOT, "surface")
SCRIPT = os.path.join(SURFACE, "max_facade_surface.py")

sys.path.insert(0, SURFACE)
import max_facade_surface as S  # noqa: E402


class FacadeSurfaceIndex(unittest.TestCase):

    def test_declares_its_abi(self):
        self.assertIsInstance(S.FACADE_ABI, int)
        self.assertGreater(S.FACADE_ABI, 0)

    def test_carries_entries_with_unique_names(self):
        names = [e.name for e in S.ENTRIES]
        self.assertGreater(len(names), 1000)
        self.assertEqual(len(names), len(set(names)))

    def test_has_answers_for_an_entry_the_barebones_use(self):
        # barebones/manipulator draws through these.
        for name in ("ManipCurrentGizmoBuild", "GizmoShapeAppendPolyline", "GizmoBuildSetAppearance"):
            with self.subTest(entry=name):
                self.assertTrue(S.has(name))
        self.assertFalse(S.has("NoSuchEntryAnywhere"))

    def test_find_matches_by_pattern(self):
        found = S.find("gizmo")
        self.assertTrue(found)
        for entry in found:
            with self.subTest(entry=entry.name):
                text = " ".join(str(getattr(entry, f)) for f in ("name", "family", "doc", "section"))
                self.assertIn("gizmo", text.lower())

    def test_every_declared_gap_is_explained(self):
        # Every gap has a kind and a reason. A deliberate trade also says what to do instead -
        # refusing something without an alternative would leave a cartridge author stuck.
        gaps = S.missing()
        self.assertTrue(gaps)
        for gap in gaps:
            with self.subTest(gap=gap.name):
                self.assertIn(gap.kind, S.KINDS)
                self.assertTrue((gap.why or "").strip(), "a gap gives no reason")
                if gap.kind == "trade":
                    self.assertTrue((gap.instead or "").strip(), "a trade names no alternative")

    def run_cli(self, *args):
        return subprocess.run([sys.executable, SCRIPT] + list(args), capture_output=True,
                              text=True, encoding="utf-8", timeout=60)

    def test_command_line_counts(self):
        result = self.run_cli()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("facade ABI %d" % S.FACADE_ABI, result.stdout)

    def test_command_line_searches_and_lists_gaps(self):
        for args in (("gizmo",), ("--missing",), ("--families",)):
            with self.subTest(args=args):
                result = self.run_cli(*args)
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertTrue(result.stdout.strip())


if __name__ == "__main__":
    unittest.main()
