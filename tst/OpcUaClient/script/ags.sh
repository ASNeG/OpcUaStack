#!/bin/bash

. ./TestConfig.sh
EndpointUrl=opc.tcp://127.0.0.1:4880


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command NodeSetServer	-NodeSetName "NodeSet-ags.xml"  
# -Command Disconnect 
