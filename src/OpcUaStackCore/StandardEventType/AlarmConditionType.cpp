/*
    EventTypeClass: AlarmConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AlarmConditionType.h"

namespace OpcUaStackCore
{
    
    AlarmConditionType::AlarmConditionType(void)
    : AcknowledgeableConditionType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("InputNode", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("SuppressedOrShelved", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("MaxTimeShelved", OpcUaBuildInType_OpcUaNodeId);
    
        OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();
        eventType->setValue(OpcUaNodeId((OpcUaUInt32)2915));
        eventVariables_.setValue("AlarmConditionType", eventType);
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AlarmConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    AlarmConditionType::~AlarmConditionType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::inputNode(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("inputNode", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedOrShelved(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("suppressedOrShelved", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::maxTimeShelved(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("maxTimeShelved", value);
    	return value;
    }
    
    bool 
    AlarmConditionType::inputNode(OpcUaVariant::SPtr& inputNode)
    {
    	return eventVariables_.setValue("InputNode", inputNode);
    }
    
    bool 
    AlarmConditionType::suppressedOrShelved(OpcUaVariant::SPtr& suppressedOrShelved)
    {
    	return eventVariables_.setValue("SuppressedOrShelved", suppressedOrShelved);
    }
    
    bool 
    AlarmConditionType::maxTimeShelved(OpcUaVariant::SPtr& maxTimeShelved)
    {
    	return eventVariables_.setValue("MaxTimeShelved", maxTimeShelved);
    }
    
    void
    AlarmConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AcknowledgeableConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventType;
        eventVariables_.getValue("AlarmConditionType", eventType);
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);
    
    	eventVariables_.setValue("AlarmConditionType", eventType);
    	eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AlarmConditionType::get(
    	OpcUaNodeId& eventType,
    	std::list<OpcUaQualifiedName::SPtr>& browseNameList,
    	EventResult::Code& resultCode
    )
    {
    	resultCode = EventResult::Success;

    	OpcUaNodeId typeNodeId;
    	OpcUaVariant::SPtr tmpVariant;
    	eventVariables_.getValue("AlarmConditionType", tmpVariant);
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
