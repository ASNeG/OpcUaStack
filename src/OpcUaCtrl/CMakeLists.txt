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


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/openssl.cnf DESTINATION /etc/OpcUaStack4/ssl)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_cert.sh DESTINATION /etc/OpcUaStack4/script)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_im_cert.sh DESTINATION /etc/OpcUaStack4/script)

install(FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_cert.pem DESTINATION /etc/OpcUaStack4/pki)
install(FILES ${PROJECT_SOURCE_DIR}/OpcUaCtrl/Config/asneg_ca_key.pem DESTINATION /etc/OpcUaStack4/pki)

