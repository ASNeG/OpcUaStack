#!/bin/bash

OpcUaEventTypeGenerator3 --nodeset Opc.Ua.NodeSet.xml --eventtype AuditEventType
OpcUaEventTypeGenerator3 --nodeset Opc.Ua.NodeSet.xml --eventtype ConditionType
OpcUaEventTypeGenerator3 --nodeset Opc.Ua.NodeSet.xml --eventtype AcknowledgeableConditionType
OpcUaEventTypeGenerator3 --nodeset Opc.Ua.NodeSet.xml --eventtype AlarmConditionType
