cmake_minimum_required (VERSION 2.8)
project (OpcUaStackCore_Test)

set (BOOST_ROOT ../../../boost_1_54_0)
set (Boost_USE_STATIC_LIBS       OFF)
set (Boost_USE_MULTITHREADED     ON)
set (Boost_USE_STATIC_RUNTIME    OFF)
find_package(
    Boost 
    REQUIRED
    COMPONENTS system unit_test_framework thread timer 
)

find_library(
    OPCUA_STACK_CORE 
    NAMES OpcUaStackCore
    PATHS ../OpcUaStackCore_lib
)

if(Boost_FOUND)

    file(
    	GLOB_RECURSE
    	OpcUaStackCore_SRCS
    	../../tst/*
    )

    include_directories(
        ../../tst
        ../../inc
        ${Boost_INCLUDE_DIRS}
    )

    add_executable(Unittest ${OpcUaStackCore_SRCS})

    target_link_libraries(Unittest ${OPCUA_STACK_CORE} ${Boost_LIBRARIES})

endif()

