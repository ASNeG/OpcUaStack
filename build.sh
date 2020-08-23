#!/bin/bash

#
# Local test:
#
# Normal test:
#   sh build.sh -t tst -s ~/.ASNeG/
#
# Enable real server test: 
#   sh build.sh -t tst -s ~/.ASNeG/ --test-with-server opc.tcp://127.0.0.1:8889   
#
# Enable MQTT:
#   export USE_MOSQUITTO_CLIENT=1
#

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
  echo "build.sh --target(-t) TARGET [OPTIONS] ..."
   echo "--target, -t: sets one of the folowing target:"
   echo " info  - create version and dependency files"
   echo " local - create local build and install in local directory defined in --install-prefix" 
   echo " deb   - create deb package"
   echo " rpm   - create rpm package"
   echo " tst   - build unit application"
   echo " clean - delete all build directories"
   echo ""
   echo "--stack-prefix, -s STACK_PREFIX:  set the path to directory"
   echo "\twhere the OpcUaStack is installed (default: /)"
   echo ""
   echo "--install-prefix, -i INSTALL_PREFIX:  is the path to directory"
   echo "\twhere the application should be installed (default: ${HOME}/.ASNeG)"
   echo "--jobs, -j JOB_COUNT: sets the number of the jobs of make"
   echo ""
   echo "--build-type, -B BUILD_TYPE:  set the build types (Debug | Release). By default, it is Debug type"
   echo "--test-with-server URI:  build client test for real OPC UA server. By default, empty "
   echo "--debug-output: activate debug output"

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
    set -e
    rm -rf build_info*
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

    # check build directoriy
    if [ ! -d "build_local_${BUILD_TYPE}" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_local_${BUILD_TYPE}
        mkdir build_local_${BUILD_TYPE}

    else
        BUILD_FIRST=0
    fi
    cd build_local_${BUILD_TYPE}

    # build local
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
        set -x
        cmake ${DEBUG_OUTPUT} \
	      ../src \
              "${CMAKE_GENERATOR_LOCAL}" \
              -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
	      -DGIT_COMMIT="${GIT_COMMIT}" \
	      -DGIT_BRANCH="${GIT_BRANCH}" 
        RESULT=$?
        set +x
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi
    else
        set -x
        cmake . ${DEBUG_OUTPUT}
        RESULT=$?
        set +x
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi

    fi

    # install local
    make DESTDIR="${INSTALL_PREFIX}" install -j"${JOBS}"
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
    set -e
    rm -rf build_local*
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

    # check build directoriy
    if [ ! -d "build_deb_${BUILD_TYPE}" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_deb_${BUILD_TYPE}
        mkdir build_deb_${BUILD_TYPE}
    else
        BUILD_FIRST=0
    fi
    cd build_deb_${BUILD_TYPE}


    # build package
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
 
        cmake ../src \
	    ${DEBUG_OUTPUT} \
            "${CMAKE_GENERATOR_LOCAL}" \
            -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
	    -DGIT_COMMIT="${GIT_COMMIT}" \
	    -DGIT_BRANCH="${GIT_BRANCH}" \
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
        cmake . ${DEBUG_OUTPUT}
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi     
    fi

    make package -j"${JOBS}"
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
    set -e
    rm -rf build_deb*
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
    if [ ! -d "build_rpm_${BUILD_TYPE}" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_rpm_${BUILD_TYPE}
        mkdir build_rpm_${BUILD_TYPE}
    else
        BUILD_FIRST=0
    fi
    cd build_rpm_${BUILD_TYPE}

    # build package
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
        cmake ../src \
	    ${DEBUG_OUTPUT} \
            "${CMAKE_GENERATOR_LOCAL}" \
            -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
            -DGIT_COMMIT="${GIT_COMMIT}" \
	    -DGIT_BRANCH="${GIT_BRANCH}" \ 
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
        cmake . ${DEBUG_OUTPUT}
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi
    fi

    make package -j"${JOBS}"
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
    set -e
    rm -rf build_rpm*
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build test
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_tst()
{    
    echo "build tst start"

    # build tst directory
    if [ ! -d "build_tst_${BUILD_TYPE}" ] ;
    then
        BUILD_FIRST=1
        rm -rf build_tst_${BUILD_TYPE}
        mkdir build_tst_${BUILD_TYPE}
    else
        BUILD_FIRST=0
    fi
    cd build_tst_${BUILD_TYPE}

    # build tst
    if [ ${BUILD_FIRST} -eq 1 ] ;
    then
        cmake ../tst \
	     ${DEBUG_OUTPUT} \
  	     "${CMAKE_GENERATOR_LOCAL}" \
	     -DOPCUASTACK_INSTALL_PREFIX="${STACK_PREFIX}" \
             -DTEST_SERVER_URI=${TEST_SERVER_URI} \
             -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
	     -DGIT_COMMIT="${GIT_COMMIT}" \
	     -DGIT_BRANCH="${GIT_BRANCH}" 
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi
    else
        cmake . ${DEBUG_OUTPUT}
        RESULT=$?
        if [ ${RESULT} -ne 0 ] ;
        then
            echo "cmake error"
            return ${RESULT}
        fi
    fi

    make -j"${JOBS}"
    RESULT=$?
     if [ ${RESULT} -ne 0 ] ;
    then
        echo "make error"
        return ${RESULT}
    fi

    return 0
}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# cleanup
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
build_tst_clean()
{
    set -e
    rm -rf build_tst*
}

clean()
{
    build_info_clean
    build_local_clean
    build_deb_clean
    build_rpm_clean
    build_tst_clean
    return 0
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# main
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if [ $# -le 1 ] ; 
then
    usage
    exit 1
fi 


INSTALL_PREFIX="${HOME}/.ASNeG"
STACK_PREFIX="/"
JOBS=1
BUILD_TYPE="Debug"
TEST_SERVER_URI=""
DEBUG_OUTPUT=""
GIT_COMMIT=`git rev-parse HEAD`
GIT_BRANCH=`git rev-parse --abbrev-ref HEAD`

while [ $# -gt 0 ];
do
key="$1"

case $key in
    -t|--target)
    TARGET="$2"
    shift # past argument
    shift # past value
    ;;
    -i|--install-prefix)
    INSTALL_PREFIX="$2"
    shift # past argument
    shift # past value
    ;;
    -s|--stack-prefix)
    STACK_PREFIX="$2"
    shift # past argument
    shift # past value
    ;;
    -j|--jobs)
    JOBS="$2"
    shift # past argument
    shift # past value
    ;;
    -B|--build-type)
    BUILD_TYPE="$2"
    shift # past argument
    shift # past value
    ;;

    --test-with-server)
    TEST_SERVER_URI="$2"
    shift # past flag
    shift # past value
    ;;

    --debug-output) 
    DEBUG_OUTPUT="--debug-output"
    shift # past argument
    ;;

    *)    # unknown option
    shift # past argument
    ;;
esac
done


case ${INSTALL_PREFIX} in
  /*) ;;
  *) INSTALL_PREFIX=${PWD}/${INSTALL_PREFIX} ;;
esac


if [ "${TARGET}" = "info" ] ;
then
    build_info
    exit $?
elif [ "${TARGET}" = "clean" ] ;
then 
    clean 
    exit $?
elif [ "${TARGET}" = "local" ] ;
then 
    build_local
    exit $?
elif [ "${TARGET}" = "deb" ] ;
then 
    build_deb 
    exit $?
elif [ "${TARGET}" = "rpm" ] ;
then 
    build_rpm
    exit $?
elif [ "${TARGET}" = "tst" ] ;
then 
    build_tst
    exit $?
else
    usage
    exit 1
fi
if [ $# -le 1 ] ; 
then
    usage
    exit 1
fi 

