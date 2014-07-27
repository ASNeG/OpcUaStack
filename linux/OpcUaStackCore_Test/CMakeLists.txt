cmake_minimum_required (VERSION 2.8)
project (OpcUaStackCore_Test)


# path
set (OPCUA_ROOT_PATH ../)
set (BOOST_ROOT_PATH ../../../boost_1_54_0)

# version number
set (OpcUaStackCore_VERSION_MAJOR 1)
set (OpcUaStackCore_VERSION_MINOR 0)


set(Boost_INCLUDE_DIR ${BOOST_ROOT_PATH})
set(Boost_LIBRARY_DIR ${BOOST_ROOT_PATH}/stage/lib)
set(Boost_USE_MULTI_THREADED ON)
find_package(Boost COMPONENTS unit_test_framework system date_time thread timer REQUIRED)


# includes
include_directories(
    ../../inc
    ../../tst
    ${Boost_INCLUDE_DIR}
)

link_directories(
    ${OPCUA_ROOT_PATH}/OpcUaStackCore_lib 
    ${Boost_LIBRARY_DIR}
)

file(
    GLOB_RECURSE
    OpcUaStackCore_SRCS
    ../../tst/OpcUaStackCore/*
)

add_executable( 
    OpcUaStackCore_Test
    ${OpcUaStackCore_SRCS} 
)

target_link_libraries(
    OpcUaStackCore_Test
    libOpcUaStackCore.so
    ${Boost_LIBRARIES}
)


