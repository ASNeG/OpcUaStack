cmake_minimum_required(VERSION 2.8.12.2)
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
set(VERSION_PATCH "1" CACHE STRING "patch version")

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

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# debian package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

if (WIN32)
	include (InstallRequiredSystemLibraries)
	
	set(CPACK_PACKAGE_EXECUTABLES "OpcUaServer" "OpcUaServer")
	set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
	
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\bin\\\\UpdateRegistry.exe\\\" addPath HKCU Environment\\\ PATH \\\"$INSTDIR\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
		"
	) 
	
	set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\bin\\\\UpdateRegistry.exe\\\" removePath HKCU Environment\\\ PATH \\\"$INSTDIR\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
		"
	) 
	
endif ()
	
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/icon/asneg.ico")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "OpcUaStack")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "OpcUaStack - Opc Ua client server application framework")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
include(CPack)
