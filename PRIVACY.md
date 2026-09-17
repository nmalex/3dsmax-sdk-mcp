# Privacy policy

**3ds Max SDK MCP collects nothing.** No telemetry, no analytics, no crash reports, no usage
counts, and no account. That was a deliberate decision, not an omission.

**Zero tracking.** Nothing in the plugin, the installer or this repository contains a tracker, an
analytics SDK (Mixpanel, Google Analytics or any other), an advertising network (AdSense or any
other), or a tracking pixel. Nothing phones home.

## What runs, and where

- **The plugin** runs inside 3ds Max on your computer. Its MCP server listens on `127.0.0.1` - your
  machine only - and answers only the coding agent (MCP client) you connect to it. It makes no
  outbound network connections of its own.
- **What it reads and writes** is what you or your agent ask it to: your open scene, the scene
  files you name, and the cartridges you deploy. It keeps logs of its own activity on your disk
  (under `%LOCALAPPDATA%\maxsdk-mcp\logs`) so you and your agent can see what happened. They never
  leave your computer unless you send them yourself.
- **The installer** (`tools/2026/install-plugin.ps1`) downloads the plugin release from GitHub,
  checks its SHA-256 against the pinned value before unpacking it, and installs it under your
  `%APPDATA%`. That download is an ordinary request to GitHub, covered by
  [GitHub's privacy statement](https://docs.github.com/site-policy/privacy-policies/github-general-privacy-statement).

## Your coding agent is a separate product

The MCP client you connect - Claude, Codex, Cursor or another - sees whatever the plugin returns to
it: scene contents, log lines, file paths. What that client does with it is governed by that
product's own privacy policy, not this one. Choose the agent you trust with your scenes.

## How we learn how the project is doing

From what people choose to share: GitHub stars, forks, issues, pull requests and discussions.
If you report a bug, you decide what goes in the report; [docs/REPORTING.md](docs/REPORTING.md)
lists what helps, and nothing in it is collected automatically.

## Changes

This policy changes only through a pull request to this repository, so its history is public.
Questions: [open an issue](https://github.com/nmalex/3dsmax-sdk-mcp/issues).
