@echo off

if "%1"=="" (
    echo ---------------------------------------------------------
    echo Usage: build.bat [Subcommand]
    echo Subcommands: 
    echo             build [Argument = Release or Debug]
    echo             clean [Deletes the build folder if itis exist]
    echo             run   [Argument = Language that you want]
    echo ----------------------------------------------------------
    exit /b 1
)




if /i "%1"=="clean" (
    if exist "build" (
        echo Cleaning build directory...
        rmdir /s /q build
        exit /b 0
    )
)

if /i "%1"=="build" (
    
    if "%2"=="" (
        echo ---------------------------------------------------------
        echo Usage: build.bat build [Argument = Release or Debug]
        echo ----------------------------------------------------------
        exit /b 1
    )

    if /i not "%2"=="Release" if /i not "%2"=="Debug" (
        echo ---------------------------------------------------------
        echo Usage: build.bat build [Argument = Release or Debug]
        echo ----------------------------------------------------------
        exit /b 1
    )

    if not exist "build" (
       mkdir build
    ) 

    cmake -B build -S .
    MSBuild.exe ./build/gitignore.sln /p:Configuration=%2 /verbosity:q
    echo ----------------------------------------------------------------
    echo -- Your code is succesfully builded on build\%2\gitignore.exe
    echo ----------------------------------------------------------------
    exit /b 0

)

if /i "%1"=="run" (
    if "%2"=="" (
        echo ---------------------------------------------------------
        echo Usage: build.bat run   [Argument = Language that you want]
        echo ----------------------------------------------------------
        exit /b 1
    )

    if exist "build\Release\gitignore.exe" (
            build\Release\gitignore.exe %2
            exit /b 0
        ) else (
            if exist "build\Debug\gitignore.exe" (
                build\Debug\gitignore.exe %2
                exit /b 0
            ) else (
                echo Error: The gitignore executable was not found in either Release or Debug folders.
                echo        Build it first build.bat [Release or Debug]
                exit /b 1
            )
        )


)
