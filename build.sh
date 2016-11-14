#!/bin/bash

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# config section
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
CMAKE_GENERATOR_LOCAL=-G"Eclipse CDT4 - Unix Makefiles"

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

usage()
{
   echo "build.sh [info, local]"
}


version_info()
{
    echo "version info"

    rm -rf build_info
    mkdir build_info
    cd build_info
    cmake -DCREATE_INFO_FILES=1 ../src/
}

build_local()
{
    echo "build local start"

    # build local directory
    rm -rf build_local
    mkdir build_local
    cd build_local

    # install build local
    set -x
    cmake ../src \
          "${CMAKE_GENERATOR_LOCAL}" 
    set +x
    if [ $? -ne 0 ] ;
    then
        echo "cmake error"
        return $?
    fi
    make DESTDIR="${HOME}/install" install
     if [ $? -ne 0 ] ;
    then
        echo "make install error"
        return $?
    fi

    return 0
}


build_local_clean()
{
    rm -rf build_local
}


build_package()
{
    echo "build package start"

    # check if debian package to be produced
    if which dpkg > /dev/null ;
    then
        echo "build deb package enable"
        CPACK_BINARY_DEB="-DCPACK_BINARY_DEB=1"
    else
        echo "build deb package disable"
        CPACK_BINARY_DEB="-DCPACK_BINARY_DEB=0"
    fi

    # check if rpm package to be produced
    if which rpmbuild > /dev/null ;
    then
        echo "build rpm package enable"
        CPACK_BINARY_RPM="-DCPACK_BINARY_RPM=1"
    else
        echo "build rpm package disable"
        CPACK_BINARY_RPM="-DCPACK_BINARY_RPM=0"
    fi
    
    # build package directory
    rm -rf build_package
    mkdir build_package
    cd build_package

    # build package
   echo "${CPACK_BINARY}"
    cmake ../src \
        "${CMAKE_GENERATOR_LOCAL}" \
        ${CPACK_BINARY_DEB} \
        ${CPACK_BINARY_RPM} 
    if [ $? -ne 0 ] ;
    then
        echo "cmake error"
        return $?
    fi
    make package
    if [ $? -ne 0 ] ;
    then
        echo "make package error"
        return $?
    fi

    return 0
}


build_package_clean()
{
    rm -rf build_package
}

build_tst()
{    
    echo "build tst start"

    # build tst directory
    rm -rf build_tst
    mkdir build_tst
    cd build_tst

    # build tst
    cmake ../tst \
  	"${CMAKE_GENERATOR_LOCAL}" \
	-DINSTALL_PREFIX_OpcUaStack="${HOME}/install"
    if [ $? -ne 0 ] ;
    then
        echo "cmake error"
        return $?
    fi
    make 
     if [ $? -ne 0 ] ;
    then
        echo "make error"
        return $?
    fi



     return 0
}


build_tst_clean()
{
    rm -rf build_tst
}

clean()
{
    build_local_clean
    build_package_clean
    build_tst_clean
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# main
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if [ $# -ne 1 ] ; 
then
    usage
    exit
fi

if [ "$1" = "info" ] ;
then
    version_info
    exit $?
elif [ "$1" = "local" ] ;
then 
    build_local
    exit $?
else
    usage
fi
