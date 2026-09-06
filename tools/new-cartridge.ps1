# Scaffolds a new cartridge into a slot, and deploys it, in one step.
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\new-cartridge.ps1 `
#       -Name "Cool Bend" [-Flavour modifier] [-Lane python] [-Replace] [-Human]
#
# What comes out is a cartridge that already works: an entry in the host, a rollout in the command
# panel, and a button that says Hello World. It changes no geometry, on purpose - see the comment at
# the top of the generated payload for why an inert scaffold is worth more than a clever one.
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

    # Which slot to occupy. One slot per plugin type.
    [ValidateSet('modifier', 'utility', 'exporter')]
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
$TemplateRoot = Join-Path $KitRoot "templates\$Flavour"
$StateDir = Join-Path $env:LOCALAPPDATA '3dsmax-sdk-mcp'
$DeployRoot = Join-Path $StateDir 'cartridges'
$SlotsFile = Join-Path $StateDir 'slots.json'

# The module name the slot for this flavour was compiled to load. Fixed, because everything about a
# slot is fixed - this is the whole binding between a slot and the cartridge in it.
$SlotModule = "slot_$Flavour"

function Fail([string]$Message, [int]$Code = 2) {
    Write-Host "REFUSED: $Message" -ForegroundColor Red
    exit $Code
}

# -- Names, all derived from one input --------------------------------------------------------------
$Slug = ($Name.Trim().ToLowerInvariant() -replace '[^a-z0-9]+', '-').Trim('-')
$Module = ($Slug -replace '-', '_')

if ([string]::IsNullOrWhiteSpace($Slug)) { Fail "'$Name' has no letters or digits in it, so no directory name can be derived from it." }
if ($Module -match '^[0-9]') { Fail "'$Name' starts with a digit, which cannot begin a Python module name. Start it with a letter." }

if (-not (Test-Path -LiteralPath $TemplateRoot)) {
    Write-Host "NOT SUPPORTED YET: there is no template for the '$Flavour' slot." -ForegroundColor Yellow
    Write-Host "Templated today: $((Get-ChildItem -LiteralPath (Join-Path $KitRoot 'templates') -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }) -join ', ')"
    Write-Host 'The remaining slots are listed in ROADMAP.md. They are not forgotten; they are not built.'
    exit 3
}
if ($Lane -eq 'native' -and -not (Test-Path -LiteralPath (Join-Path $TemplateRoot 'native'))) {
    Write-Host "NOT SUPPORTED YET: the '$Flavour' template has no native lane." -ForegroundColor Yellow
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

$Tokens = @{
    '@DISPLAY_NAME@'   = $Name.Trim()
    '@SLUG@'           = $Slug
    '@MODULE@'         = $Module
    '@FLAVOUR@'        = $Flavour
    '@SLOT_MODULE@'    = $SlotModule
    # A fresh project GUID per cartridge. Never reused from a sibling: two projects sharing one guid
    # confuse every tool that keys off it, and the confusion appears as builds that quietly do the
    # wrong thing rather than as an error.
    '@PROJECT_GUID@'   = [Guid]::NewGuid().ToString().ToUpperInvariant()
    '@MAX_YEARS@'      = (($MaxYears | Sort-Object -Unique) -join ', ')
    '@PLUGIN_VERSION@' = $PluginVersion
    '@CREATED@'        = (Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')
    '@GENERATOR@'      = 'new-cartridge.ps1'
}
function Expand-Template([string]$Text) {
    foreach ($Key in $Tokens.Keys) { $Text = $Text.Replace($Key, $Tokens[$Key]) }
    return $Text
}

$Written = New-Object System.Collections.ArrayList
New-Item -ItemType Directory -Path (Join-Path $SourceDir 'python') -Force | Out-Null

$ManifestPath = Join-Path $SourceDir 'cartridge.json'
[System.IO.File]::WriteAllText($ManifestPath, (Expand-Template (Get-Content -LiteralPath (Join-Path $TemplateRoot 'cartridge.json') -Raw)), (New-Object System.Text.UTF8Encoding($false)))
[void]$Written.Add($ManifestPath)

$PayloadPath = Join-Path $SourceDir "python\$Module.py"
[System.IO.File]::WriteAllText($PayloadPath, (Expand-Template (Get-Content -LiteralPath (Join-Path $TemplateRoot 'python\payload.py') -Raw)), (New-Object System.Text.UTF8Encoding($false)))
[void]$Written.Add($PayloadPath)

# A README is required of every cartridge, so it is scaffolded rather than demanded: a rule that is
# free to comply with is a rule people follow. The check refuses one that was never filled in.
$ReadmePath = Join-Path $SourceDir 'README.md'
[System.IO.File]::WriteAllText($ReadmePath, (Expand-Template (Get-Content -LiteralPath (Join-Path $TemplateRoot 'README.md') -Raw)), (New-Object System.Text.UTF8Encoding($false)))
[void]$Written.Add($ReadmePath)

# THE NATIVE LANE, scaffolded whenever the template has one - not only when -Lane native was asked
# for. The two lanes are not alternatives that exclude each other: a native exporter still leaves
# the options panel to Python, because composing a panel is where a language with closures earns its
# keep. Scaffolding both means porting a hot function later is an edit rather than a new project.
$TemplateNative = Join-Path $TemplateRoot 'native'
if (Test-Path -LiteralPath $TemplateNative) {
    New-Item -ItemType Directory -Path (Join-Path $SourceDir 'native\src') -Force | Out-Null

    $PropsPath = Join-Path $SourceDir 'Version.props'
    [System.IO.File]::WriteAllText($PropsPath, (Expand-Template (Get-Content -LiteralPath (Join-Path $TemplateRoot 'Version.props') -Raw)), (New-Object System.Text.UTF8Encoding($false)))
    [void]$Written.Add($PropsPath)

    foreach ($Pair in @(
        @{ From = 'native\Payload.vcxproj'; To = "native\$Module`_payload.vcxproj" },
        # NOT renamed to the module name. A Python module's filename IS its import name and must
        # match; a C++ source's filename is nothing to anybody, and renaming it only creates a second
        # place for the project file to disagree with the disk.
        @{ From = 'native\src\payload.cpp'; To = 'native\src\payload.cpp' })) {
        $Target = Join-Path $SourceDir $Pair.To
        [System.IO.File]::WriteAllText($Target, (Expand-Template (Get-Content -LiteralPath (Join-Path $TemplateRoot $Pair.From) -Raw)), (New-Object System.Text.UTF8Encoding($false)))
        [void]$Written.Add($Target)
    }
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
    name       = $Tokens['@DISPLAY_NAME@']
    slug       = $Slug
    module     = $Module
    deployedAs = "$SlotModule.py"
    source     = $SourceDir
    lane       = $Lane
    since      = $Tokens['@CREATED@']
}
$Slots.slots | Add-Member -NotePropertyName $Flavour -NotePropertyValue $Entry -Force
$Slots | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $SlotsFile -Encoding UTF8

$Replaced = if ($null -ne $Occupant -and $Occupant.slug) { $Occupant.name } else { '' }
$MaxRunning = @(Get-Process -Name '3dsmax' -ErrorAction SilentlyContinue).Count -gt 0

if ($Human) {
    Write-Host ''
    Write-Host "'$($Tokens['@DISPLAY_NAME@'])' is now in the $Flavour slot." -ForegroundColor Green
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
        name        = $Tokens['@DISPLAY_NAME@']
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
