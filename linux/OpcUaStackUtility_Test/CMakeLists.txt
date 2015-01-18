cmake_minimum_required (VERSION 2.8)
project (OpcUaStackUtility_Test)

set (BOOST_ROOT ../../../boost_1_54_0)
set (Boost_INCLUDE_DIRS ${BOOST_ROOT})

LINK_DIRECTORIES( ../../../boost_1_54_0/stage/lib ${LINK_DIRECTORIES} )


#FIND_PACKAGE ( Threads REQUIRED )


set (CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")
set (CMAKE_CXX_LINK_FLAGS "-ldl")

find_library(
    OPCUA_STACK_CORE 
    NAMES OpcUaStackCore
    PATHS ../OpcUaStackCore_lib
)
find_library(
    OPCUA_STACK_CLIENT 
    NAMES OpcUaStackClient
    PATHS ../OpcUaStackClient_lib
)
find_library(
    OPCUA_STACK_SERVER
    NAMES OpcUaStackServer
    PATHS ../OpcUaStackServer_lib
)
find_library(
    OPCUA_STACK_UTILITY
    NAMES OpcUaStackUtility
    PATHS ../OpcUaStackUtility_lib
)

file(
    GLOB_RECURSE
    OpcUaStackUtility_SRCS
    ../../tst/unittest.cpp
    ../../tst/OpcUaStackUtility/*
)

include_directories(
    ../../tst
    ../../inc
    ${Boost_INCLUDE_DIRS}
)

add_executable(
    Unittest 
    ${OpcUaStackUtility_SRCS}
)

target_link_libraries(
    Unittest 
    boost_thread 
    boost_system 
    boost_unit_test_framework 
    boost_date_time 
    boost_filesystem
    ${OPCUA_STACK_CORE}
    ${OPCUA_STACK_CLIENT}
    ${OPCUA_STACK_SERVER}
    ${OPCUA_STACK_UTILITY}
)


