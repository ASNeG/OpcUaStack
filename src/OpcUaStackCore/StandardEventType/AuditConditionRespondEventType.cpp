/*
    EventTypeClass: AuditConditionRespondEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditConditionRespondEventType.h"

namespace OpcUaStackCore
{
    
    AuditConditionRespondEventType::AuditConditionRespondEventType(void)
    : AuditConditionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SelectedResponse", OpcUaBuildInType_OpcUaInt32);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)8927));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditConditionRespondEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditConditionRespondEventType::~AuditConditionRespondEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditConditionRespondEventType::selectedResponse(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SelectedResponse", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditConditionRespondEventType::getAuditConditionRespondEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditConditionRespondEventType::selectedResponse(OpcUaVariant::SPtr& selectedResponse)
    {
    	return eventVariables_.setValue("SelectedResponse", selectedResponse);
    }
    
    bool 
    AuditConditionRespondEventType::setAuditConditionRespondEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditConditionRespondEventType::mapNamespaceUri(void)
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
    AuditConditionRespondEventType::get(
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
