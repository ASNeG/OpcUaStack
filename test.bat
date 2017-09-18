@echo off
REM
REM OpcUaStack build and install script
REM


REM ---------------------------------------------------------------------------
REM 
REM main
REM
REM ---------------------------------------------------------------------------
set COMMAND=%1


if "%COMMAND%" == "" (
    call:unittest_OpcUaStackCore
	
	pause
	goto:eof
)

if "%COMMAND%" == "core" (
    call:unittest_OpcUaStackCore
	
	pause
	goto:eof
)

if "%COMMAND%" == "client" (
    call:unittest_OpcUaStackClient
	
	pause
	goto:eof
)

if "%COMMAND%" == "server" (
    call:unittest_OpcUaStackServer
	
	pause
	goto:eof
)

call:usage

pause
goto:eof

REM ---------------------------------------------------------------------------
REM
REM usage function
REM
REM ---------------------------------------------------------------------------
:usage
   echo test.bat (core | client | server)
   echo.
goto:eof


REM ---------------------------------------------------------------------------
REM 
REM unittest OpcUaStackCore
REM
REM ---------------------------------------------------------------------------
:unittest_OpcUaStackCore
	REM
	REM copy unittest from Debug folder to test folder
	REM
	del .\build_tst\OpcUaStackCoreTest.exe
	xcopy .\build_tst\Debug\OpcUaStackCoreTest.exe .\build_tst\OpcUaStackCoreTest.exe*
	
	REM
	REM start unittest script
	REM
	cd .\build_tst
	OpcUaStackCoreTest.exe
	pause
goto:eof


REM ---------------------------------------------------------------------------
REM 
REM unittest OpcUaStackClient
REM
REM ---------------------------------------------------------------------------
:unittest_OpcUaStackClient
	REM
	REM copy unittest from Debug folder to test folder
	REM
	del .\build_tst\OpcUaStackClientTest.exe
	xcopy .\build_tst\Debug\OpcUaStackClientTest.exe .\build_tst\OpcUaStackClientTest.exe*
	
	REM
	REM start unittest script
	REM
	cd .\build_tst
	OpcUaStackClientTest.exe
	pause
goto:eof


REM ---------------------------------------------------------------------------
REM 
REM unittest OpcUaStackServer
REM
REM ---------------------------------------------------------------------------
:unittest_OpcUaStackServer
	REM
	REM copy unittest from Debug folder to test folder
	REM
	del .\build_tst\OpcUaStackServerTest.exe
	xcopy .\build_tst\Debug\OpcUaStackServerTest.exe .\build_tst\OpcUaStackServerTest.exe*
	
	REM
	REM start unittest script
	REM
	cd .\build_tst
	OpcUaStackServerTest.exe
	pause
goto:eof
