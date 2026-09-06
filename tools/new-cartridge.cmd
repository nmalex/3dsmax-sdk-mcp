@echo off
rem The front door for a PERSON. Opens a visible console, scaffolds a cartridge, and stays open -
rem the last thing it prints is what to do next, and a window that closes takes that with it.
rem
rem   new-cartridge.cmd "Hello World"
rem
rem AN AGENT SHOULD NOT RUN THIS. Run new-cartridge.ps1 directly: JSON on stdout, meaningful exit
rem code, no blocking on `pause`.
setlocal
if "%~1"=="" (
    echo Usage: new-cartridge.cmd "Display Name"
    echo.
    echo   The name a person will see in the Modifier List. Spaces are fine.
    echo.
    pause
    exit /b 2
)
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0new-cartridge.ps1" -Name "%~1" -Human
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
