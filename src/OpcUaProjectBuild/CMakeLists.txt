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

file(GLOB OpcUaProjectBuilder_SRC ${PROJECT_SOURCE_DIR}/OpcUaProjectBuilder/*.cpp)
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
install(TARGETS OpcUaProjectBuilder DESTINATION ${BIN_DIR})
