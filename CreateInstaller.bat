@echo off
echo ============================================
echo    Novara Engine - Installer Generator
echo ============================================

REM Navigate to Release build folder and run CPack
echo.
echo [1/2] Creating Release Installer...
cd /d "%~dp0out\build\x64-Release"
cpack -C Release

REM Navigate to Debug build folder and run CPack
echo.
echo [2/2] Creating Debug Installer...
cd /d "%~dp0out\build\x64-Debug"
cpack -C Debug

echo.
echo Done! Check the Installers folder for output.
pause
