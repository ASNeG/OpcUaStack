cmake_minimum_required(VERSION 2.8.12.2)
project	(OpcUaStackTest)
set (CMAKE_CXX_STANDARD 11)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# version
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(OPCUASTACK_VERSION_MAJOR "3")
set(OPCUASTACK_VERSION_MINOR "6")
set(OPCUASTACK_VERSION_PATCH "1")

set(OPENSSL_VERSION_MAJOR "1" CACHE STRING "major version")
set(OPENSSL_VERSION_MINOR "0" CACHE STRING "minor version")
set(OPENSSL_VERSION_PATCH "0" CACHE STRING "patch version")

set(OPCUASTACK_INSTALL_PREFIX "/" CACHE PATH "opc ua stack intallation prefix")

find_package(
    OpenSSL 
    "${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH}" 
    REQUIRED
)

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

if (TEST_SERVER_URI) 
  add_definitions(-DREAL_SERVER -DREAL_SERVER_URI="${TEST_SERVER_URI}")
endif()

#add_definitions(-DBOOST_ALL_DYN_LINK)

#if (WIN32)
#	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
#	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
#endif ()

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# boost 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeBoost.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# openssl
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpenSSL.txt)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# opcuastack 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpcUaStack.txt)

#find_package(Boost COMPONENTS system unit_test_framework filesystem thread date_time chrono regex REQUIRED)
#find_library(OpcUaStackCore_LIBRARY NAMES OpcUaStackCore PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)
#find_library(OpcUaStackClient_LIBRARY NAMES OpcUaStackClient PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)
#find_library(OpcUaStackServer_LIBRARY NAMES OpcUaStackServer PATHS ${OpcUaStack_INSTALL_DIR}/usr/lib/OpcUaStack)

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
