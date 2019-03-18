#!/bin/bash

OpcUaEventTypeGenerator3 --nodeset Opc.Ua.NodeSet2.xml --eventtype BaseEventType --buildSubTypes 1 \
	--ignoreEventTypeName AuditActivateSessionEventType \
	--ignoreEventTypeName AuditAddNodesEventType \
	--ignoreEventTypeName AuditAddReferencesEventType \
	--ignoreEventTypeName AuditDeleteNodesEventType \
	--ignoreEventTypeName AuditDeleteReferencesEventType \
	--ignoreEventTypeName AuditHistoryEventDeleteEventType \
	--ignoreEventTypeName AuditHistoryEventUpdateEventType \
	--ignoreEventTypeName AuditHistoryValueUpdateEventType \
	--ignoreEventTypeName AuditOpenSecureChannelEventType \
	--ignoreEventTypeName AuditWriteUpdateEventType \
	--ignoreEventTypeName GeneralModelChangeEventType \
	--ignoreEventTypeName SemanticChangeEventType \
	--ignoreEventTypeName SystemStatusChangeEventType
