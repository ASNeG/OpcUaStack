/*
    EventTypeClass: AuditConditionEnableEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditConditionEnableEventType.h"

namespace OpcUaStackCore
{
    
    AuditConditionEnableEventType::AuditConditionEnableEventType(void)
    : AuditConditionEventType()
    , eventVariables_()
    {
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2803));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditConditionEnableEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditConditionEnableEventType::~AuditConditionEnableEventType(void)
    {
    }
    
    void
    AuditConditionEnableEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditConditionEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditConditionEnableEventType::get(
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
        variant = AuditConditionEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
