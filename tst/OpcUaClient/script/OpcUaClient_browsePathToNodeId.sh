#!/bin/bash

. ./TestConfig.sh

${OpcUaClient} \
 -Command Connect 		-Session "TestSession" -EndpointUrl ${EndpointUrl} \
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "2:TestFolder"\
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "2:TestFolder" -BrowseName "2:BuildInType"\
 -Command BrowsePathToNodeId 	-NodeId "i=85" -BrowseName "2:TestFolder" -BrowseName "2:BuildInType" -BrowseName "2:Int32"\
 -Command Disconnect 
