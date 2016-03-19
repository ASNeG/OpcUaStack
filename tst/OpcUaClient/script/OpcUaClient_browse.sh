#!/bin/bash

. ./TestConfig.sh

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse 
# -Command Disconnect 


OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse -NodeId "i=84" -NodeId "i=85" -NodeId "i=87" 
# -Command Disconnect

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse -NodeId "i=84" -NodeId "i=85" -NodeId "i=87" -Direction "Forward" 
# -Command Disconnect

OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Browse -NodeId "i=84" -NodeId "i=85" -NodeId "i=87" -Direction "Forward" -Recursive "On" 
# -Command Disconnect
