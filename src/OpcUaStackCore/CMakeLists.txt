
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ../inc
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)
file(GLOB OpcUaStackCore_SRC ./OpcUaStackCore/*/*.cpp)
add_library(OpcUaStackCore SHARED ${OpcUaStackCore_SRC})

target_link_libraries(
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
#    ${pthread}
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

install(TARGETS OpcUaStackCore DESTINATION ${LIB_DIR}/OpcUaStack)
install(FILES ${INC_OpcUaStackCore_Base} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Base)
install(FILES ${INC_OpcUaStackCore_BuildInTypes} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/BuildInTypes)
install(FILES ${INC_OpcUaStackCore_Component} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Component)
install(FILES ${INC_OpcUaStackCore_Core} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Core)
install(FILES ${INC_OpcUaStackCore_SecureChannel} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/SecureChannel)
install(FILES ${INC_OpcUaStackCore_ServiceSet} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/ServiceSet)
install(FILES ${INC_OpcUaStackCore_ServiceSetApplication} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/ServiceSetApplication)
install(FILES ${INC_OpcUaStackCore_TCPChannel} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/TCPChannel)
install(FILES ${INC_OpcUaStackCore_Utility} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Utility)
install(FILES ${INC_OpcUaStackCore_Application} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Application)
install(FILES ${INC_OpcUaStackCore_Container} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackCore/Container)

