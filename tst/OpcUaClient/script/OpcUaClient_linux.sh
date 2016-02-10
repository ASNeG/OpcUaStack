#!/bin/bash

EndpointUrl=opc.tcp://192.168.0.142:4841

OpcUaClient \
 -c connect -s "TestSession" -EndpointUrl ${EndpointUrl} \
 -c disconnect 
