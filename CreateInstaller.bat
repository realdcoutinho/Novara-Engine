@echo off
echo ============================================
echo    Novara Engine - Installer Generator
echo ============================================

:: REM Navigate to Release build folder and run CPack
:: echo.
:: echo [1/4] Creating Release Installer...
:: cd /d "%~dp0out\build\x64-Release"
:: cpack -C Release

:: REM Navigate to Debug build folder and run CPack
:: echo.
:: echo [2/4] Creating Debug Installer...
:: cd /d "%~dp0out\build\x64-Debug"
:: cpack -C Debug

REM Navigate to cmake-build-debug folder and run CPack
echo.
echo [1/2] Creating Debug Installer...
cd /d "%~dp0cmake-build-debug"
cpack -C Debug

REM Navigate to cmake-build-release folder and run CPack
echo.
echo [2/2] Creating Debug Installer...
cd /d "%~dp0cmake-build-release"
cpack -C Release


echo.
echo Done! Check the Installers folder for output.
pause
