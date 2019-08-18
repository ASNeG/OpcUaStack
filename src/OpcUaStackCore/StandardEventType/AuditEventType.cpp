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
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2052));
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
    	eventVariables_.getValue("ActionTimeStamp", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::status(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Status", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::serverId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ServerId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::clientAuditEntryId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ClientAuditEntryId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::clientUserId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ClientUserId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditEventType::getAuditEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
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
    
    bool 
    AuditEventType::setAuditEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
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

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
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
