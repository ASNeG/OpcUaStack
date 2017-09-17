/*
    EventTypeClass: AuditEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditEventType.h"

namespace OpcUaStackCore
{
    
    AuditEventType::AuditEventType(void)
    : BaseEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ActionTimeStamp", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("Status", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("ServerId", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("ClientAuditEntryId", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("ClientUserId", OpcUaBuildInType_OpcUaString);
    
        OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();
        eventType->setValue(OpcUaNodeId((OpcUaUInt32)2052));
        eventVariables_.setValue("AuditEventType", eventType);
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditEventType::~AuditEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::actionTimeStamp(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("actionTimeStamp", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::status(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("status", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::serverId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("serverId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::clientAuditEntryId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("clientAuditEntryId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::clientUserId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("clientUserId", value);
    	return value;
    }
    
    bool 
    AuditEventType::actionTimeStamp(OpcUaVariant::SPtr& actionTimeStamp)
    {
    	return eventVariables_.setValue("ActionTimeStamp", actionTimeStamp);
    }
    
    bool 
    AuditEventType::status(OpcUaVariant::SPtr& status)
    {
    	return eventVariables_.setValue("Status", status);
    }
    
    bool 
    AuditEventType::serverId(OpcUaVariant::SPtr& serverId)
    {
    	return eventVariables_.setValue("ServerId", serverId);
    }
    
    bool 
    AuditEventType::clientAuditEntryId(OpcUaVariant::SPtr& clientAuditEntryId)
    {
    	return eventVariables_.setValue("ClientAuditEntryId", clientAuditEntryId);
    }
    
    bool 
    AuditEventType::clientUserId(OpcUaVariant::SPtr& clientUserId)
    {
    	return eventVariables_.setValue("ClientUserId", clientUserId);
    }
    
    void
    AuditEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventType;
        eventVariables_.getValue("AuditEventType", eventType);
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);
    
    	eventVariables_.setValue("AuditEventType", eventType);
    	eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditEventType::get(
    	OpcUaNodeId& eventType,
    	std::list<OpcUaQualifiedName::SPtr>& browseNameList,
    	EventResult::Code& resultCode
    )
    {
    	resultCode = EventResult::Success;

    	OpcUaNodeId typeNodeId;
    	OpcUaVariant::SPtr tmpVariant;
    	eventVariables_.getValue("AuditEventType", tmpVariant);
    	tmpVariant->getValue(typeNodeId);

    	// check whether eventType and typeNodeId are identical
    	if (eventType == typeNodeId) {
    		return eventVariables_.get(browseNameList, resultCode);
    	}

    	// the start item was not found. We delegate the search to the base class
    	OpcUaVariant::SPtr variant;
    	variant = BaseEventType::get(eventType, browseNameList, resultCode);
    	if (resultCode != EventResult::Success || browseNameList.empty()) {
    		return variant;
    	}

    	return eventVariables_.get(browseNameList, resultCode);
    }

}
