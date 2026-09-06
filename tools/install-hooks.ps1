<#
.SYNOPSIS
    Points this clone's git hooks at tools\hooks, so the CI checks run before you commit and push.

.DESCRIPTION
    WHY THIS IS A SCRIPT AND NOT A FILE YOU COPY. Git does not version .git\hooks - a hook committed
    to a repository does nothing until each clone opts in. Copying them is the usual answer and it
    is a bad one: the copies drift from the originals silently, and nobody finds out until a hook
    that was fixed months ago is still wrong on somebody's machine. Instead this sets

        core.hooksPath = tools/hooks

    so the hooks git runs ARE the files under version control. Fix one, and every clone that ran
    this has the fix.

    WHAT YOU GET. tools\hooks\pre-commit runs the static analysis and the Cartridge structure check.
    tools\hooks\pre-push runs those plus the full test suite. Both call tools\check-all.ps1, which
    is the same set of jobs .github\workflows\ci.yml runs on the server.

    THIS IS PER CLONE, and it is not permanent: -Remove puts it back. Nothing here touches your
    global git configuration, and nothing outside this repository is changed.

.PARAMETER Remove
    Unsets core.hooksPath for this clone, and stops running any of it.

.EXAMPLE
    tools\install-hooks.ps1
.EXAMPLE
    tools\install-hooks.ps1 -Remove
#>

[CmdletBinding()]
param([switch]$Remove)

$ErrorActionPreference = 'Stop'
$KitRoot = Split-Path -Parent $PSScriptRoot

Write-Host ''

# The clone has to be a clone. Setting core.hooksPath outside a repository silently configures
# nothing, and the message you would get later is about hooks not running rather than about this.
& git -C $KitRoot rev-parse --git-dir 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "  $KitRoot is not a git repository, so there is nothing to configure." -ForegroundColor Red
    Write-Host ''
    exit 1
}

if ($Remove) {
    & git -C $KitRoot config --unset core.hooksPath 2>&1 | Out-Null
    Write-Host '  core.hooksPath unset. The checks no longer run on commit or push.' -ForegroundColor Yellow
    Write-Host '  Re-enable with: tools\install-hooks.ps1'
    Write-Host ''
    exit 0
}

$HookDir = Join-Path $PSScriptRoot 'hooks'
foreach ($Name in @('pre-commit', 'pre-push')) {
    if (-not (Test-Path -LiteralPath (Join-Path $HookDir $Name))) {
        Write-Host "  tools\hooks\$Name is missing - the clone is incomplete." -ForegroundColor Red
        Write-Host ''
        exit 1
    }
}

& git -C $KitRoot config core.hooksPath 'tools/hooks'
$Configured = (& git -C $KitRoot config core.hooksPath)

if ($Configured -ne 'tools/hooks') {
    Write-Host "  git did not take the setting - core.hooksPath reads '$Configured'." -ForegroundColor Red
    Write-Host ''
    exit 1
}

Write-Host '  Hooks installed for this clone.' -ForegroundColor Green
Write-Host ''
Write-Host '    pre-commit   static analysis, Cartridge structure          (a few seconds)'
Write-Host '    pre-push     those, plus the full test suite               (slower, and worth it)'
Write-Host ''
Write-Host '  Both run tools\check-all.ps1, which is what CI runs. Run it yourself any time:'
Write-Host ''
Write-Host '    tools\check-all.ps1'
Write-Host ''
Write-Host '  To get past a hook once, when you know what you are doing:'
Write-Host ''
Write-Host '    git commit --no-verify'
Write-Host '    git push --no-verify'
Write-Host ''
Write-Host '  To stop running them: tools\install-hooks.ps1 -Remove'
Write-Host ''

# The tools the hooks need. Reported now rather than at the moment a commit is blocked by them,
# because the first time anyone meets a missing module should not be while they are mid-commit.
$Missing = @()
if (-not (Get-Module -ListAvailable PSScriptAnalyzer)) {
    $Missing += 'Install-Module PSScriptAnalyzer -Scope CurrentUser'
}
if (-not (Get-Module -ListAvailable Pester | Where-Object { $_.Version -ge [version]'5.5.0' })) {
    $Missing += 'Install-Module Pester -Scope CurrentUser -SkipPublisherCheck -MinimumVersion 5.5.0'
}
if ($Missing.Count -gt 0) {
    Write-Host '  The hooks need these, and they are not installed yet:' -ForegroundColor Yellow
    foreach ($M in $Missing) { Write-Host "    $M" }
    Write-Host ''
    Write-Host '  The hooks FAIL rather than pass quietly when a tool is absent - a check that did'
    Write-Host '  not run is not a check that passed.'
    Write-Host ''
}

exit 0
