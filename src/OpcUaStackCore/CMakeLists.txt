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
    GLOB OpcUaStackCore_SRC 
    ./OpcUaStackCore/*/*.cpp
)

add_library(
    OpcUaStackCore 
    SHARED 
    ${OpcUaStackCore_SRC}
)

target_link_libraries(
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    ${OPENSSL_LIBRARIES}
)

set_target_properties(
    OpcUaStackCore
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

get_target_property(
    OpcUaStackCoreLibName 
    OpcUaStackCore
    OUTPUT_NAME
)

if (WIN32)
    set_target_properties(
    	OpcUaStackCore 
    	PROPERTIES OUTPUT_NAME 
    	"OpcUaStackCore${VERSION_MAJOR}"
    )
	set(OPCUASTACK_CORE_LIB_NAME OpcUaStackCore@VERSION_MAJOR@.lib)
else()
    set(OPCUASTACK_CORE_LIB_NAME libOpcUaStackCore.so.@VERSION_MAJOR@)
endif()

message(STATUS "OpcUaStackCore")
message(STATUS "  library name: ${OPCUASTACK_CORE_LIB_NAME}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackCore_Base OpcUaStackCore/Base/*.h OpcUaStackCore/Base/*.txx)
file(GLOB INC_OpcUaStackCore_BuildInTypes OpcUaStackCore/BuildInTypes/*.h)
file(GLOB INC_OpcUaStackCore_Component OpcUaStackCore/Component/*.h)
file(GLOB INC_OpcUaStackCore_Core OpcUaStackCore/Core/*.h)
file(GLOB INC_OpcUaStackCore_SecureChannel OpcUaStackCore/SecureChannel/*.h)
file(GLOB INC_OpcUaStackCore_ServiceSet OpcUaStackCore/ServiceSet/*.h OpcUaStackCore/ServiceSet/*.txx)
file(GLOB INC_OpcUaStackCore_ServiceSetApplication OpcUaStackCore/ServiceSetApplication/*.h)
file(GLOB INC_OpcUaStackCore_TCPChannel OpcUaStackCore/TCPChannel/*.h)
file(GLOB INC_OpcUaStackCore_Utility OpcUaStackCore/Utility/*.h)
file(GLOB INC_OpcUaStackCore_Application OpcUaStackCore/Application/*.h)
file(GLOB INC_OpcUaStackCore_Container OpcUaStackCore/Container/*.h)
file(GLOB INC_OpcUaStackCore_ApplicationUtility OpcUaStackCore/ApplicationUtility/*.h)
file(GLOB INC_OpcUaStackCore_StandardDataTypes OpcUaStackCore/StandardDataTypes/*.h)
file(GLOB INC_OpcUaStackCore_ComplexDataTypes OpcUaStackCore/ComplexDataTypes/*.h)
file(GLOB INC_OpcUaStackCore_DataType OpcUaStackCore/DataType/*.h)
file(GLOB INC_OpcUaStackCore_Filter OpcUaStackCore/Filter/*.h)
file(GLOB INC_OpcUaStackCore_Network OpcUaStackCore/Network/*.h)
file(GLOB INC_OpcUaStackCore_EventType OpcUaStackCore/EventType/*.h)
file(GLOB INC_OpcUaStackCore_StandardEventType OpcUaStackCore/StandardEventType/*.h)



install(
    TARGETS OpcUaStackCore 
    DESTINATION /usr/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackCore_Base} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Base
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_BuildInTypes} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/BuildInTypes
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Component} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Component
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Core} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Core
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_SecureChannel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/SecureChannel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_ServiceSet} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ServiceSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_ServiceSetApplication} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ServiceSetApplication
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_TCPChannel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/TCPChannel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Utility} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Utility
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Application} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Application
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Container} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Container
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_ApplicationUtility} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ApplicationUtility
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_StandardDataTypes} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/StandardDataTypes
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_ComplexDataTypes} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ComplexDataTypes
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_DataType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/DataType
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Filter} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Filter
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_Network} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Network
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_EventType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/EventType
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackCore_StandardEventType} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/StandardEventType
    COMPONENT headers
)


