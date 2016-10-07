#!/bin/bash

. ./TestConfig.sh
EndpointUrl=opc.tcp://192.168.50.151:14000


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command NodeSetServer	-NodeSetName "NodeSet-daq.xml" -NamespaceUri "http://BakerHughes.com/DAQ/HSE/"   
# -Command Disconnect 

