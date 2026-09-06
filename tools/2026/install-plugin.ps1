# Installs the plugin for 3ds Max 2026.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\2026\install-plugin.ps1 [-Human]
#       [-From <path-to-zip>] [-Upgrade]
#
# THIS SCRIPT DOES NOT KNOW WHAT THE PLUGIN IS CALLED, AND THAT IS DELIBERATE.
#
# The bundle's directory name comes from the ARCHIVE - whatever top-level folder the zip carries is
# what gets placed. The asset's name comes from release.json, which the release process writes. The
# product's display name is read from the manifest that arrives inside the bundle. So this kit
# carries no copy of a name it does not own, and nothing here goes stale when the product is renamed.
#
# It also means this file states nothing about where the artifact came from or how it was made. The
# kit installs what it is pointed at and verifies it; that is the whole of its knowledge.
#
# WHAT IT DOES, IN ORDER, AND ALL OF IT OUT LOUD, because this is the script that downloads a binary
# and writes it into your profile. A run nobody could watch is a run nobody can audit.
#
#   1. Find 3ds Max 2026.                      5. Verify the SHA-256 BEFORE unpacking.
#   2. Refuse if a host is running.            6. Unpack to a staging directory.
#   3. Read the pin and what is installed.     7. Verify the tree, then swap it into place.
#   4. Fetch the asset (or take -From).        8. Record what was installed, and how to remove it.
#
# THE HASH IS CHECKED BEFORE ANYTHING IS UNPACKED, and the expected value is committed in this
# repository rather than served beside the file it describes - a checksum next to its own artifact
# proves only that both came from the same place.
#
# NOTHING IS WRITTEN INTO THE 3DS MAX INSTALL ROOT. The bundle goes to the per-user
# ApplicationPlugins directory: no elevation, and uninstall is deleting one directory.
#
# Exit codes: 0 installed (or already current), 2 refused, 3 nothing pinned and no -From, 4 the
#             download or its hash failed, 5 the installed tree did not verify.

[CmdletBinding()]
param(
    # Install a locally built bundle zip instead of fetching the pinned release. The hash check is
    # skipped for a local file and the script says so - you are vouching for it by pointing at it.
    [string]$From = '',

    # Required to replace an install of a different version. Refusing by default means an upgrade is
    # something you asked for rather than something that happened while you were reading.
    [switch]$Upgrade,

    # Where bundles go. The default is the only value a normal install should use; it is a parameter
    # so the step that DELETES an existing bundle can be exercised against a scratch directory.
    [string]$BundleRoot = (Join-Path $env:APPDATA 'Autodesk\ApplicationPlugins'),

    [switch]$Human
)

$ErrorActionPreference = 'Stop'

$TargetYear = 2026
$ToolsRoot = Split-Path -Parent $PSScriptRoot

# What this kit remembers about its own installs. Written here so that uninstall and the readiness
# check can find the bundle without either of them holding a hardcoded name.
$StateDir = Join-Path $env:LOCALAPPDATA '3dsmax-sdk-mcp'
$StateFile = Join-Path $StateDir "install-$TargetYear.json"

$Steps = New-Object System.Collections.ArrayList
function Say([string]$Text, [string]$Colour = 'Gray') { [void]$Steps.Add($Text); if ($Human) { Write-Host $Text -ForegroundColor $Colour } }
function Step([int]$N, [string]$Text) { Say ("[{0}/8] {1}" -f $N, $Text) 'Cyan' }
function Detail([string]$Text) { Say ("      $Text") 'Gray' }
function Refuse([string]$Text, [int]$Code) {
    Say "REFUSED: $Text" 'Red'
    if (-not $Human) { [ordered]@{ schema = 'install-plugin/1'; ok = $false; refused = $Text; steps = @($Steps) } | ConvertTo-Json -Depth 5 }
    exit $Code
}

# The identity a bundle manifest carries. Two bundles sharing an UpgradeCode are the same product
# installed twice - which is two servers reaching for one loopback port. Read rather than assumed,
# and it needs no knowledge of what anything is called.
function Get-BundleIdentity([string]$ManifestPath) {
    try {
        $Xml = [xml](Get-Content -LiteralPath $ManifestPath -Raw)
        return [pscustomobject]@{
            Name        = [string]$Xml.ApplicationPackage.Name
            Version     = [string]$Xml.ApplicationPackage.AppVersion
            UpgradeCode = [string]$Xml.ApplicationPackage.UpgradeCode
        }
    } catch { return $null }
}

if ($Human) { Write-Host ''; Write-Host "Installing the plugin for 3ds Max $TargetYear" -ForegroundColor White; Write-Host '' }


# -- 1. The host ------------------------------------------------------------------------------------
Step 1 "Looking for 3ds Max $TargetYear"
$FindMax = Join-Path $ToolsRoot 'find-max.ps1'
$MaxReport = $null
if (Test-Path -LiteralPath $FindMax) {
    try { $MaxReport = (& powershell -NoProfile -ExecutionPolicy Bypass -File $FindMax 2>$null | Out-String) | ConvertFrom-Json } catch { Write-Verbose "find-max returned nothing parseable; continuing without a host report" }
}
$Target = $null
if ($null -ne $MaxReport) { $Target = @($MaxReport.installs | Where-Object { $_.year -eq $TargetYear -and $_.exists }) | Select-Object -First 1 }
if ($null -eq $Target) { Refuse "3ds Max $TargetYear is not installed. Run tools\find-max.ps1 to see what is, and everywhere that was searched." 2 }
Detail "found at $($Target.installRoot)"


# -- 2. A running host holds the plugin open ----------------------------------------------------------
Step 2 'Checking that 3ds Max is not running'
$Running = @(Get-Process -Name '3dsmax' -ErrorAction SilentlyContinue)
if ($Running.Count -gt 0) {
    Refuse "3ds Max is running (pid $($Running.Id -join ', ')). It holds an open handle on every plugin it has loaded and never unloads one, so a copy over a running host half-succeeds silently. Close it and run this again." 2
}
Detail 'no host is running'


# -- 3. What is pinned, and what this kit has already installed -----------------------------------------
Step 3 'Reading the pinned release'
$Pin = $null
$PinPath = Join-Path $PSScriptRoot 'release.json'
if (Test-Path -LiteralPath $PinPath) { $Pin = Get-Content -LiteralPath $PinPath -Raw | ConvertFrom-Json }

$State = $null
$Installed = ''
if (Test-Path -LiteralPath $StateFile) {
    try { $State = Get-Content -LiteralPath $StateFile -Raw | ConvertFrom-Json } catch { Write-Verbose "install state unreadable; treated as a first install" }
}
if ($null -ne $State -and $State.bundleDir -and (Test-Path -LiteralPath (Join-Path $State.bundleDir 'PackageContents.xml'))) {
    $Identity = Get-BundleIdentity (Join-Path $State.bundleDir 'PackageContents.xml')
    if ($Identity) { $Installed = $Identity.Version }
    Detail "already installed: version $(if ($Installed) { $Installed } else { 'unreadable' }) at $($State.bundleDir)"
}

if (-not $From) {
    if ($null -eq $Pin -or -not $Pin.version) {
        Refuse ("no release is pinned in tools\$TargetYear\release.json, so there is nothing to download. " +
                "To install a locally built bundle instead, pass -From <path-to-zip>.") 3
    }
    Detail "pinned: $($Pin.version), asset $($Pin.asset)"
    if ($Installed -and $Installed -eq $Pin.version) {
        Say "Already at $Installed - nothing to do." 'Green'
        if (-not $Human) { [ordered]@{ schema = 'install-plugin/1'; ok = $true; version = $Installed; changed = $false; steps = @($Steps) } | ConvertTo-Json -Depth 5 }
        exit 0
    }
}
if ($Installed -and -not $Upgrade) {
    Refuse "version $Installed is already installed and this would replace it. Pass -Upgrade to say that is what you want." 2
}


# -- 4-8 ----------------------------------------------------------------------------------------------------
$Staging = Join-Path ([System.IO.Path]::GetTempPath()) ("plugin-install-{0}" -f ([System.IO.Path]::GetRandomFileName()))
New-Item -ItemType Directory -Path $Staging -Force | Out-Null
$HashChecked = $false
$NewVersion = ''
$ProductName = ''
$BundleDir = ''

try {
    if ($From) {
        Step 4 "Using a local bundle: $From"
        if (-not (Test-Path -LiteralPath $From)) { Refuse "no file at '$From'." 2 }
        $Zip = (Resolve-Path -LiteralPath $From).Path
        Detail ("{0:N1} MB" -f ((Get-Item -LiteralPath $Zip).Length / 1MB))
        Step 5 'Skipping the hash check'
        Detail 'a local file has no pinned hash - you are vouching for it by pointing at it'
    } else {
        Step 4 "Downloading $($Pin.asset)"
        Detail "from $($Pin.url)"
        $Zip = Join-Path $Staging $Pin.asset
        try {
            $ProgressPreference = 'SilentlyContinue'
            Invoke-WebRequest -Uri $Pin.url -OutFile $Zip -UseBasicParsing
        } catch { Refuse "the download failed: $($_.Exception.Message)" 4 }
        Detail ("{0:N1} MB downloaded" -f ((Get-Item -LiteralPath $Zip).Length / 1MB))

        # BEFORE unpacking. A hash checked afterwards has already written the thing it was meant to gate.
        Step 5 'Verifying the SHA-256 before unpacking anything'
        $Actual = (Get-FileHash -LiteralPath $Zip -Algorithm SHA256).Hash.ToLowerInvariant()
        $Expected = ([string]$Pin.sha256).ToLowerInvariant()
        Detail "expected $Expected"
        Detail "actual   $Actual"
        if ($Actual -ne $Expected) { Refuse 'the download does not match the pinned SHA-256. Nothing was unpacked and nothing was installed.' 4 }
        $HashChecked = $true
        Detail 'match'
    }

    Step 6 'Unpacking to a staging directory'
    $Unpacked = Join-Path $Staging 'tree'
    Expand-Archive -LiteralPath $Zip -DestinationPath $Unpacked -Force

    # THE ARCHIVE NAMES THE BUNDLE. Whatever top-level folder carries a PackageContents.xml is the
    # bundle, and its own name is the directory name it gets installed under. Nothing here supplies
    # that name, so nothing here can be wrong about it.
    $TreeRoot = ''
    $BundleName = ''
    if (Test-Path -LiteralPath (Join-Path $Unpacked 'PackageContents.xml')) {
        Refuse 'the archive holds a bundle''s CONTENTS rather than the bundle directory itself, so there is no name to install it under. Repackage it with the bundle folder at the root.' 5
    }
    $Inner = @(Get-ChildItem -LiteralPath $Unpacked -Directory | Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'PackageContents.xml') }) | Select-Object -First 1
    if (-not $Inner) { Refuse 'the archive contains no bundle - no top-level folder holds a PackageContents.xml.' 5 }
    $TreeRoot = $Inner.FullName
    $BundleName = $Inner.Name
    $BundleDir = Join-Path $BundleRoot $BundleName
    Detail "bundle: $BundleName"

    Step 7 'Verifying the unpacked tree'
    foreach ($Required in @('PackageContents.xml', 'Contents\Bin')) {
        if (-not (Test-Path -LiteralPath (Join-Path $TreeRoot $Required))) { Refuse "the unpacked bundle has no '$Required'. Nothing was installed." 5 }
    }
    $Identity = Get-BundleIdentity (Join-Path $TreeRoot 'PackageContents.xml')
    if ($null -eq $Identity) { Refuse 'the unpacked bundle has an unreadable manifest. Nothing was installed.' 5 }
    $NewVersion = $Identity.Version
    $ProductName = $Identity.Name
    Detail "manifest: $ProductName $NewVersion"

    # The same product installed twice is two servers reaching for one port. Detected by identity
    # rather than by name, so it holds however anything is called.
    if ($Identity.UpgradeCode) {
        foreach ($Other in (Get-ChildItem -LiteralPath $BundleRoot -Directory -ErrorAction SilentlyContinue)) {
            if ($Other.FullName -eq $BundleDir) { continue }
            $OtherManifest = Join-Path $Other.FullName 'PackageContents.xml'
            if (-not (Test-Path -LiteralPath $OtherManifest)) { continue }
            $OtherIdentity = Get-BundleIdentity $OtherManifest
            if ($OtherIdentity -and $OtherIdentity.UpgradeCode -eq $Identity.UpgradeCode) {
                Refuse ("'$($Other.Name)' is the same product already installed under another directory name. " +
                        "Two bundles claiming one product means two servers reaching for one port. Remove it first:`n" +
                        "      powershell -File tools\$TargetYear\uninstall-plugin.ps1 -Human") 2
            }
        }
    }

    Step 8 "Installing to $BundleDir"
    if (Test-Path -LiteralPath $BundleDir) {
        Detail "removing the previous install ($Installed)"
        Remove-Item -LiteralPath $BundleDir -Recurse -Force
    }
    New-Item -ItemType Directory -Path $BundleRoot -Force | Out-Null
    Copy-Item -LiteralPath $TreeRoot -Destination $BundleDir -Recurse -Force

    # Verify the artifact, not the exit status: a copy that reported success and produced no file is
    # a failure this script must not pass on.
    foreach ($Required in @('PackageContents.xml', 'Contents\Bin')) {
        if (-not (Test-Path -LiteralPath (Join-Path $BundleDir $Required))) { Refuse "after installing, '$Required' is not there. The install did not complete." 5 }
    }
    Detail 'verified in place'

    # THE BUILD SURFACE, placed into this clone. The headers and the slot library are release
    # artifacts like the binaries - they arrive with the plugin so the contract you compile against
    # and the binary you call cannot disagree. include\ and lib\ are git-ignored destinations here;
    # this is what fills them.
    $KitRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
    $KitStaged = Join-Path $BundleDir 'Contents\Kit'
    $PlacedFiles = 0
    if (Test-Path -LiteralPath $KitStaged) {
        foreach ($Part in @('include', 'lib')) {
            $From = Join-Path $KitStaged $Part
            if (-not (Test-Path -LiteralPath $From)) { continue }
            $To = Join-Path $KitRoot $Part
            New-Item -ItemType Directory -Path $To -Force | Out-Null
            foreach ($File in (Get-ChildItem -LiteralPath $From -File)) {
                Copy-Item -LiteralPath $File.FullName -Destination $To -Force
                $PlacedFiles++
            }
        }
        Detail "placed $PlacedFiles file(s) into $KitRoot\include and \lib"
    } else {
        Detail 'this bundle carries no headers or library - the native lane will not build from it'
    }

    New-Item -ItemType Directory -Path $StateDir -Force | Out-Null
    [ordered]@{
        schema      = 'install-state/1'
        targetYear  = $TargetYear
        bundleDir   = $BundleDir
        productName = $ProductName
        version     = $NewVersion
        kitRoot     = $KitRoot
        kitFiles    = $PlacedFiles
        installedAt = (Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')
    } | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath $StateFile -Encoding UTF8
    Detail "recorded in $StateFile"
}
finally {
    Remove-Item -LiteralPath $Staging -Recurse -Force -ErrorAction SilentlyContinue
}

if ($Human) {
    Write-Host ''
    Write-Host "Installed $ProductName $NewVersion for 3ds Max $TargetYear." -ForegroundColor Green
    Write-Host ''
    Write-Host 'NEXT: start 3ds Max. The server starts with the host and listens on loopback.'
    Write-Host '      Nothing was written into the 3ds Max install root.'
    Write-Host ''
    Write-Host 'TO REMOVE: delete this one directory. Your cartridges live elsewhere and survive it.'
    Write-Host "      $BundleDir"
    Write-Host ''
} else {
    [ordered]@{
        schema = 'install-plugin/1'; ok = $true; targetYear = $TargetYear; productName = $ProductName
        version = $NewVersion; changed = $true; hashChecked = $HashChecked; installedTo = $BundleDir
        uninstall = "Delete '$BundleDir'."
        nextStep = 'Start 3ds Max. The server starts with the host and listens on loopback.'
        steps = @($Steps)
    } | ConvertTo-Json -Depth 5
}

exit 0
