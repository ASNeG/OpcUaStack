#!/bin/bash

#EndpointUrl=opc.tcp://127.0.0.1:8888
EndpointUrl=opc.tcp://192.168.122.99:48010


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command ReadNodeSet 	-NodeId "ns=2;s=Demo.Static.Scalar.Double" 
 -Command Disconnect 
