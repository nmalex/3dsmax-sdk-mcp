# Runs the Python test suite (tests/test_*.py) inside the Pester run.
#
# The repository's Python - the cartridge payloads and the facade surface index - is tested with
# the standard library's unittest, so it needs no packages. Running it from here puts it in the same
# CI job and the same tools/check-all.ps1 run as the script tests, with no second pipeline to keep.
#
# No 3ds Max is needed. Python 3.8 or newer must be on PATH, as it is on a hosted Windows runner.

BeforeAll {
    $script:Root = Split-Path -Parent $PSScriptRoot
    $script:Python = Get-Command python -ErrorAction SilentlyContinue
}

Describe 'the Python test suite' {

    It 'has Python to run on' {
        $script:Python | Should -Not -BeNullOrEmpty
    }

    It 'passes' {
        $env:PYTHONIOENCODING = 'utf-8'
        $env:PYTHONDONTWRITEBYTECODE = '1'
        $Output = & $script:Python.Source -m unittest discover -s (Join-Path $script:Root 'tests') -p 'test_*.py' 2>&1 |
            Out-String
        $Code = $LASTEXITCODE
        if ($Code -ne 0) { Write-Host $Output }
        $Code | Should -Be 0
        $Output | Should -Match '(?m)^OK'
    }
}
