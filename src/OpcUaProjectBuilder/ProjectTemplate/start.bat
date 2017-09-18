
@echo OFF
REM
REM added the following string to the Path environment variable
REM
REM Computer -> Systemeigenschaften -> Erweiterte Systemeinstallung -> Umgebungsvariablen
REM
REM Name:		Path
REM String:		C:\install\usr\lib;C:\local\boost_1_58_0\lib32-msvc-12.0;C:\install\usr\bin
REM

OpcUaServer3 CONSOLE C:\install\etc\OpcUaStack\ProjectName\OpcUaServer.xml 


pause
