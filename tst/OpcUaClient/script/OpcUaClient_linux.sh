#!/bin/bash

EndpointUrl=opc.tcp://192.168.0.142:4841

OpcUaClient \
 -command connect -Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -command disconnect -Session "TestSession"
