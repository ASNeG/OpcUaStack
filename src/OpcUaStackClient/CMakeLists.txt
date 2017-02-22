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
    DESTINATION /usr/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaStackClient_Client} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/Client
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_SecureChannel} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/SecureChannel
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ServiceSet} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceSet
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ServiceAccess} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceAccess
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_VBI} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ValueBasedInterface
    COMPONENT headers
)

install(
    FILES ${INC_OpcUaStackClient_ApplicationUtility} 
    DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ApplicationUtility
    COMPONENT headers
)
