@echo off
rem The front door for a PERSON, for 3ds Max 2026. Removes the plugin, prints exactly what it is
rem about to delete BEFORE deleting it, and does not close on its own.
rem
rem   uninstall-plugin.cmd              remove the plugin; YOUR CARTRIDGES ARE KEPT
rem   uninstall-plugin.cmd all          remove the plugin AND every deployed cartridge (asks first)
rem
rem Your cartridge SOURCES in the clone are never touched by either form - removing a deployed copy
rem is not deleting your code.
rem
rem AN AGENT SHOULD NOT RUN THIS. Run uninstall-plugin.ps1 directly.
setlocal
if /i "%~1"=="all" (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0uninstall-plugin.ps1" -Human -IncludeCartridges -RemoveLegacy
) else (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0uninstall-plugin.ps1" -Human
)
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
