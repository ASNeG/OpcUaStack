
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

#configure_file(
#    "${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/PACKAGE/ASNeGServer-Demo.in"
#    "${PROJECT_BINARY_DIR}/ASNeGServer-Demo"
#)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS OpcUaServerApplicationDemo DESTINATION ${LIB_DIR}/OpcUaStack)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/OpcUaServer.xml DESTINATION ${CONF_DIR}/ASNeG-Demo) 
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTest.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLib.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLibClientServer.xml DESTINATION ${CONF_DIR}/ASNeG-Demo)
install(DIRECTORY DESTINATION ${LOG_DIR}/OpcUaStack/ASNeG-Demo)

if (WIN32)
else() 
    install(PROGRAMS ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/etc/init.d/ASNeG-Demo DESTINATION etc/init.d)
    install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/etc/init/ASNeG-Demo.conf DESTINATION etc/init)
    set( CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/postinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/preinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/prerm"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/postrm")
endif()
