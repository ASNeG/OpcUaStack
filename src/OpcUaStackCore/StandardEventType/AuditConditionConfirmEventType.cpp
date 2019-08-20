/*
    EventTypeClass: AuditConditionConfirmEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditConditionConfirmEventType.h"

namespace OpcUaStackCore
{
    
    AuditConditionConfirmEventType::AuditConditionConfirmEventType(void)
    : AuditConditionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("EventId", OpcUaBuildInType_OpcUaByteString);
        eventVariables_.registerEventVariable("Comment", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)8961));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditConditionConfirmEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditConditionConfirmEventType::~AuditConditionConfirmEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditConditionConfirmEventType::eventId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EventId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditConditionConfirmEventType::comment(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Comment", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditConditionConfirmEventType::getAuditConditionConfirmEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditConditionConfirmEventType::eventId(OpcUaVariant::SPtr& eventId)
    {
    	return eventVariables_.setValue("EventId", eventId);
    }
    
    bool 
    AuditConditionConfirmEventType::comment(OpcUaVariant::SPtr& comment)
    {
    	return eventVariables_.setValue("Comment", comment);
    }
    
    bool 
    AuditConditionConfirmEventType::setAuditConditionConfirmEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditConditionConfirmEventType::mapNamespaceUri(void)
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
    AuditConditionConfirmEventType::get(
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
