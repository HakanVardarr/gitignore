@echo off

if "%1"=="" (
    echo Usage: build.bat [Configuration] or [Language] 'To run the file'
    exit /b 1
)

set Arg=%1%


if /i not "%Arg%"=="Release" if /i not "%Arg%"=="Debug" (
    if exist "build\Release\gitignore.exe" (
        build\Release\gitignore.exe %Arg%
        exit /b 0
    ) else (
        if exist "build\Debug\gitignore.exe" (
            build\Debug\gitignore.exe %Arg%
            exit /b 0
        ) else (
            exit /b 1
        )
    )
)

mkdir build
cmake -B build -S .

MSBuild.exe ./build/gitignore.sln /p:Configuration=%Arg%
