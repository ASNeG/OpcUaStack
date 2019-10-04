# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# prebuild
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
configure_file(
    "${PROJECT_SOURCE_DIR}/OpcUaServer/Build/BuildConfig.h.in"
    "${PROJECT_BINARY_DIR}/BuildConfig.h"
)

set(BUILD_DATE "${CURRENT_DATE}" CACHE STRING "current build an time")


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaClient_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaClient/*/*.cpp
)

add_executable(
    OpcUaClient${VERSION_MAJOR}
    ${OpcUaClient_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaClient${VERSION_MAJOR}
    OpcUaStackCore
    OpcUaStackServer
    OpcUaStackClient
    ${CMAKE_DL_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    TARGETS OpcUaClient${VERSION_MAJOR} 
    DESTINATION ${INSTALL_PREFIX}/bin
    COMPONENT libraries
)

install(
    DIRECTORY DESTINATION 
    /var/log/OpcUaStack/OpcUaClient
)

install(
    FILES ${PROJECT_SOURCE_DIR}/OpcUaClient/Config/OpcUaClient.xml 
    DESTINATION /etc/OpcUaStack/OpcUaClient/
    
)

