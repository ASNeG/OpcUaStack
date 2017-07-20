cmake_minimum_required(VERSION 2.8.12.2)
project	(OpcUaStackTest)
set (CMAKE_CXX_STANDARD 11)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global options
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(OpcUaStack_INSTALL_DIR "/" CACHE STRING "OpcUaStack installation output directory")

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

add_definitions(-DBOOST_ALL_DYN_LINK)

if (WIN32)
	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
endif ()

find_package(Boost COMPONENTS system unit_test_framework filesystem thread date_time chrono regex REQUIRED)
find_library(OpcUaStackCore_LIBRARY NAMES OpcUaStackCore PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)
find_library(OpcUaStackClient_LIBRARY NAMES OpcUaStackClient PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)
find_library(OpcUaStackServer_LIBRARY NAMES OpcUaStackServer PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)

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
