
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
file(GLOB OpcUaStackServer_SRC ./OpcUaStackServer/*/*.cpp)
add_library(OpcUaStackServer SHARED ${OpcUaStackServer_SRC})

target_link_libraries(
    OpcUaStackServer
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
file(GLOB INC_OpcUaStackServer_Server OpcUaStackServer/Server/*.h)
file(GLOB INC_OpcUaStackServer_AddressSpaceModel OpcUaStackServer/AddressSpaceModel/*.h)
file(GLOB INC_OpcUaStackServer_Application OpcUaStackServer/Application/*.h)
file(GLOB INC_OpcUaStackServer_InformationModel OpcUaStackServer/InformationModel/*.h)
file(GLOB INC_OpcUaStackServer_NodeSet OpcUaStackServer/NodeSet/*.h)
file(GLOB INC_OpcUaStackServer_SecureChannel OpcUaStackServer/SecureChannel/*.h)
file(GLOB INC_OpcUaStackServer_ServiceManager OpcUaStackServer/ServiceManager/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSet OpcUaStackServer/ServiceSet/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSet OpcUaStackServerApplication/ServiceSetApplication/*.h)


install(TARGETS OpcUaStackServer DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackServer_Server} DESTINATION include/OpcUaStack/OpcUaStackServer/Server)
install(FILES ${INC_OpcUaStackServer_AddressSpaceModel} DESTINATION include/OpcUaStack/OpcUaStackServer/AddressSpaceModel)
install(FILES ${INC_OpcUaStackServer_Application} DESTINATION include/OpcUaStack/OpcUaStackServer/Application)
install(FILES ${INC_OpcUaStackServer_InformationModel} DESTINATION include/OpcUaStack/OpcUaStackServer/InformationModel)
install(FILES ${INC_OpcUaStackServer_NodeSet} DESTINATION include/OpcUaStack/OpcUaStackServer/NodeSet)
install(FILES ${INC_OpcUaStackServer_SecureChannel} DESTINATION include/OpcUaStack/OpcUaStackServer/SecureChannel)
install(FILES ${INC_OpcUaStackServer_ServiceManager} DESTINATION include/OpcUaStack/OpcUaStackServer/ServiceManager)
install(FILES ${INC_OpcUaStackServer_ServiceSet} DESTINATION include/OpcUaStack/OpcUaStackServer/ServiceSet)
install(FILES ${INC_OpcUaStackServer_ServiceSetApplication} DESTINATION include/OpcUaStack/OpcUaStackServer/ServiceSetApplication)

