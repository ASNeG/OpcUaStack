# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# prebuild
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/CMakeOpcUaStack.txt.in"
    "${PROJECT_BINARY_DIR}/CMakeOpcUaStack.txt"
    @ONLY
)

configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/CMakeBoost.txt.in"
    "${PROJECT_BINARY_DIR}/CMakeBoost.txt"
    @ONLY
)

configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/CMakeOpenSSL.txt.in"
    "${PROJECT_BINARY_DIR}/CMakeOpenSSL.txt"
    @ONLY
)


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# install
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
install(
    FILES "${PROJECT_BINARY_DIR}/CMakeOpcUaStack.txt" 
    DESTINATION /usr/share/cmake/OpcUaStack${VERSION_MAJOR}
    COMPONENT tools
)

install(
    FILES "${PROJECT_BINARY_DIR}/CMakeBoost.txt" 
    DESTINATION /usr/share/cmake/OpcUaStack${VERSION_MAJOR}
    COMPONENT tools
)

install(
    FILES "${PROJECT_BINARY_DIR}/CMakeOpenSSL.txt" 
    DESTINATION /usr/share/cmake/OpcUaStack${VERSION_MAJOR}
    COMPONENT tools
)
