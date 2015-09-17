
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${INSTALL_PREFIX_OpcUaStack}/usr/include/OpcUaStack
    ${PROJECT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(GLOB ProjectName_SRC ${PROJECT_SOURCE_DIR}/ProjectName/*/*.cpp)
add_library(ProjectName SHARED ${ProjectName_SRC})

target_link_libraries(
    ProjectName
    ${OpcUaStackCore}
    ${OpcUaStackServer}
    ${OpcUaStackClient}
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
install(TARGETS ProjectName DESTINATION ${LIB_DIR}/OpcUaStack)

install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/Config/OpcUaServer.xml DESTINATION ${CONF_DIR}/OpcUaStack/ProjectName) 
install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/Config/Opc.Ua.NodeSet.xml DESTINATION ${CONF_DIR}/OpcUaStack/ProjectName)
install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/linux/log/README DESTINATION ${LOG_DIR}/OpcUaStack/ProjectName)
install(DIRECTORY DESTINATION ${LOG_DIR}/OpcUaStack/ProjectName)

if (WIN32)
else() 
    install(PROGRAMS ${PROJECT_SOURCE_DIR}/ProjectName/linux/etc/init.d/ProjectName DESTINATION etc/init.d)
    install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/linux/etc/init/ProjectName.conf DESTINATION etc/init)
    install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/linux/usr/lib/systemd/system/ProjectName.service DESTINATION usr/lib/systemd/system)
endif()

if (CPACK_BINARY_DEB)
    set( CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/postinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/preinst"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/prerm"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/postrm")
endif()

if (CPACK_BINARY_RPM)
    set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/postinst)
    set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/ProjectName/linux/script/prerm)
endif()
