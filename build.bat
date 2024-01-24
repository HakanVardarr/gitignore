@echo off

if "%1"=="" (
    echo Usage: build.bat [Configuration] or [Language] 'To run the file'
    exit /b 1
)

set Arg=%1%


if /i not "%Arg%"=="Release" if /i not "%Arg%"=="Debug" (
    if "%Arg%"=="Clean" (
        echo Cleaning build directory...
        rmdir /s /q build
        exit /b 0
    ) else (
        if exist "build\Release\gitignore.exe" (
            build\Release\gitignore.exe %Arg%
            exit /b 0
        ) else (
            if exist "build\Debug\gitignore.exe" (
                build\Debug\gitignore.exe %Arg%
                exit /b 0
            ) else (
                echo Error: The gitignore executable was not found in either Release or Debug folders.
                echo Usage: build.bat [Configuration] or [Language] 'To run the file'
                exit /b 1
            )
        )
    )
)

if not exist "build" (
       mkdir build
) 

cmake -B build -S .
MSBuild.exe ./build/gitignore.sln /p:Configuration=%Arg% /verbosity:q
echo ----------------------------------------------------------------
echo -- Your code is succesfully builded on build\%Arg%\gitignore.exe
echo ----------------------------------------------------------------
