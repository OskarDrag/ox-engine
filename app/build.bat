@ECHO OFF

REM the batch file used to compile the engine code

REM reseting the build cache folder
rmdir /q /s build
mkdir build

REM configurating and building the project using CMake (some version called "Ninja")

cmake -S . -B build -G "Ninja"

IF %errorlevel% neq 0 (
    ECHO [ERROR] CMake configuration failed.
    pause
    exit
)

cmake --build build

IF %errorlevel% neq 0 (
    ECHO [ERROR] Build failed.
    pause
    exit
)

exit