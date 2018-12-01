# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    .
)
file(GLOB UpdateRegistry_SRC ${PROJECT_SOURCE_DIR}/Tools/UpdateRegistry.cpp)
add_executable(
    UpdateRegistry
    ${UpdateRegistry_SRC}
    ${PROJECT_BINARY_DIR}
)
file(GLOB OpcUaStackService_SRC 
    ${PROJECT_SOURCE_DIR}/Tools/OpcUaStackService.cpp
    OpcUaServer/Service/WindowsService.cpp
)
add_executable(
    OpcUaStackService
    ${OpcUaStackService_SRC}
    ${PROJECT_BINARY_DIR}
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS UpdateRegistry DESTINATION ${INSTALL_PREFIX}/bin COMPONENT tools)
install(TARGETS OpcUaStackService DESTINATION ${INSTALL_PREFIX}/bin COMPONENT tools)
