# Tests for mcp-tools.json and docs/TOOLS.md - the published list of the server's MCP tools.
#
# WHY THESE EXIST. The server is a compiled 3ds Max plugin, and its MCP endpoint only answers on
# 127.0.0.1 inside a running 3ds Max. So the published list is the only place a reader, an agent
# choosing what to call, or a scanner can see which tools it serves. These tests hold that list to
# the MCP tool contract: every tool the server serves is there, and each one has a name, a title, a
# description, an object input schema, and all four behaviour hints.
#
# THE EXPECTED NAMES ARE WRITTEN OUT BELOW, ON PURPOSE. The list is generated from the server's own
# tools/list for each release. Adding, removing or renaming a tool is a change to what clients can
# call, so it must be made here as well, deliberately - a generated list that silently lost a tool
# would otherwise pass.
#
# No 3ds Max is needed: these read files only, so they run on a hosted CI runner.

BeforeDiscovery {
    $script:ExpectedTools = @(
        'cartridge_logs'
        'max_capabilities'
        'max_cartridge_probe'
        'max_cartridge_refresh'
        'max_cartridges'
        'max_facade'
        'max_job_cancel'
        'max_job_result'
        'max_job_start'
        'max_job_status'
        'max_jobs'
        'max_python_probe'
        'max_python_status'
        'max_quit'
        'max_restart'
        'max_scene_open'
        'max_scene_reset'
        'max_scene_save'
        'max_scene_save_as'
        'max_scene_state'
        'max_tools'
    )
    # Tools that change or discard what the user has open. A client may ask before calling these,
    # so the published hint must say so.
    $script:DestructiveTools = @(
        'max_job_start'
        'max_quit'
        'max_restart'
        'max_scene_open'
        'max_scene_reset'
    )
}

BeforeAll {
    $script:Root = Split-Path -Parent $PSScriptRoot
    $script:JsonPath = Join-Path $script:Root 'mcp-tools.json'
    $script:DocPath = Join-Path $script:Root 'docs\TOOLS.md'
    $script:Record = [System.IO.File]::ReadAllText($script:JsonPath) | ConvertFrom-Json
    $script:Doc = [System.IO.File]::ReadAllText($script:DocPath)

    function Get-PublishedTool([string]$Name) {
        return @($script:Record.tools | Where-Object { $_.name -eq $Name })
    }
}

Describe 'mcp-tools.json' {

    It 'declares its schema, so a consumer can tell one version of this record from the next' {
        $script:Record.schema | Should -Be 'mcp-tools/1'
    }

    It 'names the server and the version it was generated from' {
        $script:Record.server.name | Should -Be 'maxsdk-mcp'
        $script:Record.server.version | Should -Match '^\d+\.\d+\.\d+'
        $script:Record.protocolVersion | Should -Match '^\d{4}-\d{2}-\d{2}$'
    }

    It 'lists exactly the tools the server serves - no more, no fewer' -ForEach @(@{ Expected = $ExpectedTools }) {
        $Names = @($script:Record.tools | ForEach-Object { $_.name })
        Compare-Object -ReferenceObject $Expected -DifferenceObject $Names | Should -BeNullOrEmpty
    }

    It 'lists each tool once' {
        $Names = @($script:Record.tools | ForEach-Object { $_.name })
        @($Names | Select-Object -Unique).Count | Should -Be $Names.Count
    }
}

Describe 'the published tool <_>' -ForEach $ExpectedTools {

    BeforeAll {
        $script:Name = $_
        $script:Tool = @(Get-PublishedTool $script:Name)
    }

    It 'is published' {
        $script:Tool.Count | Should -Be 1
    }

    It 'has a title and a description' {
        $script:Tool[0].title | Should -Not -BeNullOrEmpty
        $script:Tool[0].description | Should -Not -BeNullOrEmpty
    }

    It 'takes an object input schema whose required arguments are all declared' {
        $Schema = $script:Tool[0].inputSchema
        $Schema.type | Should -Be 'object'
        $Declared = @()
        if ($Schema.properties) { $Declared = @($Schema.properties.PSObject.Properties.Name) }
        foreach ($Required in @($Schema.required)) {
            if ($Required) { $Declared | Should -Contain $Required }
        }
    }

    It 'carries all four behaviour hints, each true or false' {
        $Hints = $script:Tool[0].annotations
        foreach ($Hint in 'readOnlyHint', 'destructiveHint', 'idempotentHint', 'openWorldHint') {
            $Hints.PSObject.Properties.Name | Should -Contain $Hint
            $Hints.$Hint | Should -BeOfType [bool]
        }
    }

    It 'never claims to be both read-only and destructive' {
        $Hints = $script:Tool[0].annotations
        ($Hints.readOnlyHint -and $Hints.destructiveHint) | Should -BeFalse
    }

    It 'is documented in docs/TOOLS.md' {
        $script:Doc | Should -Match ('(?m)^## ' + [regex]::Escape($script:Name) + '\s*$')
    }
}

Describe 'the destructive tool <_>' -ForEach $DestructiveTools {

    It 'is marked destructive, so a client can ask before calling it' {
        @(Get-PublishedTool $_)[0].annotations.destructiveHint | Should -BeTrue
    }
}
