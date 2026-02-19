@ECHO OFF

TITLE build all

REM batch file for compiling and building both the testbed and the application
REM if the application folder name is changed, you have to change it at line 18

CD engine
START /WAIT build.bat
IF %ERRORLEVEL% neq 0 (
    ECHO [ERROR] Engine build failed.
    pause
    exit
)
ECHO [INFO] Engine build succesfull.
CD ..

CD app
START /WAIT build.bat
IF %ERRORLEVEL% neq 0 (
    ECHO [ERROR] Application build failed.
    pause
    exit
)
ECHO [INFO] Application build succesfull.
CD ..

exit