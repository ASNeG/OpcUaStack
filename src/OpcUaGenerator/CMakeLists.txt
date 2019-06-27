# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build OpcUaDataTypeGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaDataTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaDataTypeGenerator.cpp
)


add_executable(
    OpcUaDataTypeGenerator${VERSION_MAJOR}
    ${OpcUaDataTypeGenerator_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaDataTypeGenerator${VERSION_MAJOR}
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
# build OpcUaEnumTypeGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaEnumTypeGenerator_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaEnumTypeGenerator.cpp
)


add_executable(
    OpcUaEnumTypeGenerator${VERSION_MAJOR}
    ${OpcUaEnumTypeGenerator_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaEnumTypeGenerator${VERSION_MAJOR}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
    OpcUaStackCore
    OpcUaStackClient
    OpcUaStackServer
)

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
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    TARGETS OpcUaDataTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaEnumTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaEventTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaVariableTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)

install(
    TARGETS OpcUaObjectTypeGenerator${VERSION_MAJOR} 
    DESTINATION /usr/bin
    COMPONENT tools
)
