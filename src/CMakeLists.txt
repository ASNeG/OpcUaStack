cmake_minimum_required(VERSION 3.5)
project	(OpcUaStack4)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#
# version
#
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
set(VERSION_MAJOR "4" CACHE STRING "major version")
set(VERSION_MINOR "0" CACHE STRING "minor version")
set(VERSION_PATCH "0" CACHE STRING "patch version")

set(BOOST_VERSION_MAJOR "1"  CACHE STRING "boost major version")
set(BOOST_VERSION_MINOR "65" CACHE STRING "boost minor version")

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
# build information
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

string(TIMESTAMP BUILD_TIME "%Y-%m-%d %HH:%MM")
set (BUILD_NUMBER 0)
if (DEFINED ENV{BUILD_NUMBER})
  set(BUILD_NUMBER ENV{BUILD_NUMBER})
endif()

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# global info messages
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
message(STATUS "Version info")
message(STATUS "  product version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
message(STATUS "  git commit: ${GIT_COMMIT}")
message(STATUS "  git branch: ${GIT_BRANCH}")

message(STATUS "Dependency info")
message(STATUS "  boost version: ${BOOST_VERSION_MAJOR}.${BOOST_VERSION_MINOR}")
message(STATUS "  openssl version: ${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH} (${OPENSSL_VERSION_NUMBER})")

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
 if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")    
    set(Boost_USE_DEBUG_LIBS     ON)
    set(Boost_USE_RELEASE_LIBS   OFF)
 else()
    set(Boost_USE_DEBUG_LIBS     OFF)
    set(Boost_USE_RELEASE_LIBS   ON)
 endif()
add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_NO_BOOST_CMAKE ON)
find_package(
    Boost 
    COMPONENTS program_options system unit_test_framework filesystem thread date_time chrono regex 
    REQUIRED
)

add_definitions(-DBOOST_VERSION_${BOOST_VERSION_MAJOR}_${BOOST_VERSION_MINOR})
#https://www.boost.org/doc/libs/1_78_0/boost/bind.hpp
#Retain behavior of havin Bind placeholders (_1,_2,..) in the global namespace, even if deprecated
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

message(STATUS "Boost library")
message(STATUS "  version major: ${Boost_MAJOR_VERSION}")
message(STATUS "  version minor: ${Boost_MINOR_VERSION}")
message(STATUS "  version subminor: ${Boost_SUBMINOR_VERSION}")
message(STATUS "  include directory: ${Boost_INCLUDE_DIRS}")
message(STATUS "  library directory: ${Boost_LIBRARY_DIRS}")
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
    REQUIRED
)

message(STATUS "OpenSSL library")
message(STATUS "  found: ${OPENSSL_FOUND}")
message(STATUS "  version number: ${OPENSSL_VERSION_NUMBER}")
message(STATUS "  version major: ${OPENSSL_VERSION_MAJOR}")
message(STATUS "  version minor: ${OPENSSL_VERSION_MINOR}")
message(STATUS "  version patch: ${OPENSSL_VERSION_PATCH}")
message(STATUS "  version: ${OPENSSL_VERSION}")
message(STATUS "  include library: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "  openssl library: ${OPENSSL_CRYPTO_LIBRARY}")
message(STATUS "  crypto library: ${OPENSSL_SSL_LIBRARY}")
message(STATUS "  libraries: ${OPENSSL_LIBRARIES}")


# -----------------------------------------------------------------------------
# find thread library
# -----------------------------------------------------------------------------
find_package (Threads)



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build info
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
message(STATUS "Build info")
message(STATUS "  thread library: ${CMAKE_THREAD_LIBS_INIT}")



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
else()
        message(STATUS "Mosquitto disabled")
endif()

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
		add_definitions(/bigobj)
	else ()
		add_definitions(-Wa,-mbig-obj)
	endif ()
    if (MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    endif()

    if (CPACK_BINARY_MSI)
        set (INSTALL_PREFIX "./usr")   
    endif()
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
include(OpcUaCtrl/CMakeLists.txt)
include(cmake/CMakeLists.txt)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# installation
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------


install(
    FILES icon/asneg.ico 
    DESTINATION ${INSTALL_PREFIX}/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES icon/asneg_install.ico 
    DESTINATION ${INSTALL_PREFIX}/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES icon/asneg_uninstall.ico 
    DESTINATION ${INSTALL_PREFIX}/share/icons/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES ${CMAKE_SOURCE_DIR}/../LICENSE
    DESTINATION ${INSTALL_PREFIX}/share/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)

install(
    FILES ${CMAKE_SOURCE_DIR}/../README.rst
    DESTINATION ${INSTALL_PREFIX}/share/OpcUaStack${VERSION_MAJOR}
    COMPONENT applications
)



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include(${CMAKE_SOURCE_DIR}/cmake/CPackHelpers.txt)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/../LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/../README.rst")
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
set(CPACK_COMPONENT_DEPENDENCIES_DISPLAY_NAME "C++ OPC UA Stack Dependencies")
set(CPACK_COMPONENT_DEPENDENCY_HEADERS_DISPLAY_NAME "Headers of C++ OPC UA Stack Dependencies")

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
set(CPACK_COMPONENT_DEPENDENCIES_DESCRIPTION
    "Dependencies (boost-${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION} and opennssl-${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH}")
set(CPACK_COMPONENT_DEPENDENCY_HEADERS_DESCRIPTION
    "Headers of (boost-${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION} and opennssl-${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_PATCH}")

# Put the components into two different groups: "Runtime" and "Development"
set(CPACK_COMPONENT_LIBRARIES_GROUP "bin")
set(CPACK_COMPONENT_APPLICATIONS_GROUP "bin")
set(CPACK_COMPONENT_DEPENDENCIES_GROUP "bin" )
set(CPACK_COMPONENT_TOOLS_GROUP "bin")

if (CPACK_BINARY_DEB OR CPACK_BINARY_RPM)
    set(CPACK_COMPONENT_HEADERS_GROUP "dev")    
    set(CPACK_COMPONENT_DEPENDENCY_HEADERS_GROUP "dev" )
   
    set(CPACK_PACKAGE_FILE_NAME "OpcUaStack-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")
endif()

if (CPACK_BINARY_DEB)
    set(CPACK_DEB_COMPONENT_INSTALL "ON")

    SSLDepends(libssl)         
    
    set(DEB_DEPS_DEV "${LIST_OF_LIB_VERSIONS_DEV}")
    set(DEB_DEPS_BIN "${LIST_OF_LIB_VERSIONS_BIN}")

    foreach(lib
        libboost-system libboost-thread libboost-date-time libboost-chrono libboost-regex libboost-program-options)
        BoostDepends(${lib})
        
        set(DEB_DEPS_BIN "${DEB_DEPS_BIN}, ${LIST_OF_LIB_VERSIONS_BIN}")
        set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, ${LIST_OF_LIB_VERSIONS_DEV}")            
    endforeach(lib)
        
    BoostDepends(libboost-test)
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, ${LIST_OF_LIB_VERSIONS_DEV}")
    set(DEB_DEPS_DEV "${DEB_DEPS_DEV}, OpcUaStack-${VERSION_MAJOR}-bin (=${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})")    
    
    set(CPACK_DEBIAN_DEV_PACKAGE_DEPENDS ${DEB_DEPS_DEV})       
    set(CPACK_DEBIAN_BIN_PACKAGE_DEPENDS ${DEB_DEPS_BIN})             
endif()

if (CPACK_BINARY_RPM)
    set(CPACK_RPM_COMPONENT_INSTALL "ON")
    set(CPACK_RPM_PACKAGE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
    set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE "${CMAKE_SOURCE_DIR}/linux/script/postinst")

    SSLDepends(libopenssl)         
    set(RPM_DEPS_BIN "${LIST_OF_LIB_VERSIONS_BIN}")
    set(RPM_DEPS_DEV "${LIST_OF_LIB_VERSIONS_DEV}")            
    
    foreach(lib
        libboost_system libboost_thread libboost_date_time libboost_chrono libboost_regex libboost_program_options)

        BoostDepends(${lib})
        set(RPM_DEPS_BIN "${RPM_DEPS_BIN}, ${LIST_OF_LIB_VERSIONS_BIN}")
        set(RPM_DEPS_DEV "${RPM_DEPS_DEV}, ${LIST_OF_LIB_VERSIONS_DEV}")            
    endforeach(lib)

    BoostDepends(libboost_test)
    set(RPM_DEPS_DEV "${RPM_DEPS_DEV}, ${LIST_OF_LIB_VERSIONS_DEV}")
    set(RPM_DEPS_DEV "${RPM_DEPS_DEV}, opcuastack-${VERSION_MAJOR}-bin = ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")    
    
    set(CPACK_RPM_DEV_PACKAGE_REQUIRES ${RPM_DEPS_DEV})       
    set(CPACK_RPM_BIN_PACKAGE_REQUIRES ${RPM_DEPS_BIN})             
endif()


if (CPACK_BINARY_MSI)
    if (CPACK_PACKAGE_TYPE STREQUAL "Dev")
        set(CPACK_COMPONENT_HEADERS_GROUP "dev")    
        set(CPACK_COMPONENT_DEPENDENCY_HEADERS_GROUP "dev" )
    endif()

    set(CPACK_PACKAGE_FILE_NAME "OpcUaStack-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}-${CPACK_PACKAGE_TYPE}")    
    
    if (CPACK_PACKAGE_TYPE STREQUAL "Dev")
		file (GLOB DEPS_DLL ${OPENSSL_INCLUDE_DIR}/../bin/libssl* ${OPENSSL_INCLUDE_DIR}/../bin/libcrypto*)
        set(CPACK_COMPONENTS_ALL libraries headers applications tools dependencies dependency_headers)
        file(GLOB ALL_DEP_LIBS ${OPENSSL_LIBRARIES}/* ${Boost_LIBRARY_DIRS}/*)
        install(FILES ${DEPS_DLL} DESTINATION ${INSTALL_PREFIX}/lib COMPONENT dependencies)             
        install(FILES ${ALL_DEP_LIBS} DESTINATION ${INSTALL_PREFIX}/lib COMPONENT dependencies)

        install(DIRECTORY ${Boost_INCLUDE_DIRS}/boost DESTINATION ${INSTALL_PREFIX}/include COMPONENT dependency_headers)
        install(DIRECTORY ${OPENSSL_INCLUDE_DIR}/openssl DESTINATION ${INSTALL_PREFIX}/include COMPONENT dependency_headers)
    else()
        set(CPACK_COMPONENTS_ALL libraries applications tools dependencies)
        GetStackDependencies()   

        install(FILES ${DEPS_DLL} DESTINATION ${INSTALL_PREFIX}/lib COMPONENT dependencies)
    endif()


    
	include (InstallRequiredSystemLibraries)
  install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${INSTALL_PREFIX}/lib COMPONENT dependencies)

	set(CPACK_GENERATOR NSIS)	
	set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpcUaStack")
	set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\\\\\icon\\\\asneg.ico")
	set(CPACK_NSIS_URL_INFO_ABOUT "http://asneg.de")
	set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/icon/asneg_install.ico")
	set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/icon/asneg_uninstall.ico")   
	set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
	
	set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
		"
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" addPath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib;$INSTDIR\\\\usr\\\\bin\\\"'          
		"
	) 
	
	set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
		"			
			ExecWait '\\\"$INSTDIR\\\\usr\\\\bin\\\\UpdateRegistry.exe\\\" removePath HKLM \\\"SYSTEM\\\\CurrentControlSet\\\\Control\\\\Session Manager\\\\Environment\\\" \\\"Path\\\" \\\"$INSTDIR\\\\usr\\\\lib;$INSTDIR\\\\usr\\\\bin\\\"'
		"
	)     
endif ()
include(CPack)	

