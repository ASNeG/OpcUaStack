# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# prebuild
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
configure_file(
    "${PROJECT_SOURCE_DIR}/ProjectName/Build/BuildConfig.h.in"
    "${PROJECT_BINARY_DIR}/BuildConfig.h"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/ProjectName/linux/etc/init/ProjectName.conf.in"
    "${PROJECT_BINARY_DIR}/ProjectName.conf"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/ProjectName/linux/etc/init.d/ProjectName.in"
    "${PROJECT_BINARY_DIR}/ProjectName"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/ProjectName/linux/usr/lib/systemd/system/ProjectName.service.in"
    "${PROJECT_BINARY_DIR}/ProjectName.service"
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${OPCUASTACK_INSTALL_PREFIX}/usr/include/OpcUaStack${OPCUASTACK_VERSION_MAJOR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
)

file(
    GLOB 
    ProjectName_SRC 
    ${PROJECT_SOURCE_DIR}/ProjectName/*/*.cpp
)

add_library(
    ProjectName SHARED 
    ${ProjectName_SRC}
)

target_link_libraries(
    ProjectName
    ${pthread}
    ${OPCUASTACK_LIBRARY_CORE}
    ${OPCUASTACK_LIBRARY_CLIENT}
    ${OPCUASTACK_LIBRARY_SERVER}
    ${OPCUASTACK_LIBRARY_PUBSUB}
    ${Boost_LIBRARIES}
)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

file (GLOB CONFIG_FILES ${PROJECT_SOURCE_DIR}/ProjectName/Config/*.xml)
install(TARGETS ProjectName DESTINATION ${INSTALL_PREFIX}/lib)

if (WIN32)
    install(FILES ${CONFIG_FILES} DESTINATION ${INSTALL_PREFIX}/../etc/OpcUaStack/ProjectName) 
    install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/linux/log/README DESTINATION ${INSTALL_PREFIX}/../var/log/OpcUaStack/ProjectName)
    install(DIRECTORY DESTINATION ${INSTALL_PREFIX}/../var/log/OpcUaStack/ProjectName)
else()    
    install(FILES ${CONFIG_FILES} DESTINATION ${INSTALL_PREFIX}/../etc/OpcUaStack/ProjectName) 
    install(FILES ${PROJECT_SOURCE_DIR}/ProjectName/linux/log/README DESTINATION /var/log/OpcUaStack/ProjectName)
    install(DIRECTORY DESTINATION /var/log/OpcUaStack/ProjectName)

    install(PROGRAMS ${PROJECT_BINARY_DIR}/ProjectName DESTINATION /etc/init.d)
    install(FILES ${PROJECT_BINARY_DIR}/ProjectName.conf DESTINATION /etc/init)
    install(FILES ${PROJECT_BINARY_DIR}/ProjectName.service DESTINATION /usr/lib/systemd/system)
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
