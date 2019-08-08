# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build OpcUaGenerator
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)

file(
    GLOB OpcUaGenerator_SRC 
    ./OpcUaGenerator/OpcUaDataTypeGenerator.cpp
	./OpcUaGenerator/OpcUaEnumTypeGenerator.cpp
	./OpcUaGenerator/OpcUaEventTypeGenerator.cpp
	./OpcUaGenerator/OpcUaObjectTypeGenerator.cpp
	./OpcUaGenerator/OpcUaVariableTypeGenerator.cpp
)

add_library(
    OpcUaGenerator 
    SHARED 
    ${OpcUaGenerator_SRC}
)

target_link_libraries(
    OpcUaGenerator
    OpcUaStackCore
    OpcUaStackClient
    OpcUaStackServer
    ${CMAKE_DL_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    ${OPENSSL_LIBRARIES}
)

set_target_properties(
    OpcUaGenerator
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

get_target_property(
    OpcUaGeneratorLibName 
    OpcUaGenerator
    OUTPUT_NAME
)

if (WIN32)
    set_target_properties(
    	OpcUaGenerator
    	PROPERTIES OUTPUT_NAME 
    	"OpcUaGenerator${VERSION_MAJOR}"
    )
	set(OPCUAGENERATOR_LIB_NAME OpcUaGenerator${VERSION_MAJOR}.lib)
else()
    set(OPCUAGENERATOR_LIB_NAME libOpcUaGenerator.so.${VERSION_MAJOR})
endif()

message(STATUS "OpcUaGenerator")
message(STATUS "  library name: ${OPCUAGENERATOR_LIB_NAME}")

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install generator library
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaGenerator OpcUaGenerator/*.h)

install(
    TARGETS OpcUaGenerator 
    DESTINATION ${INSTALL_PREFIX}/lib
    COMPONENT libraries
)

install(
    FILES ${INC_OpcUaGenerator} 
    DESTINATION ${INSTALL_PREFIX}/include/OpcUaStack${VERSION_MAJOR}/OpcUaGenerator
    COMPONENT headers
)

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
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaDataTypeGeneratorMain.cpp
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
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaEnumTypeGeneratorMain.cpp
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
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaEventTypeGeneratorMain.cpp
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
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaVariableTypeGeneratorMain.cpp
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
    ${PROJECT_SOURCE_DIR}/OpcUaGenerator/OpcUaObjectTypeGeneratorMain.cpp
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
# install generators
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
