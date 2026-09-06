@echo off
rem The front door for a PERSON, for 3ds Max 2026. This is the script that downloads a binary and
rem writes it into your profile, so every step it takes is printed as it happens and the window does
rem not close on its own - not on success, and least of all on a failure, where the reason is the
rem whole point.
rem
rem THE FOLDER NAME IS WHICH 3DS MAX THIS INSTALLS FOR. tools\2026\ installs the 2026 binaries.
rem
rem   install-plugin.cmd              install the pinned release
rem   install-plugin.cmd "C:\path\to\bundle.zip"   install a locally built bundle instead
rem
rem AN AGENT SHOULD NOT RUN THIS. Run install-plugin.ps1 directly: JSON on stdout, meaningful exit
rem code, no blocking on `pause`. To open this for a user without waiting on it:
rem     start "" "%~dp0install-plugin.cmd"
setlocal
if "%~1"=="" (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0install-plugin.ps1" -Human
) else (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0install-plugin.ps1" -Human -From "%~1"
)
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
