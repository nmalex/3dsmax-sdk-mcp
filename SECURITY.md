# Security

## Supported versions

Only the latest release receives fixes. The project is pre-release (`0.x`); upgrade with the
installer before reporting.

## Reporting a vulnerability

Please report it privately: on this repository's **Security** tab, choose **Report a
vulnerability**. If that option is not shown, open an issue that says only that you have a
security report - no details - and the maintainer will arrange a private channel.

You will get an answer within a week. Please give us a reasonable time to fix it before disclosing.

## How the server is protected

The MCP server runs inside 3ds Max and is meant for one user: the person at the machine, and the
coding agent they connected.

- **Local only.** It listens on `127.0.0.1`, never on a network interface, and refuses any request
  whose peer is not a loopback address.
- **Browsers are refused.** Binding to loopback does not stop a web page on the same machine from
  calling it, so a request carrying an `Origin` header is accepted only from `http://localhost`,
  `http://127.0.0.1` or `http://[::1]`.
- **No login, on purpose.** Anything that can already run code as you on your machine could drive
  3ds Max directly; a token would add setup, not protection. There is no rate limiting for the same
  reason: the only client is yours.
- **Destructive calls ask the human.** When a call would discard or overwrite work - quitting,
  restarting, resetting or opening a scene, saving over an existing file, starting a job, some
  cartridge reloads - the server asks the user for consent through the MCP client before running
  it, rather than taking the agent's word. The tools that can do this are marked in
  [mcp-tools.json](mcp-tools.json).
- **Verified install.** The installer checks each release's SHA-256 against the value pinned in
  this repository before it unpacks anything. The binaries are not code-signed yet, so Windows
  SmartScreen may warn.
- **Cartridges are your code.** A cartridge runs inside 3ds Max with your permissions. Install
  cartridges only from sources you trust, as you would any 3ds Max plugin.

See [PRIVACY.md](PRIVACY.md) for what the plugin does and does not collect.
