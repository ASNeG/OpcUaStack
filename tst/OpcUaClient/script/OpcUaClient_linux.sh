#!/bin/bash

#EndpointUrl=opc.tcp://127.0.0.1:8888
EndpointUrl=opc.tcp://192.168.122.99:48010


OpcUaClient \
 -help

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Write 	-NodeId "ns=2;s=Demo.Static.Scalar.Double" -Value Double:1.1  -NodeId "ns=2;s=Demo.Static.Scalar.Int32" -Value Int32:123 \
 -Command Read 		-NodeId "ns=2;s=Demo.Static.Scalar.Double" -NodeId "ns=2;s=Demo.Static.Scalar.Int32" \
 -Command Delay 	-Timeout 1000 \
 -Command ReadH         -NodeId "ns=2;s=Demo.History.DoubleWithHistory" \
 -Command Disconnect 
