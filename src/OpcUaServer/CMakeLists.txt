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
set(GIT_COMMIT "${GIT_COMMIT}" CACHE STRING "git commit id")
set(GIT_BRANCH "${GIT_BRANCH}" CACHE STRING "git branch name")


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
    GLOB OpcUaServer_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaServer/*/*.cpp
)

add_executable(
    OpcUaServer${VERSION_MAJOR}
    ${OpcUaServer_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaServer${VERSION_MAJOR}
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
    TARGETS OpcUaServer${VERSION_MAJOR} 
    DESTINATION ${INSTALL_PREFIX}/bin
    COMPONENT applications
)
