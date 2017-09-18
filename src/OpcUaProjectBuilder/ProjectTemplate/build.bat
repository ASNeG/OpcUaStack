@echo off
REM
REM OpcUaStack build and install script
REM

rmdir ./build_local

set OpcUaStack_Install_Prefix=C:\install

set CMAKE=cmake.exe
set VS=Visual Studio 12 2013
set MSBUILD=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe

REM ---------------------------------------------------------------------------
REM 
REM main
REM
REM ---------------------------------------------------------------------------
set COMMAND=%1

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
	%CMAKE% -G"%VS%" -DOPCUASTACK_INSTALL_PREFIX=%OpcUaStack_Install_Prefix% -H./src/ -B./build_local

	REM
	REM install OpcUaStack
	REM
	set DESTDIR=C:\install
	%MSBUILD% ./build_local/INSTALL.vcxproj
goto:eof



REM ---------------------------------------------------------------------------
REM
REM usage function
REM
REM ---------------------------------------------------------------------------
:usage
   echo build.bat (local)
   echo.
   echo   local - create local build and install in folder C:/install
   echo.
goto:eof

pause
