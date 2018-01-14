cmake_minimum_required(VERSION 2.8.9)
project	(OpcUaStack4)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0053 OLD)

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#
# version
#
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
set(VERSION_MAJOR "4" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "1" CACHE STRING "patch version")

set(BOOST_VERSION_MAJOR "1"  CACHE STRING "boost major version")
set(BOOST_VERSION_MINOR "54" CACHE STRING "boost minor version")

set(OPENSSL_VERSION_MAJOR "1" CACHE STRING "major version")
set(OPENSSL_VERSION_MINOR "0" CACHE STRING "minor version")
set(OPENSSL_VERSION_PATCH "0" CACHE STRING "patch version")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# check environment variables
#
# list of possible environment variables
#   - OPENSSL_VERSION_MAJOR
#   - OPENSSL_VERSION_MINOR
#   - OPENSSL_VERSION_PATCH
#   - BOOST_VERSION_MAJOR
#   - BOOST_VERSION_MINOR
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

# boost
if (DEFINED ENV{BOOST_VERSION_MAJOR})
    set(BOOST_VERSION_MAJOR $ENV{BOOST_VERSION_MAJOR})
endif ()
if (DEFINED ENV{BOOST_VERSION_MINOR})
    set(BOOST_VERSION_MINOR $ENV{BOOST_VERSION_MINOR})
endif ()

# openssl
if (DEFINED ENV{OPENSSL_VERSION_MAJOR})
    set(OPENSSL_VERSION_MAJOR $ENV{OPENSSL_VERSION_MAJOR})
endif ()
if (DEFINED ENV{OPENSSL_VERSION_MINOR})
    set(OPENSSL_VERSION_MINOR $ENV{OPENSSL_VERSION_MINOR})
endif ()
if (DEFINED ENV{OPENSSL_VERSION_PATCH})
    set(OPENSSL_VERSION_PATCH $ENV{OPENSSL_VERSION_PATCH})
endif ()

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
    COMPONENTS program_options system unit_test_framework filesystem thread date_time chrono regex 
    REQUIRED
)

add_definitions(-DBOOST_VERSION_${BOOST_VERSION_MAJOR}_${BOOST_VERSION_MINOR})

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
message(STATUS "  program_options debug library: ${Boost_PROGRAM_OPTIONS_LIBRARY_DEBUG}")
message(STATUS "  program_options release library: ${Boost_PROGRAM_OPTIONS_LIBRARY_RELEASE}")

message(STATUS "  libraries: ${Boost_LIBRARIES}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# openssl
#
# BOOST_ROOT             - Preferred installation prefix
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
message(STATUS "  found: ${OPENSSL_FOUND}")
message(STATUS "  version major: ${OPENSSL_VERSION_MAJOR}")
message(STATUS "  version minor: ${OPENSSL_VERSION_MINOR}")
message(STATUS "  version patch: ${OPENSSL_VERSION_PATCH}")
message(STATUS "  version: ${OPENSSL_VERSION}")
message(STATUS "  include library: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "  openssl library: ${OPENSSL_CRYPTO_LIBRARY}")
message(STATUS "  crypto library: ${OPENSSL_SSL_LIBRARY}")
message(STATUS "  libraries: ${OPENSSL_LIBRARIES}")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# Mosquitto
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (DEFINED ENV{USE_MOSQUITTO_CLIENT})
	message(STATUS "Mosquitto enabled")
	set(USE_MOSQUITTO_CLIENT $ENV{USE_MOSQUITTO_CLIENT})
	set(MOSQUITTO_LIBRARIES "mosquitto")
	add_definitions(-DUSE_MOSQUITTO_CLIENT)
endif()

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
include(OpcUaStackPubSub/CMakeLists.txt)
include(OpcUaStackClient/CMakeLists.txt) 
include(OpcUaStackServer/CMakeLists.txt)
include(OpcUaServer/CMakeLists.txt)
include(OpcUaClient/CMakeLists.txt) 
include(OpcUaProjectBuilder/CMakeLists.txt)
include(OpcUaGenerator/CMakeLists.txt)
include(cmake/CMakeLists.txt)













if (WIN32)
	set(CMAKE_PREFIX_PATH C:\\local\\boost_1_54_0)
	set(BOOST_LIBRARYDIR C:\\local\\boost_1_54_0\\lib32-msvc-11.0)
	#ADD_DEFINITIONS(-DUNICODE)
	#ADD_DEFINITIONS(-D_UNICODE)
endif ()


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    FILES icon/asneg.ico 
    DESTINATION /usr/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES icon/asneg_install.ico 
    DESTINATION /usr/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES icon/asneg_uninstall.ico 
    DESTINATION /usr/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES ${CMAKE_SOURCE_DIR}/Copyright.txt 
    DESTINATION /usr/share/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES ${CMAKE_SOURCE_DIR}/../NOTICE 
    DESTINATION /usr/share/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
set(CPACK_PACKAGE_CONTACT "info@asneg.de")
set(CPACK_PACKAGE_NAME "OpcUaStack-${VERSION_MAJOR}")
set(CPACK_PACKAGE_VENDOR "asneg.de")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "OpcUaStack - Opc Ua client server application framework")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_BINARY_STGZ "OFF")
set(CPACK_BINARY_TGZ "OFF")
set(CPACK_BINARY_TZ "OFF")

if (CPACK_BINARY_DEB)
    set(CPACK_DEB_COMPONENT_INSTALL "ON")
    set(CPACK_PACKAGE_FILE_NAME "OpcUaStack-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_DEB_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")

    set(DEB_DEPS_DEV "libboost-system${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-test${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-filesystem${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-thread${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-date-time${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-chrono${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libboost-regex${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}-dev")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, libssl-dev (>= ${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR})")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, OpcUaStack-${VERSION_MAJOR}-bin (=${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})")
    set(CPACK_DEBIAN_DEV_PACKAGE_DEPENDS ${DEB_DEPS_DEV})

    set(DEB_DEPS_BIN "libboost-system${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libboost-filesystem${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libboost-thread${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libboost-date-time${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libboost-chrono${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libboost-regex${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}.0")
    set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, libssl${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.0")
    set(CPACK_DEBIAN_BIN_PACKAGE_DEPENDS ${DEB_DEPS_BIN})
endif()

if (CPACK_BINARY_RPM)
    set(CPACK_RPM_COMPONENT_INSTALL "ON")
 #   set(CPACK_PACKAGE_FILE_NAME "OpcUaStack-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/Copyright.txt")
endif()


# Tell CPack all of the components to install. The "ALL"
# refers to the fact that this is the set of components that
# will be included when CPack is instructed to put everything
# into the binary installer (the default behavior).
set(CPACK_COMPONENTS_ALL libraries headers applications tools)

# Set the displayed names for each of the components to install.
# These will be displayed in the list of components inside the installer.
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "C++ OPC UA Stack Libraries")
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ OPC UA Stack Headers")
set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "C++ OPC UA Applications Server")
set(CPACK_COMPONENT_TOOLS_DISPLAY_NAME "OPC UA Stack Tools")

# Provide descriptions for each of the components to install.
# When the user hovers the mouse over the name of a component, 
# the description will be shown in the "Description" box in the
# installer. If no descriptions are provided, the "Description" 
# box will be removed.
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION
  "Shared libraries used to build opc ua applications")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION
  "C/C++ header files used to build opc ua applications")
set(CPACK_COMPONENT_APPLICATIONS_DESCRIPTION
  "C/C++ opc ua application server")
set(CPACK_COMPONENT_TOOLS_DESCRIPTION
  "C/C++ development tools")

# Put the components into two different groups: "Runtime" and "Development"
set(CPACK_COMPONENT_LIBRARIES_GROUP "bin")
set(CPACK_COMPONENT_HEADERS_GROUP "dev")
set(CPACK_COMPONENT_APPLICATIONS_GROUP "bin")
set(CPACK_COMPONENT_TOOLS_GROUP "dev")

include(CPack)





















#
# todo
#
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


