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
	${OPENSSL_INCLUDE_DIR}
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
    ${OPCUASTACK_LIBRARY_CORE}
    ${OPCUASTACK_LIBRARY_CLIENT}
    ${OPCUASTACK_LIBRARY_SERVER}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
