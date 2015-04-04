
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}
)

file(GLOB OpcUaServerApplicationDemo_SRC ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/*/*.cpp)
add_library(OpcUaServerApplicationDemo SHARED ${OpcUaServerApplicationDemo_SRC})

target_link_libraries(
    OpcUaServerApplicationDemo
    OpcUaStackCore
    OpcUaStackServer
	OpcUaStackClient
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
install(TARGETS OpcUaServerApplicationDemo DESTINATION lib/OpcUaStack)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/OpcUaServer.xml DESTINATION ${CONF_DIR}/ASNeG-Demo) 
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTest.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetRaspberry.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(DIRECTORY DESTINATION ${LOG_DIR}/ASNeG-Demo)
