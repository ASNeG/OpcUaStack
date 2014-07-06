cmake_minimum_required (VERSION 2.8)
project (OpcUaStackCore)

# version number
set (OpcUaStackCore_VERSION_MAJOR 1)
set (OpcUaStackCore_VERSION_MINOR 0)

# includes
include_directories(
    ../../inc
    ../../../boost_1_54_0
)

file(
    GLOB_RECURSE
    OpcUaStackCore_SRCS
    ../../src/OpcUaStackCore/*
)


add_library( 
    OpcUaStackCore
    SHARED
    ${OpcUaStackCore_SRCS} 
)
