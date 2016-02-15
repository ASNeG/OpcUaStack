#!/bin/bash

EndpointUrl=opc.tcp://192.168.0.142:4841

OpcUaClient \
 -Command connect -Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command disconnect -Session "TestSession"
