# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build OpcUaEventTypeGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaEventTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaEventTypeGenerator.cpp
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
    OpcUaStackCore
    OpcUaStackClient
    OpcUaStackServer
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build OpcUaObjectTypeGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaObjectTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaObjectTypeGenerator.cpp
)


add_executable(
    OpcUaObjectTypeGenerator${VERSION_MAJOR}
    ${OpcUaObjectTypeGenerator_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaObjectTypeGenerator${VERSION_MAJOR}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    OpcUaStackCore
    OpcUaStackClient
    OpcUaStackServer
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build OpcUaVariableTypeGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaVariableTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaVariableTypeGenerator.cpp
)


add_executable(
    OpcUaVariableTypeGenerator${VERSION_MAJOR}
    ${OpcUaVariableTypeGenerator_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaVariableTypeGenerator${VERSION_MAJOR}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
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
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaObjectTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaVariableTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)
