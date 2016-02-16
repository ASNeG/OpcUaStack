#!/bin/bash

EndpointUrl=opc.tcp://192.168.0.142:4841

OpcUaClient \
 -Command Connect -Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command Read -NodeId "ns=1;s=node1" -NodeId "ns1;s=node2" \
 -Command Delay -Timeout 1000 \
 -Command Read -NodeId "ns=1;s=node1" -NodeId "ns1;s=node2" \
 -Command Disconnect -Session "TestSession"
