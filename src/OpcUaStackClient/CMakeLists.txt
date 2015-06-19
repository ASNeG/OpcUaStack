
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
)
file(GLOB OpcUaStackClient_SRC ./OpcUaStackClient/*/*.cpp)
add_library(OpcUaStackClient SHARED ${OpcUaStackClient_SRC})

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

install(TARGETS OpcUaStackClient DESTINATION ${LIB_DIR}/OpcUaStack)
install(FILES ${INC_OpcUaStackClient_Client} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackClient/Client)
install(FILES ${INC_OpcUaStackClient_SecureChannel} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackClient/SecureChannel)
install(FILES ${INC_OpcUaStackClient_ServiceSet} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackClient/ServiceSet)
install(FILES ${INC_OpcUaStackClient_ServiceAccess} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackClient/ServiceAccess)

