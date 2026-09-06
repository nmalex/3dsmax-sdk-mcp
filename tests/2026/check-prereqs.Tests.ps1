# Tests for tools/2026/check-prereqs.ps1.
#
# ONE TEST FILE PER RELEASE FOLDER, for the same reason the scripts are duplicated rather than
# shared: a test that loops over every year would pass by testing whichever one happens to exist.
#
# The valuable ones here are not "does it run" - they are the DESIGN RULES, written as assertions.
# The readiness model's central rule is that a row is a state, a reason and a remedy, never just a
# colour; and that an absent C++ toolchain is a warning rather than a failure, because a Python
# payload compiles nothing. Both are enforced below, so a later edit that quietly breaks either one
# fails here instead of in somebody's first hour with the project.

BeforeAll {
    # tests\2026\ -> tests\ -> the clone.
    $script:Root = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
    $script:Script = Join-Path $script:Root 'tools\2026\check-prereqs.ps1'

    $script:StdOut = & powershell -NoProfile -ExecutionPolicy Bypass -File $script:Script
    $script:ExitCode = $LASTEXITCODE
    $script:Text = ($script:StdOut | Out-String)
    $script:Report = $script:Text | ConvertFrom-Json
    $script:Rows = @($script:Report.rows)
}

Describe 'check-prereqs.ps1' {

    It 'exists' {
        Test-Path -LiteralPath $script:Script | Should -BeTrue
    }

    It 'emits parseable JSON and declares its schema' {
        $script:Report | Should -Not -BeNullOrEmpty
        $script:Report.schema | Should -Be 'check-prereqs/1'
    }

    It 'reports at least one row - a check over nothing is not a check' {
        $script:Rows.Count | Should -BeGreaterThan 0
    }

    It 'gives every row an id, a title, a state and a detail' {
        foreach ($Row in $script:Rows) {
            $Row.id     | Should -Not -BeNullOrEmpty
            $Row.title  | Should -Not -BeNullOrEmpty
            $Row.state  | Should -Not -BeNullOrEmpty
            # A row that says nothing is a row that wasted its line.
            $Row.detail | Should -Not -BeNullOrEmpty
        }
    }

    It 'uses only the three states a reader is expected to know' {
        foreach ($Row in $script:Rows) {
            $Row.state | Should -BeIn @('Ok', 'Warning', 'Failed')
        }
    }

    # THE RULE THE WHOLE MODEL RESTS ON. The code that found the problem is the code that knows the
    # recipe; a row that reports trouble without saying what would fix it has thrown that away.
    It 'gives every row that is not Ok a remedy' {
        foreach ($Row in $script:Rows | Where-Object { $_.state -ne 'Ok' }) {
            $Row.remedy | Should -Not -BeNullOrEmpty -Because "row '$($Row.id)' is $($Row.state) and must say what would fix it"
        }
    }

    It 'names each row once' {
        $Ids = $script:Rows | ForEach-Object { $_.id }
        ($Ids | Select-Object -Unique).Count | Should -Be $Ids.Count
    }

    It 'checks the things installing actually depends on' {
        $Ids = $script:Rows | ForEach-Object { $_.id }
        foreach ($Expected in @('max', 'max-running', 'bundle-root', 'port', 'toolchain', 'kit')) {
            $Ids | Should -Contain $Expected
        }
    }

    It 'agrees with itself about what failed' {
        $Failed = @($script:Rows | Where-Object { $_.state -eq 'Failed' })
        $script:Report.failedCount | Should -Be $Failed.Count
        $script:Report.ok | Should -Be ($Failed.Count -eq 0)
        if ($Failed.Count -eq 0) { $script:ExitCode | Should -Be 0 } else { $script:ExitCode | Should -Be 1 }
    }

    # A cartridge with a Python payload needs no compiler, and the slots ship as binaries so nothing
    # here ever needs the 3ds Max SDK. Reporting an absent toolchain as a failure would send a user
    # to install what they were never going to use.
    It 'never fails the run over a missing C++ toolchain' {
        $Toolchain = $script:Rows | Where-Object { $_.id -eq 'toolchain' }
        $Toolchain.state | Should -BeIn @('Ok', 'Warning')
    }

    It 'points a user without a toolchain at the Python lane rather than at a download' {
        $Toolchain = $script:Rows | Where-Object { $_.id -eq 'toolchain' }
        if ($Toolchain.state -eq 'Warning') {
            $Toolchain.remedy | Should -Match 'Python'
        }
    }
}
