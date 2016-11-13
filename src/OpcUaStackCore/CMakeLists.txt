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

install(TARGETS OpcUaStackCore DESTINATION /usr/local/lib)
install(FILES ${INC_OpcUaStackCore_Base} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Base)
install(FILES ${INC_OpcUaStackCore_BuildInTypes} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/BuildInTypes)
install(FILES ${INC_OpcUaStackCore_Component} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Component)
install(FILES ${INC_OpcUaStackCore_Core} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Core)
install(FILES ${INC_OpcUaStackCore_SecureChannel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/SecureChannel)
install(FILES ${INC_OpcUaStackCore_ServiceSet} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ServiceSet)
install(FILES ${INC_OpcUaStackCore_ServiceSetApplication} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/ServiceSetApplication)
install(FILES ${INC_OpcUaStackCore_TCPChannel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/TCPChannel)
install(FILES ${INC_OpcUaStackCore_Utility} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Utility)
install(FILES ${INC_OpcUaStackCore_Application} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Application)
install(FILES ${INC_OpcUaStackCore_Container} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackCore/Container)
