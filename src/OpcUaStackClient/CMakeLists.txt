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

install(TARGETS OpcUaStackClient DESTINATION /usr/local/lib/OpcUaStack)
install(FILES ${INC_OpcUaStackClient_Client} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/Client)
install(FILES ${INC_OpcUaStackClient_SecureChannel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/SecureChannel)
install(FILES ${INC_OpcUaStackClient_ServiceSet} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceSet)
install(FILES ${INC_OpcUaStackClient_ServiceAccess} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ServiceAccess)
install(FILES ${INC_OpcUaStackClient_VBI} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackClient/ValueBasedInterface)
