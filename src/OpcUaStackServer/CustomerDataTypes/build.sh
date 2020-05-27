#!/bin/bash

NODESETS="--nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet.ASNeGServer.xml"

OpcUaEnumTypeGenerator4 ${NODESETS} --enumtype SessionState --namespaces 1:OpcUaStackServer

