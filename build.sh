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
   echo "build.sh <Command>"
   echo ""
   echo "Commands:"
   echo "  info" 
   echo "    create version and dependency files"
   echo "  local [renew]"
   echo "    create or renew local build and install in folder ${HOME}/install"
   echo "  deb [renew]"
   echo "    create or renew deb package"
   echo "  rpm"
   echo "    create or renew rpm package"
   echo "  clean"
   echo "    delete all build directories"
}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# create version and dependency files
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
version_info()
{
    echo "version info"

    rm -rf build_info
    mkdir build_info
    cd build_info
    cmake -DCREATE_INFO_FILES=1 ../src/
}

version_info_clean()
{
    rm -rf build_info
}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# 
# build and install local
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_local()
{
    echo "build local start"

    # build local directory
    rm -rf build_local
    mkdir build_local
    cd build_local

    # build local
    set -x
    cmake ../src \
          "${CMAKE_GENERATOR_LOCAL}" 
    set +x
    if [ $? -ne 0 ] ;
    then
        echo "cmake error"
        return $?
    fi

    # install local
    make DESTDIR="${HOME}/install" install
     if [ $? -ne 0 ] ;
    then
        echo "make install error"
        return $?
    fi

    return 0
}


build_local_renew()
{
    echo "renew local start"

    # build local directory
    if [ ! -d "build_local" ] ; 
    then
        echo "error - directory build_local do not exist"
        return 1;
    fi
    cd build_local

    # build local
    set -x
    cmake .
    set +x
    if [ $? -ne 0 ] ;
    then
        echo "cmake error"
        return $?
    fi

    # install local
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


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build deb package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_deb()
{
    echo "build deb package start"

    # check if debian package to be produced
    if which dpkg > /dev/null ;
    then
        echo "build deb package enable"
    else
        echo "build deb package disable"
        return -1
    fi

    # build package directory
    rm -rf build_deb
    mkdir build_deb
    cd build_deb

    # build package
    cmake ../src \
        "${CMAKE_GENERATOR_LOCAL}" \
        "-DCPACK_BINARY_DEB=1" \
        "-DCPACK_BINARY_RPM=0" 
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

build_deb_renew()
{
    echo "renew deb package start"

    # build package directory
    if [ ! -d "build_deb" ] ; 
    then
        echo "error - directory build_deb do not exist"
        return 1;
    fi
    cd build_deb

    # build package
    cmake .
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


build_deb_clean()
{
    rm -rf build_deb
}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build rpm package
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_rpm()
{
    echo "build rpm package start"

    # check if rpm package to be produced
    if which rpmbuild > /dev/null ;
    then
        echo "build rpm package enable"
    else
        echo "build rpm package disable"
        return -1
    fi
    
    # build package directory
    rm -rf build_rpm
    mkdir build_rpm
    cd build_rpm

    # build package
   echo "${CPACK_BINARY}"
    cmake ../src \
        "${CMAKE_GENERATOR_LOCAL}" \
        "-DCPACK_BINARY_DEB=0" \
        "-DCPACK_BINARY_RPM=1"
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


build_rpm_renew()
{
    echo "renew rpm package start"

    # build package directory
    if [ ! -d "build_rpm" ] ; 
    then
        echo "error - directory build_rpm do not exist"
        return 1;
    fi
    cd build_rpm

    # build package
   echo "${CPACK_BINARY}"
    cmake .
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



build_rpm_clean()
{
    rm -rf build_rpm
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
    build_info_clean
    build_local_clean
    build_deb_clean
    build_rpm_clean
    build_tst_clean
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# main
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if [ $# -eq 1 ] ; 
then
    RENEW=0
elif [ $# -eq 2 ] ;
then
    if [ "$2" = "renew" ] ;
    then
        RENEW=1
    else
        usage
        exit 1
    fi
else
    usage
    exit 1
fi 

if [ "$1" = "info" ] ;
then
    version_info
    exit $?
elif [ "$1" = "clean" ] ;
then 
    clean 
elif [ "$1" = "local" ] ;
then 
    if [ ${RENEW} -eq 1 ] ;
    then
        build_local_renew
    else
        build_local
    fi 
    exit $?
elif [ "$1" = "deb" ] ;
then 
    if [ ${RENEW} -eq 1 ] ;
    then
        build_deb_renew
    else
        build_deb 
    fi
    exit $?
elif [ "$1" = "rpm" ] ;
then 
    if [ ${RENEW} -eq 1 ] ;
    then
        build_rpm_renew
    else 
        build_rpm
    fi 
    exit $?
else
    usage
fi

exit 0
