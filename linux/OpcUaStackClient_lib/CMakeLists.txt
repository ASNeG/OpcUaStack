cmake_minimum_required (VERSION 2.8)
project (OpcUaStackClient)

# version number
set (OpcUaStackClient_VERSION_MAJOR 1)
set (OpcUaStackClient_VERSION_MINOR 0)

# includes
include_directories(
    ../../inc
    ../../../boost_1_54_0
)

file(
    GLOB_RECURSE
    OpcUaStackClient_SRCS
    ../../src/OpcUaStackClient/*
)


add_library( 
    OpcUaStackClient
    SHARED
    ${OpcUaStackClient_SRCS} 
)
