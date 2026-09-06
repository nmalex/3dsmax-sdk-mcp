@echo off
rem The front door for a PERSON. Points this clone's git hooks at tools\hooks so the CI checks run
rem before you commit and before you push, and stays open so you can read what it configured.
rem
rem   install-hooks.cmd            install them
rem   install-hooks.cmd -Remove    stop running them
rem
rem AN AGENT SHOULD NOT RUN THIS. Run install-hooks.ps1 directly: no blocking on `pause`.
setlocal
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0install-hooks.ps1" %*
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
