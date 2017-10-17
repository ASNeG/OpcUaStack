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
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    ${OPENSSL_LIBRARIES}
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
	set(OPCUASTACK_PUBSUB_LIB_NAME OpcUaStackPubSub@VERSION_MAJOR@.lib)
else()
    set(OPCUASTACK_PUBSUB_LIB_NAME libOpcUaStackPubSub.so.@VERSION_MAJOR@)
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
file(GLOB INC_OpcUaStackPubSub_Base OpcUaStackPubSub/Base/*.h OpcUaStackPubSub/Base/*.txx)
file(GLOB INC_OpcUaStackPubSub_Network OpcUaStackPubSub/Network/*.h OpcUaStackPubSub/Network/*.txx)
file(GLOB INC_OpcUaStackPubSub_MQTT OpcUaStackPubSub/MQTT/*.h OpcUaStackPubSub/MQTT/*.txx)
file(GLOB INC_OpcUaStackPubSub_DataSet OpcUaStackPubSub/DataSet/*.h OpcUaStackPubSub/DataSet/*.txx)
file(GLOB INC_OpcUaStackPubSub_DataSetDispatcher OpcUaStackPubSub/DataSetDispatcher/*.h OpcUaStackPubSub/DataSetDispatcher/*.txx)

install(
    TARGETS OpcUaStackPubSub 
    DESTINATION /usr/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackPubSub_Base} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/Base
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackPubSub_Network} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/Network
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackPubSub_MQTT} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/MQTT
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackPubSub_DataSet} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/DataSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackPubSub_DataSetDispatcher} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackPubSub/DataSetDispatcher
    COMPONENT headers
)


