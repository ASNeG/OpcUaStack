if [ -z "${CPACK_BINARY_DEB}" ] ; then
    echo "set environment variable CPACK_BINARY_DEB to 0"
    CPACK_BINARY_DEB="1"
fi

if [ -z "${CPACK_BINARY_STGZ}" ] ; then
    echo "set environment variable CPACK_BINARY_STGZ to 0"
    CPACK_BINARY_STGZ="0"
fi

if [ -z "${CPACK_BINARY_TGZ}" ] ; then
    echo "set environment variable CPACK_BINARY_TGZ to 0"
    CPACK_BINARY_TGZ="0"
fi

if [ -z "${CPACK_SOURCE_TBZ2}" ] ; then
    echo "set environment variable CPACK_SOURCE_TBZ2 to 0"
    CPACK_SOURCE_TBZ2="0"
fi

if [ -z "${CPACK_SOURCE_TGZ}" ] ; then
    echo "set environment variable CPACK_SOURCE_TGZ to 0"
    CPACK_SOURCE_TGZ="0"
fi

if [ -z "${CPACK_SOURCE_TZ}" ] ; then
    echo "set environment variable CPACK_SOURCE_TZ to 0"
    CPACK_SOURCE_TZ="0"
fi

if [ -z "${CPACK_BINARY_TZ}" ] ; then
    echo "set environment variable CPACK_BINARY_TZ to 0"
    CPACK_BINARY_TZ="0"
fi

if [ -z "${CMAKE_INSTALL_PREFIX}"] ; then
    echo "set environment variable CMAKE_INSTALL_PREFIX to ${HOME}/install"
    CMAKE_INSTALL_PREFIX="${HOME}/install"
fi

if [ -z "${CPACK_PACKAGING_INSTALL_PREFIX}"] ; then
    echo "set environment variable CPACK_PACKAGING_INSTALL_PREFIX to /"
    CPACK_PACKAGING_INSTALL_PREFIX="/"
fi

if [ -z "${CMAKE_BUILD_TYPE}" ] ; then
    echo "set environment variable CMAKE_BUILD_TYPE to Debug"
    CMAKE_BUILD_TYPE="Debug"
fi

CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_BINARY_DEB=${CPACK_BINARY_DEB}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_BINARY_STGZ=${CPACK_BINARY_STGZ}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_BINARY_TGZ=${CPACK_BINARY_TGZ}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_BINARY_TZ=${CPACK_BINARY_TZ}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_SOURCE_TBZ2=${CPACK_SOURCE_TBZ2}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_SOURCE_TGZ=${CPACK_SOURCE_TGZ}" 
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_SOURCE_TZ=${CPACK_SOURCE_TZ}"
CMAKE_ARGS="${CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_PACKAGING_INSTALL_PREFIX=${CPACK_PACKAGING_INSTALL_PREFIX}"
CMAKE_ARGS="${CMAKE_ARGS} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
echo "CMAKE_ARGS=${CMAKE_ARGS}"

# create build directory and move into it
rm -rf build_local
mkdir -p build_local
cd build_local

# configure cmake
cmake -G"Eclipse CDT4 - Unix Makefiles" ../src ${CMAKE_ARGS}

#build and install
make
make install

