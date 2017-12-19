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
)

file(
    GLOB OpcUaStackServer_SRC 
    ./OpcUaStackServer/*/*.cpp
)

add_library(
    OpcUaStackServer 
    SHARED 
    ${OpcUaStackServer_SRC}
)

target_link_libraries(
    OpcUaStackServer
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
)

set_target_properties(
    OpcUaStackServer
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

if (WIN32)
    set_target_properties(
    	OpcUaStackServer 
    	PROPERTIES OUTPUT_NAME 
    	"OpcUaStackServer${VERSION_MAJOR}"
	)
	set(OPCUASTACK_SERVER_LIB_NAME OpcUaStackServer@VERSION_MAJOR@.lib)
else()
    set(OPCUASTACK_SERVER_LIB_NAME libOpcUaStackServer.so.@VERSION_MAJOR@)
endif()

message(STATUS "OpcUaStackServer")
message(STATUS "  library name: ${OPCUASTACK_SERVER_LIB_NAME}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackServer_Server OpcUaStackServer/Server/*.h)
file(GLOB INC_OpcUaStackServer_AddressSpaceModel OpcUaStackServer/AddressSpaceModel/*.h)
file(GLOB INC_OpcUaStackServer_Application OpcUaStackServer/Application/*.h)
file(GLOB INC_OpcUaStackServer_InformationModel OpcUaStackServer/InformationModel/*.h)
file(GLOB INC_OpcUaStackServer_NodeSet OpcUaStackServer/NodeSet/*.h)
file(GLOB INC_OpcUaStackServer_SecureChannel OpcUaStackServer/SecureChannel/*.h)
file(GLOB INC_OpcUaStackServer_ServiceManager OpcUaStackServer/ServiceManager/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSet OpcUaStackServer/ServiceSet/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSetApplication OpcUaStackServer/ServiceSetApplication/*.h)
file(GLOB INC_OpcUaStackServer_ApplicationUtility OpcUaStackServer/ApplicationUtility/*.h)
file(GLOB INC_OpcUaStackServer_VariableType OpcUaStackServer/VariableType/*.h)
file(GLOB INC_OpcUaStackServer_ObjectType OpcUaStackServer/ObjectType/*.h)
file(GLOB INC_OpcUaStackServer_StandardVariableType OpcUaStackServer/StandardVariableType/*.h)
file(GLOB INC_OpcUaStackServer_StandardObjectType OpcUaStackServer/StandardObjectType/*.h)


install(
    TARGETS OpcUaStackServer 
    DESTINATION /usr/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackServer_Server} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/Server
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_AddressSpaceModel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/AddressSpaceModel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_Application} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/Application
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_InformationModel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/InformationModel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_NodeSet} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/NodeSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_SecureChannel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/SecureChannel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_ServiceManager} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceManager
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_ServiceSet} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_ServiceSetApplication} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceSetApplication
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_ApplicationUtility} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ApplicationUtility
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_VariableType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/VariableType
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_ObjectType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ObjectType
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_StandardVariableType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/StandardVariableType
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackServer_StandardObjectType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/StandardObjectType
    COMPONENT headers
)
