
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

install(TARGETS OpcUaStackClient DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackClient_Client} DESTINATION include/OpcUaStack/OpcUaStackClient/Client)
install(FILES ${INC_OpcUaStackClient_SecureChannel} DESTINATION include/OpcUaStack/OpcUaStackClient/SecureChannel)
install(FILES ${INC_OpcUaStackClient_ServiceSet} DESTINATION include/OpcUaStack/OpcUaStackClient/ServiceSet)

