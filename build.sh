if [ -z "${CPACK_BINARY_DEB}" ] ; then
    echo "set environment variable CPACK_BINARY_DEB to 1"
    CPACK_BINARY_DEB="1"
fi

if [ -z "${CMAKE_INSTALL_PREFIX}"] ; then
    echo "set environment variable CMAKE_INSTALL_PREFIX to /"
    CMAKE_INSTALL_PREFIX="/"
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
CMAKE_ARGS="${CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
CMAKE_ARGS="${CMAKE_ARGS} -DCPACK_PACKAGING_INSTALL_PREFIX=${CPACK_PACKAGING_INSTALL_PREFIX}"
CMAKE_ARGS="${CMAKE_ARGS} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
echo "CMAKE_ARGS=${CMAKE_ARGS}"

# create build directory and move into it
rm -rf build
mkdir -p build
cd build

# configure cmake
cmake ../src ${CMAKE_ARGS}

#build package
make package

