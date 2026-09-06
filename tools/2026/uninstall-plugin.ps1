# Removes the plugin for 3ds Max 2026.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\2026\uninstall-plugin.ps1 [-Human]
#       [-IncludeCartridges] [-Yes]
#
# THIS SCRIPT DOES NOT KNOW WHAT THE PLUGIN IS CALLED. It removes what the installer recorded
# installing, and any other bundle carrying the same product identity - two bundles sharing an
# UpgradeCode are one product installed twice, which is two servers reaching for one loopback port.
# Identity is read from each manifest; nothing here holds a name of its own.
#
# WHAT IT REMOVES BY DEFAULT: the bundle directory, and nothing else. That is the whole install -
# nothing was ever written into the 3ds Max install root, so there is nothing else of ours to find.
#
# WHAT IT NEVER TOUCHES UNLESS ASKED BY NAME:
#
#   - YOUR CARTRIDGES. They live outside the bundle precisely so that removing the plugin does not
#     remove your work. -IncludeCartridges deletes them, and it asks first.
#   - YOUR SCENES. Nothing here reads or writes a .max file.
#   - THE CARTRIDGE SOURCES IN YOUR CLONE. Removing a deployed copy is not deleting your code.
#
# A RUNNING 3DS MAX KEEPS WHAT IT HAS ALREADY LOADED. The host never unloads a plugin, so removing
# files under a live session frees nothing and leaves the classes registered for that session. This
# refuses rather than half-removing an install that is still in use.
#
# Exit codes: 0 removed (or nothing was installed), 2 refused.

[CmdletBinding()]
param(
    # Also delete every cartridge deployed on this machine. Your work - asks before it does it.
    [switch]$IncludeCartridges,

    # Answer the confirmation without being asked. For unattended use only.
    [switch]$Yes,

    [string]$BundleRoot = (Join-Path $env:APPDATA 'Autodesk\ApplicationPlugins'),

    [switch]$Human
)

$ErrorActionPreference = 'Stop'

$TargetYear = 2026
$StateDir = Join-Path $env:LOCALAPPDATA '3dsmax-sdk-mcp'
$StateFile = Join-Path $StateDir "install-$TargetYear.json"
$CartridgeRoot = Join-Path $StateDir 'cartridges'

$Removed = New-Object System.Collections.ArrayList
$Kept = New-Object System.Collections.ArrayList

function Say([string]$Text, [string]$Colour = 'Gray') { if ($Human) { Write-Host $Text -ForegroundColor $Colour } }

function Get-BundleIdentity([string]$ManifestPath) {
    try {
        $Xml = [xml](Get-Content -LiteralPath $ManifestPath -Raw)
        return [pscustomobject]@{
            Name = [string]$Xml.ApplicationPackage.Name
            Version = [string]$Xml.ApplicationPackage.AppVersion
            UpgradeCode = [string]$Xml.ApplicationPackage.UpgradeCode
        }
    } catch { return $null }
}

if ($Human) { Write-Host ''; Write-Host "Removing the plugin for 3ds Max $TargetYear" -ForegroundColor White; Write-Host '' }

# -- A running host still holds it ---------------------------------------------------------------------
$Running = @(Get-Process -Name '3dsmax' -ErrorAction SilentlyContinue)
if ($Running.Count -gt 0) {
    Say "REFUSED: 3ds Max is running (pid $($Running.Id -join ', '))." 'Red'
    Say '         It never unloads a plugin, so removing these files would free nothing and leave' 'Red'
    Say '         the classes registered for that session. Close it and run this again.' 'Red'
    if (-not $Human) { [ordered]@{ schema = 'uninstall-plugin/1'; ok = $false; refused = '3ds Max is running' } | ConvertTo-Json -Depth 4 }
    exit 2
}

# -- What this kit installed, and anything claiming the same identity ---------------------------------------
$State = $null
if (Test-Path -LiteralPath $StateFile) {
    try { $State = Get-Content -LiteralPath $StateFile -Raw | ConvertFrom-Json } catch { }
}

$Targets = New-Object System.Collections.ArrayList
$Identity = $null

if ($null -ne $State -and $State.bundleDir -and (Test-Path -LiteralPath $State.bundleDir)) {
    [void]$Targets.Add($State.bundleDir)
    $Identity = Get-BundleIdentity (Join-Path $State.bundleDir 'PackageContents.xml')
}

# A duplicate install under another directory name is found by product identity, never by guessing a
# name. Without a record there is nothing to compare against, and this says so rather than sweeping.
if ($null -ne $Identity -and $Identity.UpgradeCode) {
    foreach ($Other in (Get-ChildItem -LiteralPath $BundleRoot -Directory -ErrorAction SilentlyContinue)) {
        if ($Targets -contains $Other.FullName) { continue }
        $OtherManifest = Join-Path $Other.FullName 'PackageContents.xml'
        if (-not (Test-Path -LiteralPath $OtherManifest)) { continue }
        $OtherIdentity = Get-BundleIdentity $OtherManifest
        if ($OtherIdentity -and $OtherIdentity.UpgradeCode -eq $Identity.UpgradeCode) {
            Say "Also found the same product installed at: $($Other.Name)" 'Yellow'
            [void]$Targets.Add($Other.FullName)
        }
    }
}

$Cartridges = @()
if (Test-Path -LiteralPath $CartridgeRoot) {
    $Cartridges = @(Get-ChildItem -LiteralPath $CartridgeRoot -Directory -ErrorAction SilentlyContinue |
                    Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'cartridge.json') })
}

if ($Targets.Count -eq 0) {
    if ($null -eq $State) {
        Say 'No record of an install by this kit, so there is nothing it can safely remove.' 'Yellow'
        $Present = @(Get-ChildItem -LiteralPath $BundleRoot -Directory -ErrorAction SilentlyContinue |
                     Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'PackageContents.xml') })
        if ($Present.Count -gt 0) {
            Say ''
            Say 'Bundles present, for you to judge - this script will not guess which is ours:' 'Yellow'
            foreach ($P in $Present) {
                $Id = Get-BundleIdentity (Join-Path $P.FullName 'PackageContents.xml')
                Say ("  {0,-32} {1}" -f $P.Name, $(if ($Id) { "$($Id.Name) $($Id.Version)" } else { 'unreadable manifest' }))
            }
        }
    } else {
        Say 'Nothing to remove - the recorded install is already gone.' 'Green'
    }
    if (-not $Human) { [ordered]@{ schema = 'uninstall-plugin/1'; ok = $true; removed = @(); kept = @($Kept) } | ConvertTo-Json -Depth 4 }
    exit 0
}

# -- Say exactly what will go, BEFORE anything goes ---------------------------------------------------------
Say 'This will delete:' 'White'
foreach ($T in $Targets) { Say "  $T" }
if ($IncludeCartridges -and $Cartridges.Count -gt 0) {
    Say ''
    Say "  ...and $($Cartridges.Count) deployed cartridge(s) - YOUR WORK:" 'Yellow'
    foreach ($C in $Cartridges) { Say "    $($C.Name)" 'Yellow' }
    Say ''
    Say '  A saved scene resolves a cartridge by the class it was created with. Any scene using one' 'Yellow'
    Say '  of these will report a missing plugin. The SOURCE in your clone is not touched.' 'Yellow'
}
Say ''

if ($IncludeCartridges -and $Cartridges.Count -gt 0 -and -not $Yes) {
    if (-not $Human) {
        Say 'REFUSED: -IncludeCartridges deletes your work and needs -Yes when not run interactively.' 'Red'
        [ordered]@{ schema = 'uninstall-plugin/1'; ok = $false; refused = 'confirmation required for -IncludeCartridges' } | ConvertTo-Json -Depth 4
        exit 2
    }
    $Answer = Read-Host 'Type the word DELETE to remove the cartridges as well'
    if ($Answer -ne 'DELETE') {
        Say 'Not confirmed - cartridges kept. Removing the bundle only.' 'Yellow'
        $IncludeCartridges = $false
    }
}

# -- Remove ---------------------------------------------------------------------------------------------------
foreach ($T in $Targets) {
    Remove-Item -LiteralPath $T -Recurse -Force
    if (Test-Path -LiteralPath $T) { Say "FAILED: '$T' is still there." 'Red'; exit 2 }
    [void]$Removed.Add($T)
    Say "removed $T" 'Green'
}

if ($IncludeCartridges) {
    foreach ($C in $Cartridges) {
        Remove-Item -LiteralPath $C.FullName -Recurse -Force
        [void]$Removed.Add($C.FullName)
        Say "removed cartridge $($C.Name)" 'Green'
    }
} elseif ($Cartridges.Count -gt 0) {
    [void]$Kept.Add($CartridgeRoot)
    Say ''
    Say "Kept $($Cartridges.Count) cartridge(s) in $CartridgeRoot" 'Cyan'
    Say 'They are yours. Pass -IncludeCartridges to remove them too.' 'Cyan'
}

Remove-Item -LiteralPath $StateFile -Force -ErrorAction SilentlyContinue

if ($Human) {
    Write-Host ''
    Write-Host 'Removed. Nothing was ever written into the 3ds Max install root, so nothing is left there.' -ForegroundColor Green
    Write-Host ''
} else {
    [ordered]@{ schema = 'uninstall-plugin/1'; ok = $true; targetYear = $TargetYear; removed = @($Removed); kept = @($Kept) } | ConvertTo-Json -Depth 4
}

exit 0
