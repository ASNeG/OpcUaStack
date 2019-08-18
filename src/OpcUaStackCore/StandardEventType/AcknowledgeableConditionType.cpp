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
        eventVariables_.registerEventVariable("EnabledState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("EnabledState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("AckedState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("AckedState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("AckedState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("ConfirmedState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ConfirmedState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("ConfirmedState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2881));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AcknowledgeableConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    AcknowledgeableConditionType::~AcknowledgeableConditionType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::enabledState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::enabledState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::ackedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("AckedState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::ackedState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("AckedState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::ackedState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("AckedState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::confirmedState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ConfirmedState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::confirmedState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ConfirmedState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::confirmedState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ConfirmedState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AcknowledgeableConditionType::getAcknowledgeableConditionType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AcknowledgeableConditionType::enabledState(OpcUaVariant::SPtr& enabledState)
    {
    	return eventVariables_.setValue("EnabledState", enabledState);
    }
    
    bool 
    AcknowledgeableConditionType::enabledState_Id(OpcUaVariant::SPtr& enabledState_Id)
    {
    	return eventVariables_.setValue("EnabledState_Id", enabledState_Id);
    }
    
    bool 
    AcknowledgeableConditionType::ackedState(OpcUaVariant::SPtr& ackedState)
    {
    	return eventVariables_.setValue("AckedState", ackedState);
    }
    
    bool 
    AcknowledgeableConditionType::ackedState_Id(OpcUaVariant::SPtr& ackedState_Id)
    {
    	return eventVariables_.setValue("AckedState_Id", ackedState_Id);
    }
    
    bool 
    AcknowledgeableConditionType::ackedState_TransitionTime(OpcUaVariant::SPtr& ackedState_TransitionTime)
    {
    	return eventVariables_.setValue("AckedState_TransitionTime", ackedState_TransitionTime);
    }
    
    bool 
    AcknowledgeableConditionType::confirmedState(OpcUaVariant::SPtr& confirmedState)
    {
    	return eventVariables_.setValue("ConfirmedState", confirmedState);
    }
    
    bool 
    AcknowledgeableConditionType::confirmedState_Id(OpcUaVariant::SPtr& confirmedState_Id)
    {
    	return eventVariables_.setValue("ConfirmedState_Id", confirmedState_Id);
    }
    
    bool 
    AcknowledgeableConditionType::confirmedState_TransitionTime(OpcUaVariant::SPtr& confirmedState_TransitionTime)
    {
    	return eventVariables_.setValue("ConfirmedState_TransitionTime", confirmedState_TransitionTime);
    }
    
    bool 
    AcknowledgeableConditionType::setAcknowledgeableConditionType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AcknowledgeableConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        ConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
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

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
    	    return eventVariables_.get(browseNameList, resultCode);
        }

        // the start item was not found. We delegate the search to the base class
        OpcUaVariant::SPtr variant;
        variant = ConditionType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
