
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

add_definitions(-DBOOST_DYN_LINK)

file(GLOB OpcUaServerApplicationDemo_SRC ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/*/*.cpp)
add_library(OpcUaServerApplicationDemo SHARED ${OpcUaServerApplicationDemo_SRC})


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS OpcUaServerApplicationDemo DESTINATION lib/OpcUaStack)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/OpcUaServer.xml DESTINATION ${CONF_DIR}/Demo) 
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.xml DESTINATION ${CONF_DIR}/Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTest.xml DESTINATION ${CONF_DIR}/Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetRaspberry.xml DESTINATION ${CONF_DIR}/Demo)
install(DIRECTORY DESTINATION ${LOG_DIR})
