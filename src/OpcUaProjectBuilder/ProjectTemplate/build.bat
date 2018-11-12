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
set BUILD_TYPE="Debug"
set STANDALONE=OFF

:parse
    if "%~1"=="" goto :execute

    if "%~1"=="/t"               set COMMAND=%2
    if "%~1"=="-t"               set COMMAND=%2
    if "%~1"=="--target"         set COMMAND=%2

    if "%~1"=="/i"               set INSTALL_PREFIX="%~2"
    if "%~1"=="-i"               set INSTALL_PREFIX="%~2"
    if "%~1"=="--install-prefix" set INSTALL_PREFIX="%~2"

    if "%~1"=="/s"               set STACK_PREFIX="%~2"
    if "%~1"=="-s"               set STACK_PREFIX="%~2"
    if "%~1"=="--stack-prefix"   set STACK_PREFIX="%~2"

    if "%~1"=="/vs"               set VS_GENERATOR="-G%~2"
    if "%~1"=="-vs"               set VS_GENERATOR="-G%~2"
    if "%~1"=="--vs-generator"    set VS_GENERATOR="-G%~2"

    if "%~1"=="/B"               set BUILD_TYPE=%~2
    if "%~1"=="-B"               set BUILD_TYPE=%~2
    if "%~1"=="--build-type"     set BUILD_TYPE=%~2
    shift

    REM flags
    if "%~2"=="/S"               set STANDALONE=ON
    if "%~2"=="-S"               set STANDALONE=ON
    if "%~2"=="--standalone"     set STANDALONE=ON

    
    shift
    goto :parse

:execute

set ARCH="x86"
if %VS_GENERATOR%=="" goto :set_build_suffix

if /i "%VS_GENERATOR:~-6,-1%"=="Win64" set ARCH="x64"
if /i "%VS_GENERATOR:~-4,-1%%"=="ARM" set ARCH="arm"	

:set_build_suffix
set BUILD_DIR_SUFFIX=%ARCH%_vs%VisualStudioVersion%_%BUILD_TYPE%

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

if "%COMMAND%" == "msi" (
    call:build_msi
	
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
	%CMAKE% %VS_GENERATOR% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DOPCUASTACK_INSTALL_PREFIX=%STACK_PREFIX% -H./src/ -B./build_local_%BUILD_DIR_SUFFIX%

	REM
	REM install OpcUaStack
	REM
    
	set DESTDIR=%INSTALL_PREFIX%
	%CMAKE% --build build_local_%BUILD_DIR_SUFFIX% --target install --config %BUILD_TYPE%
goto:eof

REM ---------------------------------------------------------------------------
REM
REM build MSI function
REM
REM ---------------------------------------------------------------------------
:build_msi
	echo build MSI package

	REM
	REM build OpcUaStack
	REM
	%CMAKE% %VS_GENERATOR% -DCPACK_BINARY_MSI=ON -DSTANDALONE=%STANDALONE% -DOPCUASTACK_INSTALL_PREFIX=%STACK_PREFIX%  -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -H./src/ -B./build_msi_%BUILD_DIR_SUFFIX%

	REM
	REM package OpcUaStack to MSI
	REM    		
    %CMAKE% --build build_msi_%BUILD_DIR_SUFFIX% --target package --config %BUILD_TYPE%
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
	%CMAKE% %VS_GENERATOR% -DOPCUASTACK_INSTALL_PREFIX="%STACK_PREFIX%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -H./tst/ -B./build_tst_%BUILD_DIR_SUFFIX%

	REM
	REM install OpcUaStack
	REM    
	%CMAKE% --build build_tst_%BUILD_DIR_SUFFIX% --config %BUILD_TYPE%
goto:eof


REM ---------------------------------------------------------------------------
REM
REM usage function
REM
REM ---------------------------------------------------------------------------
:usage
   echo "build.bat --target (local | tst | msi)"
   echo.
   echo --target, -t, /t: sets one of the folowing target:
   echo   local - create local build and install in folder C:/install
   echo   tst   - build unit application
   echo   msi   - build msi package
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
   echo --build-type, -B, /B BUILD_TYPE:  set the build types (Debug | Release). By default, it is Debug type.
   echo.
   echo --standalone, -S, /S:  includes OpcUaStack and its dependencies in MSI package of the application
   echo.

goto:eof
