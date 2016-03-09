#!/bin/bash

. ./TestConfig.sh

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Function 	-ObjectNodeId "ns=2;s=Support" -FunctionNodeId "ns=2;s=Support.resetPersistent" \
 -Command Function 	-ObjectNodeId "ns=2;s=Support" -FunctionNodeId "ns=2;s=Support.resetPersistent" \
 -Command Function 	-ObjectNodeId "ns=2;s=Support" -FunctionNodeId "ns=2;s=Support.resetPersistent" \
 -Command Function 	-ObjectNodeId "ns=4;s=Function" -FunctionNodeId "ns=4;i=7004" \
 -Command Function 	-ObjectNodeId "ns=2;s=Support" -FunctionNodeId "ns=2;s=Support.resetPersistent" \
 -Command Disconnect 
