/*
    EventTypeClass: ExclusiveDeviationAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/ExclusiveDeviationAlarmType.h"

namespace OpcUaStackCore
{
    
    ExclusiveDeviationAlarmType::ExclusiveDeviationAlarmType(void)
    : ExclusiveLimitAlarmType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SetpointNode", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)9764));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("ExclusiveDeviationAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    ExclusiveDeviationAlarmType::~ExclusiveDeviationAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    ExclusiveDeviationAlarmType::setpointNode(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SetpointNode", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ExclusiveDeviationAlarmType::getExclusiveDeviationAlarmType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    ExclusiveDeviationAlarmType::setpointNode(OpcUaVariant::SPtr& setpointNode)
    {
    	return eventVariables_.setValue("SetpointNode", setpointNode);
    }
    
    bool 
    ExclusiveDeviationAlarmType::setExclusiveDeviationAlarmType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    ExclusiveDeviationAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        ExclusiveLimitAlarmType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    ExclusiveDeviationAlarmType::get(
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
        variant = ExclusiveLimitAlarmType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
