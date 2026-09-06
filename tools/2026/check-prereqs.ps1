# Is this machine ready to install the plugin for 3ds Max 2026 and author a cartridge - and if not,
# what would fix it.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\2026\check-prereqs.ps1 [-Human]
#
# ONE FOLDER PER 3DS MAX RELEASE, AND THE SCRIPTS INSIDE ARE COMPLETE RATHER THAN SHARED. The facts
# that differ between releases - which MSVC toolset the SDK pins, which series range the bundle
# declares, which asset carries the binaries - are precisely what a prerequisite check is about. One
# shared script would have to branch on the version, and a wrong branch here does not fail loudly:
# it reports a machine as ready to build a binary that 3ds Max will silently refuse to load.
#
# So each release gets its own copy, free to diverge the day it needs to, and the FOLDER NAME is
# which 3ds Max you are checking. If you are looking for tools\2027\ and it is not there, that is
# the answer - see ROADMAP.md. The script also prints its target release, because a file copied out
# of its folder loses the only other clue.
#
# A ROW IS A STATE, A REASON AND A REMEDY - NEVER JUST A COLOUR. The code that found a problem is
# the code that knows the recipe, so every row that is not Ok carries the literal command that fixes
# it, not a description of one.
#
# THE ROW SHAPE IS DELIBERATELY THE SAME as the readiness model the plugin serves once installed.
# There are two prerequisite surfaces - this script BEFORE the plugin exists, and the plugin's own
# rows AFTER - and they answer about the same machine. Two shapes would drift.
#
# STATES: Ok (nothing to do), Warning (works, or a capability not everyone needs is unavailable),
# Failed (does not work, and Remedy says what would fix it). AN ABSENT C++ TOOLCHAIN IS A WARNING
# AND NEVER A FAILURE: a cartridge with a Python payload compiles nothing, and reporting that as
# broken sends a user to install six gigabytes they were never going to use.
#
# THIS SCRIPT DIAGNOSES AND NEVER INSTALLS. Every remedy is a command for the user to run or a
# decision for the user to take. An elevated install changes the machine, and 3ds Max is a download
# behind an Autodesk account that no script can fetch on someone's behalf.
#
# Exit codes: 0 nothing failed (warnings are not failures), 1 at least one row failed.

[CmdletBinding()]
param(
    [switch]$Human
)

$ErrorActionPreference = 'Stop'

# -- What this release IS. The whole of the version-specific knowledge, in one block. ---------------
$TargetYear = 2026

# The toolset 3ds Max 2026's own SDK property sheets pin. The component id is what the Visual Studio
# Installer understands, so it is what a remedy can name. A different toolset does not fail to
# compile - it produces a binary that is wrong.
$PinnedToolsetComponent = 'Microsoft.VisualStudio.Component.VC.14.38.17.8.x86.x64'
$PinnedToolsetVersion = '14.38.33130'

# The loopback port the server binds by default.
$DefaultPort = 3000

$BundleRoot = Join-Path $env:APPDATA 'Autodesk\ApplicationPlugins'

# Where the installer recorded what it installed. This script holds no product name of its own: it
# asks the record, and the record was written from the artifact's own manifest.
$StateFile = Join-Path $env:LOCALAPPDATA "3dsmax-sdk-mcp\install-$TargetYear.json"
$BundleDir = ''
$InstalledName = ''
if (Test-Path -LiteralPath $StateFile) {
    try {
        $State = Get-Content -LiteralPath $StateFile -Raw | ConvertFrom-Json
        $BundleDir = [string]$State.bundleDir
        $InstalledName = [string]$State.productName
    } catch { }
}

# tools\2026\ -> tools\ -> the clone.
$ToolsRoot = Split-Path -Parent $PSScriptRoot
$KitRoot = Split-Path -Parent $ToolsRoot

$Rows = New-Object System.Collections.ArrayList

function Add-Row {
    param(
        [string]$Id,
        [string]$Title,
        [ValidateSet('Ok', 'Warning', 'Failed')][string]$State,
        [string]$Detail,
        [string]$Remedy = '',
        [string]$Doc = ''
    )
    [void]$Rows.Add([ordered]@{
        id = $Id; title = $Title; state = $State; detail = $Detail; remedy = $Remedy; doc = $Doc
    })
}


# -- 3ds Max 2026 ------------------------------------------------------------------------------------
# Discovery is not repeated here. find-max.ps1 owns it and spans every release - it is deliberately
# NOT one of the per-version scripts, because its whole job is to report what is installed including
# the versions this kit does not support.
$FindMax = Join-Path $ToolsRoot 'find-max.ps1'
$MaxReport = $null
if (Test-Path -LiteralPath $FindMax) {
    try {
        $MaxJson = & powershell -NoProfile -ExecutionPolicy Bypass -File $FindMax 2>$null
        $MaxReport = ($MaxJson | Out-String) | ConvertFrom-Json
    } catch { $MaxReport = $null }
}

$Target = $null
if ($null -ne $MaxReport) {
    $Target = @($MaxReport.installs | Where-Object { $_.year -eq $TargetYear -and $_.exists }) | Select-Object -First 1
}

if ($null -eq $MaxReport) {
    Add-Row -Id 'max' -Title "3ds Max $TargetYear" -State 'Failed' `
            -Detail 'could not run tools\find-max.ps1, so nothing is known about the installed hosts' `
            -Remedy 'Run tools\find-max.ps1 directly and read the error it prints.'
} elseif ($null -ne $Target) {
    Add-Row -Id 'max' -Title "3ds Max $TargetYear" -State 'Ok' -Detail $Target.installRoot
} elseif ($MaxReport.installCount -gt 0) {
    $Others = ($MaxReport.installs | ForEach-Object { "$($_.year)" }) -join ', '
    Add-Row -Id 'max' -Title "3ds Max $TargetYear" -State 'Failed' `
            -Detail "3ds Max $TargetYear is not installed. Found instead: $Others" `
            -Remedy "These scripts are the $TargetYear set. For another release use tools\<year>\ - and if that folder does not exist, this kit has no binary for it yet (ROADMAP.md)." `
            -Doc 'ROADMAP.md'
} else {
    Add-Row -Id 'max' -Title "3ds Max $TargetYear" -State 'Failed' `
            -Detail 'no 3ds Max found in the registry or the well-known install directories' `
            -Remedy 'Install 3ds Max 2026. Run tools\find-max.ps1 to see everywhere that was searched.' `
            -Doc 'README.md'
}

# -- Is a host running right now ----------------------------------------------------------------------
# 3ds Max holds an open handle on every plugin it has loaded and never unloads one, so a copy over a
# running host half-succeeds silently. Reported early, while closing it is still cheap.
if ($null -ne $MaxReport -and $MaxReport.maxRunning) {
    Add-Row -Id 'max-running' -Title '3ds Max is running' -State 'Warning' `
            -Detail "pid $($MaxReport.maxPids -join ', ')" `
            -Remedy 'Close 3ds Max before installing. A running host holds the loaded plugin open and the copy would half-succeed.'
} else {
    Add-Row -Id 'max-running' -Title '3ds Max is running' -State 'Ok' -Detail 'no host is running'
}

# -- Where the bundle goes ------------------------------------------------------------------------------
# Per-user, so no elevation is needed and nothing is written into the 3ds Max install root. The
# writability probe walks up to the nearest existing directory rather than creating anything:
# checking is not installing.
$Probe = $BundleRoot
while ($Probe -and -not (Test-Path -LiteralPath $Probe)) { $Probe = Split-Path -Parent $Probe }
$Writable = $false
if ($Probe) {
    $TestFile = Join-Path $Probe ([System.IO.Path]::GetRandomFileName())
    try {
        [System.IO.File]::WriteAllText($TestFile, 'x')
        Remove-Item -LiteralPath $TestFile -Force -ErrorAction SilentlyContinue
        $Writable = $true
    } catch { $Writable = $false }
}

if (-not $Writable) {
    Add-Row -Id 'bundle-root' -Title 'Plugin location' -State 'Failed' `
            -Detail "cannot write under '$Probe'" `
            -Remedy "Check permissions on '$BundleRoot'. The plugin installs per-user and never into the 3ds Max install root."
} elseif ($BundleDir -and (Test-Path -LiteralPath $BundleDir)) {
    $Installed = ''
    $Manifest = Join-Path $BundleDir 'PackageContents.xml'
    if (Test-Path -LiteralPath $Manifest) {
        try { $Installed = ([xml](Get-Content -LiteralPath $Manifest -Raw)).ApplicationPackage.AppVersion } catch { }
    }
    $What = if ($Installed) { "$InstalledName $Installed installed" } else { 'present, version unreadable' }
    Add-Row -Id 'bundle-root' -Title 'Plugin location' -State 'Ok' -Detail "$BundleDir - $What"
} else {
    Add-Row -Id 'bundle-root' -Title 'Plugin location' -State 'Ok' -Detail "$BundleRoot - writable, nothing installed yet"
}

# -- The port -------------------------------------------------------------------------------------------
# "Port 3000 is in use" is half an answer. Name the process holding it, because that is the half the
# user can act on.
$Listener = $null
try {
    $Listener = Get-NetTCPConnection -LocalPort $DefaultPort -State Listen -ErrorAction SilentlyContinue | Select-Object -First 1
} catch { }

if ($null -eq $Listener) {
    Add-Row -Id 'port' -Title "Port $DefaultPort" -State 'Ok' -Detail 'free'
} else {
    $Owner = ''
    try {
        $Process = Get-Process -Id $Listener.OwningProcess -ErrorAction SilentlyContinue
        if ($Process) { $Owner = "$($Process.ProcessName) (pid $($Process.Id))" }
    } catch { }
    if (-not $Owner) { $Owner = "pid $($Listener.OwningProcess)" }
    Add-Row -Id 'port' -Title "Port $DefaultPort" -State 'Warning' `
            -Detail "held by $Owner" `
            -Remedy "Stop $Owner, or set another port in the plugin's settings once it is installed. The server refuses to start rather than fighting for the port."
}

# -- The C++ toolchain, which ONLY a native payload needs -------------------------------------------------
# A Warning, never a Failure. The entry path this kit is built around is a Python payload, which
# compiles nothing - and the slots ship as binaries, so nothing here ever needs the 3ds Max SDK.
$VsWhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (-not (Test-Path -LiteralPath $VsWhere)) {
    Add-Row -Id 'toolchain' -Title 'Native payload builds' -State 'Warning' `
            -Detail 'Visual Studio is not installed (no vswhere.exe)' `
            -Remedy ("Python payloads need no compiler - only do this if you want a NATIVE payload. " +
                     "Installs elevated and changes this machine, so run it yourself:`n" +
                     "  winget install --id Microsoft.VisualStudio.2022.BuildTools --override `"--quiet --wait --add Microsoft.VisualStudio.Workload.VCTools --add $PinnedToolsetComponent`"") `
            -Doc 'README.md'
} else {
    $Install = (& $VsWhere -latest -products * -requires $PinnedToolsetComponent -property installationPath 2>$null | Out-String).Trim()
    if ($Install) {
        Add-Row -Id 'toolchain' -Title 'Native payload builds' -State 'Ok' -Detail "$Install (toolset $PinnedToolsetVersion)"
    } else {
        $AnyVs = (& $VsWhere -latest -products * -property installationPath 2>$null | Out-String).Trim()
        Add-Row -Id 'toolchain' -Title 'Native payload builds' -State 'Warning' `
                -Detail "Visual Studio is installed at '$AnyVs' but without toolset $PinnedToolsetVersion" `
                -Remedy ("Python payloads need no compiler - only do this if you want a NATIVE payload. " +
                         "Add the component to the install you already have, elevated:`n" +
                         "  `"${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vs_installer.exe`" modify --installPath `"$AnyVs`" --add $PinnedToolsetComponent --quiet --norestart`n" +
                         "Or in the Visual Studio Installer UI: Modify > Individual components > search '14.38'.") `
                -Doc 'README.md'
    }
}

# -- Is this clone complete ---------------------------------------------------------------------------------
# Cheap, and it catches the download that looked fine: a partial clone, a zip unpacked one level too
# deep, a file the fork never had.
$Expected = @('README.md', 'tools\find-max.ps1', 'tools\new-cartridge.ps1', "tools\$TargetYear\check-prereqs.ps1")
$Missing = @($Expected | Where-Object { -not (Test-Path -LiteralPath (Join-Path $KitRoot $_)) })
if ($Missing.Count -eq 0) {
    Add-Row -Id 'kit' -Title 'This clone' -State 'Ok' -Detail $KitRoot
} else {
    Add-Row -Id 'kit' -Title 'This clone' -State 'Warning' `
            -Detail "missing: $($Missing -join ', ')" `
            -Remedy 'Clone the repository rather than copying files out of it, and run this from the clone.'
}


# -- Report -------------------------------------------------------------------------------------------------
$Failed = @($Rows | Where-Object { $_.state -eq 'Failed' })
$Warned = @($Rows | Where-Object { $_.state -eq 'Warning' })

$Report = [ordered]@{
    schema       = 'check-prereqs/1'
    targetYear   = $TargetYear
    rows         = @($Rows)
    ok           = ($Failed.Count -eq 0)
    failedCount  = $Failed.Count
    warningCount = $Warned.Count
}

if ($Human) {
    Write-Host ''
    Write-Host "Prerequisites for 3ds Max $TargetYear" -ForegroundColor Cyan
    Write-Host ''
    foreach ($Row in $Rows) {
        $Colour = switch ($Row.state) { 'Ok' { 'Green' } 'Warning' { 'Yellow' } default { 'Red' } }
        Write-Host ("{0,-8} {1,-24} {2}" -f $Row.state, $Row.title, $Row.detail) -ForegroundColor $Colour
        if ($Row.remedy) {
            foreach ($Line in ($Row.remedy -split "`n")) { Write-Host ("         " + $Line) -ForegroundColor DarkGray }
        }
    }
    Write-Host ''
    if ($Failed.Count -eq 0) {
        Write-Host "Ready for 3ds Max $TargetYear. $($Warned.Count) warning(s)." -ForegroundColor Green
    } else {
        Write-Host "$($Failed.Count) row(s) failed." -ForegroundColor Red
    }
} else {
    $Report | ConvertTo-Json -Depth 6
}

if ($Failed.Count -gt 0) { exit 1 }
exit 0
