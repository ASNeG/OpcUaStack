# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ./
    ${PROJECT_BINARY_DIR}
    ../src/
	${Boost_INCLUDE_DIRS}
)

file(
	GLOB OpcUaStackCoreTest_SRC 
	${PROJECT_SOURCE_DIR}/unittest.cpp
	${PROJECT_SOURCE_DIR}/OpcUaStackCore/*/*.cpp 
	${PROJECT_SOURCE_DIR}/unittest.cpp
)
add_executable(
    OpcUaStackCoreTest
    ${OpcUaStackCoreTest_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaStackCoreTest
    ${OpcUaStackCore_LIBRARY}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
