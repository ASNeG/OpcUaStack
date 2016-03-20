#!/bin/bash

. ./TestConfig.sh

OpcUaClient \
 -Command NodeSetFilter	-SrcNodeSetName "data/NodeSetTest1.xml" -DstNodeSetName "NodeSet-Static.xml" -NamespaceUri "http://yourorganisation.org/Test-Server/"  
