#!/bin/bash

. ./TestConfig.sh
EndpointUrl=opc.tcp://127.0.0.1:8889


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command NodeSetServer	-NodeSetName "NodeSet-ASNeG-Demo.xml"  
# -Command Disconnect 
