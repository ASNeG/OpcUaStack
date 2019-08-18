/*
    EventTypeClass: NonExclusiveLimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/NonExclusiveLimitAlarmType.h"

namespace OpcUaStackCore
{
    
    NonExclusiveLimitAlarmType::NonExclusiveLimitAlarmType(void)
    : LimitAlarmType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ActiveState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ActiveState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("HighHighState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("HighHighState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("HighHighState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("HighState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("HighState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("HighState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("LowState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("LowState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("LowState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("LowLowState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("LowLowState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("LowLowState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)9906));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("NonExclusiveLimitAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    NonExclusiveLimitAlarmType::~NonExclusiveLimitAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::activeState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::activeState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highHighState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighHighState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highHighState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighHighState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highHighState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighHighState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowLowState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowLowState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowLowState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowLowState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowLowState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowLowState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::getNonExclusiveLimitAlarmType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    NonExclusiveLimitAlarmType::activeState(OpcUaVariant::SPtr& activeState)
    {
    	return eventVariables_.setValue("ActiveState", activeState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::activeState_Id(OpcUaVariant::SPtr& activeState_Id)
    {
    	return eventVariables_.setValue("ActiveState_Id", activeState_Id);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highHighState(OpcUaVariant::SPtr& highHighState)
    {
    	return eventVariables_.setValue("HighHighState", highHighState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highHighState_Id(OpcUaVariant::SPtr& highHighState_Id)
    {
    	return eventVariables_.setValue("HighHighState_Id", highHighState_Id);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highHighState_TransitionTime(OpcUaVariant::SPtr& highHighState_TransitionTime)
    {
    	return eventVariables_.setValue("HighHighState_TransitionTime", highHighState_TransitionTime);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highState(OpcUaVariant::SPtr& highState)
    {
    	return eventVariables_.setValue("HighState", highState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highState_Id(OpcUaVariant::SPtr& highState_Id)
    {
    	return eventVariables_.setValue("HighState_Id", highState_Id);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highState_TransitionTime(OpcUaVariant::SPtr& highState_TransitionTime)
    {
    	return eventVariables_.setValue("HighState_TransitionTime", highState_TransitionTime);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowState(OpcUaVariant::SPtr& lowState)
    {
    	return eventVariables_.setValue("LowState", lowState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowState_Id(OpcUaVariant::SPtr& lowState_Id)
    {
    	return eventVariables_.setValue("LowState_Id", lowState_Id);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowState_TransitionTime(OpcUaVariant::SPtr& lowState_TransitionTime)
    {
    	return eventVariables_.setValue("LowState_TransitionTime", lowState_TransitionTime);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowLowState(OpcUaVariant::SPtr& lowLowState)
    {
    	return eventVariables_.setValue("LowLowState", lowLowState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowLowState_Id(OpcUaVariant::SPtr& lowLowState_Id)
    {
    	return eventVariables_.setValue("LowLowState_Id", lowLowState_Id);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowLowState_TransitionTime(OpcUaVariant::SPtr& lowLowState_TransitionTime)
    {
    	return eventVariables_.setValue("LowLowState_TransitionTime", lowLowState_TransitionTime);
    }
    
    bool 
    NonExclusiveLimitAlarmType::setNonExclusiveLimitAlarmType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    NonExclusiveLimitAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        LimitAlarmType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    NonExclusiveLimitAlarmType::get(
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
        variant = LimitAlarmType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
