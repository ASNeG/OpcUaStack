#!/bin/bash

. ./TestConfig.sh

${OpcUaClient} \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Function 	-ObjectNodeId "ns=6;s=Function" -FunctionNodeId "ns=6;s=func1" \
 -Command Function 	-ObjectNodeId "ns=6;s=Function" -FunctionNodeId "ns=6;s=func2" -InputValue "UInt32:1234" -InputValue "UInt32:1234" \
 -Command Function 	-ObjectNodeId "ns=6;s=Function" -FunctionNodeId "ns=6;s=func3" -InputValue "UInt32:1234" -InputValue "UInt32:1234" \
 -Command Function 	-ObjectNodeId "ns=6;s=Function" -FunctionNodeId "ns=6;s=funcMult" -InputValue "UInt32:5" -InputValue "UInt32:10" \
 -Command Disconnect 
