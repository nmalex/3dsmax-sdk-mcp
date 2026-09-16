# Scaffolds a new cartridge into a slot, and deploys it, in one step.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\new-cartridge.ps1 `
#       -Name "Cool Bend" [-Flavour modifier] [-Lane python] [-Replace] [-Human]
#
# WHAT COMES OUT IS A COPY OF THAT SLOT'S BAREBONES (barebones/<slot>), renamed: the same working
# payload - both lanes where the barebones has them - under your cartridge's name, with its own
# manifest and a README for you to fill in. The barebones is the template: it is the smallest thing
# that registers, appears where its kind appears and says hello, and it is kept working release by
# release, so a scaffold made from it starts from something that is known to run today.
#
# A SLOT IS A WORKBENCH STATION, NOT A HOME. A slot is a pre-compiled plugin that ships with the
# release; its class identity, its visible name and the payload module name it loads are all
# compiled into it. So there is no class id to generate here and none to keep - occupying a slot is
# copying your payload to the name that slot was built to load.
#
# THE CONSEQUENCE, WHICH THIS SCRIPT STATES RATHER THAN LETTING YOU DISCOVER: a saved scene resolves
# by the SLOT's identity, so a scene saved while one cartridge occupied a slot will evaluate whatever
# occupies that slot later. Replacing an occupant is therefore a decision, and -Replace is how you
# record having taken it. See docs\SLOTS.md.
#
# WHAT THIS CANNOT DO. It cannot make 3ds Max notice a newly occupied slot. Classes register once,
# during the plugin scan at startup, so the entry appears after a restart. Editing the payload of a
# cartridge ALREADY in a slot needs no restart; that is the fast loop.
#
# Exit codes: 0 scaffolded and deployed, 2 refused, 3 not supported yet.

[CmdletBinding()]
param(
    # What you call this cartridge. Used in its About rollout, in its record, and when it is
    # eventually sealed as a product of its own.
    [Parameter(Mandatory = $true)]
    [string]$Name,

    # Which slot to occupy. One slot per plugin type: any barebones with a shipping slot
    # (barebones/<slot>/cartridge.json that is not marked "template"). Checked below, not here, so the
    # list is read from the barebones instead of being kept by hand in a second place.
    [string]$Flavour = 'modifier',

    [ValidateSet('python', 'native')]
    [string]$Lane = 'python',

    # Where the cartridge SOURCE is written. Defaults to cartridges/<slug> in this clone, so it is
    # under version control from the first minute.
    [string]$Into = '',

    # Take over a slot that already holds a cartridge. Refusing by default is not caution: scenes
    # saved with the previous occupant will evaluate this one instead.
    [switch]$Replace,

    # The names a RUNNING 3ds Max has registered. Strongly preferred for the name check: without it
    # only exact and mangled collisions can be found.
    [string]$ClassesJson = '',

    # Output of tools\list-plugins.ps1. Generated automatically when not supplied.
    [string]$PluginsJson = '',

    # Proceed despite a name that conflicts or reads as confusable.
    [switch]$Force,

    [switch]$Human
)

$ErrorActionPreference = 'Stop'

$KitRoot = Split-Path -Parent $PSScriptRoot
$BarebonesRoot = Join-Path $KitRoot 'barebones'
$SourceRoot = Join-Path $BarebonesRoot $Flavour
$StateDir = Join-Path $env:LOCALAPPDATA '3dsmax-sdk-mcp'
$DeployRoot = Join-Path $StateDir 'cartridges'
$SlotsFile = Join-Path $StateDir 'slots.json'

function Fail([string]$Message, [int]$Code = 2) {
    Write-Host "REFUSED: $Message" -ForegroundColor Red
    exit $Code
}

# The barebones this kit can scaffold from: a manifest, a Python payload, and not a "template"
# (the shape-only examples for plugin kinds no slot can ever host).
function Get-ScaffoldableSlot {
    foreach ($Dir in (Get-ChildItem -LiteralPath $BarebonesRoot -Directory -ErrorAction SilentlyContinue)) {
        $Path = Join-Path $Dir.FullName 'cartridge.json'
        if (-not (Test-Path -LiteralPath $Path)) { continue }
        try { $M = Get-Content -LiteralPath $Path -Raw | ConvertFrom-Json } catch { continue }
        if ($M.template -or -not $M.payload -or -not $M.payload.deployedAs) { continue }
        if (-not (Test-Path -LiteralPath (Join-Path $Dir.FullName ("python\{0}.py" -f $M.payload.deployedAs)))) { continue }
        $Dir.Name
    }
}

# -- Names, all derived from one input --------------------------------------------------------------
$Slug = ($Name.Trim().ToLowerInvariant() -replace '[^a-z0-9]+', '-').Trim('-')
$Module = ($Slug -replace '-', '_')

if ([string]::IsNullOrWhiteSpace($Slug)) { Fail "'$Name' has no letters or digits in it, so no directory name can be derived from it." }
if ($Module -match '^[0-9]') { Fail "'$Name' starts with a digit, which cannot begin a Python module name. Start it with a letter." }

$Scaffoldable = @(Get-ScaffoldableSlot)
if ($Scaffoldable -notcontains $Flavour) {
    Write-Host "NOT SUPPORTED: there is no barebones with a shipping slot called '$Flavour'." -ForegroundColor Yellow
    Write-Host "Slots you can scaffold: $($Scaffoldable -join ', ')"
    Write-Host 'barebones\README.md says which plugin kinds have no slot, and why.'
    exit 3
}
$SourceManifest = Get-Content -LiteralPath (Join-Path $SourceRoot 'cartridge.json') -Raw | ConvertFrom-Json

# The module name the slot for this flavour was compiled to load, as its barebones records it. Fixed,
# because everything about a slot is fixed - this is the whole binding between a slot and the
# cartridge in it. Not derived from the flavour: uv-generator loads slot_uvgen.
$SlotModule = [string]$SourceManifest.payload.deployedAs

if ($Lane -eq 'native' -and -not (Test-Path -LiteralPath (Join-Path $SourceRoot 'native'))) {
    Write-Host "NOT SUPPORTED YET: the '$Flavour' barebones has no native lane." -ForegroundColor Yellow
    Write-Host 'Start in Python, then port the payload. See ROADMAP.md.'
    exit 3
}

# -- Is the slot free -------------------------------------------------------------------------------
$Slots = $null
if (Test-Path -LiteralPath $SlotsFile) {
    try { $Slots = Get-Content -LiteralPath $SlotsFile -Raw | ConvertFrom-Json } catch { Write-Verbose "slots.json unreadable; treated as no slot occupied" }
}
$Occupant = $null
if ($null -ne $Slots -and $Slots.slots -and $Slots.slots.$Flavour) { $Occupant = $Slots.slots.$Flavour }

if ($null -ne $Occupant -and $Occupant.slug -and -not $Replace) {
    Write-Host ''
    Write-Host "The $Flavour slot is occupied by '$($Occupant.name)' (since $($Occupant.since))." -ForegroundColor Yellow
    Write-Host ''
    Write-Host 'Replacing it is a decision, not a formality:' -ForegroundColor Yellow
    Write-Host '  A saved scene resolves by the SLOT''s identity, not by the cartridge in it. Any scene'
    Write-Host "  saved while '$($Occupant.name)' was here will evaluate '$Name' instead once you replace it."
    Write-Host ''
    Write-Host '  Pass -Replace to take the slot over.'
    Write-Host "  Its source stays where it is and is not touched: cartridges\$($Occupant.slug)"
    Write-Host ''
    Fail "the $Flavour slot already holds '$($Occupant.name)'."
}

# -- Claim the name ---------------------------------------------------------------------------------
# The slot's visible name is compiled in today, so this does not decide what the Modifier List shows.
# It decides what this cartridge is CALLED - in its About rollout, in its record, and when it is
# sealed as a product of its own, which is when a collision would be permanent and public.
$ClaimScript = Join-Path $PSScriptRoot 'claim-cartridge-name.ps1'
$ListPlugins = Join-Path $PSScriptRoot 'list-plugins.ps1'
$ClaimVerdict = 'unchecked'

if (Test-Path -LiteralPath $ClaimScript) {
    if (-not $PluginsJson -and (Test-Path -LiteralPath $ListPlugins)) {
        $PluginsJson = Join-Path ([System.IO.Path]::GetTempPath()) ("plugins-{0}.json" -f ([System.IO.Path]::GetRandomFileName()))
        & powershell -NoProfile -ExecutionPolicy Bypass -File $ListPlugins > $PluginsJson 2>$null
        if (-not (Test-Path -LiteralPath $PluginsJson)) { $PluginsJson = '' }
    }
    if ($ClassesJson -or $PluginsJson) {
        $ClaimArgs = @('-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $ClaimScript, '-Name', $Name, '-Flavour', $Flavour, '-Human')
        if ($ClassesJson) { $ClaimArgs += @('-ClassesJson', $ClassesJson) }
        if ($PluginsJson) { $ClaimArgs += @('-PluginsJson', $PluginsJson) }
        & powershell @ClaimArgs
        switch ($LASTEXITCODE) {
            0 { $ClaimVerdict = 'clear' }
            1 { $ClaimVerdict = 'conflict' }
            2 { $ClaimVerdict = 'confusable' }
            default { $ClaimVerdict = 'unchecked' }
        }
        if ($ClaimVerdict -eq 'conflict' -and -not $Force) {
            Fail "'$Name' collides with a name 3ds Max already knows (see above). Choose another, or pass -Force if you have decided to ship it anyway."
        }
        if ($ClaimVerdict -eq 'confusable' -and -not $Force) {
            Fail "'$Name' is not a collision but reads as a near-duplicate (see above). Choose a clearer name, or pass -Force to record that you decided."
        }
    }
}
if ($ClaimVerdict -eq 'unchecked') {
    Write-Host 'WARNING: the name was not claimed against any inventory - no plugin list was available.' -ForegroundColor Yellow
}

# -- Scaffold ------------------------------------------------------------------------------------------
$SourceDir = if ($Into) { $Into } else { Join-Path $KitRoot "cartridges\$Slug" }
if (Test-Path -LiteralPath $SourceDir) {
    Fail "'$SourceDir' already exists. This is a resume, not a fresh scaffold - read what is there before writing over it."
}

# -- What this cartridge will be verified against ---------------------------------------------------
# Read from what is actually installed rather than asked for or assumed. A crowdsourced library is
# only usable if each entry says which 3ds Max and which plugin version it ran under - and a value
# the author typed is a value that is right once and then quietly is not.
$MaxYears = @()
$PluginVersion = ''
foreach ($Record in (Get-ChildItem -LiteralPath $StateDir -Filter 'install-*.json' -ErrorAction SilentlyContinue)) {
    try {
        $State = Get-Content -LiteralPath $Record.FullName -Raw | ConvertFrom-Json
        if ($State.targetYear) { $MaxYears += [int]$State.targetYear }
        if ($State.version -and -not $PluginVersion) { $PluginVersion = [string]$State.version }
    } catch { Write-Verbose "install state unreadable; 3ds Max year and plugin version left unset" }
}
if ($MaxYears.Count -eq 0) {
    # Not fatal: you can scaffold before installing. It IS fatal to contributing - the structure
    # check refuses an unknown, because a library entry nobody can match to a version is one nobody
    # can safely try.
    Write-Host 'WARNING: no installed plugin found, so this cartridge cannot record what it was verified against.' -ForegroundColor Yellow
    Write-Host '         Fine while you experiment; tools\check-cartridges.ps1 will refuse it until you install and re-record.' -ForegroundColor Yellow
    $PluginVersion = 'unknown'
}

$Created = (Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')
$Utf8 = New-Object System.Text.UTF8Encoding($false)
$Written = New-Object System.Collections.ArrayList
New-Item -ItemType Directory -Path (Join-Path $SourceDir 'python') -Force | Out-Null

# THE MANIFEST, written fresh rather than copied: the barebones' own record describes the barebones.
# Anything the slot or the kit reads beyond the common fields (an exporter's file type) is carried over.
$Manifest = [ordered]@{
    schema   = 'cartridge/2'
    name     = $Name.Trim()
    slug     = $Slug
    version  = '0.1.0-dev'
    slot     = $Flavour
    requires = [ordered]@{ max = @($MaxYears | Sort-Object -Unique); plugin = $PluginVersion }
    payload  = [ordered]@{ lane = $Lane; module = $Module; deployedAs = $SlotModule }
}
foreach ($Extra in $SourceManifest.PSObject.Properties) {
    if (@('schema', 'name', 'slug', 'version', 'slot', 'requires', 'payload', 'created', 'generator', 'template') -notcontains $Extra.Name -and -not $Extra.Name.StartsWith('_')) {
        $Manifest[$Extra.Name] = $Extra.Value
    }
}
$Manifest['basedOn'] = "barebones/$Flavour"
$Manifest['created'] = $Created
$Manifest['generator'] = 'new-cartridge.ps1'
$ManifestPath = Join-Path $SourceDir 'cartridge.json'
[System.IO.File]::WriteAllText($ManifestPath, ($Manifest | ConvertTo-Json -Depth 8), $Utf8)
[void]$Written.Add($ManifestPath)

# THE PAYLOAD, the barebones' own, under your module name. A Python module's filename is its import
# name; the copy the slot loads is renamed back at deploy time, below.
$PayloadPath = Join-Path $SourceDir "python\$Module.py"
Copy-Item -LiteralPath (Join-Path $SourceRoot "python\$SlotModule.py") -Destination $PayloadPath
[void]$Written.Add($PayloadPath)

# A README is required of every cartridge, so it is scaffolded rather than demanded: a rule that is
# free to comply with is a rule people follow. The barebones' README stays in the barebones - it
# explains the slot; yours explains your cartridge.
$ReadmePath = Join-Path $SourceDir 'README.md'
$Readme = @"
# $($Name.Trim())

*(Scaffolded from [barebones/$Flavour](../../barebones/$Flavour/README.md). Replace this file's contents
before opening a pull request - see [docs/CARTRIDGE_PR.md](../../docs/CARTRIDGE_PR.md).)*

**What it does:** for now, what the $Flavour barebones does - it registers, appears where its kind
appears and says hello. That proves the whole crossing works before your behaviour is in the way.

## What to write here

- **What it does to a scene.** In plain words, not "a $Flavour cartridge".
- **How to use it** - apply it to what, and what changes.
- **What it does not do**, if that is not obvious. A stated limit saves a bug report.

## Facts worth keeping current

| | |
| --- | --- |
| Slot | ``$Flavour`` |
| Lane | Python - ``python/$Module.py`` |
| Version | see ``cartridge.json``, and the row in [``../README.md``](../README.md) |

Both of those move together on every pull request. That is not optional.
"@
[System.IO.File]::WriteAllText($ReadmePath, $Readme, $Utf8)
[void]$Written.Add($ReadmePath)

# THE NATIVE LANE, copied whenever the barebones has one - not only when -Lane native was asked
# for. The two lanes are not alternatives that exclude each other, and scaffolding both means porting
# a hot function later is an edit rather than a new project. The project keeps its target name
# (<slot module>_native): that is the file name the slot looks for beside itself.
$SourceNative = Join-Path $SourceRoot 'native'
if (Test-Path -LiteralPath $SourceNative) {
    New-Item -ItemType Directory -Path (Join-Path $SourceDir 'native\src') -Force | Out-Null

    $PropsSource = Join-Path $SourceRoot 'Version.props'
    if (Test-Path -LiteralPath $PropsSource) {
        $PropsPath = Join-Path $SourceDir 'Version.props'
        Copy-Item -LiteralPath $PropsSource -Destination $PropsPath
        [void]$Written.Add($PropsPath)
    }

    # A fresh project GUID. Never reused from the barebones: two projects sharing one guid confuse
    # every tool that keys off it, and the confusion appears as builds that quietly do the wrong
    # thing rather than as an error.
    $Project = Get-Content -LiteralPath (Join-Path $SourceNative 'Payload.vcxproj') -Raw
    $Guid = [Guid]::NewGuid().ToString().ToUpperInvariant()
    $Project = [regex]::Replace($Project, '<ProjectGuid>\{[0-9A-Fa-f-]+\}</ProjectGuid>', "<ProjectGuid>{$Guid}</ProjectGuid>")
    $Project = [regex]::Replace($Project, '<RootNamespace>[^<]*</RootNamespace>', "<RootNamespace>$($Module)_payload</RootNamespace>")
    $ProjectPath = Join-Path $SourceDir "native\$Module`_payload.vcxproj"
    [System.IO.File]::WriteAllText($ProjectPath, $Project, $Utf8)
    [void]$Written.Add($ProjectPath)

    # NOT renamed to the module name. A C++ source's filename is nothing to anybody, and renaming it
    # only creates a second place for the project file to disagree with the disk.
    $CppPath = Join-Path $SourceDir 'native\src\payload.cpp'
    Copy-Item -LiteralPath (Join-Path $SourceNative 'src\payload.cpp') -Destination $CppPath
    [void]$Written.Add($CppPath)
}

# -- Deploy into the slot ---------------------------------------------------------------------------------
# Flat, and under the slot's compiled module name. The file you edit keeps your name; the copy the
# slot loads carries the name the slot was built to look for.
New-Item -ItemType Directory -Path $DeployRoot -Force | Out-Null
$DeployedPath = Join-Path $DeployRoot "$SlotModule.py"
Copy-Item -LiteralPath $PayloadPath -Destination $DeployedPath -Force
if (-not (Test-Path -LiteralPath $DeployedPath)) { Fail "deploy produced no '$DeployedPath'." }

# THE EXPORTER SIDECAR. An exporter's file extension cannot be compiled into its slot - a slot with
# one baked in would host this cartridge and write the wrong file type - so the slot reads it when
# 3ds Max builds the File > Export type list. This is the one thing a slot reads from a cartridge,
# and it is written here rather than by hand so it cannot disagree with the manifest.
$SidecarPath = ''
try {
    $Declared = Get-Content -LiteralPath $ManifestPath -Raw | ConvertFrom-Json
    if ($Declared.exporter) {
        $SidecarPath = Join-Path $DeployRoot "$SlotModule.slot.json"
        [ordered]@{
            ext       = [string]$Declared.exporter.ext
            shortDesc = [string]$Declared.exporter.shortDesc
        } | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath $SidecarPath -Encoding UTF8
        if (-not (Test-Path -LiteralPath $SidecarPath)) { Fail "deploy produced no sidecar at '$SidecarPath'." }
    }
} catch {
    Fail "the manifest just written could not be read back: $($_.Exception.Message)"
}

# -- Record which cartridge is in which slot ------------------------------------------------------------------
if ($null -eq $Slots) { $Slots = [pscustomobject]@{ schema = 'slots/1'; slots = [pscustomobject]@{} } }
if (-not $Slots.slots) { $Slots | Add-Member -NotePropertyName slots -NotePropertyValue ([pscustomobject]@{}) -Force }
$Entry = [ordered]@{
    name       = $Name.Trim()
    slug       = $Slug
    module     = $Module
    deployedAs = "$SlotModule.py"
    source     = $SourceDir
    lane       = $Lane
    since      = $Created
}
$Slots.slots | Add-Member -NotePropertyName $Flavour -NotePropertyValue $Entry -Force
$Slots | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $SlotsFile -Encoding UTF8

$Replaced = if ($null -ne $Occupant -and $Occupant.slug) { $Occupant.name } else { '' }
$MaxRunning = @(Get-Process -Name '3dsmax' -ErrorAction SilentlyContinue).Count -gt 0

if ($Human) {
    Write-Host ''
    Write-Host "'$($Name.Trim())' is now in the $Flavour slot." -ForegroundColor Green
    if ($Replaced) { Write-Host "  It replaced '$Replaced'. Scenes saved with that one will now evaluate this one." -ForegroundColor Yellow }
    Write-Host ''
    Write-Host "  Source      $SourceDir"
    Write-Host "  Deployed    $DeployedPath"
    Write-Host "  Record      $SlotsFile"
    Write-Host ''
    Write-Host 'NEXT: restart 3ds Max.' -ForegroundColor Yellow
    Write-Host '  Slots register their classes during the plugin scan at startup, and 3ds Max offers'
    Write-Host '  no supported way to add one to a running session.'
    if ($MaxRunning) { Write-Host '  3ds Max is running now, so it will not see this until it restarts.' -ForegroundColor Yellow }
    Write-Host ''
    Write-Host "THEN: find the $Flavour slot's entry in the host, apply it, and click Hello World."
    Write-Host '  The entry carries the SLOT''s name for now, not this cartridge''s - see docs\SLOTS.md.'
    Write-Host ''
    Write-Host 'AFTER THAT: edit the payload and refresh. No restart is needed for an edit.'
    Write-Host "  $PayloadPath"
    Write-Host ''
} else {
    [ordered]@{
        schema      = 'new-cartridge/2'
        name        = $Name.Trim()
        slug        = $Slug
        slot        = $Flavour
        lane        = $Lane
        module      = $Module
        deployedAs  = "$SlotModule.py"
        sourceDir   = $SourceDir
        deployedTo  = $DeployedPath
        replaced    = $Replaced
        nameVerdict = $ClaimVerdict
        written     = @($Written)
        maxRunning  = $MaxRunning
        nextStep    = 'Restart 3ds Max. Slots register their classes during the plugin scan at startup.'
    } | ConvertTo-Json -Depth 6
}

exit 0
