#!/bin/bash

. ./TestConfig.sh

gdb --args OpcUaClient \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command NodeSet
# -Command Disconnect 
