<#
.SYNOPSIS
    Runs, on your machine, exactly what CI runs on the server.

.DESCRIPTION
    WHY THIS EXISTS. CI runs after a push. That is too late to be the first thing that tells you a
    branch is broken - the first red build on this repository's main branch was a set of findings
    that had been sitting in the working tree for days with nothing on a developer's machine able
    to report them. A check you can only run by pushing is a check that finds problems in public.

    So this is the same three jobs as .github\workflows\ci.yml, in the same order, with the same
    settings file. If this passes, CI passes - and if it does not, the two have drifted and THAT is
    the bug. Keep them in step: a job added there gets added here in the same change.

    WHAT IT DOES NOT COVER, stated so a green run is not read as more than it is. There is no 3ds
    Max on a CI runner and there may be none here either, so nothing below loads the plugin, starts
    the host, or exercises a Cartridge in a running session. This holds the scripts and the
    repository structure to their contract. It does not tell you your Cartridge works.

.PARAMETER Fast
    Skips the Pester suite, which is the slow job. Used by the pre-commit hook, where a wait of
    several seconds on every commit is what teaches people to pass --no-verify. The pre-push hook
    runs the whole thing.

.PARAMETER Since
    A base revision, passed through to the cartridge check so it can enforce the version-bump rule
    the way a pull request does. Without it, structure is checked and the bump rule is not.

.EXAMPLE
    tools\check-all.ps1
    Everything, the way CI runs it.

.EXAMPLE
    tools\check-all.ps1 -Since origin/main
    Everything, plus the rule that a changed Cartridge must bump its version.
#>

[CmdletBinding()]
param(
    [switch]$Fast,
    [string]$Since = ''
)

$ErrorActionPreference = 'Stop'
$KitRoot = Split-Path -Parent $PSScriptRoot

# Row-per-job, and every row carries its own remedy. A check that reports a failure without saying
# what to do about it has moved the problem rather than found it.
$Rows = New-Object System.Collections.ArrayList
$Failed = 0

function Add-Row {
    param([string]$Job, [string]$Verdict, [string]$Detail, [string]$Remedy = '')
    [void]$Rows.Add([pscustomobject]@{ Job = $Job; Verdict = $Verdict; Detail = $Detail; Remedy = $Remedy })
    # 'skipped' is a CHOICE - -Fast asking for it - so it does not fail the run. It still prints as
    # skipped rather than ok, because the difference between "passed" and "not run" is the whole
    # reason this file exists. 'missing' is not a choice and does fail: see the analyzer job below.
    if ($Verdict -ne 'ok' -and $Verdict -ne 'skipped') { $script:Failed++ }
}

Write-Host ''
Write-Host 'Running the CI jobs locally.' -ForegroundColor Cyan
Write-Host ''


# -- 1. PowerShell static analysis ---------------------------------------------------------------
#
# A MISSING ANALYZER IS A FAILURE, NOT A SKIP. This whole file exists because something passed
# quietly when it should not have; a run that reports ok because the tool was absent would repeat
# that mistake at the one moment it matters.
Write-Host '  [1/3] PowerShell static analysis ... ' -NoNewline
$Analyzer = Get-Module -ListAvailable PSScriptAnalyzer | Sort-Object Version -Descending | Select-Object -First 1
if (-not $Analyzer) {
    Write-Host 'TOOL MISSING' -ForegroundColor Red
    Add-Row 'analyze' 'missing' 'PSScriptAnalyzer is not installed' `
            'Install-Module PSScriptAnalyzer -Scope CurrentUser'
} else {
    Import-Module PSScriptAnalyzer -ErrorAction Stop
    $Settings = Join-Path $KitRoot 'PSScriptAnalyzerSettings.psd1'
    $Results = @(Invoke-ScriptAnalyzer -Path (Join-Path $KitRoot 'tools') -Recurse -Settings $Settings)
    if ($Results.Count -eq 0) {
        Write-Host 'ok' -ForegroundColor Green
        Add-Row 'analyze' 'ok' "PSScriptAnalyzer $($Analyzer.Version), no findings"
    } else {
        Write-Host "$($Results.Count) finding(s)" -ForegroundColor Red
        Write-Host ''
        $Results | Format-Table -AutoSize | Out-String -Width 200 | Write-Host
        Add-Row 'analyze' 'failed' "$($Results.Count) finding(s)" `
                'Fix them, or - if a rule is wrong about this repository - exclude it in PSScriptAnalyzerSettings.psd1 WITH the reason.'
    }
}


# -- 2. Cartridge structure ----------------------------------------------------------------------
Write-Host '  [2/3] Cartridge structure ....... ' -NoNewline
$CheckCartridges = Join-Path $PSScriptRoot 'check-cartridges.ps1'
if (-not (Test-Path -LiteralPath $CheckCartridges)) {
    Write-Host 'SCRIPT MISSING' -ForegroundColor Red
    Add-Row 'cartridges' 'missing' 'tools\check-cartridges.ps1 is not there' 'Restore it from the repository.'
} else {
    $CartridgeArgs = @('-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $CheckCartridges, '-Human')
    if ($Since) { $CartridgeArgs += @('-Since', $Since) }
    $CartridgeOut = & powershell @CartridgeArgs 2>&1 | Out-String
    if ($LASTEXITCODE -eq 0) {
        Write-Host 'ok' -ForegroundColor Green
        Add-Row 'cartridges' 'ok' $(if ($Since) { "structure and the version-bump rule against $Since" } else { 'structure; bump rule not checked without -Since' })
    } else {
        Write-Host 'failed' -ForegroundColor Red
        Write-Host ''
        Write-Host $CartridgeOut
        Add-Row 'cartridges' 'failed' "check-cartridges exited $LASTEXITCODE" `
                'Read the rows above; each names the Cartridge and what it is missing.'
    }
}


# -- 3. Script tests -----------------------------------------------------------------------------
Write-Host '  [3/3] Script tests .............. ' -NoNewline
if ($Fast) {
    Write-Host 'skipped (-Fast)' -ForegroundColor DarkGray
    Add-Row 'test' 'skipped' 'not run because -Fast was passed' 'The pre-push hook runs these; so does tools\check-all.ps1 with no switches.'
} else {
    $Pester = Get-Module -ListAvailable Pester | Where-Object { $_.Version -ge [version]'5.5.0' } |
              Sort-Object Version -Descending | Select-Object -First 1
    if (-not $Pester) {
        Write-Host 'TOOL MISSING' -ForegroundColor Red
        Add-Row 'test' 'missing' 'Pester 5.5.0 or newer is not installed' `
                'Install-Module Pester -Scope CurrentUser -SkipPublisherCheck -MinimumVersion 5.5.0'
    } else {
        # A CHILD PROCESS, DELIBERATELY. Pester is configured with Run.Exit in CI, and a suite that
        # calls exit inside this session would take the rest of these checks with it.
        $Runner = Join-Path ([System.IO.Path]::GetTempPath()) ('check-all-pester-' + [System.Guid]::NewGuid().ToString('N') + '.ps1')
        $Script = @"
Set-Location '$KitRoot'
Import-Module Pester -MinimumVersion 5.5.0
`$config = New-PesterConfiguration
`$config.Run.Path = 'tests'
`$config.Output.Verbosity = 'Normal'
Invoke-Pester -Configuration `$config
if (`$Error.Count -and -not `$?) { exit 1 }
"@
        Set-Content -LiteralPath $Runner -Value $Script -Encoding UTF8
        try {
            $TestOut = & powershell -NoProfile -ExecutionPolicy Bypass -File $Runner 2>&1 | Out-String
            # Pester colours its summary, and the escape sequences survive Out-String into the
            # table below as visible garbage. Strip them: [char]27 rather than "`e", which
            # Windows PowerShell 5.1 does not understand and which would make this file version
            # dependent for no gain.
            $Escape = [char]27
            $Summary = ($TestOut -split "`n" | Where-Object { $_ -match 'Tests Passed:' } | Select-Object -Last 1)
            $Summary = ($Summary -replace "$Escape\[[0-9;]*m", '').Trim()
            if ($TestOut -match 'Failed:\s*0\b') {
                Write-Host 'ok' -ForegroundColor Green
                Add-Row 'test' 'ok' $(if ($Summary) { $Summary } else { "Pester $($Pester.Version)" })
            } else {
                Write-Host 'failed' -ForegroundColor Red
                Write-Host ''
                Write-Host $TestOut
                Add-Row 'test' 'failed' $(if ($Summary) { $Summary } else { 'see the output above' }) `
                        'Fix the failing test, or the code it is testing.'
            }
        } finally {
            Remove-Item -LiteralPath $Runner -Force -ErrorAction SilentlyContinue
        }
    }
}


# -- the verdict ---------------------------------------------------------------------------------
Write-Host ''
$Rows | Format-Table -AutoSize -Property Job, Verdict, Detail | Out-String -Width 160 | Write-Host

$Remedies = @($Rows | Where-Object { $_.Verdict -ne 'ok' -and $_.Verdict -ne 'skipped' -and $_.Remedy })
if ($Remedies.Count -gt 0) {
    Write-Host 'What to do:' -ForegroundColor Yellow
    foreach ($R in $Remedies) { Write-Host ("  {0,-12} {1}" -f $R.Job, $R.Remedy) }
    Write-Host ''
}

if ($Failed -eq 0) {
    $Skipped = @($Rows | Where-Object { $_.Verdict -eq 'skipped' })
    if ($Skipped.Count -gt 0) {
        # Never "all checks passed" when one did not run. The claim has to match what happened.
        Write-Host ("CHECKS PASSED, {0} NOT RUN - {1}." -f $Skipped.Count, (($Skipped | ForEach-Object { $_.Job }) -join ', ')) -ForegroundColor Yellow
        Write-Host 'CI runs them all, so this is not yet evidence that CI will be green.'
    } else {
        Write-Host 'ALL CHECKS PASSED - CI should agree.' -ForegroundColor Green
    }
    Write-Host ''
    exit 0
}

Write-Host "$Failed CHECK(S) NOT PASSING - CI will fail on this." -ForegroundColor Red
Write-Host ''
exit 1
