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
        eventVariables_.registerEventVariable("EnabledState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("ActiveState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ActiveState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("ActiveState_EffectiveDisplayName", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ActiveState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("ActiveState_EffectiveTransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("SuppressedState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("SuppressedState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("SuppressedState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
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
    	eventVariables_.getValue("InputNode", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedOrShelved(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SuppressedOrShelved", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::maxTimeShelved(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("MaxTimeShelved", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::enabledState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::enabledState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState_EffectiveDisplayName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_EffectiveDisplayName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::activeState_EffectiveTransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_EffectiveTransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SuppressedState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SuppressedState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::suppressedState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SuppressedState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AlarmConditionType::getAlarmConditionType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
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
    AlarmConditionType::enabledState_Id(OpcUaVariant::SPtr& enabledState_Id)
    {
    	return eventVariables_.setValue("EnabledState_Id", enabledState_Id);
    }
    
    bool 
    AlarmConditionType::activeState(OpcUaVariant::SPtr& activeState)
    {
    	return eventVariables_.setValue("ActiveState", activeState);
    }
    
    bool 
    AlarmConditionType::activeState_Id(OpcUaVariant::SPtr& activeState_Id)
    {
    	return eventVariables_.setValue("ActiveState_Id", activeState_Id);
    }
    
    bool 
    AlarmConditionType::activeState_EffectiveDisplayName(OpcUaVariant::SPtr& activeState_EffectiveDisplayName)
    {
    	return eventVariables_.setValue("ActiveState_EffectiveDisplayName", activeState_EffectiveDisplayName);
    }
    
    bool 
    AlarmConditionType::activeState_TransitionTime(OpcUaVariant::SPtr& activeState_TransitionTime)
    {
    	return eventVariables_.setValue("ActiveState_TransitionTime", activeState_TransitionTime);
    }
    
    bool 
    AlarmConditionType::activeState_EffectiveTransitionTime(OpcUaVariant::SPtr& activeState_EffectiveTransitionTime)
    {
    	return eventVariables_.setValue("ActiveState_EffectiveTransitionTime", activeState_EffectiveTransitionTime);
    }
    
    bool 
    AlarmConditionType::suppressedState(OpcUaVariant::SPtr& suppressedState)
    {
    	return eventVariables_.setValue("SuppressedState", suppressedState);
    }
    
    bool 
    AlarmConditionType::suppressedState_Id(OpcUaVariant::SPtr& suppressedState_Id)
    {
    	return eventVariables_.setValue("SuppressedState_Id", suppressedState_Id);
    }
    
    bool 
    AlarmConditionType::suppressedState_TransitionTime(OpcUaVariant::SPtr& suppressedState_TransitionTime)
    {
    	return eventVariables_.setValue("SuppressedState_TransitionTime", suppressedState_TransitionTime);
    }
    
    bool 
    AlarmConditionType::setAlarmConditionType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AlarmConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AcknowledgeableConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
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
