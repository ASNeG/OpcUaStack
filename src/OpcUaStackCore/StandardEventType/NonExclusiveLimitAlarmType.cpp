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
        eventVariables_.registerEventVariable("HighHighState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("HighState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("LowState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("LowLowState", OpcUaBuildInType_OpcUaLocalizedText);
    
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
    	eventVariables_.getValue("activeState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highHighState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("highHighState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::highState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("highState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("lowState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveLimitAlarmType::lowLowState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("lowLowState", value);
    	return value;
    }
    
    bool 
    NonExclusiveLimitAlarmType::activeState(OpcUaVariant::SPtr& activeState)
    {
    	return eventVariables_.setValue("ActiveState", activeState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highHighState(OpcUaVariant::SPtr& highHighState)
    {
    	return eventVariables_.setValue("HighHighState", highHighState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::highState(OpcUaVariant::SPtr& highState)
    {
    	return eventVariables_.setValue("HighState", highState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowState(OpcUaVariant::SPtr& lowState)
    {
    	return eventVariables_.setValue("LowState", lowState);
    }
    
    bool 
    NonExclusiveLimitAlarmType::lowLowState(OpcUaVariant::SPtr& lowLowState)
    {
    	return eventVariables_.setValue("LowLowState", lowLowState);
    }
    
    void
    NonExclusiveLimitAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        LimitAlarmType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
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
