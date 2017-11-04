/*
    EventTypeClass: AcknowledgeableConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AcknowledgeableConditionType.h"

namespace OpcUaStackCore
{
    
    AcknowledgeableConditionType::AcknowledgeableConditionType(void)
    : ConditionType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("EnabledState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("AckedState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ConfirmedState", OpcUaBuildInType_OpcUaLocalizedText);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2881));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AcknowledgeableConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    AcknowledgeableConditionType::~AcknowledgeableConditionType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::enabledState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("enabledState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::ackedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ackedState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::confirmedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("confirmedState", value);
    	return value;
    }
    
    bool 
    AcknowledgeableConditionType::enabledState(OpcUaVariant::SPtr& enabledState)
    {
    	return eventVariables_.setValue("EnabledState", enabledState);
    }
    
    bool 
    AcknowledgeableConditionType::ackedState(OpcUaVariant::SPtr& ackedState)
    {
    	return eventVariables_.setValue("AckedState", ackedState);
    }
    
    bool 
    AcknowledgeableConditionType::confirmedState(OpcUaVariant::SPtr& confirmedState)
    {
    	return eventVariables_.setValue("ConfirmedState", confirmedState);
    }
    
    void
    AcknowledgeableConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        ConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AcknowledgeableConditionType::get(
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
        variant = ConditionType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
