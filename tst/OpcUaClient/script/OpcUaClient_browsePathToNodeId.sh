#!/bin/bash

. ./TestConfig.sh

${OpcUaClient} \
 -Command Connect 		-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "1:TestFolder"\
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "1:TestFolder" -BrowseName "1:BuildInType"\
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "1:TestFolder" -BrowseName "1:BuildInType" -BrowseName "1:Int32"\
 -Command Disconnect 
