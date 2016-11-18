
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

file(
    GLOB OpcUaServerApplicationDemo_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/*/*.cpp
)

add_library(
    OpcUaServerApplicationDemo 
    SHARED ${OpcUaServerApplicationDemo_SRC}
)

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
install(TARGETS OpcUaServerApplicationDemo DESTINATION /usr/lib)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/OpcUaServer.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo) 
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTest.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLib.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLibClientServer.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.Camera.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.Function.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/ApplicationDemoModel.xml DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/animation00.gif DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/animation01.gif DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/animation02.gif DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/animation03.gif DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/Config/animation04.gif DESTINATION /etc/OpcUaStack/ASNeG-Demo)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/log/README DESTINATION /var/log/OpcUaStack//ASNeG-Demo)
install(DIRECTORY DESTINATION /var/log/OpcUaStack/ASNeG-Demo)

#if (WIN32)
#else() 
#    install(PROGRAMS ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/etc/init.d/ASNeG-Demo DESTINATION etc/init.d)
#    install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/etc/init/ASNeG-Demo.conf DESTINATION etc/init)
#    install(FILES ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/usr/lib/systemd/system/ASNeG-Demo.service DESTINATION usr/lib/systemd/system)
#endif()
#
#if (CPACK_BINARY_DEB)
#    set( CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/postinst"
#                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/preinst"
#                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/prerm"
#                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/postrm")
#endif()
#
#if (CPACK_BINARY_RPM)
#    set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/postinst)
#    set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/OpcUaServerApplicationDemo/linux/script/prerm)
#endif()
