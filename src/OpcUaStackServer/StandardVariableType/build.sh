#!/bin/bash

OpcUaVariableTypeGenerator4 --nodeset Opc.Ua.NodeSet.xml --variabletype BaseDataVariableType --buildSubTypes 1
OpcUaVariableTypeGenerator4 --nodeset Opc.Ua.NodeSet.xml --variabletype PropertyType
