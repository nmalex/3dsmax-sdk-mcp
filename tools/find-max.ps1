# Finds every 3ds Max installed on this machine and reports it as JSON.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\find-max.ps1 [-Human]
#
# JSON rather than prose because an agent reads this, and prose is the format that invites
# a guess. -Human prints a table instead, for a person running it directly.
#
# THE INSTALL ROOT IS DISCOVERED, NEVER ASSUMED. The development machine this project was
# built on has 3ds Max at "C:\Autodesk\3ds Max 2026", not under "C:\Program Files\Autodesk",
# so any script that hardcodes either path is already wrong on the machine that wrote it.
# The registry is asked first; the well-known directories are a fallback for an install whose
# registration is missing, never the primary route.
#
# THE YEAR COMES FROM THE REGISTRY, NOT FROM ARITHMETIC. The key is named for the internal
# release ("28.0"), and it is tempting to turn that into a year with `+ 1998`. The same key
# carries ProductName = "Autodesk 3ds Max 2026", which states the year outright, so the
# formula is never needed and never risked. The install directory name is the second witness
# and the arithmetic is the third, used only when both are absent.
#
# WHAT THIS DELIBERATELY DOES NOT REPORT. The same registry key holds SerialNumber, FirstName,
# LastName and Organization. None of them is needed to install a plugin, all of them are the
# user's, and this script's output is written for an agent that may quote it back into a
# conversation, a log or an issue. They are not read and not emitted.
#
# EVERY INSTALL IS REPORTED, INCLUDING THE ONES THAT ARE NOT SUPPORTED. A 3ds Max this release
# does not build for is reported with `supported: false` and a reason, because the failure
# being prevented is the silent one: the bundle installs fine, the host refuses it by its
# SeriesMin/SeriesMax range, and the user sees a plugin that simply is not there. Finding
# nothing at all is likewise answered with where it looked, never an empty list on its own.
#
# Exit codes: 0 a supported install was found, 3 installs were found but none supported,
#             4 nothing was found at all.

[CmdletBinding()]
param(
    [switch]$Human
)

$ErrorActionPreference = 'Stop'

# The 3ds Max releases this release of the plugin ships a binary for. ONE year today: the
# bundle manifest pins SeriesMin/SeriesMax to 2026, and a plugin built against one Max SDK must
# not load into another. Widening this list is not a matter of editing it - a second binary has
# to exist first.
$SupportedYears = @(2026)

# Where an unregistered install might still be found. Neither is treated as authoritative, and
# the list is ordered with the non-default location first precisely because the default is the
# assumption this script exists to avoid.
$WellKnownParents = @(
    'C:\Autodesk',
    "$env:ProgramFiles\Autodesk",
    "${env:ProgramFiles(x86)}\Autodesk"
)

$Searched = New-Object System.Collections.ArrayList
$Found = @{}   # keyed by install root, lowercased, so two routes to one install report once


# The year this install is, from the strongest evidence available. Returns 0 when nothing
# states it, which is a real answer and is reported as one rather than being papered over.
function Resolve-MaxYear {
    param([string]$ProductName, [string]$InstallDir, [string]$KeyName)

    # 1. The registry says so outright.
    if ($ProductName -match '\b(20\d\d)\b') { return [int]$Matches[1] }

    # 2. The install directory is named for it ("...\3ds Max 2026").
    if ($InstallDir -match '\b(20\d\d)\b') { return [int]$Matches[1] }

    # 3. Arithmetic on the internal release, which held from 19.0/2017 through 28.0/2026. Last
    #    because it is the only one of the three that is a rule rather than a statement, and a
    #    rule can be broken by a release that has not shipped yet.
    if ($KeyName -match '^(\d+)\.') {
        $Major = [int]$Matches[1]
        if ($Major -ge 19) { return $Major + 1998 }
    }

    return 0
}


# One install, in the shape the JSON reports. Everything derived here is derived from the root,
# so a registry entry pointing at a directory that no longer exists is caught by `exists`
# rather than by whatever fails later.
function Resolve-MaxRecord {
    param([string]$InstallDir, [string]$ProductName, [string]$Release, [string]$KeyName, [string]$Source)

    $Root = $InstallDir.TrimEnd('\')
    $Exe = Join-Path $Root '3dsmax.exe'
    $Year = Resolve-MaxYear -ProductName $ProductName -InstallDir $Root -KeyName $KeyName

    $Exists = Test-Path -LiteralPath $Exe
    $FileVersion = ''
    if ($Exists) {
        try { $FileVersion = (Get-Item -LiteralPath $Exe).VersionInfo.FileVersion } catch { Write-Verbose "file version unavailable; reported as empty" }
    }

    # The per-user configuration tree, named for the YEAR rather than the release. Reported
    # because the readiness and log paths hang off it; nothing here writes to it.
    $EnuUser = ''
    if ($Year -gt 0) {
        $EnuUser = Join-Path $env:LOCALAPPDATA ("Autodesk\3dsMax\{0} - 64bit\ENU" -f $Year)
    }

    # Max's own bundled CPython. Reported as an oracle - a fast way to ask the scripting layer
    # what it thinks - and never as this plugin's runtime, which ships its own interpreter.
    $PythonExe = Join-Path $Root 'Python\python.exe'

    $Supported = $false
    $Why = ''
    if (-not $Exists) {
        $Why = "registered at '$Root' but 3dsmax.exe is not there - the install was moved or removed"
    } elseif ($Year -le 0) {
        $Why = 'the release year could not be determined from the registry or the install path'
    } elseif ($SupportedYears -notcontains $Year) {
        $Why = "this release ships a binary for $($SupportedYears -join ', ') only; 3ds Max $Year would refuse the bundle at load time"
    } else {
        $Supported = $true
    }

    return [ordered]@{
        year           = $Year
        release        = $Release
        installRoot    = $Root
        exe            = $Exe
        exeVersion     = $FileVersion
        exists         = $Exists
        bundledPython  = $(if (Test-Path -LiteralPath $PythonExe) { $PythonExe } else { '' })
        enuUserPath    = $EnuUser
        supported      = $Supported
        reason         = $Why
        source         = $Source
    }
}


function Add-Found {
    param($Record)
    $Key = $Record.installRoot.ToLowerInvariant()
    if (-not $Found.ContainsKey($Key)) { $Found[$Key] = $Record }
}


# -- 1. The registry, which is the authoritative route -------------------------------------
# Both views are read: a 32-bit host process sees the WOW6432Node redirection, and asking for
# both costs nothing while assuming one is a machine-specific bet.
foreach ($Hive in @('HKLM:\SOFTWARE\Autodesk\3dsMax', 'HKLM:\SOFTWARE\WOW6432Node\Autodesk\3dsMax')) {
    [void]$Searched.Add($Hive)
    if (-not (Test-Path -LiteralPath $Hive)) { continue }
    foreach ($Key in (Get-ChildItem -LiteralPath $Hive -ErrorAction SilentlyContinue)) {
        $Values = Get-ItemProperty -LiteralPath $Key.PSPath -ErrorAction SilentlyContinue
        if ($null -eq $Values) { continue }
        # Installdir on this machine; Location is the same value under a second name in the
        # shipped key, so it is taken as a fallback rather than assumed absent.
        $Dir = $Values.Installdir
        if ([string]::IsNullOrWhiteSpace($Dir)) { $Dir = $Values.Location }
        if ([string]::IsNullOrWhiteSpace($Dir)) { continue }
        Add-Found (Resolve-MaxRecord -InstallDir $Dir -ProductName $Values.ProductName `
                                 -Release $Values.Release -KeyName $Key.PSChildName -Source 'registry')
    }
}

# -- 2. The well-known directories, for an install the registry does not know about ---------
foreach ($Parent in $WellKnownParents) {
    if ([string]::IsNullOrWhiteSpace($Parent)) { continue }
    [void]$Searched.Add($Parent)
    if (-not (Test-Path -LiteralPath $Parent)) { continue }
    foreach ($Dir in (Get-ChildItem -LiteralPath $Parent -Directory -ErrorAction SilentlyContinue |
                      Where-Object { $_.Name -like '3ds Max*' })) {
        if (-not (Test-Path -LiteralPath (Join-Path $Dir.FullName '3dsmax.exe'))) { continue }
        Add-Found (Resolve-MaxRecord -InstallDir $Dir.FullName -ProductName $Dir.Name `
                                 -Release '' -KeyName '' -Source 'filesystem')
    }
}

$Installs = @($Found.Values | Sort-Object { $_.year })
$Supported = @($Installs | Where-Object { $_.supported })

# Whether a host is up right now. An install cannot proceed into a running 3ds Max - it holds an
# open handle on every plugin it has loaded and never unloads one - so the installer needs this
# fact and it is cheaper to report it here than to discover it half way through a copy.
$Running = @(Get-Process -Name '3dsmax' -ErrorAction SilentlyContinue | ForEach-Object { $_.Id })

$Report = [ordered]@{
    schema         = 'find-max/1'
    supportedYears = $SupportedYears
    installs       = $Installs
    installCount   = $Installs.Count
    supportedCount = $Supported.Count
    maxRunning     = ($Running.Count -gt 0)
    maxPids        = $Running
    searched       = @($Searched)
    remedy         = ''
}

if ($Installs.Count -eq 0) {
    $Report.remedy = 'No 3ds Max was found in the registry or in the well-known install directories listed in "searched". Install 3ds Max ' +
                     ($SupportedYears -join ' or ') + ', or run this again on the machine that has it.'
} elseif ($Supported.Count -eq 0) {
    $Report.remedy = 'A 3ds Max is installed but this release ships no binary for it. See the per-install "reason". ' +
                     'Supported: ' + ($SupportedYears -join ', ') + '.'
}

if ($Human) {
    if ($Installs.Count -eq 0) {
        Write-Host 'No 3ds Max found.' -ForegroundColor Yellow
        Write-Host $Report.remedy
    } else {
        $Installs | ForEach-Object {
            [pscustomobject]@{
                Year      = $(if ($_.year -gt 0) { $_.year } else { '?' })
                Release   = $_.release
                Supported = $_.supported
                Root      = $_.installRoot
                Reason    = $_.reason
            }
        } | Format-Table -AutoSize | Out-String -Width 200 | Write-Host
        if ($Report.remedy) { Write-Host $Report.remedy -ForegroundColor Yellow }
        if ($Report.maxRunning) { Write-Host "3ds Max is running (pid $($Running -join ', ')) - an install cannot proceed while it is." -ForegroundColor Yellow }
    }
} else {
    $Report | ConvertTo-Json -Depth 6
}

if ($Installs.Count -eq 0) { exit 4 }
if ($Supported.Count -eq 0) { exit 3 }
exit 0
