# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ./
    ${PROJECT_BINARY_DIR}
    ../src/
    ${Boost_INCLUDE_DIRS}
)

file(
	GLOB OpcUaStackClientTest_SRC 
	${PROJECT_SOURCE_DIR}/unittest.cpp
	${PROJECT_SOURCE_DIR}/OpcUaStackClient/*/*.cpp 
	${PROJECT_SOURCE_DIR}/unittest.cpp
)
add_executable(
    OpcUaStackClientTest
    ${OpcUaStackClientTest_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaStackClientTest
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackClient_LIBRARY}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
