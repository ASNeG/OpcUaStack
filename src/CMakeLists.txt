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

find_package(Boost COMPONENTS system unit_test_framework filesystem thread REQUIRED)

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
