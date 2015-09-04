
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

file(GLOB OpcUaProjectName_SRC ${PROJECT_SOURCE_DIR}/OpcUaProjectName/*/*.cpp)
add_library(OpcUaProjectName SHARED ${OpcUaProjectName_SRC})

target_link_libraries(
    OpcUaProjectName
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
install(TARGETS OpcUaProjectName DESTINATION ${LIB_DIR}/OpcUaStack)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaProjectName/Config/OpcUaServer.xml DESTINATION ${CONF_DIR}/OpcUaProjectName) 
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaProjectName/Config/Opc.Ua.NodeSet.xml DESTINATION ${CONF_DIR}/OpcUaProjectName)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaProjectName/linux/log/README DESTINATION ${LOG_DIR}/OpcUaProjectName)
install(DIRECTORY DESTINATION ${LOG_DIR}/OpcUaProjectName)

if (WIN32)
else() 
    install(PROGRAMS ${PROJECT_SOURCE_DIR}/OpcUaProjectName/linux/etc/init.d/OpcUaProjectName DESTINATION etc/init.d)
    install(FILES ${PROJECT_SOURCE_DIR}/OpcUaProjectName/linux/etc/init/OpcUaProjectName.conf DESTINATION etc/init)
    install(FILES ${PROJECT_SOURCE_DIR}/OpcUaProjectName/linux/usr/lib/systemd/system/OpcUaProjectName.service DESTINATION usr/lib/systemd/system)
endif()

if (CPACK_BINARY_DEB)
    set( CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/postinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/preinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/prerm"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/postrm")
endif()

if (CPACK_BINARY_RPM)
    set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/postinst)
    set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/OpcUaProjectName/linux/script/prerm)
endif()
