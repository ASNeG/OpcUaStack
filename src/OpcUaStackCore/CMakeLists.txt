
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
file(GLOB OpcUaStackCore_SRC ./OpcUaStackCore/*/*.cpp)
add_library(OpcUaStackCore SHARED ${OpcUaStackCore_SRC})

target_link_libraries(
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
#    ${pthread}
    ${Boost_LIBRARIES}
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
file(GLOB INC_OpcUaStackCore_ServiceSet OpcUaStackCore/ServiceSet/*.h)
file(GLOB INC_OpcUaStackCore_ServiceSetApplication OpcUaStackCore/ServiceSetApplication/*.h)
file(GLOB INC_OpcUaStackCore_TCPChannel OpcUaStackCore/TCPChannel/*.h)
file(GLOB INC_OpcUaStackCore_Utility OpcUaStackCore/Utility/*.h)

install(TARGETS OpcUaStackCore DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackCore_Base} DESTINATION include/OpcUaStack/OpcUaStackCore/Base)
install(FILES ${INC_OpcUaStackCore_BuildInTypes} DESTINATION include/OpcUaStack/OpcUaStackCore/BuildInTypes)
install(FILES ${INC_OpcUaStackCore_Component} DESTINATION include/OpcUaStack/OpcUaStackCore/Component)
install(FILES ${INC_OpcUaStackCore_Core} DESTINATION include/OpcUaStack/OpcUaStackCore/Core)
install(FILES ${INC_OpcUaStackCore_SecureChannel} DESTINATION include/OpcUaStack/OpcUaStackCore/SecureChannel)
install(FILES ${INC_OpcUaStackCore_ServiceSet} DESTINATION include/OpcUaStack/OpcUaStackCore/ServiceSet)
install(FILES ${INC_OpcUaStackCore_ServiceSetApplication} DESTINATION include/OpcUaStack/OpcUaStackCore/ServiceSetApplication)
install(FILES ${INC_OpcUaStackCore_TCPChannel} DESTINATION include/OpcUaStack/OpcUaStackCore/TCPChannel)
install(FILES ${INC_OpcUaStackCore_Utility} DESTINATION include/OpcUaStack/OpcUaStackCore/Utility)

