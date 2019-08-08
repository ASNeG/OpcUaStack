#!/bin/bash

NODESETS="--nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --nodeset Opc.Ua.NodeSet2.Services.xml"

OpcUaObjectTypeGenerator4 ${NODESETS} --objecttype BaseObjectType --buildSubTypes 1
