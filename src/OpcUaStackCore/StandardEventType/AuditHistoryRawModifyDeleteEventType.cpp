/*
    EventTypeClass: AuditHistoryRawModifyDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditHistoryRawModifyDeleteEventType.h"

namespace OpcUaStackCore
{
    
    AuditHistoryRawModifyDeleteEventType::AuditHistoryRawModifyDeleteEventType(void)
    : AuditHistoryDeleteEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("IsDeleteModified", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("StartTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EndTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("OldValues", OpcUaBuildInType_OpcUaDataValue);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)3014));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditHistoryRawModifyDeleteEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditHistoryRawModifyDeleteEventType::~AuditHistoryRawModifyDeleteEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryRawModifyDeleteEventType::isDeleteModified(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("IsDeleteModified", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryRawModifyDeleteEventType::startTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("StartTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryRawModifyDeleteEventType::endTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EndTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryRawModifyDeleteEventType::oldValues(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("OldValues", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryRawModifyDeleteEventType::getAuditHistoryRawModifyDeleteEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditHistoryRawModifyDeleteEventType::isDeleteModified(OpcUaVariant::SPtr& isDeleteModified)
    {
    	return eventVariables_.setValue("IsDeleteModified", isDeleteModified);
    }
    
    bool 
    AuditHistoryRawModifyDeleteEventType::startTime(OpcUaVariant::SPtr& startTime)
    {
    	return eventVariables_.setValue("StartTime", startTime);
    }
    
    bool 
    AuditHistoryRawModifyDeleteEventType::endTime(OpcUaVariant::SPtr& endTime)
    {
    	return eventVariables_.setValue("EndTime", endTime);
    }
    
    bool 
    AuditHistoryRawModifyDeleteEventType::oldValues(OpcUaVariant::SPtr& oldValues)
    {
    	return eventVariables_.setValue("OldValues", oldValues);
    }
    
    bool 
    AuditHistoryRawModifyDeleteEventType::setAuditHistoryRawModifyDeleteEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditHistoryRawModifyDeleteEventType::mapNamespaceUri(void)
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
    AuditHistoryRawModifyDeleteEventType::get(
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
