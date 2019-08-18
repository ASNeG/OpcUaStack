/*
    EventTypeClass: ExclusiveLimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/ExclusiveLimitAlarmType.h"

namespace OpcUaStackCore
{
    
    ExclusiveLimitAlarmType::ExclusiveLimitAlarmType(void)
    : LimitAlarmType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ActiveState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ActiveState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)9341));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("ExclusiveLimitAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    ExclusiveLimitAlarmType::~ExclusiveLimitAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    ExclusiveLimitAlarmType::activeState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ExclusiveLimitAlarmType::activeState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ActiveState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ExclusiveLimitAlarmType::getExclusiveLimitAlarmType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    ExclusiveLimitAlarmType::activeState(OpcUaVariant::SPtr& activeState)
    {
    	return eventVariables_.setValue("ActiveState", activeState);
    }
    
    bool 
    ExclusiveLimitAlarmType::activeState_Id(OpcUaVariant::SPtr& activeState_Id)
    {
    	return eventVariables_.setValue("ActiveState_Id", activeState_Id);
    }
    
    bool 
    ExclusiveLimitAlarmType::setExclusiveLimitAlarmType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    ExclusiveLimitAlarmType::mapNamespaceUri(void)
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
    ExclusiveLimitAlarmType::get(
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
