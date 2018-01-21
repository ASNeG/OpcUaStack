cmake_minimum_required(VERSION 2.8.12.2)
project	(OpcUaStackTest4)
set (CMAKE_CXX_STANDARD 11)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# version
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(OPCUASTACK_VERSION_MAJOR "4" CACHE STRING "major version")
set(OPCUASTACK_VERSION_MINOR "0" CACHE STRING "minor version")
set(OPCUASTACK_VERSION_PATCH "1" CACHE STRING "patch version")
set(OPCUASTACK_INSTALL_PREFIX "/" CACHE PATH "opc ua stack intallation prefix")

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

option(
    USE_OpcUaStackPubSub
    "build opc ua pub sub library"
    ON
)


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

if (USE_OpcUaStackPubSub)
    include(OpcUaStackPubSub/CMakeLists.txt) 
endif ()
