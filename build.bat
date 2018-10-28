@echo off
REM
REM OpcUaStack build and install script
REM

set CMAKE=cmake.exe

REM ---------------------------------------------------------------------------
REM 
REM main
REM
REM ---------------------------------------------------------------------------

set ARG_COUNT=0
for %%x in (%*) do set /A ARG_COUNT+=1

if %ARG_COUNT% LSS 2 goto :usage

set INSTALL_PREFIX=C:\ASNeG
set COMMAND="local"
set STACK_PREFIX=C:\ASNeG
set VS_GENERATOR=""

:parse
    if "%~1"=="" goto :execute

    if /i "%~1"=="/t"               set COMMAND=%2
    if /i "%~1"=="-t"               set COMMAND=%2
    if /i "%~1"=="--target"         set COMMAND=%2

    if /i "%~1"=="/i"               set INSTALL_PREFIX=%~2
    if /i "%~1"=="-i"               set INSTALL_PREFIX=%~2
    if /i "%~1"=="--install-prefix" set INSTALL_PREFIX=%~2

    if /i "%~1"=="/s"               set STACK_PREFIX=%~2
    if /i "%~1"=="-s"               set STACK_PREFIX=%~2
    if /i "%~1"=="--stack-prefix"   set STACK_PREFIX=%~2

    if /i "%~1"=="/vs"               set VS_GENERATOR="-G%~2"
    if /i "%~1"=="-vs"               set VS_GENERATOR="-G%~2"
    if /i "%~1"=="--vs-generator"    set VS_GENERATOR="-G%~2"


    shift
    shift
    goto :parse


:execute
if "%COMMAND%" == "" (
    call:build_local
	
	pause
	goto:eof
)

if "%COMMAND%" == "local" (
    call:build_local
	
	pause
	goto:eof
)

if "%COMMAND%" == "tst" (
    call:build_tst
	
	pause
	goto:eof
)

call:usage

pause
goto:eof


REM ---------------------------------------------------------------------------
REM
REM build local function
REM
REM ---------------------------------------------------------------------------
:build_local
	echo build and install local

	REM
	REM build OpcUaStack
	REM
	%CMAKE% %VS_GENERATOR% -H./src/ -B./build_local

	REM
	REM install OpcUaStack
	REM
    
	set DESTDIR=%INSTALL_PREFIX%
	%CMAKE% --build build_local --target install
goto:eof


REM ---------------------------------------------------------------------------
REM
REM build tst function
REM
REM ---------------------------------------------------------------------------
:build_tst
	echo build unittest

	REM
	REM build unittest
	REM
	%CMAKE% %VS_GENERATOR% -DOPCUASTACK_INSTALL_PREFIX="%STACK_PREFIX%" -H./tst/ -B./build_tst

	REM
	REM install OpcUaStack
	REM    
	%CMAKE% --build build_tst
goto:eof


REM ---------------------------------------------------------------------------
REM
REM usage function
REM
REM ---------------------------------------------------------------------------
:usage
   echo "build.bat --target (local | tst)"
   echo.
   echo --target, -t, /t: sets one of the folowing target:
   echo   local - create local build and install in folder C:/install
   echo   tst   - build unit application
   echo.
   echo --stack-prefix, -s, /s STACK_PREFIX:  set the path to directory
   echo \twhere the OpcUaStack is installed (default: C:\ASNeG)
   echo.
   echo --install-prefix, -i, /i INSTALL_PREFIX:  is the path to directory
   echo \twhere the application should be installed (default: C:\ASNeG)
   echo.
   echo --vs-generator, -vs, /vs VS_GENERATOR:  is the name of cmake generator
   echo \t witch cmake uses during the building of the project. By default, cmake tries to figure out the generator from the environment.
   echo.
goto:eof
