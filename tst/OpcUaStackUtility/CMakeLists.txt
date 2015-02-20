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
    ../inc/
	${Boost_INCLUDE_DIRS}
)

file(
	GLOB OpcUaStackUtilityTest_SRC 
	${PROJECT_SOURCE_DIR}/unittest.cpp
	${PROJECT_SOURCE_DIR}/OpcUaStackUtility/*/*.cpp 
	${PROJECT_SOURCE_DIR}/unittest.cpp
)
add_executable(
    OpcUaStackUtilityTest
    ${OpcUaStackUtilityTest_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaStackUtilityTest
    ${OpcUaStackCore_LIBRARY}
    ${OpcUaStackClient_LIBRARY}
    ${OpcUaStackServer_LIBRARY}
    ${OpcUaStackUtility_LIBRARY}
    ${CMAKE_DL_LIBS}
    ${pthread}
    ${Boost_LIBRARIES}
)
