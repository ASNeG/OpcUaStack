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

find_package(Boost COMPONENTS system unit_test_framework filesystem thread date_time REQUIRED)

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
set(CPACK_PACKAGE_CONTACT "kai@huebl-sgh.de")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
include(CPack)
