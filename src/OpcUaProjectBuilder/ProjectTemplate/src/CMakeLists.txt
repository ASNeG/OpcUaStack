cmake_minimum_required(VERSION 2.8.9)
project	(ProjectName)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)


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

set(OPCUASTACK_VERSION_MAJOR "VersionMajor")
set(OPCUASTACK_VERSION_MINOR "VersionMinor")
set(OPCUASTACK_VERSION_PATCH "VersionPatch")


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
set (INSTALL_PREFIX "/usr")        
if (WIN32)    
    if (MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    endif()

    if (CPACK_BINARY_MSI)
        set (INSTALL_PREFIX "./usr")   
    endif()   
endif()

include(ProjectName/CMakeLists.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(FILES ${CMAKE_SOURCE_DIR}/icon/asneg.ico DESTINATION ${INSTALL_PREFIX}/share/icons/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/icon/asneg_install.ico DESTINATION ${INSTALL_PREFIX}/share/icons/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/icon/asneg_uninstall.ico DESTINATION ${INSTALL_PREFIX}/share/icons/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/Copyright.txt DESTINATION ${INSTALL_PREFIX}/share/ProjectName)
install(FILES ${CMAKE_SOURCE_DIR}/../NOTICE DESTINATION ${INSTALL_PREFIX}/share/ProjectName)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
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

if (CPACK_BINARY_MSI)
	set(CPACK_PACKAGE_FILE_NAME "ProjectName-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}")

    set(CPACK_GENERATOR NSIS)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "ProjectName")
    set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
    set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\\\\\icon\\\\asneg.ico")
    set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/icon/asneg_install.ico")
    set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/icon/asneg_uninstall.ico")
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
	
	if (STANDALONE)	
		set(CPACK_PACKAGE_FILE_NAME "ProjectName-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}-Standalone")

        if (MINGW)
            get_filename_component(MINGW_PATH ${CMAKE_CXX_COMPILER} PATH)
            file(
                    GLOB CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS
                    ${MINGW_PATH}/*.dll
            )
        endif(MINGW)

		include (InstallRequiredSystemLibraries)
		install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${INSTALL_PREFIX}/lib)

		include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CPackHelpers.txt)
		GetStackDependencies()
		install(FILES ${DEPS_DLL} DESTINATION ${INSTALL_PREFIX}/lib)

		file(TO_CMAKE_PATH ${OPCUASTACK_INSTALL_PREFIX} OPCUASTACK_INSTALL_PREFIX)
		file(GLOB STACK_BINARIES ${OPCUASTACK_INSTALL_PREFIX}/usr/bin/*)
		install(FILES ${STACK_BINARIES} DESTINATION ${INSTALL_PREFIX}/bin)		
		file(GLOB STACK_DLLS ${OPCUASTACK_INSTALL_PREFIX}/usr/lib/OpcUaStack*.dll)
		install(FILES ${STACK_DLLS} DESTINATION ${INSTALL_PREFIX}/lib)

		set(UPDATE_REGISTRY "$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe")
		set(OPC_UA_STACK_SERVICE "$INSTDIR\\\\usr\\\\bin\\\\OpcUaStackService.exe")
	else()
		set(UPDATE_REGISTRY "UpdateRegistry.exe")
		set(OPC_UA_STACK_SERVICE "OpcUaStackService.exe")
	endif()

    set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
            "
                    ExecWait '\\\"${UPDATE_REGISTRY}\\\" addPath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib'
                    ExecWait '\\\"${OPC_UA_STACK_SERVICE}\\\" INSTALL \\\"ProjectName\\\" \\\"ProjectDescription\\\" \\\"$INSTDIR\\\\etc\\\\OpcUaStack\\\\ProjectName\\\\OpcUaServer.xml\\\"'
            "
    )

    set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
            "
                    ExecWait '\\\"${OPC_UA_STACK_SERVICE}\\\" UNINSTALL \\\"ProjectName\\\"'
                    ExecWait '\\\"${UPDATE_REGISTRY}\\\" removePath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib'
            "
    )
endif ()

if (CPACK_BINARY_DEB)
    set(CPACK_PACKAGE_FILE_NAME "ProjectName-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_DEB_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")

    set(DEB_DEPS "OpcUaStack-${OPCUASTACK_VERSION_MAJOR}-bin (>=${OPCUASTACK_VERSION_MAJOR}.${OPCUASTACK_VERSION_MINOR}.${OPCUASTACK_VERSION_PATCH})")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS ${DEB_DEPS})

endif()

if (CPACK_BINARY_RPM)
    set(CPACK_PACKAGE_FILE_NAME "ProjectName-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")

    set(RPM_DEPS "opcuastack-${VERSION_MAJOR}-bin = ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")    
    set(CPACK_RPM__PACKAGE_REQUIRES ${RPM_DEPS})             
endif()


include(CPack)
