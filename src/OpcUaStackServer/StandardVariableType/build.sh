#!/bin/bash

NODESETS="--nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --nodeset Opc.Ua.NodeSet2.Services.xml"

OpcUaVariableTypeGenerator4 ${NODESETS} --variabletype BaseVariableType --buildSubTypes 1
