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
        eventVariables_.registerEventVariable("SuppressedOrShelved", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("MaxTimeShelved", OpcUaBuildInType_OpcUaDuration);
        eventVariables_.registerEventVariable("EnabledState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ActiveState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("SuppressedState", OpcUaBuildInType_OpcUaLocalizedText);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2915));
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
    
    OpcUaVariant::SPtr 
    AlarmConditionType::enabledState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("enabledState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("activeState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("suppressedState", value);
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
    
    bool 
    AlarmConditionType::enabledState(OpcUaVariant::SPtr& enabledState)
    {
    	return eventVariables_.setValue("EnabledState", enabledState);
    }
    
    bool 
    AlarmConditionType::activeState(OpcUaVariant::SPtr& activeState)
    {
    	return eventVariables_.setValue("ActiveState", activeState);
    }
    
    bool 
    AlarmConditionType::suppressedState(OpcUaVariant::SPtr& suppressedState)
    {
    	return eventVariables_.setValue("SuppressedState", suppressedState);
    }
    
    void
    AlarmConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AcknowledgeableConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
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

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
    	    return eventVariables_.get(browseNameList, resultCode);
        }

        // the start item was not found. We delegate the search to the base class
        OpcUaVariant::SPtr variant;
        variant = AcknowledgeableConditionType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
