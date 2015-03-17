
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}
)

add_definitions(-DBOOST_DYN_LINK)

file(GLOB OpcUaServerApplicationDemo_SRC ${PROJECT_SOURCE_DIR}/OpcUaServerApplicationDemo/*/*.cpp)
add_library(OpcUaServerApplicationDemo SHARED ${OpcUaServerApplicationDemo_SRC})


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(TARGETS OpcUaServerApplicationDemo DESTINATION lib/OpcUaStack)
