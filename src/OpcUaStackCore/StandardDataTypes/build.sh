#!/bin/bash

#OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --datatype ConnectionTransportDataType --buildSubTypes 0
#OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --datatype BrokerConnectionTransportDataType --buildSubTypes 0
#OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --datatype DatagramConnectionTransportDataType --buildSubTypes 0
#
#OpcUaEnumTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --enumtype ApplicationType --buildSubTypes 0
#OpcUaEnumTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --enumtype ServerState --buildSubTypes 0
#
#

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --datatype ServerStatusDataType --buildSubTypes 0


OpcUaEnumTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --enumtype Enumeration --buildSubTypes 1
