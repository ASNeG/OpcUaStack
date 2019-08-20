/*
    EventTypeClass: AuditConditionShelvingEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditConditionShelvingEventType.h"

namespace OpcUaStackCore
{
    
    AuditConditionShelvingEventType::AuditConditionShelvingEventType(void)
    : AuditConditionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ShelvingTime", OpcUaBuildInType_OpcUaDuration);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)11093));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditConditionShelvingEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditConditionShelvingEventType::~AuditConditionShelvingEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditConditionShelvingEventType::shelvingTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ShelvingTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditConditionShelvingEventType::getAuditConditionShelvingEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditConditionShelvingEventType::shelvingTime(OpcUaVariant::SPtr& shelvingTime)
    {
    	return eventVariables_.setValue("ShelvingTime", shelvingTime);
    }
    
    bool 
    AuditConditionShelvingEventType::setAuditConditionShelvingEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditConditionShelvingEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditConditionEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditConditionShelvingEventType::get(
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
        variant = AuditConditionEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
