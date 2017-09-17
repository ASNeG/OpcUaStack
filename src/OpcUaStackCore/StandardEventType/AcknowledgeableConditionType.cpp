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
    
        OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();
        eventType->setValue(OpcUaNodeId((OpcUaUInt32)2881));
        eventVariables_.setValue("AcknowledgeableConditionType", eventType);
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AcknowledgeableConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    AcknowledgeableConditionType::~AcknowledgeableConditionType(void)
    {
    }
    
    void
    AcknowledgeableConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        ConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventType;
        eventVariables_.getValue("AcknowledgeableConditionType", eventType);
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);
    
    	eventVariables_.setValue("AcknowledgeableConditionType", eventType);
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

    	OpcUaNodeId typeNodeId;
    	OpcUaVariant::SPtr tmpVariant;
    	eventVariables_.getValue("AcknowledgeableConditionType", tmpVariant);
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
