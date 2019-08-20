/*
    EventTypeClass: ProgramTransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/ProgramTransitionEventType.h"

namespace OpcUaStackCore
{
    
    ProgramTransitionEventType::ProgramTransitionEventType(void)
    : TransitionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("IntermediateResult", OpcUaBuildInType_OpcUaVariant);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2378));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("ProgramTransitionEventType"));
        eventVariables_.namespaceUri("");
    }
    
    ProgramTransitionEventType::~ProgramTransitionEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    ProgramTransitionEventType::intermediateResult(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("IntermediateResult", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ProgramTransitionEventType::getProgramTransitionEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    ProgramTransitionEventType::intermediateResult(OpcUaVariant::SPtr& intermediateResult)
    {
    	return eventVariables_.setValue("IntermediateResult", intermediateResult);
    }
    
    bool 
    ProgramTransitionEventType::setProgramTransitionEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    ProgramTransitionEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        TransitionEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    ProgramTransitionEventType::get(
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
        variant = TransitionEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
