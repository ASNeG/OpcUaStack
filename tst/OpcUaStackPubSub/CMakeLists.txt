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
	GLOB OpcUaStackPubSubTest_SRC 
	${PROJECT_SOURCE_DIR}/unittest.cpp
	${PROJECT_SOURCE_DIR}/OpcUaStackPubSub/*/*.cpp
	${PROJECT_SOURCE_DIR}/unittest.cpp
)
add_executable(
    OpcUaStackPubSubTest
    ${OpcUaStackPubSubTest_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaStackPubSubTest
    ${OPCUASTACK_LIBRARY_CORE}
    ${OPCUASTACK_LIBRARY_CLIENT}
    ${OPCUASTACK_LIBRARY_SERVER}
    ${OPCUASTACK_LIBRARY_PUBSUB}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
