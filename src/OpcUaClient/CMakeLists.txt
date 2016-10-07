# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# configuration
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

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

file(GLOB OpcUaClient_SRC ${PROJECT_SOURCE_DIR}/OpcUaClient/*/*.cpp)
add_executable(
    OpcUaClient
    ${OpcUaClient_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaClient
    OpcUaStackCore
    OpcUaStackServer
    OpcUaStackClient
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
install(TARGETS OpcUaClient DESTINATION ${BIN_DIR})
