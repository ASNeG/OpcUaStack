
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
file(GLOB OpcUaStackClient_SRC ./OpcUaStackClient/*/*.cpp)
add_library(OpcUaStackClient ${OpcUaStackClient_SRC})


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackClient_Client ../inc/OpcUaStackClient/Client/*.h)
file(GLOB INC_OpcUaStackClient_SecureChannel ../inc/OpcUaStackClient/SecureChannel/*.h)
file(GLOB INC_OpcUaStackClient_ServiceSet ../inc/OpcUaStackClient/ServiceSet/*.h)

install(TARGETS OpcUaStackClient DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackClient_Client} DESTINATION include/OpcUaStack/OpcUaStackClient/Client)
install(FILES ${INC_OpcUaStackClient_SecureChannel} DESTINATION include/OpcUaStack/OpcUaStackClient/SecureChannel)
install(FILES ${INC_OpcUaStackClient_ServiceSet} DESTINATION include/OpcUaStack/OpcUaStackClient/ServiceSet)

