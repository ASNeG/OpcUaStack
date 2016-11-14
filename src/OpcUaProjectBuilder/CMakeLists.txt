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
    OpcUaProjectBuilder
    ${OpcUaProjectBuilder_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaProjectBuilder
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS OpcUaProjectBuilder DESTINATION /usr/local/bin)
install(DIRECTORY OpcUaProjectBuilder/ProjectTemplate DESTINATION usr/share/OpcUaStack${VERSION_MAJOR})
