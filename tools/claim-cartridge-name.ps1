# Is this a good name for a cartridge - and does it collide with anything already in 3ds Max?
#
#   powershell -NoProfile -ExecutionPolicy Bypass -File tools\check-name.ps1 `
#       -Name "Bending" -ClassesJson <file> [-Flavour modifier] [-Human]
#
# THE CLASS LIST IS REQUIRED, AND THAT IS THE POINT. Without the exact list of what 3ds Max has
# registered, this script cannot say a name is clear - it can only say it did not happen to see a
# problem, which is not the same claim and is the more dangerous one to make. Eyeballing the
# cartridge directory finds cartridges and misses every stock modifier and every third-party plugin
# the user installed. So: no list, no verdict. It exits 3 and says what to ask for.
#
# WHERE THE LIST COMES FROM. The running 3ds Max, which is authoritative and current:
# modifierPlugin.classes, utilityPlugin.classes, exporterPlugin.classes. Write them to a JSON array
# and pass the file. NOTHING IS SHIPPED WITH THIS KIT: a list of stock names carried in this
# repository would be wrong the day a service pack shipped, and wrong in the direction that lets a
# real collision through.
#
# WHAT 3DS MAX DOES WITH A NAME, which is invisible from the source and is why this exists:
#
#   1. It derives a MAXScript global - spaces become underscores, '+' characters are DROPPED. So
#      "Bend C++" becomes Bend_C, and two different display names can mangle to one global.
#   2. When that global collides with one already registered, it resolves SILENTLY by appending the
#      superclass: "Bend ++" becomes Bendmodifier. Nothing warns you, and the result depends on
#      plugin load order, so nothing can script against it reliably.
#
# THREE TIERS, AND ONLY THE FIRST TWO REFUSE:
#
#   CONFLICT    an exact or mangled collision. Do not ship it.
#   CONFUSABLE  "Bending" beside "Bend" collides with nothing and is still a bad name, because the
#               two sit together in an alphabetical Modifier List and nobody can tell them apart.
#               Reported, never auto-refused - it is a question for the person choosing.
#   STYLE       advice only. Never changes the verdict.
#
# THE STYLE ADVICE IS MEASURED, NOT ASSERTED. Good cartridge names look like the native plugin
# names - short and revealing: Bend, Twist, Shell, Lattice, UVW Map. Rather than hardcode what
# "short" means, this measures the host's OWN registered names and compares against them, so the
# advice is about the 3ds Max in front of you. It is a recommendation and never a limit: a longer
# name that is genuinely clearer wins, and the script says so rather than blocking it.
#
# Exit codes: 0 clear, 1 conflict, 2 confusable, 3 nothing authoritative to check against.

[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$Name,

    [ValidateSet('modifier', 'utility', 'exporter')]
    [string]$Flavour = 'modifier',

    # A JSON array of the names 3ds Max has REGISTERED, e.g. ["Bend","Twist","Skin","UVW Map"].
    # The strongest source: only a running host can produce it, and it is what a user actually sees.
    [string]$ClassesJson = '',

    # Output of tools\list-plugins.ps1 - every plugin MODULE installed, from the directories 3ds Max
    # searches. Weaker than the class list and always available, including with Max shut down: a
    # module file name is not a class name, but a module called "bend" is still evidence that the
    # name "Bend" is spoken for.
    [string]$PluginsJson = '',

    [switch]$Human
)

$ErrorActionPreference = 'Stop'

$KitRoot = Split-Path -Parent $PSScriptRoot
$DeployRoot = Join-Path $env:LOCALAPPDATA '3dsmax-sdk-mcp\cartridges'

# Words that describe a category rather than a capability. A plugin called "Mesh Tool" tells a user
# nothing they did not already know from the fact that it is a plugin.
$VagueWords = @('tool', 'tools', 'helper', 'manager', 'utility', 'plugin', 'plug-in', 'custom',
                'my', 'new', 'test', 'demo', 'thing', 'stuff', 'generic', 'wrapper', 'handler',
                'module', 'system', 'cartridge')


function Get-DisplayKey([string]$Text) { return (($Text.ToLowerInvariant() -replace '[^a-z0-9]', '')) }

# What MAXScript will actually derive. Measured behaviour, not a guess: '+' is dropped, a space
# becomes an underscore. "Bend C++" -> Bend_C (collides with nothing); "Bend ++" -> Bend (collides).
function Get-MaxScriptGlobal([string]$Text) {
    $Global = $Text -replace '\+', ''
    return ($Global.Trim() -replace '\s+', '_')
}

# A crude stem, for the confusable tier only. Never refuses anything - it exists to notice that
# "Bending", "Bends" and "Bender" are all in the neighbourhood of "Bend".
function Get-Stem([string]$Key) {
    foreach ($Suffix in @('ing', 'tion', 'ion', 'ers', 'er', 'ors', 'or', 'ed', 'es', 's')) {
        if ($Key.Length -gt ($Suffix.Length + 2) -and $Key.EndsWith($Suffix)) {
            return $Key.Substring(0, $Key.Length - $Suffix.Length)
        }
    }
    return $Key
}

function Get-EditDistance([string]$A, [string]$B) {
    if ($A -eq $B) { return 0 }
    if ($A.Length -eq 0) { return $B.Length }
    if ($B.Length -eq 0) { return $A.Length }
    $Previous = 0..$B.Length
    for ($i = 1; $i -le $A.Length; $i++) {
        $Current = @($i) + (1..$B.Length | ForEach-Object { 0 })
        for ($j = 1; $j -le $B.Length; $j++) {
            $Cost = if ($A[$i - 1] -eq $B[$j - 1]) { 0 } else { 1 }
            $Current[$j] = [Math]::Min([Math]::Min($Current[$j - 1] + 1, $Previous[$j] + 1), $Previous[$j - 1] + $Cost)
        }
        $Previous = $Current
    }
    return $Previous[$B.Length]
}

function Get-Median([int[]]$Values) {
    if ($Values.Count -eq 0) { return 0 }
    $Sorted = $Values | Sort-Object
    return [int]$Sorted[[int][Math]::Floor($Sorted.Count / 2)]
}


# -- The authoritative list, without which there is no verdict --------------------------------------
if (-not $ClassesJson -and -not $PluginsJson) {
    Write-Host 'NOTHING AUTHORITATIVE TO CHECK AGAINST - REFUSING TO GIVE A VERDICT.' -ForegroundColor Yellow
    Write-Host ''
    Write-Host 'A name can only be cleared against a real inventory. Reading the cartridge directory'
    Write-Host 'finds cartridges and misses every stock modifier and every third-party plugin on this'
    Write-Host 'machine, so a pass would mean nothing.'
    Write-Host ''
    Write-Host 'Pass one or both:'
    Write-Host '  -ClassesJson  the names a RUNNING 3ds Max has registered (strongest)'
    Write-Host '  -PluginsJson  the output of tools\list-plugins.ps1 (works with Max shut down)'
    exit 3
}

$Existing = New-Object System.Collections.ArrayList
$Sources = New-Object System.Collections.ArrayList
$HostNames = @()

if ($ClassesJson) {
    if (-not (Test-Path -LiteralPath $ClassesJson)) {
        Write-Host "REFUSED: no class list at '$ClassesJson'." -ForegroundColor Red
        exit 3
    }
    # The ForEach-Object is load-bearing. PowerShell 5.1's ConvertFrom-Json emits a JSON ARRAY as a
    # single object rather than enumerating it, so `@(... | ConvertFrom-Json)` yields a one-element
    # array holding the array - and every name then compares as one space-joined string. Measured:
    # eight class names arrived as "Bend Twist Taper Noise Shell UVW Map Edit Poly Skin" and every
    # collision check silently passed. Piping through ForEach-Object unrolls it properly.
    $Parsed = Get-Content -LiteralPath $ClassesJson -Raw | ConvertFrom-Json
    $HostNames = @($Parsed | ForEach-Object { $_ })
    foreach ($Entry in $HostNames) {
        if ($Entry) { [void]$Existing.Add([pscustomobject]@{ name = [string]$Entry; from = 'class' }) }
    }
    [void]$Sources.Add("3ds Max registered classes: $($HostNames.Count)")
}

if ($PluginsJson) {
    if (-not (Test-Path -LiteralPath $PluginsJson)) {
        Write-Host "REFUSED: no plugin inventory at '$PluginsJson'." -ForegroundColor Red
        exit 3
    }
    $Inventory = Get-Content -LiteralPath $PluginsJson -Raw | ConvertFrom-Json
    $ModuleCount = 0
    foreach ($Module in @($Inventory.modules)) {
        if ($Module.module) {
            [void]$Existing.Add([pscustomobject]@{ name = [string]$Module.module; from = 'module' })
            $ModuleCount++
        }
        # A version resource's FileDescription often carries the human name, so it is worth comparing
        # for an EXACT hit. It is tagged separately because descriptions like "Autodesk 3ds Max
        # Modifiers" would fire the "contains" tier against half the names anyone could choose, which
        # is noise dressed up as diligence - the tier loop below only takes exact hits from these.
        if ($Module.description) {
            [void]$Existing.Add([pscustomobject]@{ name = [string]$Module.description; from = 'module-description' })
        }
    }
    [void]$Sources.Add("installed plugin modules: $ModuleCount")
}

if ($Existing.Count -eq 0) {
    Write-Host 'REFUSED: the lists supplied held no names. A check over an empty list is not a check.' -ForegroundColor Red
    exit 3
}

# What backed this verdict, so a caller can weigh it. A pass against module names alone is a
# weaker claim than a pass against what the host actually registered, and saying so is the
# difference between a check and a rubber stamp.
$Confidence = if ($ClassesJson -and $PluginsJson) { 'class-names+modules' }
              elseif ($ClassesJson) { 'class-names' }
              else { 'modules-only' }

# Cartridges on this machine, added to the same comparison. These are a SUPPLEMENT to the host list
# and never a substitute for it - a cartridge scaffolded five minutes ago is not registered yet.
foreach ($Root in @((Join-Path $KitRoot 'cartridges'), $DeployRoot)) {
    if (-not (Test-Path -LiteralPath $Root)) { continue }
    $Found = 0
    foreach ($File in (Get-ChildItem -LiteralPath $Root -Filter 'cartridge.json' -Recurse -ErrorAction SilentlyContinue)) {
        try {
            $Json = Get-Content -LiteralPath $File.FullName -Raw | ConvertFrom-Json
            if ($Json.name) { [void]$Existing.Add([pscustomobject]@{ name = [string]$Json.name; from = 'cartridge' }); $Found++ }
        } catch { }
    }
    if ($Found -gt 0) { [void]$Sources.Add("$Root : $Found cartridge(s)") }
}


# -- Tiers one and two ---------------------------------------------------------------------------------
$Key = Get-DisplayKey $Name
$Global = Get-MaxScriptGlobal $Name
$GlobalKey = Get-DisplayKey $Global
$Stem = Get-Stem $Key

$Conflicts = New-Object System.Collections.ArrayList
$Confusable = New-Object System.Collections.ArrayList

foreach ($Item in $Existing) {
    $OtherKey = Get-DisplayKey $Item.name
    if (-not $OtherKey) { continue }
    $OtherGlobalKey = Get-DisplayKey (Get-MaxScriptGlobal $Item.name)

    if ($OtherKey -eq $Key) {
        [void]$Conflicts.Add([pscustomobject]@{ existing = $Item.name; from = $Item.from; kind = 'exact'
            why = "'$($Item.name)' is already registered. Two classes with one name means 3ds Max picks the MAXScript global by load order." })
        continue
    }
    if ($OtherGlobalKey -eq $GlobalKey) {
        [void]$Conflicts.Add([pscustomobject]@{ existing = $Item.name; from = $Item.from; kind = 'mangled'
            why = "different on screen, but both resolve to the MAXScript global '$Global'. 3ds Max breaks that tie silently by appending the superclass." })
        continue
    }

    # THE SOFT TIERS RUN AGAINST REAL CLASS NAMES ONLY, and this was measured rather than reasoned:
    # asking about "Bend" against a module inventory reported a near-miss with 'rend' - a stock
    # module file name no user has ever seen - while "Bending" came back CLEAR, because the stock
    # Bend modifier lives inside a shared module and there is no file called bend.dlm. So module
    # names produce false alarms on the soft tiers AND miss the case those tiers exist for.
    # They are exact-and-mangled evidence, and nothing softer.
    if ($Item.from -eq 'module' -or $Item.from -eq 'module-description') { continue }

    if ((Get-Stem $OtherKey) -eq $Stem) {
        [void]$Confusable.Add([pscustomobject]@{ existing = $Item.name; from = $Item.from; kind = 'same-stem'
            why = "'$($Item.name)' and '$Name' are the same word in different clothes. In an alphabetical list they sit together and nobody can tell which does what." })
    } elseif ($OtherKey.Contains($Key) -or $Key.Contains($OtherKey)) {
        [void]$Confusable.Add([pscustomobject]@{ existing = $Item.name; from = $Item.from; kind = 'contains'
            why = "one name contains the other ('$($Item.name)' / '$Name'), so the list reads as two versions of one thing." })
    } elseif ($Key.Length -ge 4 -and (Get-EditDistance $Key $OtherKey) -le 1) {
        [void]$Confusable.Add([pscustomobject]@{ existing = $Item.name; from = $Item.from; kind = 'near-miss'
            why = "one character apart from '$($Item.name)'. That is a typo waiting to be filed as a bug against the wrong plugin." })
    }
}


# -- Tier three: style, measured against the host's own names -------------------------------------------
# The benchmark is not a number chosen here. It is what the 3ds Max in front of you actually calls
# its own plugins, which is the standard a user's eye is already calibrated to.
#
# Class names are the right yardstick because they are what a user reads in the Modifier List. When
# only a module inventory was supplied there are none, so module base names stand in - a weaker
# benchmark, and still measured from this machine rather than asserted here.
$Benchmark = if ($HostNames.Count -gt 0) { @($HostNames) }
             else { @($Existing | Where-Object { $_.from -eq 'module' } | ForEach-Object { $_.name }) }
$HostWordCounts = @($Benchmark | ForEach-Object { @(([string]$_ -split '\s+') | Where-Object { $_ }).Count })
$HostLengths = @($Benchmark | ForEach-Object { ([string]$_).Length })
$MedianWords = Get-Median $HostWordCounts
$MedianChars = Get-Median $HostLengths

$Words = @(($Name -split '\s+') | Where-Object { $_ })
$Style = New-Object System.Collections.ArrayList

if ($Words.Count -gt ($MedianWords + 1)) {
    [void]$Style.Add("$($Words.Count) words. The names this 3ds Max ships average $MedianWords - short and revealing is the house style, e.g. Bend, Shell, UVW Map. A recommendation, not a limit: a longer name that is genuinely clearer wins.")
}
if ($Name.Length -gt ([Math]::Max(16, $MedianChars * 2))) {
    [void]$Style.Add("$($Name.Length) characters against a median of $MedianChars here. Long names are truncated in the Modifier List, which is where people read them.")
}
foreach ($Word in $Words) {
    if ($VagueWords -contains $Word.ToLowerInvariant()) {
        [void]$Style.Add("'$Word' names a category, not a capability - it tells a user nothing they did not already know. Name what it DOES.")
    }
}
if ($Key.EndsWith('ing') -and $Key.Length -gt 5) {
    [void]$Style.Add("ends in -ing. Stock names are nouns or verbs - 'Bend', not 'Bending' - and the gerund is also how a name ends up confusable with one that already exists.")
}
if ($Name -match '\d') {
    [void]$Style.Add('contains a digit. Versions belong in the manifest, not in the name a user reads forever.')
}


# -- The convention, when the name IS a stock plugin's ----------------------------------------------------
# Most cartridges exist to reproduce something 3ds Max already ships, so the two can be put side by
# side. When that is the intent the name is not free-form: it is the stock name plus a lane suffix,
# so the entries group together in the list where the comparison actually happens.
$Suggestions = New-Object System.Collections.ArrayList
if (@($Conflicts | Where-Object { $_.kind -eq 'exact' }).Count -gt 0) {
    [void]$Suggestions.Add("$Name C++  -> mangles to $(Get-MaxScriptGlobal "$Name C++"), which collides with nothing")
    [void]$Suggestions.Add("$Name Py   -> the Python lane, grouped beside it in the list")
}

$Verdict = if ($Conflicts.Count -gt 0) { 'conflict' } elseif ($Confusable.Count -gt 0) { 'confusable' } else { 'clear' }

$Report = [ordered]@{
    schema          = 'check-name/1'
    name            = $Name
    flavour         = $Flavour
    maxscriptGlobal = $Global
    verdict         = $Verdict
    confidence      = $Confidence
    conflicts       = @($Conflicts)
    confusable      = @($Confusable)
    style           = @($Style)
    suggestions     = @($Suggestions)
    comparedAgainst = $Existing.Count
    hostMedianWords = $MedianWords
    hostMedianChars = $MedianChars
    sources         = @($Sources)
    caveat          = $(if ($Confidence -eq 'modules-only') {
        'MODULES ONLY. Without the class list from a running 3ds Max, only exact and mangled collisions were checked. The confusable tiers did NOT run against real class names - so "clear" here means "no file collides", not "no plugin collides". A stock modifier living inside a shared module is invisible to this check.'
    } else { '' })
}

if ($Human) {
    Write-Host ''
    Write-Host "Name:             $Name"
    Write-Host "MAXScript global: $Global"
    Write-Host "Compared against: $($Existing.Count) name(s) [$Confidence]"
    Write-Host ''
    if ($Report.caveat) {
        Write-Host $Report.caveat -ForegroundColor Yellow
        Write-Host ''
    }
    switch ($Verdict) {
        'clear'      { Write-Host 'CLEAR - no conflict and nothing confusable.' -ForegroundColor Green }

        'confusable' { Write-Host 'CONFUSABLE - it works, but a person would struggle to tell it apart:' -ForegroundColor Yellow }
        'conflict'   { Write-Host 'CONFLICT - do not ship this name:' -ForegroundColor Red }
    }
    foreach ($Row in $Conflicts)  { Write-Host "  [$($Row.kind)] $($Row.why)" -ForegroundColor Red }
    foreach ($Row in $Confusable) { Write-Host "  [$($Row.kind)] $($Row.why)" -ForegroundColor Yellow }
    if ($Style.Count -gt 0) {
        Write-Host ''
        Write-Host 'Style, measured against this host (advice, never a limit):' -ForegroundColor DarkGray
        foreach ($S in $Style) { Write-Host "  - $S" -ForegroundColor DarkGray }
    }
    if ($Suggestions.Count -gt 0) {
        Write-Host ''
        Write-Host 'If you MEANT to replicate the stock plugin, the convention is a lane suffix:'
        foreach ($S in $Suggestions) { Write-Host "  $S" }
    }
    Write-Host ''
} else {
    $Report | ConvertTo-Json -Depth 6
}

switch ($Verdict) {
    'conflict'   { exit 1 }
    'confusable' { exit 2 }
    default      { exit 0 }
}
