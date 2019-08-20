/*
    EventTypeClass: NonExclusiveDeviationAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/NonExclusiveDeviationAlarmType.h"

namespace OpcUaStackCore
{
    
    NonExclusiveDeviationAlarmType::NonExclusiveDeviationAlarmType(void)
    : NonExclusiveLimitAlarmType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SetpointNode", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)10368));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("NonExclusiveDeviationAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    NonExclusiveDeviationAlarmType::~NonExclusiveDeviationAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveDeviationAlarmType::setpointNode(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SetpointNode", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    NonExclusiveDeviationAlarmType::getNonExclusiveDeviationAlarmType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    NonExclusiveDeviationAlarmType::setpointNode(OpcUaVariant::SPtr& setpointNode)
    {
    	return eventVariables_.setValue("SetpointNode", setpointNode);
    }
    
    bool 
    NonExclusiveDeviationAlarmType::setNonExclusiveDeviationAlarmType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    NonExclusiveDeviationAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        NonExclusiveLimitAlarmType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    NonExclusiveDeviationAlarmType::get(
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
        variant = NonExclusiveLimitAlarmType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
