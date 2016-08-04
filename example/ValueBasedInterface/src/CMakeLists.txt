cmake_minimum_required(VERSION 2.8.9)
project	(Example)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global options
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(OpcUaStack_ROOT /)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# libraries
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
find_package(Boost COMPONENTS system REQUIRED)
find_library(OpcUaStackCore_LIBRARY NAMES OpcUaStackCore PATHS ${OpcUaStack_ROOT}/usr/lib/OpcUaStack)
find_library(OpcUaStackClient_LIBRARY NAMES OpcUaStackClient PATHS ${OpcUaStack_ROOT}/usr/lib/OpcUaStack)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# infos
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
message(STATUS "directories")
message(STATUS "  OpcUaStack_ROOT: ${OpcUaStack_ROOT}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build examples
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
    ${OpcUaStack_ROOT}/usr/include/OpcUaStack
)


add_executable(
    SyncConnectToServer
    SyncConnectToServer.cpp
)

target_link_libraries(
    SyncConnectToServer
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackClient_LIBRARY}
    ${Boost_LIBRARIES}
)


add_executable(
    SyncReadFromServer
    SyncReadFromServer.cpp
)

target_link_libraries(
    SyncReadFromServer
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackClient_LIBRARY}
    ${Boost_LIBRARIES}
)


add_executable(
    SyncWriteToServer
    SyncWriteToServer.cpp
)

target_link_libraries(
    SyncWriteToServer
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackClient_LIBRARY}
    ${Boost_LIBRARIES}
)

