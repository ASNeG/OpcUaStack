
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ../inc
)
file(GLOB OpcUaStackCore_SRC ./OpcUaStackCore/*/*.cpp)
add_library(OpcUaStackCore SHARED ${OpcUaStackCore_SRC})


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackCore_Base ../inc/OpcUaStackCore/Base/*.h)
file(GLOB INC_OpcUaStackCore_BuildInTypes ../inc/OpcUaStackCore/BuildInTypes/*.h)
file(GLOB INC_OpcUaStackCore_Component ../inc/OpcUaStackCore/Component/*.h)
file(GLOB INC_OpcUaStackCore_Core ../inc/OpcUaStackCore/Core/*.h)
file(GLOB INC_OpcUaStackCore_SecureChannel ../inc/OpcUaStackCore/SecureChannel/*.h)
file(GLOB INC_OpcUaStackCore_ServiceSet ../inc/OpcUaStackCore/ServiceSet/*.h)
file(GLOB INC_OpcUaStackCore_TCPChannel ../inc/OpcUaStackCore/TCPChannel/*.h)
file(GLOB INC_OpcUaStackCore_Utility ../inc/OpcUaStackCore/Utility/*.h)

install(TARGETS OpcUaStackCore DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackCore_Base} DESTINATION include/OpcUaStack/OpcUaStackCore/Base)
install(FILES ${INC_OpcUaStackCore_BuildInTypes} DESTINATION include/OpcUaStack/OpcUaStackCore/BuildInTypes)
install(FILES ${INC_OpcUaStackCore_Component} DESTINATION include/OpcUaStack/OpcUaStackCore/Component)
install(FILES ${INC_OpcUaStackCore_Core} DESTINATION include/OpcUaStack/OpcUaStackCore/Core)
install(FILES ${INC_OpcUaStackCore_SecureChannel} DESTINATION include/OpcUaStack/OpcUaStackCore/SecureChannel)
install(FILES ${INC_OpcUaStackCore_ServiceSet} DESTINATION include/OpcUaStack/OpcUaStackCore/ServiceSet)
install(FILES ${INC_OpcUaStackCore_TCPChannel} DESTINATION include/OpcUaStack/OpcUaStackCore/TCPChannel)
install(FILES ${INC_OpcUaStackCore_Utility} DESTINATION include/OpcUaStack/OpcUaStackCore/Utility)

