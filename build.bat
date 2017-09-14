@echo off
REM
REM OpcUaStack build and install script
REM

rmdir ./build_local

set BOOST_VERSION_MAJOR=1
set BOOST_VERSION_MINOR=58
set BOOST_LIBRARYDIR=C:\local\boost_1_58_0\lib32-msvc-12.0

set CMAKE=cmake.exe
set MSBUILD=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe


REM ---------------------------------------------------------------------------
REM 
REM main
REM
REM ---------------------------------------------------------------------------
set COMAMND=%1

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
	REM
	REM build OpcUaStack
	REM
	%CMAKE% -G"Visual Studio 12 2013" -H./src/ -B./build_local

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
