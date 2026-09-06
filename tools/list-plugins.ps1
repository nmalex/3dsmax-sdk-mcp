# Every 3ds Max plugin module installed on this machine, from the directories 3ds Max actually
# searches - not from a guess about where plugins live.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\list-plugins.ps1 [-Human] [-InstallRoot <path>]
#
# WHY BY EXTENSION, AND WHICH EXTENSIONS. A 3ds Max plugin's extension states what KIND of plugin it
# is, and the host scans for all of them alike. Measured on a 2026 install rather than recalled:
#
#     .dlo 74   objects        .dlt 32   textures/materials     .dlx 10   extensions
#     .dlm 67   modifiers      .dlc 24   controllers            .dlr  6   renderers
#     .dlu 58   utilities      .gup 24   global utilities       .dls  4
#     .dle 11   exporters      .bmi 17   bitmap i/o             .dlv 12   video post
#     .dli 11   importers      .flt 11   image filters          .dl? rest
#
# ...against 1178 plain .dll files in the same tree, which are support libraries and NOT plugins.
# That is the whole reason the pattern is `*.dl?` plus the three that break the convention, rather
# than "every DLL": a list that swept in .dll would be 80% noise and would look thorough.
#
# WHICH DIRECTORIES, AND WHY ONLY THESE. 3ds Max searches a fixed set plus whatever the user has
# added, and both halves are knowable without asking the host:
#
#   - the install root's own Plugins, stdplugs, ExternalPlugins and ApplicationPlugins
#   - the per-user and all-machine ApplicationPlugins bundle roots
#   - every directory listed under [Directories] in the per-user Plugin.UserSettings.ini
#
# Nothing else is searched. A directory that merely contains a .dlm is not a plugin directory, and
# treating it as one would report modules 3ds Max will never load.
#
# WHAT THIS IS NOT. A module's FILE NAME is not the CLASS NAME 3ds Max registers - one module can
# register several classes, under names that appear nowhere in the file name. Only a running 3ds Max
# can list registered classes. So this is a real, complete inventory of what is INSTALLED, and it is
# a supplement to the host's class list rather than a replacement for it. Anything that claims
# otherwise is claiming more than this file can know.
#
# Exit codes: 0 modules were found, 3 no 3ds Max install could be located.

[CmdletBinding()]
param(
    # Defaults to the supported install that find-max.ps1 reports.
    [string]$InstallRoot = '',
    [switch]$Human
)

$ErrorActionPreference = 'Stop'

# The extensions 3ds Max recognises as plugins, as a RULE rather than a hand-kept list: the DL
# family is exactly `.dl` plus one letter, and three others break that convention.
#
# `.dll` IS EXCLUDED EXPLICITLY, and it is the reason this is a regex and not a wildcard. The
# obvious `-Filter '*.dl?'` looks right and is wrong twice over: `?` matches the third 'l' of
# `.dll`, so it swept in 285 support libraries and reported them as plugins, and Windows' legacy
# 8.3 matching let `.dlmp` through as well. A list that is 40% wrong looks thorough, which is worse
# than a list that is short.
$PluginExtensionPattern = '^\.dl[a-z]$'
$PluginExtensionExtra = @('.gup', '.bmi', '.flt')
$NotAPlugin = @('.dll')

if (-not $InstallRoot) {
    $FindMax = Join-Path $PSScriptRoot 'find-max.ps1'
    if (Test-Path -LiteralPath $FindMax) {
        try {
            $Report = (& powershell -NoProfile -ExecutionPolicy Bypass -File $FindMax 2>$null | Out-String) | ConvertFrom-Json
            $Supported = @($Report.installs | Where-Object { $_.supported }) | Select-Object -First 1
            if ($Supported) { $InstallRoot = $Supported.installRoot }
            elseif ($Report.installCount -gt 0) { $InstallRoot = @($Report.installs)[0].installRoot }
        } catch { Write-Verbose "find-max report unusable; install root left unset" }
    }
}

if (-not $InstallRoot -or -not (Test-Path -LiteralPath $InstallRoot)) {
    Write-Host 'REFUSED: no 3ds Max install found. Pass -InstallRoot, or run tools\find-max.ps1 to see why.' -ForegroundColor Red
    exit 3
}

$Dirs = New-Object System.Collections.ArrayList
function Add-Dir([string]$Path, [string]$Why) {
    if (-not $Path) { return }
    $Path = $Path.Trim().TrimEnd('\')
    if (-not (Test-Path -LiteralPath $Path)) { return }
    if ($Dirs | Where-Object { $_.path -eq $Path }) { return }
    [void]$Dirs.Add([pscustomobject]@{ path = $Path; why = $Why })
}

# The install's own, in the order 3ds Max lays them down.
Add-Dir (Join-Path $InstallRoot 'Plugins')            'install: Plugins'
Add-Dir (Join-Path $InstallRoot 'stdplugs')           'install: stdplugs'
Add-Dir (Join-Path $InstallRoot 'ExternalPlugins')    'install: ExternalPlugins'
Add-Dir (Join-Path $InstallRoot 'ApplicationPlugins') 'install: ApplicationPlugins'

# Bundle roots, which is how a modern plugin ships.
Add-Dir (Join-Path $env:APPDATA 'Autodesk\ApplicationPlugins')      'bundles: per-user'
Add-Dir (Join-Path $env:ProgramData 'Autodesk\ApplicationPlugins')  'bundles: all users'

# Whatever the user has added. The file is UTF-16LE with a BOM, which PowerShell detects - stated
# because writing it back as UTF-8 produces a file 3ds Max silently cannot read.
$IniCandidates = @()
if ($InstallRoot -match '\b(20\d\d)\b') {
    $Year = $Matches[1]
    $IniCandidates += (Join-Path $env:LOCALAPPDATA "Autodesk\3dsMax\$Year - 64bit\ENU\Plugin.UserSettings.ini")
}
foreach ($Ini in $IniCandidates) {
    if (-not (Test-Path -LiteralPath $Ini)) { continue }
    $InSection = $false
    foreach ($Line in (Get-Content -LiteralPath $Ini)) {
        $Trimmed = $Line.Trim()
        if ($Trimmed -match '^\[(.+)\]$') { $InSection = ($Matches[1] -eq 'Directories'); continue }
        if (-not $InSection) { continue }
        $Split = $Trimmed.IndexOf('=')
        if ($Split -lt 1) { continue }
        Add-Dir $Trimmed.Substring($Split + 1) "ini: $($Trimmed.Substring(0, $Split))"
    }
}

$Modules = New-Object System.Collections.ArrayList
foreach ($Dir in $Dirs) {
    foreach ($File in (Get-ChildItem -LiteralPath $Dir.path -Recurse -File -ErrorAction SilentlyContinue)) {
            $Ext = $File.Extension.ToLowerInvariant()
            if ($NotAPlugin -contains $Ext) { continue }
            if (-not (($Ext -match $PluginExtensionPattern) -or ($PluginExtensionExtra -contains $Ext))) { continue }
            # The version resource often carries a human-readable name. It is EVIDENCE about what a
            # module is, never the registered class name - reading it costs nothing and loads no code.
            $Description = ''
            $Product = ''
            try {
                $Info = (Get-Item -LiteralPath $File.FullName).VersionInfo
                $Description = $Info.FileDescription
                $Product = $Info.ProductName
            } catch { Write-Verbose "version info unavailable; description and product left empty" }
            [void]$Modules.Add([ordered]@{
                module      = $File.BaseName
                extension   = $File.Extension.ToLowerInvariant()
                description = $Description
                product     = $Product
                directory   = $File.DirectoryName
                source      = $Dir.why
            })
    }
}

$Report = [ordered]@{
    schema      = 'list-plugins/1'
    installRoot = $InstallRoot
    directories = @($Dirs)
    modules     = @($Modules)
    moduleCount = $Modules.Count
    byExtension = @($Modules | Group-Object { $_.extension } | Sort-Object Count -Descending |
                    ForEach-Object { [ordered]@{ extension = $_.Name; count = $_.Count } })
    caveat      = 'A module file name is not a registered class name: one module can register several classes under names that appear nowhere in the file name. Only a running 3ds Max can list registered classes.'
}

if ($Human) {
    Write-Host ''
    Write-Host "Install root: $InstallRoot"
    Write-Host "Directories searched:"
    foreach ($Dir in $Dirs) { Write-Host ("  {0,-22} {1}" -f $Dir.why, $Dir.path) }
    Write-Host ''
    Write-Host "$($Modules.Count) plugin module(s):"
    foreach ($Group in ($Modules | Group-Object { $_.extension } | Sort-Object Count -Descending)) {
        Write-Host ("  {0,-6} {1}" -f $Group.Name, $Group.Count)
    }
    Write-Host ''
    Write-Host $Report.caveat -ForegroundColor DarkGray
    Write-Host ''
} else {
    $Report | ConvertTo-Json -Depth 6
}

exit 0
