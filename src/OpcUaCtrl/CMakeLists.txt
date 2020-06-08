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
    GLOB OpcUaCtrl_SRC 
    ${PROJECT_SOURCE_DIR}/OpcUaCtrl/*.cpp
)

add_executable(
    OpcUaCtrl${VERSION_MAJOR}
    ${OpcUaCtrl_SRC}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(
    OpcUaCtrl${VERSION_MAJOR}
    OpcUaStackCore
    OpcUaStackServer
    OpcUaStackClient
    ${CMAKE_DL_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
)

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

install(
    TARGETS OpcUaCtrl${VERSION_MAJOR} 
    DESTINATION ${INSTALL_PREFIX}/bin
    COMPONENT applications
)

install(
    FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/openssl.cnf 
    DESTINATION /etc/OpcUaStack/ssl
)

install(
	FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_cert.sh 
	DESTINATION /etc/OpcUaStack/script
)
install(
	FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_im_cert.sh 
	DESTINATION /etc/OpcUaStack/script
)

install(
	FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_cert.pem 
	DESTINATION /etc/OpcUaStack/pki
)
install(
	FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_key.pem 
	DESTINATION /etc/OpcUaStack/pki
)
