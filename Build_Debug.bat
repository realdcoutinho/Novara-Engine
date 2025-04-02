@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvars64.bat"
cd /d %~dp0
cmake -B cmake-build-debug -S . -G "Ninja" -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug
pause
