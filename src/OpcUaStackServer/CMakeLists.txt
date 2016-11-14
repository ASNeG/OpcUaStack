# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
)

file(
    GLOB OpcUaStackServer_SRC 
    ./OpcUaStackServer/*/*.cpp
)

add_library(
    OpcUaStackServer 
    SHARED 
    ${OpcUaStackServer_SRC}
)

target_link_libraries(
    OpcUaStackServer
    OpcUaStackCore
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
)

set_target_properties(
    OpcUaStackServer
    PROPERTIES 
    VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
    SOVERSION ${VERSION_MAJOR}
)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
file(GLOB INC_OpcUaStackServer_Server OpcUaStackServer/Server/*.h)
file(GLOB INC_OpcUaStackServer_AddressSpaceModel OpcUaStackServer/AddressSpaceModel/*.h)
file(GLOB INC_OpcUaStackServer_Application OpcUaStackServer/Application/*.h)
file(GLOB INC_OpcUaStackServer_InformationModel OpcUaStackServer/InformationModel/*.h)
file(GLOB INC_OpcUaStackServer_NodeSet OpcUaStackServer/NodeSet/*.h)
file(GLOB INC_OpcUaStackServer_SecureChannel OpcUaStackServer/SecureChannel/*.h)
file(GLOB INC_OpcUaStackServer_ServiceManager OpcUaStackServer/ServiceManager/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSet OpcUaStackServer/ServiceSet/*.h)
file(GLOB INC_OpcUaStackServer_ServiceSetApplication OpcUaStackServer/ServiceSetApplication/*.h)


install(TARGETS OpcUaStackServer DESTINATION /usr/local/lib)
install(FILES ${INC_OpcUaStackServer_Server} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/Server)
install(FILES ${INC_OpcUaStackServer_AddressSpaceModel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/AddressSpaceModel)
install(FILES ${INC_OpcUaStackServer_Application} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/Application)
install(FILES ${INC_OpcUaStackServer_InformationModel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/InformationModel)
install(FILES ${INC_OpcUaStackServer_NodeSet} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/NodeSet)
install(FILES ${INC_OpcUaStackServer_SecureChannel} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/SecureChannel)
install(FILES ${INC_OpcUaStackServer_ServiceManager} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceManager)
install(FILES ${INC_OpcUaStackServer_ServiceSet} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceSet)
install(FILES ${INC_OpcUaStackServer_ServiceSetApplication} DESTINATION /usr/include/OpcUaStack${VERSION_MAJOR}/OpcUaStackServer/ServiceSetApplication)
