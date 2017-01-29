#!/bin/bash

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# config section
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
CMAKE_GENERATOR_LOCAL=-G"Eclipse CDT4 - Unix Makefiles"
#OPCUASTACK_INSTALL_PREFIX=${HOME}/install

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

usage()
{
   echo "build.sh (info | local | deb | rpm | tst | clean)"
   echo ""
   echo "  info  - create version and dependency files"
   echo "  local - create local build and install in folder ${HOME}/install"
   echo "  deb   - create deb package"
   echo "  rpm   - create rpm package"
   echo "  tst   - build unit application"
   echo "  clean - delete all build directories"

}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# create version and dependency files
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_info()
{
    echo "version info"

    rm -rf build_info
    mkdir build_info
    cd build_info
    cmake -DCREATE_INFO_FILES=1 ../src/
}

build_info_clean()
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
    if [ ! -d "build_local" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_local
        mkdir build_local
    else
        BUILD_FIRST=0
    fi
    cd build_local


    # build local
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
	: ${OPCUASTACK_INSTALL_PREFIX:=${HOME}/install}
	set -x
	cmake ../src \
	    -DOPCUASTACK_INSTALL_PREFIX=${OPCUASTACK_INSTALL_PREFIX} \
	    "${CMAKE_GENERATOR_LOCAL}" 
        RESULT=$?
	set +x
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    else
        cmake .
        RESULT=$?
	set +x
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    fi

    # install local
    make DESTDIR="${HOME}/install" install
    RESULT=$?
    if [ ${RESULT} -ne 0 ] ;
    then
        echo "make install error"
        return ${RESULT}
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
    if [ ! -d "build_deb" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_deb
        mkdir build_deb
    else
        BUILD_FIRST=0
    fi
    cd build_deb


    # build package
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
	: ${OPCUASTACK_INSTALL_PREFIX:=/}
	cmake ../src \
	    -DOPCUASTACK_INSTALL_PREFIX=${OPCUASTACK_INSTALL_PREFIX} \
	    "${CMAKE_GENERATOR_LOCAL}" \
	    "-DCPACK_BINARY_DEB=1" \
	    "-DCPACK_BINARY_RPM=0" \
            "-DCPACK_BINARY_STGZ=0" \
            "-DCPACK_BINARY_TGZ=0" \
            "-DCPACK_BINARY_TZ=0"
	RESULT=$?
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    else
        cmake .
	RESULT=$?
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    fi

    make package
    RESULT=$?
    if [ ${RESULT} -ne 0 ] ;
    then
        echo "make package error"
        return ${RESULT}
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
    if [ ! -d "build_rpm" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_rpm
        mkdir build_rpm
    else
        BUILD_FIRST=0
    fi
    cd build_rpm


    # build package
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
	: ${OPCUASTACK_INSTALL_PREFIX:=/}
	cmake ../src \
	    -DOPCUASTACK_INSTALL_PREFIX=${OPCUASTACK_INSTALL_PREFIX} \
	    "${CMAKE_GENERATOR_LOCAL}" \
	    "-DCPACK_BINARY_DEB=0" \
	    "-DCPACK_BINARY_RPM=1" \
            "-DCPACK_BINARY_STGZ=0" \
            "-DCPACK_BINARY_TGZ=0" \
            "-DCPACK_BINARY_TZ=0"
        RESULT=$? 
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    else
        cmake .
        RESULT=$? 
	if [ ${RESULT} -ne 0 ] ;
	then
	    echo "cmake error"
	    return ${RESULT}
	fi
    fi

    make package
    RESULT=$?
    if [ ${RESULT} -ne 0 ] ;
    then
        echo "make package error"
        return ${RESULT}
    fi

    return 0
}


build_rpm_clean()
{
    rm -rf build_rpm
}



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build unittest
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_tst()
{    
    echo "build tst start"

    # build tst directory
    if [ ! -d "build_tst" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_tst
        mkdir build_tst
    else
        BUILD_FIRST=0
    fi
    cd build_tst


    # build tst
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
        : ${OPCUASTACK_INSTALL_PREFIX:=${HOME}/install}
        cmake ../tst \
            -DOPCUASTACK_INSTALL_PREFIX=${OPCUASTACK_INSTALL_PREFIX} \
  	    "${CMAKE_GENERATOR_LOCAL}" \
	    -DOPCUASTACK_INSTALL_PREFIX="${HOME}/install"
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi
    else 
        cmake .
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi

    fi

    make 
    RESULT=$?
    if [ ${RESULT} -ne 0 ] ;
    then
        echo "make error"
        return ${RESULT}
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
if [ $# -ne 1 ] ; 
then
    usage
    exit 1
fi 

if [ "$1" = "info" ] ;
then
    build_info
    exit $?
elif [ "$1" = "clean" ] ;
then 
    clean 
elif [ "$1" = "local" ] ;
then 
    build_local
    exit $?
elif [ "$1" = "deb" ] ;
then 
    build_deb 
    exit $?
elif [ "$1" = "rpm" ] ;
then 
    build_rpm
    exit $?
elif [ "$1" = "tst" ] ;
then 
    build_tst
    exit $?
else
    usage
    exit 1
fi
