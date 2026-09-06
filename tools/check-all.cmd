@echo off
rem The front door for a PERSON. Runs the same jobs CI runs, on this machine, and stays open - a
rem window that closes takes the findings with it.
rem
rem   check-all.cmd            everything
rem   check-all.cmd -Fast      skips the test suite
rem
rem AN AGENT SHOULD NOT RUN THIS. Run check-all.ps1 directly: meaningful exit code, no `pause`.
setlocal
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0check-all.ps1" %*
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
