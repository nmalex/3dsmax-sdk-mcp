@echo off
rem The front door for a PERSON, for 3ds Max 2026. Opens a visible console, prints every row with
rem its remedy, and does not close on its own - the failing run is the one worth reading, and a
rem window that vanishes takes the fix with it.
rem
rem THE FOLDER NAME IS WHICH 3DS MAX THIS IS FOR. tools\2026\ checks 3ds Max 2026 and nothing else.
rem
rem AN AGENT SHOULD NOT RUN THIS. Run check-prereqs.ps1 directly: JSON on stdout, meaningful exit
rem code, no blocking. To open this for a user without waiting on it:
rem     start "" "%~dp0check-prereqs.cmd"
setlocal
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0check-prereqs.ps1" -Human
set RC=%ERRORLEVEL%
echo.
echo Exit code: %RC%
echo.
pause
exit /b %RC%
