#!/bin/bash

. ./TestConfig.sh

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command NodeSetServer	-NodeSetName "NodeSet-Static.xml" -NamespaceUri "http://yourorganisation.org/Test-Server/"  
# -Command Disconnect 
