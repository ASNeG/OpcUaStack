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
    ../inc/
	${Boost_INCLUDE_DIRS}
)

file(
	GLOB OpcUaStackServerTest_SRC 
	${PROJECT_SOURCE_DIR}/unittest.cpp
	${PROJECT_SOURCE_DIR}/OpcUaStackServer/*/*.cpp
	${PROJECT_SOURCE_DIR}/unittest.cpp
)
add_executable(
    OpcUaStackServerTest
    ${OpcUaStackServerTest_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaStackServerTest
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackServer_LIBRARY}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
