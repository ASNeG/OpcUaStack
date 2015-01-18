cmake_minimum_required (VERSION 2.8)
project (OpcUaStackUtility)

# version number
set (OpcUaStackUtility_VERSION_MAJOR 1)
set (OpcUaStackUtility_VERSION_MINOR 0)

# includes
include_directories(
    ../../inc
    ../../../boost_1_54_0
)

file(
    GLOB_RECURSE
    OpcUaStackUtility_SRCS
    ../../src/OpcUaStackUtility/*
)


add_library( 
    OpcUaStackUtility
    SHARED
    ${OpcUaStackUtility_SRCS} 
)
