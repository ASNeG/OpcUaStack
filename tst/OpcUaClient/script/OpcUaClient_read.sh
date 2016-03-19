#!/bin/bash

. ./TestConfig.sh

gdb --args OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Read		-NodeId "i=2991" \
 -Command Disconnect 
