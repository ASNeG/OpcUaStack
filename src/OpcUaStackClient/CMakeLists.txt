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
    GLOB OpcUaStackClient_SRC 
    ./OpcUaStackClient/*/*.cpp
)

add_library(
    OpcUaStackClient 
    SHARED 
    ${OpcUaStackClient_SRC}
)

target_link_libraries(
    OpcUaStackClient
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)

set_target_properties(
    OpcUaStackClient
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

if (WIN32)
    set_target_properties(
    	OpcUaStackClient 
    	PROPERTIES OUTPUT_NAME 
    	"OpcUaStackClient${VERSION_MAJOR}"
	)
	set(OPCUASTACK_CLIENT_LIB_NAME OpcUaStackClient@VERSION_MAJOR@.lib)
else()
    set(OPCUASTACK_CLIENT_LIB_NAME libOpcUaStackClient.so.@VERSION_MAJOR@)
endif()

message(STATUS "OpcUaStackClient")
message(STATUS "  library name: ${OPCUASTACK_CLIENT_LIB_NAME}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackClient_Client OpcUaStackClient/Client/*.h)
file(GLOB INC_OpcUaStackClient_SecureChannel OpcUaStackClient/SecureChannel/*.h)
file(GLOB INC_OpcUaStackClient_ServiceSet OpcUaStackClient/ServiceSet/*.h)
file(GLOB INC_OpcUaStackClient_VBI OpcUaStackClient/ValueBasedInterface/*.h)
file(GLOB INC_OpcUaStackClient_ApplicationUtility OpcUaStackClient/ApplicationUtility/*.h)

install(
    TARGETS OpcUaStackClient 
    DESTINATION ${INSTALL_PREFIX}/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackClient_Client} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/Client
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_SecureChannel} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/SecureChannel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ServiceSet} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ServiceAccess} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceAccess
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_VBI} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ValueBasedInterface
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ApplicationUtility} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ApplicationUtility
    COMPONENT headers
)
