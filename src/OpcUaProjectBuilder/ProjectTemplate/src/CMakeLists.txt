cmake_minimum_required(VERSION 2.8.9)
project	(ProjectName)
set(CMAKE_VERBOSE_MAKEFILE ON)

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#
# version
#
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
set(VERSION_MAJOR "1" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "0" CACHE STRING "patch version")

set(OPCUASTACK_VERSION_MAJOR "3" CACHE STRING "major version")
set(OPCUASTACK_VERSION_MINOR "0" CACHE STRING "minor version")
set(OPCUASTACK_VERSION_PATCH "1" CACHE STRING "patch version")
set(OPCUASTACK_INSTALL_PREFIX "/" CACHE PATH "opc ua stack intallation prefix")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# create version file and dependency file
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (CREATE_INFO_FILES)
    message(STATUS "create info file ${CMAKE_BINARY_DIR}/version")
    file(WRITE ${CMAKE_BINARY_DIR}/version "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

    message(STATUS "create dependency file ${CMAKE_BINARY_DIR}/dependency")
    file(WRITE ${CMAKE_BINARY_DIR}/dependency "opcuastack ${OPCUASTACK_VERSION_MAJOR}.${OPCUASTACK_VERSION_MINOR}.${OPCUASTACK_VERSION_PATCH}")

    return()
endif ()


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global info messages
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
message(STATUS "Version info")
message(STATUS "  product version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

message(STATUS "Dependency info")
message(STATUS "  opcuastack version: ${OPCUASTACK_VERSION_MAJOR}.${OPCUASTACK_VERSION_MINOR}.${OPCUASTACK_VERSION_PATCH}")
message(STATUS "  boost version: ${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}")
message(STATUS "  openssl version: ${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH}")

message(STATUS "System info")
message(STATUS "  host system name: ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "  host system processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "  system processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "  system name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "  host system: ${CMAKE_HOST_SYSTEM}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# boost 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeBoost.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# openssl
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpenSSL.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# opcuastack 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpcUaStack.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build subdirectories
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(ProjectName/CMakeLists.txt) 


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(FILES icon/asneg.ico DESTINATION usr/share/icons/ProjectName)
install(FILES icon/asneg_install.ico DESTINATION usr/share/icons/ProjectName)
install(FILES icon/asneg_uninstall.ico DESTINATION usr/share/icons/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/Copyright.txt DESTINATION usr/share/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/../NOTICE DESTINATION usr/share/ProjectName)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (WIN32)
	include (InstallRequiredSystemLibraries)
	
	#set(CPACK_PACKAGE_EXECUTABLES "OpcUaServer" "OpcUaServer")
	set(CPACK_PACKAGE_INSTALL_DIRECTORY "ProjectName")
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\\\\\icon\\\\asneg.ico")
	set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
	set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/icon/asneg_install.ico")
	set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/icon/asneg_uninstall.ico")
	#set(CPACK_NSIS_INSTALLED_ICON_NAME "asneg.ico")
	
       set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
                "
                        ExecWait '\\\"C:\\\\Program Files (x86)\\\\OpcUaStack\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" addPath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack'
                        ExecWait '\\\"C:\\\\Program Files (x86)\\\\OpcUaStack\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" INSTALL \\\"ProjectName\\\" \\\"ProjectDescription\\\"'
                "
        )

        set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
                "
                        ExecWait '\\\"C:\\\\Program Files (x86)\\\\OpcUaStack\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" UNINSTALL \\\"ProjectName\\\"'
                        ExecWait '\\\"C:\\\\Program Files (x86)\\\\OpcUaStack\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" removePath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack'
                "
        )



	
endif ()


set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "ProjectName")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ProjectName - ProjectDescription")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_BINARY_STGZ "OFF")
set(CPACK_BINARY_TGZ "OFF")
set(CPACK_BINARY_TZ "OFF")

if (CPACK_BINARY_DEB)
    set(CPACK_PACKAGE_FILE_NAME "ProjectName-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_DEB_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")

    set(DEB_DEPS "OpcUaStack-${OPCUASTACK_VERSION_MAJOR}-bin (>=${OPCUASTACK_VERSION_MAJOR}.${OPCUASTACK_VERSION_MINOR}.${OPCUASTACK_VERSION_PATCH})")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS ${DEB_DEPS})

endif()

if (CPACK_BINARY_RPM)
    set(CPACK_RPM_COMPONENT_INSTALL "ON")
 #   set(CPACK_PACKAGE_FILE_NAME "OpcUaStack-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
endif()


include(CPack)
