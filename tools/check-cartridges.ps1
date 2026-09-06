# Every cartridge in this repository has the same shape.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\check-cartridges.ps1 [-Human]
#
# WHY A CHECK AND NOT A CONVENTION. `new-cartridge.ps1` produces the right shape, so for anyone who
# used it this passes without their noticing. It exists for everything that did not come from the
# scaffolder: a cartridge copied from another machine, one hand-written, one carried across from an
# older layout, or one arriving in a pull request from someone who has never read this file. A
# convention that only holds while everybody remembers it is not a convention, it is a habit.
#
# WHAT IT IS FOR. A contributed cartridge has to be legible to somebody who did not write it, and
# every rule below exists because breaking it makes that impossible in a specific way:
#
#   - a slug that disagrees with its directory means two names for one thing, and tools disagree
#     about which is real;
#   - a manifest naming a payload that is not there is a cartridge that scaffolds and cannot load;
#   - an absolute path is a cartridge that works on exactly one machine;
#   - committed build output is somebody else's binary in your fork's history, forever;
#   - no README is a directory nobody can review, because its purpose lives only in its author.
#
# Exit codes: 0 every cartridge is well-formed (including when there are none), 1 at least one is not.

[CmdletBinding()]
param(
    # A git ref to compare against - `origin/main` in CI, `main` locally. When given, every cartridge
    # whose files changed since that ref must ALSO have changed its version. Omitted, the bump rule
    # is not checked and the structural rules still are.
    [string]$Since = '',

    [switch]$Human
)

$ErrorActionPreference = 'Stop'

$KitRoot = Split-Path -Parent $PSScriptRoot
$CartridgeRoot = Join-Path $KitRoot 'cartridges'
$TemplateRoot = Join-Path $KitRoot 'templates'

# The slots a cartridge may claim. Derived from what this kit can actually scaffold, so adding a
# template teaches this check about it with no second edit - a hand-kept mirror of another list is a
# list that goes stale, and it goes stale silently.
$KnownSlots = @(Get-ChildItem -LiteralPath $TemplateRoot -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.Name })

# Never committed inside a cartridge. Build output belongs to whoever built it.
# NOT '.obj'. It was here to catch MSVC object files, and it would have rejected an OBJ exporter's
# own fixtures - a cartridge refused for containing an example of the format it exists to write.
# MSVC output lands in out\ and obj\, which $BannedDirs already refuses, so nothing is lost.
$BannedExtensions = @('.dll', '.lib', '.pdb', '.exp', '.ilk', '.zip', '.dlm', '.dlu', '.dle')
$BannedDirs = @('out', 'obj', '__pycache__', '.vs')

$Findings = New-Object System.Collections.ArrayList
$Checked = 0

function Note([string]$Cartridge, [string]$Problem, [string]$Fix) {
    [void]$Findings.Add([ordered]@{ cartridge = $Cartridge; problem = $Problem; fix = $Fix })
}

if (-not (Test-Path -LiteralPath $CartridgeRoot)) {
    if ($Human) { Write-Host 'No cartridges/ directory - nothing to check.' -ForegroundColor Gray }
    else { [ordered]@{ schema = 'check-cartridges/1'; ok = $true; checked = 0; findings = @() } | ConvertTo-Json -Depth 5 }
    exit 0
}

foreach ($Dir in (Get-ChildItem -LiteralPath $CartridgeRoot -Directory -ErrorAction SilentlyContinue)) {
    $Checked++
    $Name = $Dir.Name
    $ManifestPath = Join-Path $Dir.FullName 'cartridge.json'

    # -- the manifest ------------------------------------------------------------------------------
    if (-not (Test-Path -LiteralPath $ManifestPath)) {
        Note $Name 'no cartridge.json' 'Every cartridge directory carries one. Scaffold with tools\new-cartridge.ps1 rather than by hand.'
        continue
    }
    $Manifest = $null
    try { $Manifest = Get-Content -LiteralPath $ManifestPath -Raw | ConvertFrom-Json } catch { Write-Verbose "cartridge.json could not be parsed; reported as a malformed manifest" }
    if ($null -eq $Manifest) {
        Note $Name 'cartridge.json does not parse as JSON' 'Open it and fix the syntax; nothing else here can be checked until it reads.'
        continue
    }

    if (-not $Manifest.name) {
        Note $Name 'cartridge.json has no name' 'Add "name" - it is what this cartridge is called, and what it is named when sealed.'
    }

    # -- the slug agrees with the directory ---------------------------------------------------------
    if (-not $Manifest.slug) {
        Note $Name 'cartridge.json has no slug' 'Add "slug", matching the directory name.'
    } elseif ($Manifest.slug -ne $Name) {
        Note $Name "slug '$($Manifest.slug)' does not match the directory '$Name'" 'Two names for one thing means tools disagree about which is real. Make them the same.'
    }
    if ($Name -notmatch '^[a-z0-9]+(-[a-z0-9]+)*$') {
        Note $Name 'the directory name is not kebab-case' 'Lower case, digits and single hyphens. It is derived from the display name by the scaffolder.'
    }

    # -- the slot ------------------------------------------------------------------------------------
    if (-not $Manifest.slot) {
        Note $Name 'cartridge.json names no slot' "Add `"slot`" - one of: $($KnownSlots -join ', ')."
    } elseif ($KnownSlots.Count -gt 0 -and $KnownSlots -notcontains $Manifest.slot) {
        Note $Name "slot '$($Manifest.slot)' is not one this kit knows" "Known slots: $($KnownSlots -join ', '). A slot with no template cannot be scaffolded or hosted."
    }

    # -- what it was verified against, which is what makes a shared library usable -------------------
    # Somebody who did not write this will download it and try to run it. These are what tell them
    # whether it can work at all. Without them, a cartridge failing on their 3ds Max is
    # indistinguishable from a cartridge that is broken - and they will report it as broken.
    if (-not $Manifest.requires) {
        Note $Name 'cartridge.json has no "requires"' 'Add "requires": { "max": [2026], "plugin": "<version>" } - what you actually ran it against.'
    } else {
        $Years = @($Manifest.requires.max)
        if ($Years.Count -eq 0 -or -not $Years[0]) {
            Note $Name 'requires.max is empty' 'Name the 3ds Max release(s) you ran this in. An untested claim is worse than no claim.'
        } else {
            foreach ($Year in $Years) {
                if ("$Year" -notmatch '^20\d\d$') { Note $Name "requires.max contains '$Year', which is not a 3ds Max release year" 'Four digits, e.g. 2026.' }
            }
        }
        $Plugin = [string]$Manifest.requires.plugin
        if (-not $Plugin) {
            Note $Name 'requires.plugin is missing' 'Record the plugin version this was verified against.'
        } elseif ($Plugin -eq 'unknown') {
            Note $Name 'requires.plugin is "unknown"' 'Scaffolded before the plugin was installed. Install, verify it runs, and record the version - a library entry nobody can match to a version is one nobody can safely try.'
        }
    }

    # -- the payload exists ---------------------------------------------------------------------------
    $Lane = if ($Manifest.payload) { [string]$Manifest.payload.lane } else { '' }
    $Module = if ($Manifest.payload) { [string]$Manifest.payload.module } else { '' }

    if (-not $Lane) {
        Note $Name 'cartridge.json names no payload lane' 'Add "payload": { "lane": "python" | "native", "module": "..." }.'
    } elseif ($Lane -notin @('python', 'native')) {
        Note $Name "payload lane '$Lane' is neither python nor native" 'Those are the two lanes.'
    }

    if (-not $Module) {
        Note $Name 'cartridge.json names no payload module' 'Add "payload.module" - the file you edit, without its extension.'
    } else {
        if ($Module -notmatch '^[a-z][a-z0-9_]*$') {
            Note $Name "payload module '$Module' is not a legal snake_case module name" 'Lower case, starting with a letter. It is a Python module name.'
        }
        if ($Lane -eq 'python') {
            $PayloadFile = Join-Path $Dir.FullName "python\$Module.py"
            if (-not (Test-Path -LiteralPath $PayloadFile)) {
                Note $Name "the manifest names payload module '$Module' and python\$Module.py is not there" 'A cartridge that scaffolds and cannot load. Either the file or the manifest is wrong.'
            }
        }
    }

    # -- the version -------------------------------------------------------------------------------------
    # Downloaded by people who are not watching the commits. A version is the only thing that lets
    # them say "I have 0.2.0 and it does the wrong thing" and lets the author answer without an
    # interview.
    $Version = [string]$Manifest.version
    if (-not $Version) {
        Note $Name 'cartridge.json has no version' 'Add "version": "0.1.0". It moves with every pull request.'
    } elseif ($Version -notmatch '^\d+\.\d+\.\d+(-[0-9A-Za-z.-]+)?$') {
        Note $Name "version '$Version' is not MAJOR.MINOR.PATCH" 'e.g. 0.1.0, or 0.1.0-dev while you work.'
    }

    # -- a README, because a contribution has to be reviewable ------------------------------------------
    $Readme = Join-Path $Dir.FullName 'README.md'
    if (-not (Test-Path -LiteralPath $Readme)) {
        Note $Name 'no README.md' 'Say what this cartridge does and why it exists. A directory whose purpose lives only in its author is one nobody can review.'
    } elseif ((Get-Item -LiteralPath $Readme).Length -lt 80) {
        Note $Name 'README.md is effectively empty' 'A heading alone tells a reader nothing they could not see from the directory name.'
    }

    # -- nothing built, nothing absolute -----------------------------------------------------------------
    foreach ($File in (Get-ChildItem -LiteralPath $Dir.FullName -Recurse -File -ErrorAction SilentlyContinue)) {
        if ($BannedExtensions -contains $File.Extension.ToLowerInvariant()) {
            $Rel = $File.FullName.Substring($Dir.FullName.Length + 1)
            Note $Name "build output is committed: $Rel" 'Build output belongs to whoever built it. Remove it; .gitignore already covers the usual places.'
            break
        }
    }
    foreach ($Banned in $BannedDirs) {
        if (Test-Path -LiteralPath (Join-Path $Dir.FullName $Banned)) {
            Note $Name "a '$Banned' directory is committed" 'Remove it - it is build or editor state, not part of the cartridge.'
        }
    }

    $ManifestText = Get-Content -LiteralPath $ManifestPath -Raw
    if ($ManifestText -match '[A-Za-z]:\\\\' -or $ManifestText -match '[A-Za-z]:\\') {
        Note $Name 'cartridge.json contains an absolute path' 'A cartridge with an absolute path in it works on exactly one machine.'
    }
}

# -- Nothing is claimed twice ---------------------------------------------------------------------
#
# This directory is CROWDSOURCED: cartridges arrive by pull request from people who cannot see each
# other's work in progress. Two contributors picking the same name is not a remote possibility, it is
# the normal case for anything obvious - and a duplicate is invisible to each of them right up until
# both branches exist. Caught here, where it is a comment on a pull request, rather than after a
# merge that quietly gave one directory two purposes.
$Names = @{}
foreach ($Dir in (Get-ChildItem -LiteralPath $CartridgeRoot -Directory -ErrorAction SilentlyContinue)) {
    $ManifestPath = Join-Path $Dir.FullName 'cartridge.json'
    if (-not (Test-Path -LiteralPath $ManifestPath)) { continue }
    try { $M = Get-Content -LiteralPath $ManifestPath -Raw | ConvertFrom-Json } catch { continue }
    if (-not $M.name) { continue }
    # Compared case- and punctuation-insensitively, because "Poly Count" and "polycount" are the same
    # name to every person who reads the two entries side by side.
    $Key = ([string]$M.name).ToLowerInvariant() -replace '[^a-z0-9]', ''
    if ($Names.ContainsKey($Key)) {
        Note $Dir.Name "the name '$($M.name)' is already used by cartridge '$($Names[$Key])'" `
             'Two cartridges a reader cannot tell apart. Rename one - tools\claim-cartridge-name.ps1 will suggest something clear.'
    } else {
        $Names[$Key] = $Dir.Name
    }
}

# -- Every cartridge is announced in the inventory -------------------------------------------------
#
# cartridges/README.md is the library's index, and the person reading it is never the person who
# wrote the entry. A cartridge present on disk but absent from the table is invisible to everyone
# who did not already know it was there; a row with no directory is a promise the repository cannot
# keep. Both are caught here rather than by a reviewer noticing.
$InventoryPath = Join-Path $CartridgeRoot 'README.md'
if (-not (Test-Path -LiteralPath $InventoryPath)) {
    Note '(inventory)' 'cartridges\README.md is missing' 'It is the library index every cartridge must appear in.'
} else {
    # Table rows only, and NOT the worked example inside the fenced block further down - which this
    # check flagged on its first run as a cartridge promised and missing. A document that teaches by
    # example gets read by tools too.
    $Rows = New-Object System.Collections.ArrayList
    $InFence = $false
    foreach ($Line in (Get-Content -LiteralPath $InventoryPath)) {
        if ($Line.TrimStart().StartsWith('```')) { $InFence = -not $InFence; continue }
        if (-not $InFence -and $Line.TrimStart().StartsWith('|')) { [void]$Rows.Add($Line) }
    }
    $Rows = @($Rows)

    # slug -> the version the table claims, so the two places that carry it can be held together.
    $Listed = @{}
    foreach ($Row in $Rows) {
        if ($Row -match '\]\(([a-z0-9][a-z0-9-]*)/\)') {
            $Cells = @($Row -split '\|' | ForEach-Object { $_.Trim() })
            $Listed[$Matches[1]] = if ($Cells.Count -gt 2) { $Cells[2] } else { '' }
        }
    }

    foreach ($Dir in (Get-ChildItem -LiteralPath $CartridgeRoot -Directory -ErrorAction SilentlyContinue)) {
        # Matched on the directory link, which is the one column that cannot be paraphrased.
        if (-not $Listed.ContainsKey($Dir.Name)) {
            Note $Dir.Name 'not listed in cartridges\README.md' `
                 'Add a row: name linked to the directory, its version, what it does, slot, the 3ds Max releases and plugin version you ran it against, your handle, the date. A cartridge that is not listed does not exist.'
            continue
        }
        # The version lives in two places by design - the manifest a tool reads and the table a
        # person reads - so the two disagreeing is the failure worth catching, not the duplication.
        $ManifestPath = Join-Path $Dir.FullName 'cartridge.json'
        if (Test-Path -LiteralPath $ManifestPath) {
            try {
                $M = Get-Content -LiteralPath $ManifestPath -Raw | ConvertFrom-Json
                if ($M.version -and $Listed[$Dir.Name] -and $M.version -ne $Listed[$Dir.Name]) {
                    Note $Dir.Name "cartridge.json says version $($M.version); the table says $($Listed[$Dir.Name])" `
                         'Both move together. A reader trusts the table and a tool trusts the manifest; when they disagree one of them is lying to somebody.'
                }
            } catch { Write-Verbose "cartridge.json could not be parsed; version comparison skipped for this cartridge" }
        }
    }

    # ...and nothing is promised that is not there.
    foreach ($Row in $Rows) {
        if ($Row -match '\]\(([a-z0-9][a-z0-9-]*)/\)') {
            $Linked = $Matches[1]
            if (-not (Test-Path -LiteralPath (Join-Path $CartridgeRoot $Linked))) {
                Note '(inventory)' "the table lists '$Linked', which is not in cartridges\" 'Remove the row, or restore the cartridge. A row with no directory is a promise the repository cannot keep.'
            }
        }
    }
}

# -- Changed means bumped -----------------------------------------------------------------------------
#
# A pull request that changes a cartridge and leaves its version alone ships two different files
# both calling themselves the same version. That is a bug report nobody can act on, and by the time
# it hurts, the history that would explain it is months deep.
#
# A cartridge that did not exist at the base ref is new and needs no bump - it has nothing to differ
# from.
if ($Since) {
    $Changed = @()
    try { $Changed = @(& git -C $KitRoot diff --name-only "$Since...HEAD" -- 'cartridges' 2>$null) } catch { Write-Verbose "git diff unavailable; no cartridge is treated as changed" }

    if ($LASTEXITCODE -ne 0) {
        Note '(bump)' "could not diff against '$Since'" 'Fetch it first, or pass a ref this clone has. The bump rule was NOT checked.'
    } else {
        $Touched = @($Changed |
            ForEach-Object { if ($_ -match '^cartridges/([^/]+)/') { $Matches[1] } } |
            Sort-Object -Unique)

        foreach ($Slug in $Touched) {
            $Current = ''
            $ManifestPath = Join-Path (Join-Path $CartridgeRoot $Slug) 'cartridge.json'
            if (Test-Path -LiteralPath $ManifestPath) {
                try { $Current = [string](Get-Content -LiteralPath $ManifestPath -Raw | ConvertFrom-Json).version } catch { Write-Verbose "cartridge.json could not be parsed; current version left unknown" }
            }

            $Before = ''
            try {
                $BaseText = (& git -C $KitRoot show "${Since}:cartridges/$Slug/cartridge.json" 2>$null | Out-String)
                if ($BaseText.Trim()) { $Before = [string]($BaseText | ConvertFrom-Json).version }
            } catch { Write-Verbose "base revision unreadable; previous version left unknown" }

            if (-not $Before) { continue }   # new in this branch
            if ($Current -and $Current -eq $Before) {
                Note $Slug "changed since $Since but the version is still $Current" `
                     'Bump it, and update the Version column in cartridges\README.md to match. This is not optional.'
            }
        }
    }
}

$Report = [ordered]@{
    schema   = 'check-cartridges/1'
    ok       = ($Findings.Count -eq 0)
    checked  = $Checked
    findings = @($Findings)
}

if ($Human) {
    Write-Host ''
    if ($Checked -eq 0) {
        Write-Host 'No cartridges to check.' -ForegroundColor Gray
    } elseif ($Findings.Count -eq 0) {
        Write-Host "$Checked cartridge(s) checked - all well-formed." -ForegroundColor Green
    } else {
        foreach ($F in $Findings) {
            Write-Host "  $($F.cartridge): $($F.problem)" -ForegroundColor Red
            Write-Host "      $($F.fix)" -ForegroundColor DarkGray
        }
        Write-Host ''
        Write-Host "$($Findings.Count) finding(s) across $Checked cartridge(s)." -ForegroundColor Red
    }
    Write-Host ''
} else {
    $Report | ConvertTo-Json -Depth 5
}

if ($Findings.Count -gt 0) { exit 1 }
exit 0
