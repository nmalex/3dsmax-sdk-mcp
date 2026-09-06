# Tests for tools/find-max.ps1.
#
# BLACK BOX, ON PURPOSE. These run the script as a user runs it and assert on what comes out,
# because the output IS the contract - an agent reads that JSON and acts on it. A test that reached
# inside and checked a variable would pass while the contract broke.
#
# THEY RUN ON A MACHINE WITH 3DS MAX AND ON ONE WITHOUT. A hosted CI runner has no 3ds Max, this
# developer's machine has one, and both are legitimate. So every assertion below is either true in
# both cases, or conditioned on which case it is. A test that only passes where it was written is
# not a test, it is a local habit.

BeforeAll {
    $script:Root = Split-Path -Parent $PSScriptRoot
    $script:Script = Join-Path $script:Root 'tools\find-max.ps1'

    $script:StdOut = & powershell -NoProfile -ExecutionPolicy Bypass -File $script:Script
    $script:ExitCode = $LASTEXITCODE
    $script:Text = ($script:StdOut | Out-String)
    $script:Report = $script:Text | ConvertFrom-Json
}

Describe 'find-max.ps1' {

    It 'exists' {
        Test-Path -LiteralPath $script:Script | Should -BeTrue
    }

    It 'emits parseable JSON' {
        $script:Report | Should -Not -BeNullOrEmpty
    }

    It 'declares its schema, so a consumer can tell one version of this contract from the next' {
        $script:Report.schema | Should -Be 'find-max/1'
    }

    It 'states which 3ds Max releases this release of the plugin supports' {
        $script:Report.supportedYears | Should -Not -BeNullOrEmpty
        $script:Report.supportedYears | Should -Contain 2026
    }

    It 'reports where it looked, so finding nothing is an answer rather than a silence' {
        $script:Report.searched | Should -Not -BeNullOrEmpty
        $script:Report.searched -join ' ' | Should -Match 'Autodesk'
    }

    It 'agrees with itself about how many installs it found' {
        $script:Report.installCount | Should -Be @($script:Report.installs).Count
    }

    It 'exits 4 when nothing was found and 0 or 3 when something was' {
        if ($script:Report.installCount -eq 0) {
            $script:ExitCode | Should -Be 4
        } elseif ($script:Report.supportedCount -gt 0) {
            $script:ExitCode | Should -Be 0
        } else {
            $script:ExitCode | Should -Be 3
        }
    }

    It 'always carries a remedy when it has nothing useful to report' {
        if ($script:Report.supportedCount -eq 0) {
            $script:Report.remedy | Should -Not -BeNullOrEmpty
        }
    }

    # The registry key this script reads also holds SerialNumber, FirstName, LastName and
    # Organization. None is needed to install a plugin, all are the user's, and this output is
    # written for an agent that may quote it into a conversation, a log or an issue. This test is
    # the rule, enforced.
    It 'never emits the personal data that sits in the same registry key' {
        foreach ($Forbidden in @('serialNumber', 'firstName', 'lastName', 'organization', 'dealer')) {
            $script:Text | Should -Not -Match $Forbidden
        }
    }

    Context 'when a 3ds Max is installed on this machine' {
        It 'describes each install completely enough to act on' -Skip:($script:Report.installCount -eq 0) {
            foreach ($Install in $script:Report.installs) {
                $Install.PSObject.Properties.Name | Should -Contain 'year'
                $Install.PSObject.Properties.Name | Should -Contain 'installRoot'
                $Install.PSObject.Properties.Name | Should -Contain 'exe'
                $Install.PSObject.Properties.Name | Should -Contain 'supported'
                $Install.installRoot | Should -Not -BeNullOrEmpty
            }
        }

        It 'gives every unsupported install a reason, never a bare false' -Skip:($script:Report.installCount -eq 0) {
            foreach ($Install in $script:Report.installs | Where-Object { -not $_.supported }) {
                $Install.reason | Should -Not -BeNullOrEmpty
            }
        }

        It 'resolves a real year rather than falling back to zero' -Skip:($script:Report.installCount -eq 0) {
            foreach ($Install in $script:Report.installs) {
                $Install.year | Should -BeGreaterThan 2000
            }
        }
    }
}
