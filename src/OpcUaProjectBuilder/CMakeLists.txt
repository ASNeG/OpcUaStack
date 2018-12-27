# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# prebuild
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
configure_file(
    "${PROJECT_SOURCE_DIR}/OpcUaProjectBuilder/OpcUaProjectBuilderConfig.h.in"
    "${PROJECT_BINARY_DIR}/OpcUaProjectBuilderConfig.h"
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaProjectBuilder_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaProjectBuilder/*.cpp
)


add_executable(
    OpcUaProjectBuilder${VERSION_MAJOR}
    ${OpcUaProjectBuilder_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaProjectBuilder${VERSION_MAJOR}
    ${CMAKE_DL_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    OpcUaStackCore
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    TARGETS OpcUaProjectBuilder${VERSION_MAJOR} 
    DESTINATION ${INSTALL_PREFIX}/bin
    COMPONENT tools
)

install(
    DIRECTORY OpcUaProjectBuilder/ProjectTemplate 
    DESTINATION ${INSTALL_PREFIX}/share/OpcUaStack${VERSION_MAJOR}
    COMPONENT tools
)
