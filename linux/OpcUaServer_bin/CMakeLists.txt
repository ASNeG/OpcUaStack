cmake_minimum_required (VERSION 2.8)
project (OpcUaStackCore_Test)

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
    OPCUA_STACK_SERVER 
    NAMES OpcUaStackServer
    PATHS ../OpcUaStackServer_lib
)

find_library(
    OPCUA_STACK_CLIENT
    NAMES OpcUaStackClient
    PATHS ../OpcUaStackClient_lib
)


file(
    GLOB_RECURSE
    OpcUaServer_SRCS
    ../../src/OpcUaServer/*
)

include_directories(
    ../../inc
    ${Boost_INCLUDE_DIRS}
)

add_executable(
    OpcUaServer 
    ${OpcUaServer_SRCS}
)

target_link_libraries(
    OpcUaServer 
    boost_thread 
    boost_system 
    boost_date_time 
    boost_filesystem
    ${OPCUA_STACK_CORE}
    ${OPCUA_STACK_SERVER}
    ${OPCUA_STACK_CLIENT}
)


