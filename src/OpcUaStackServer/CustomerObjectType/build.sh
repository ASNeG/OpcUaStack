#!/bin/bash

NODESETS="--nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet.ASNeGServer.xml"

OpcUaObjectTypeGenerator4 ${NODESETS} --objecttype SessionInfo --buildSubTypes 1 --namespaces_ ASNeG-Server 
