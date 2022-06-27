# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)

file(
    GLOB OpcUaStackPubSub_SRC 
    ./OpcUaStackPubSub/*/*.cpp
)

add_library(
    OpcUaStackPubSub 
    SHARED 
    ${OpcUaStackPubSub_SRC}
)

target_link_libraries(
    OpcUaStackPubSub
    OpcUaStackCore
	OpcUaStackServer
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    ${OPENSSL_LIBRARIES}
    ${MOSQUITTO_LIBRARIES}
)

set_target_properties(
    OpcUaStackPubSub
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

get_target_property(
    OpcUaStackPubSubLibName 
    OpcUaStackPubSub
    OUTPUT_NAME
)

if (WIN32)
    set_target_properties(
    	OpcUaStackPubSub 
    	PROPERTIES OUTPUT_NAME 
    	"OpcUaStackPubSub${VERSION_MAJOR}"
    )

	if (MSVC)
		set(OPCUASTACK_PUBSUB_LIB_NAME OpcUaStackPubSub${VERSION_MAJOR}.lib)
	endif()

	if (MINGW)
		set(OPCUASTACK_PUBSUB_LIB_NAME libOpcUaStackPubSub${VERSION_MAJOR}.dll.a)
	endif()

	target_link_libraries(OpcUaStackPubSub wsock32 ws2_32)
else()
    set(OPCUASTACK_PUBSUB_LIB_NAME libOpcUaStackPubSub.so.${VERSION_MAJOR})
endif()

message(STATUS "OpcUaStackPubSub")
message(STATUS "  library name: ${OPCUASTACK_PUBSUB_LIB_NAME}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackPubSub_Base OpcUaStackPubSub/Base/*.h)
file(GLOB INC_OpcUaStackPubSub_Events OpcUaStackPubSub/Events/*.h)
file(GLOB INC_OpcUaStackPubSub_Connection OpcUaStackPubSub/Connection/*.h)

install(
    TARGETS OpcUaStackPubSub 
    DESTINATION ${INSTALL_PREFIX}/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackPubSub_Base} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/Base
    COMPONENT headers
)


install(
    FILES ${INC_OpcUaStackPubSub_Events} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/Events
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackPubSub_Connection} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/Connection
    COMPONENT headers
)
