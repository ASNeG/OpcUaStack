#!/usr/bin/sh

cd OpcUaStackCore_lib
cmake CMakeLists.txt
make
cd ..


cd OpcUaStackCore_Test
cmake CMakeLists.txt
make
cd ..

if [ $1 = "run" ] ;
then
    cd OpcUaStackCore_Test
    ./Unittest
    cd ..
fi
