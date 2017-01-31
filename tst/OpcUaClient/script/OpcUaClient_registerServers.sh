#!/bin/bash

. ./TestConfig.sh

${OpcUaClient} \
 -Command Connect 	-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command RegisterServer \
 -Command Disconnect 
