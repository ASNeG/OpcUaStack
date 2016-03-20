#!/bin/bash

. ./TestConfig.sh

OpcUaClient \
 -Command NodeSetFilter	-SrcNodeSetName "data/NodeSet-Static.xml" -DstNodeSetName "NodeSet-Static.xml" -NamespaceUri "http://yourorganisation.org/Test-Server/"  
