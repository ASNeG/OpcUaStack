cmake_minimum_required(VERSION 2.8.9)
project	(OpcUaStack)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global options
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(VERSION_MAJOR "0" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "11" CACHE STRING "patch version")

set(BIN_DIR "usr/bin" CACHE STRING "binary directory")
set(LIB_DIR "usr/lib" CACHE STRING "library directory")
set(INC_DIR "usr/include" CACHE STRING "library directory")
set(CONF_DIR "etc/OpcUaStack" CACHE STRING "configuration directory")
set(LOG_DIR "var/log/OpcUaStack" CACHE STRING "log output directory")

option(
    USE_OpcUaStackCore
    "build opc ua core library"
    ON
)

option(
    USE_OpcUaStackClient
    "build opc ua client library"
    ON
)

option(
    USE_OpcUaStackServer
    "build opc ua server library"
    ON
)

option(
    USE_OpcUaStackUtility
    "build opc ua utility library"
    ON
)

option(
    USE_OpcUaServer
    "build opc ua server library"
    ON
)

option(
    USE_OpcUaServerApplicationDemo
    "build opc ua server application demo library"
    ON
)

include(Tools/CMakeLists.txt) 

add_definitions(-DBOOST_ALL_DYN_LINK)

if (WIN32)
	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
	#ADD_DEFINITIONS(-DUNICODE)
	#ADD_DEFINITIONS(-D_UNICODE)
endif ()

find_package(Boost COMPONENTS system unit_test_framework filesystem thread date_time chrono regex REQUIRED)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build subdirectories
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (USE_OpcUaStackCore)
    include(OpcUaStackCore/CMakeLists.txt) 
endif ()

if (USE_OpcUaStackClient)
    include(OpcUaStackClient/CMakeLists.txt) 
endif ()

if (USE_OpcUaStackServer)
    include(OpcUaStackServer/CMakeLists.txt) 
endif ()

if (USE_OpcUaStackUtility)
    include(OpcUaStackUtility/CMakeLists.txt) 
endif ()

if (USE_OpcUaServer)
    include(OpcUaServer/CMakeLists.txt) 
endif ()

if (USE_OpcUaServerApplicationDemo)
    include(OpcUaServerApplicationDemo/CMakeLists.txt) 
endif ()


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(FILES icon/asneg.ico DESTINATION usr/share/icons/OpcUaStack)
install(FILES icon/asneg_install.ico DESTINATION usr/share/icons/OpcUaStack)
install(FILES icon/asneg_uninstall.ico DESTINATION usr/share/icons/OpcUaStack)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# debian package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (WIN32)
	include (InstallRequiredSystemLibraries)
	
	#set(CPACK_PACKAGE_EXECUTABLES "OpcUaServer" "OpcUaServer")
	set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpcUaStack")
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\usr\\\\share\\\\icons\\\\OpcUaStack\\\\asneg.ico")
	set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
	set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/usr/share/icons/OpcUaStack/asneg_install.ico")
	set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/usr/share/icons/OpcUaStack/asneg_uninstall.ico")
	#set(CPACK_NSIS_INSTALLED_ICON_NAME "asneg.ico")
	
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" addPath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" INSTALL \\\"ASNeG-Demo\\\" \\\"ASNeG Demo Server\\\"'
		"
	) 
	
	set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" UNINSTALL \\\"ASNeG-Demo\\\"'
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" removePath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
		"
	) 
	
endif ()


set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "OpcUaStack")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "OpcUaStack - Opc Ua client server application framework")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

if (CPACK_BINARY_DEB)
    	set (CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
endif()
	

include(CPack)
