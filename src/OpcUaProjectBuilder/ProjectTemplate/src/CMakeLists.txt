cmake_minimum_required(VERSION 2.8.9)
project	(ProjectName)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global options
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(VERSION_MAJOR "1" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "5" CACHE STRING "patch version")

set(BIN_DIR "usr/bin" CACHE STRING "binary directory")
set(LIB_DIR "usr/lib" CACHE STRING "library directory")
set(INC_DIR "usr/include" CACHE STRING "library directory")
set(CONF_DIR "etc" CACHE STRING "configuration directory")
set(LOG_DIR "var/log" CACHE STRING "log output directory")

option(
    USE_ProjectName
    "build opc ua server application library"
    ON
)

add_definitions(-DBOOST_ALL_DYN_LINK)

if (WIN32)
	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
endif ()

find_package(Boost COMPONENTS system unit_test_framework filesystem thread date_time chrono regex REQUIRED)
find_library(OpcUaStackCore NAME OpcUaStackCore PATHS ${INSTALL_PREFIX_OpcUaStack}/usr/lib/OpcUaStack/ REQUIRED)
find_library(OpcUaStackClient NAME OpcUaStackClient PATHS ${INSTALL_PREFIX_OpcUaStack}/usr/lib/OpcUaStack/ REQUIRED)
find_library(OpcUaStackServer NAME OpcUaStackServer PATHS ${INSTALL_PREFIX_OpcUaStack}/usr/lib/OpcUaStack/ REQUIRED)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build subdirectories
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (USE_ProjectName)
    include(ProjectName/CMakeLists.txt) 
endif ()


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

set(CPACK_PACKAGING_INSTALL_PREFIX "/")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "ProjectName")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ProjectName - ProjectDescription")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

if (CPACK_BINARY_DEB)
    	set (CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
	set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
endif()

if (CPACK_BINARY_RPM)
    	set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
	set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
endif()

	

include(CPack)
