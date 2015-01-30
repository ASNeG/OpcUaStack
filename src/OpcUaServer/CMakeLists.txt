# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# configuration
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
set(CONF_DIR "${CMAKE_INSTALL_PREFIX}/etc/OpcUaStack" CACHE STRING "configuration directory")
set(LOG_DIR "${CMAKE_INSTALL_PREFIX}/var/log/OpcUaStack" CACHE STRING "log output directory")

#configure_file(
#    "${PROJECT_SOURCE_DIR}/OpcUaApplicationDemo/Application/Config.h.in"
#    "${PROJECT_BINARY_DIR}/Config.h"
#)

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
    ../inc/
)

add_definitions(-DBOOST_DYN_LINK)

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
install(TARGETS OpcUaServer DESTINATION bin)
#install(FILES ${PROJECT_SOURCE_DIR}/OpcUaApplicationDemo/Config/OpcUaApplicationDemo.ini DESTINATION ${CONF_DIR}) 
