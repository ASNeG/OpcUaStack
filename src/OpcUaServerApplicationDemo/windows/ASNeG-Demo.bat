
SET INSTALL_PREFIX=D:\install
SET BOOST_DLL=C:\local\boost_1_54_0\lib32-msvc-11.0


SETX PATH=%INSTALL_PREFIX%\usr\lib\OpcUaStack;%PATH%
XCOPY /Y %BOOST_DLL%\boost_system-vc110-mt-gd-1_54.dll %INSTALL_PREFIX%\usr\bin\
XCOPY /Y %BOOST_DLL%\boost_filesystem-vc110-mt-gd-1_54.dll %INSTALL_PREFIX%\usr\bin\
XCOPY /Y %BOOST_DLL%\boost_thread-vc110-mt-gd-1_54.dll %INSTALL_PREFIX%\usr\bin\
XCOPY /Y %BOOST_DLL%\boost_chrono-vc110-mt-gd-1_54.dll %INSTALL_PREFIX%\usr\bin\
XCOPY /Y %BOOST_DLL%\boost_date_time-vc110-mt-gd-1_54.dll %INSTALL_PREFIX%\usr\bin\

%INSTALL_PREFIX%\usr\bin\OpcUaServer.exe CONSOLE ASNeG-Demo

pause


