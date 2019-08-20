/*
    EventTypeClass: ProgramTransitionAuditEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/ProgramTransitionAuditEventType.h"

namespace OpcUaStackCore
{
    
    ProgramTransitionAuditEventType::ProgramTransitionAuditEventType(void)
    : AuditUpdateStateEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("Transition", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("Transition_Id", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)3806));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("ProgramTransitionAuditEventType"));
        eventVariables_.namespaceUri("");
    }
    
    ProgramTransitionAuditEventType::~ProgramTransitionAuditEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    ProgramTransitionAuditEventType::transition(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Transition", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ProgramTransitionAuditEventType::transition_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Transition_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ProgramTransitionAuditEventType::getProgramTransitionAuditEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    ProgramTransitionAuditEventType::transition(OpcUaVariant::SPtr& transition)
    {
    	return eventVariables_.setValue("Transition", transition);
    }
    
    bool 
    ProgramTransitionAuditEventType::transition_Id(OpcUaVariant::SPtr& transition_Id)
    {
    	return eventVariables_.setValue("Transition_Id", transition_Id);
    }
    
    bool 
    ProgramTransitionAuditEventType::setProgramTransitionAuditEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    ProgramTransitionAuditEventType::mapNamespaceUri(void)
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
    ProgramTransitionAuditEventType::get(
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
