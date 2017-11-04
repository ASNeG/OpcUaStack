/*
    EventTypeClass: TransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/TransitionEventType.h"

namespace OpcUaStackCore
{
    
    TransitionEventType::TransitionEventType(void)
    : BaseEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("Transition", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("FromState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ToState", OpcUaBuildInType_OpcUaLocalizedText);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2311));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("TransitionEventType"));
        eventVariables_.namespaceUri("");
    }
    
    TransitionEventType::~TransitionEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    TransitionEventType::transition(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("transition", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    TransitionEventType::fromState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("fromState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    TransitionEventType::toState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("toState", value);
    	return value;
    }
    
    bool 
    TransitionEventType::transition(OpcUaVariant::SPtr& transition)
    {
    	return eventVariables_.setValue("Transition", transition);
    }
    
    bool 
    TransitionEventType::fromState(OpcUaVariant::SPtr& fromState)
    {
    	return eventVariables_.setValue("FromState", fromState);
    }
    
    bool 
    TransitionEventType::toState(OpcUaVariant::SPtr& toState)
    {
    	return eventVariables_.setValue("ToState", toState);
    }
    
    void
    TransitionEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    TransitionEventType::get(
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
        variant = BaseEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
