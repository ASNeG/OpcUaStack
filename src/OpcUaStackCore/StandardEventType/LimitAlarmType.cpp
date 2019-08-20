/*
    EventTypeClass: LimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/LimitAlarmType.h"

namespace OpcUaStackCore
{
    
    LimitAlarmType::LimitAlarmType(void)
    : AlarmConditionType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("HighHighLimit", OpcUaBuildInType_OpcUaDouble);
        eventVariables_.registerEventVariable("HighLimit", OpcUaBuildInType_OpcUaDouble);
        eventVariables_.registerEventVariable("LowLimit", OpcUaBuildInType_OpcUaDouble);
        eventVariables_.registerEventVariable("LowLowLimit", OpcUaBuildInType_OpcUaDouble);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2955));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("LimitAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    LimitAlarmType::~LimitAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    LimitAlarmType::highHighLimit(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighHighLimit", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    LimitAlarmType::highLimit(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("HighLimit", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    LimitAlarmType::lowLimit(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowLimit", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    LimitAlarmType::lowLowLimit(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LowLowLimit", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    LimitAlarmType::getLimitAlarmType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    LimitAlarmType::highHighLimit(OpcUaVariant::SPtr& highHighLimit)
    {
    	return eventVariables_.setValue("HighHighLimit", highHighLimit);
    }
    
    bool 
    LimitAlarmType::highLimit(OpcUaVariant::SPtr& highLimit)
    {
    	return eventVariables_.setValue("HighLimit", highLimit);
    }
    
    bool 
    LimitAlarmType::lowLimit(OpcUaVariant::SPtr& lowLimit)
    {
    	return eventVariables_.setValue("LowLimit", lowLimit);
    }
    
    bool 
    LimitAlarmType::lowLowLimit(OpcUaVariant::SPtr& lowLowLimit)
    {
    	return eventVariables_.setValue("LowLowLimit", lowLowLimit);
    }
    
    bool 
    LimitAlarmType::setLimitAlarmType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    LimitAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AlarmConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    LimitAlarmType::get(
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
        variant = AlarmConditionType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
