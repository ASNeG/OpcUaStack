
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ../inc
)
file(GLOB OpcUaStackUtility_SRC ./OpcUaStackUtility/*/*.cpp)
add_library(OpcUaStackUtility SHARED ${OpcUaStackUtility_SRC})


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackUtility_Utility ../inc/OpcUaStackUtility/Utility/*.h)


install(TARGETS OpcUaStackUtility DESTINATION lib/OpcUaStack)
install(FILES ${INC_OpcUaStackUtility_Utility} DESTINATION include/OpcUaStack/OpcUaStackUtility/Utility)
