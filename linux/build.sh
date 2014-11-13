#!/usr/bin/sh

OpcUaStackCore_lib() {
    cd OpcUaStackCore_lib
    cmake CMakeLists.txt
    make
    cd ..
}

OpcUaStackClient_lib() {
    cd OpcUaStackClient_lib
    cmake CMakeLists.txt
    make
    cd ..
}

OpcUaStackServer_lib() {
    cd OpcUaStackServer_lib
    cmake CMakeLists.txt
    make
    cd ..
}


OpcUaStackCore_Test() {
    cd OpcUaStackCore_Test
    cmake CMakeLists.txt
    make
    cd ..
}

OpcUaStackCore_Test_run() {
    cd OpcUaStackCore_Test
    ./Unittest
    cd .. 
}


# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
#  all
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

if [ $1 = "all" ] ;
then
    OpcUaStackCore_lib
    OpcUaStackClient_lib
    OpcUaStackServer_lib
    OpcUaStackCore_Test
    OpcUaStackCore_Test_run
fi

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# build
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if [ $1 = "build-all" ] ;
then
    OpcUaStackCore_lib
    OpcUaStackClient_lib
    OpcUaStackServer_lib
    OpcUaStackCore_Test
    OpcUaStackClientServer_Test
fi

if [ $1 = "build-lib" ] ;
then
    OpcUaStackCore_lib
    OpcUaStackClient_lib
    OpcUaStackServer_lib
fi

if [ $1 = "build-test" ] ;
then
    OpcUaStackCore_Test
fi



# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# test 
# 
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
if [ $1 = "test-all" ] ;
then
    OpcUaStackCore_Test_run
    OpcUaStackClientServer_Test_run
fi

if [ $1 = "test-core" ] ;
then
    OpcUaStackCore_Test_run
fi

if [ $1 = "test-clientserver" ] ;
then
    OpcUaStackClientServer_Test_run
fi
