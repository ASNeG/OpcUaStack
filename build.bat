@echo off
REM
REM OpcUaStack build and install script
REM

REM rmdir ./build_local
REM rmdir ./build_tst

set BOOST_VERSION_MAJOR=1
set BOOST_VERSION_MINOR=58
set BOOST_LIBRARYDIR=C:\local\boost_1_58_0\lib32-msvc-12.0

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
	%CMAKE% -G"%VS%" -H./src/ -B./build_local

	REM
	REM install OpcUaStack
	REM
	set DESTDIR=C:\install
	%MSBUILD% ./build_local/INSTALL.vcxproj
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
	%CMAKE% -G"%VS%" -DOPCUASTACK_INSTALL_PREFIX=C:\install -H./tst/ -B./build_tst

	REM
	REM install OpcUaStack
	REM
	%MSBUILD% ./build_tst/ALL_BUILD.vcxproj
goto:eof


REM ---------------------------------------------------------------------------
REM
REM usage function
REM
REM ---------------------------------------------------------------------------
:usage
   echo build.bat (local | tst)
   echo.
   echo   local - create local build and install in folder C:/install
   echo   tst   - build unit application
   echo.
goto:eof
