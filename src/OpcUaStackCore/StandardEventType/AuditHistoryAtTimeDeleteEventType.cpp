/*
    EventTypeClass: AuditHistoryAtTimeDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditHistoryAtTimeDeleteEventType.h"

namespace OpcUaStackCore
{
    
    AuditHistoryAtTimeDeleteEventType::AuditHistoryAtTimeDeleteEventType(void)
    : AuditHistoryDeleteEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ReqTimes", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("OldValues", OpcUaBuildInType_OpcUaDataValue);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)3019));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditHistoryAtTimeDeleteEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditHistoryAtTimeDeleteEventType::~AuditHistoryAtTimeDeleteEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryAtTimeDeleteEventType::reqTimes(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ReqTimes", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryAtTimeDeleteEventType::oldValues(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("OldValues", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryAtTimeDeleteEventType::getAuditHistoryAtTimeDeleteEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditHistoryAtTimeDeleteEventType::reqTimes(OpcUaVariant::SPtr& reqTimes)
    {
    	return eventVariables_.setValue("ReqTimes", reqTimes);
    }
    
    bool 
    AuditHistoryAtTimeDeleteEventType::oldValues(OpcUaVariant::SPtr& oldValues)
    {
    	return eventVariables_.setValue("OldValues", oldValues);
    }
    
    bool 
    AuditHistoryAtTimeDeleteEventType::setAuditHistoryAtTimeDeleteEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditHistoryAtTimeDeleteEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditHistoryDeleteEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditHistoryAtTimeDeleteEventType::get(
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
        variant = AuditHistoryDeleteEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
