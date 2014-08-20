cmake_minimum_required (VERSION 2.8)
project (OpcUaStackServer)

# version number
set (OpcUaStackServer_VERSION_MAJOR 1)
set (OpcUaStackServer_VERSION_MINOR 0)

# includes
include_directories(
    ../../inc
    ../../../boost_1_54_0
)

file(
    GLOB_RECURSE
    OpcUaStackServer_SRCS
    ../../src/OpcUaStackServer/*
)


add_library( 
    OpcUaStackServer
    SHARED
    ${OpcUaStackServer_SRCS} 
)
