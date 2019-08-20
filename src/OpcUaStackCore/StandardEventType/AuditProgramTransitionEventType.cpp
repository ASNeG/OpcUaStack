/*
    EventTypeClass: AuditProgramTransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditProgramTransitionEventType.h"

namespace OpcUaStackCore
{
    
    AuditProgramTransitionEventType::AuditProgramTransitionEventType(void)
    : AuditUpdateStateEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("TransitionNumber", OpcUaBuildInType_OpcUaUInt32);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)11856));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditProgramTransitionEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditProgramTransitionEventType::~AuditProgramTransitionEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditProgramTransitionEventType::transitionNumber(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("TransitionNumber", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditProgramTransitionEventType::getAuditProgramTransitionEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditProgramTransitionEventType::transitionNumber(OpcUaVariant::SPtr& transitionNumber)
    {
    	return eventVariables_.setValue("TransitionNumber", transitionNumber);
    }
    
    bool 
    AuditProgramTransitionEventType::setAuditProgramTransitionEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditProgramTransitionEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditUpdateStateEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditProgramTransitionEventType::get(
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
        variant = AuditUpdateStateEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
