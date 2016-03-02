#!/bin/bash

EndpointUrl=opc.tcp://127.0.0.1:4841


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse \
 -Command Disconnect 


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse -NodeId "i=84" -NodeId "i=85" -NodeId "i=87" \
 -Command Disconnect
