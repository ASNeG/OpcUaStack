cmake_minimum_required(VERSION 2.8.9)
project	(OpcUaStack)
set(CMAKE_VERBOSE_MAKEFILE ON)

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#
# version
#
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
set(VERSION_MAJOR "2" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "1" CACHE STRING "patch version")

set(BOOST_VERSION_MAJOR "1"  CACHE STRING "boost major version")
set(BOOST_VERSION_MINOR "54" CACHE STRING "boost minor version")

set(OPENSSL_VERSION_MAJOR "1" CACHE STRING "major version")
set(OPENSSL_VERSION_MINOR "0" CACHE STRING "minor version")
set(OPENSSL_VERSION_PATCH "1" CACHE STRING "patch version")


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
    file(WRITE ${CMAKE_BINARY_DIR}/dependency "boost ${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}")

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
message(STATUS "  boost version: ${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}")

message(STATUS "System info")
message(STATUS "  host system name: ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "  host system processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "  system processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "  system name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "  host system: ${CMAKE_HOST_SYSTEM}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# boost library
#
# This module reads hints about search locations from variables:
#
# BOOST_ROOT             - Preferred installation prefix
#  (or BOOSTROOT)
# BOOST_INCLUDEDIR       - Preferred include directory e.g. <prefix>/include
# BOOST_LIBRARYDIR       - Preferred library directory e.g. <prefix>/lib
# Boost_NO_SYSTEM_PATHS  - Set to ON to disable searching in locations not
#                          specified by these hint variables. Default is OFF.
# Boost_ADDITIONAL_VERSIONS
#                       - List of Boost versions not known to this module
#                         (Boost install locations may contain the version)
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
add_definitions(-DBOOST_ALL_DYN_LINK)
find_package(
    Boost 
    "${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}" 
    COMPONENTS system unit_test_framework filesystem thread date_time chrono regex 
    REQUIRED
)

message(STATUS "Boost library")
message(STATUS "  version major: ${Boost_MAJOR_VERSION}")
message(STATUS "  version minor: ${Boost_MINOR_VERSION}")
message(STATUS "  version subminor: ${Boost_SUBMINOR_VERSION}")
message(STATUS "  include directory: ${Boost_INCLUDE_DIR}")
message(STATUS "  library directory: ${Boost_LIBRARY_DIR}")
message(STATUS "  system debug library: ${Boost_SYSTEM_LIBRARY_DEBUG}")
message(STATUS "  system release library: ${Boost_SYSTEM_LIBRARY_RELEASE}")
message(STATUS "  unit_test_framework debug library: ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_DEBUG}")
message(STATUS "  unit_test_framework release library: ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_RELEASE}")
message(STATUS "  filesystem debug library: ${Boost_FILESYSTEM_LIBRARY_DEBUG}")
message(STATUS "  filesystem release library: ${Boost_FILESYSTEM_LIBRARY_RELEASE}")
message(STATUS "  thread debug library: ${Boost_THREAD_LIBRARY_DEBUG}")
message(STATUS "  thread release library: ${Boost_THREAD_LIBRARY_RELEASE}")
message(STATUS "  date_time debug library: ${Boost_DATE_TIME_LIBRARY_DEBUG}")
message(STATUS "  date_time release library: ${Boost_DATE_TIME_LIBRARY_RELEASE}")
message(STATUS "  chrono debug library: ${Boost_CHRONO_LIBRARY_DEBUG}")
message(STATUS "  chrono release library: ${Boost_CHRONO_LIBRARY_RELEASE}")
message(STATUS "  regex debug library: ${Boost_REGEX_LIBRARY_DEBUG}")
message(STATUS "  regex release library: ${Boost_REGEX_LIBRARY_RELEASE}")
message(STATUS "  libraries: ${Boost_LIBRARIES}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# openssl
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
find_package(
    OpenSSL 
    "${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH}" 
    COMPONENTS openssl crypto 
    REQUIRED
)

message(STATUS "OpenSSL library")
message(STATUS "  version: ${OPENSSL_VERSION}")
message(STATUS "  include library: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "  openssl library: ${OPENSSL_CRYPTO_LIBRARY}")
message(STATUS "  crypto library: ${OPENSSL_SSL_LIBRARY}")
message(STATUS "  libraries: ${OPENSSL_LIBRARIES}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build subdirectories
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (WIN32)
    include(Tools/CMakeLists.txt) 
endif()
include(OpcUaStackCore/CMakeLists.txt)
include(OpcUaStackClient/CMakeLists.txt) 
include(OpcUaStackServer/CMakeLists.txt)
include(OpcUaServer/CMakeLists.txt)












if (WIN32)
	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
	#ADD_DEFINITIONS(-DUNICODE)
	#ADD_DEFINITIONS(-D_UNICODE)
endif ()



set(BIN_DIR "usr/bin" CACHE STRING "binary directory")
set(LIB_DIR "usr/lib" CACHE STRING "library directory")
set(INC_DIR "usr/include" CACHE STRING "library directory")
set(CONF_DIR "etc/OpcUaStack" CACHE STRING "configuration directory")
set(LOG_DIR "var/log/OpcUaStack" CACHE STRING "log output directory")




# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build subdirectories
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (USE_OpcUaServer)
     
endif ()

if (USE_OpcUaClient)
    include(OpcUaClient/CMakeLists.txt) 
endif ()

if (USE_OpcUaServerApplicationDemo)
    include(OpcUaServerApplicationDemo/CMakeLists.txt) 
endif ()

if (USE_OpcUaProjectBuilder)
    include(OpcUaProjectBuilder/CMakeLists.txt) 
endif ()

if (USE_Certificate)
    include(OpcUaCertificate/CMakeLists.txt) 
endif ()


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(FILES icon/asneg.ico DESTINATION usr/share/icons/OpcUaStack)
install(FILES icon/asneg_install.ico DESTINATION usr/share/icons/OpcUaStack)
install(FILES icon/asneg_uninstall.ico DESTINATION usr/share/icons/OpcUaStack)
install(FILES ${CMAKE_SOURCE_DIR}/Copyright.txt DESTINATION usr/share/OpcUaStack)
install(FILES ${CMAKE_SOURCE_DIR}/../NOTICE DESTINATION usr/share/OpcUaStack)



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
	set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpcUaStack")
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\\\\\icon\\\\asneg.ico")
	set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
	set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/icon/asneg_install.ico")
	set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/icon/asneg_uninstall.ico")
	#set(CPACK_NSIS_INSTALLED_ICON_NAME "asneg.ico")
	
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" addPath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" INSTALL \\\"ASNeG-Demo\\\" \\\"ASNeG Demo Server\\\"'
		"
	) 
	
	set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\OpcUaStackService.exe\\\" UNINSTALL \\\"ASNeG-Demo\\\"'
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" removePath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib\\\\OpcUaStack;C:\\\\local\\\\boost_1_54_0\\\\lib32-msvc-11.0\\\"'
		"
	) 
	
endif ()

set(CPACK_PACKAGING_INSTALL_PREFIX "/")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "OpcUaStack")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "OpcUaStack - Opc Ua client server application framework")
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
