@echo off

if "%1"=="" (
    echo Usage: build.bat [Configuration]
    exit /b 1
)

set Configuration=%1%


if /i not "%Configuration%"=="Release" if /i not "%Configuration%"=="Debug" (
    echo Invalid build configuration. Use only "Release" or "Debug".
    exit /b 1
)

mkdir build
cmake -B build -S .


MSBuild.exe ./build/gitignore.sln /p:Configuration=%Configuration%
