@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cd /d %~dp0
cmake -B cmake-build-release -S . -G "Ninja" -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release
pause
