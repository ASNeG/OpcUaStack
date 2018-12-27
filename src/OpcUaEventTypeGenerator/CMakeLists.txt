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
    GLOB OpcUaEventTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaEventTypeGenerator/*.cpp
)


add_executable(
    OpcUaEventTypeGenerator${VERSION_MAJOR}
    ${OpcUaEventTypeGenerator_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaEventTypeGenerator${VERSION_MAJOR}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    OpcUaStackCore
    OpcUaStackClient
    OpcUaStackServer
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    TARGETS OpcUaEventTypeGenerator${VERSION_MAJOR} 
    DESTINATION ${INSTALL_PREFIX}/bin
    COMPONENT tools
)
