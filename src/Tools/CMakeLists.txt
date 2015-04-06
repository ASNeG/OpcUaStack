# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# configuration
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(BIN_DIR "bin" CACHE STRING "binary directory")

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

if (WIN32)
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
endif ()



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if (WIN32)
	install(TARGETS UpdateRegistry DESTINATION bin)
	install(TARGETS OpcUaStackService DESTINATION bin)
endif ()