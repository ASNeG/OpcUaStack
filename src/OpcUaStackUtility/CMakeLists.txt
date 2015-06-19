
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ../inc
	${Boost_INCLUDE_DIRS}
)
file(GLOB OpcUaStackUtility_SRC ./OpcUaStackUtility/*/*.cpp)
add_library(OpcUaStackUtility SHARED ${OpcUaStackUtility_SRC})

target_link_libraries(
    OpcUaStackUtility
	OpcUaStackCore
	OpcUaStackClient
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
file(GLOB INC_OpcUaStackUtility_NodeSet OpcUaStackUtility/NodeSet/*.h)


install(TARGETS OpcUaStackUtility DESTINATION ${LIB_DIR}/OpcUaStack)
install(FILES ${INC_OpcUaStackUtility_NodeSet} DESTINATION ${INC_DIR}/OpcUaStack/OpcUaStackUtility/NodeSet)
