#!/bin/bash

. ./TestConfig.sh

${OpcUaClient} \
 -Command NodeSetFilter	-SrcNodeSetName "data/NodeSetTest1.xml" -DstNodeSetName "NodeSet1.xml" -NamespaceUri "http://yourorganisation.org/Test-Server/"  

${OpcUaClient} \
 -Command NodeSetFilter	-SrcNodeSetName "data/NodeSetTest2.xml" -DstNodeSetName "NodeSet2.xml" 
