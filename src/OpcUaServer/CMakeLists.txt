# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# configuration
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(BIN_DIR "bin" CACHE STRING "binary directory")
set(CONF_DIR "etc/OpcUaStack" CACHE STRING "configuration directory")
set(LOG_DIR "var/log/OpcUaStack" CACHE STRING "log output directory")

configure_file(
    "${PROJECT_SOURCE_DIR}/OpcUaServer/Build/BuildConfig.h.in"
    "${PROJECT_BINARY_DIR}/BuildConfig.h"
)

#try_run(
#    RUN_CURRENT_DATE
#    COMPILE_CURRENT_DATE
#    ${PROJECT_BINARY_DIR}
#    ${PROJECT_SOURCE_DIR}/buildSource/currentDate.cpp 
#    RUN_OUTPUT_VARIABLE CURRENT_DATE 
#)

set(BUILD_DATE "${CURRENT_DATE}" CACHE STRING "current build an time")



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ../inc/
	${Boost_INCLUDE_DIRS}
)

file(GLOB OpcUaServer_SRC ${PROJECT_SOURCE_DIR}/OpcUaServer/*/*.cpp)
add_executable(
    OpcUaServer
    ${OpcUaServer_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaServer
    OpcUaStackCore
    OpcUaStackServer
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS OpcUaServer DESTINATION ${BIN_DIR})
