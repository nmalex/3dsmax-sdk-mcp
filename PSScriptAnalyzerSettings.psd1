# PSScriptAnalyzer settings for this repository.
#
# CI runs the analyzer over tools\ on every push and pull request and fails on anything it reports,
# so this file is the one place a rule is allowed to be turned off - and every exclusion has to say
# why here, in the open, rather than being scattered through the scripts as suppression attributes.
#
# Severity is Error and Warning. Information is not a gate: it is advice, and a gate made of advice
# is a gate people learn to ignore.

@{
    Severity = @('Error', 'Warning')

    ExcludeRules = @(
        # PSAvoidUsingWriteHost - EXCLUDED DELIBERATELY, and this is the only rule that is.
        #
        # The rule is right about ordinary scripts and wrong about these. Two reasons, and the
        # second one is not a preference:
        #
        # 1. THE SCRIPTS EXIST TO BE WATCHED. An install has to show a person what it is doing, in
        #    a console that does not close on them - that is why every one of these tools has a
        #    .cmd beside it that pauses at the end. Write-Verbose and Write-Information are off by
        #    default, so text written through them is text nobody sees, which fails the one
        #    requirement these scripts have.
        #
        # 2. STDOUT IS A MACHINE CONTRACT HERE. find-max.ps1 and list-plugins.ps1 emit JSON on
        #    standard output and are parsed by agents and by other scripts in this repository.
        #    Write-Output puts a string INTO that pipeline. Swapping Write-Host for Write-Output to
        #    satisfy the analyzer would mix progress text into the JSON and break every caller -
        #    the rule's recommended fix is, for these files, the actual bug.
        #
        # So Write-Host is the correct call: it reaches the person and stays out of the pipeline.
        # A script here that wants to RETURN something uses Write-Output, and the two are kept
        # apart on purpose.
        'PSAvoidUsingWriteHost'
    )
}
