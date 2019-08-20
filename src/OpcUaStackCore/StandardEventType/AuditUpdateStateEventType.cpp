/*
    EventTypeClass: AuditUpdateStateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditUpdateStateEventType.h"

namespace OpcUaStackCore
{
    
    AuditUpdateStateEventType::AuditUpdateStateEventType(void)
    : AuditUpdateMethodEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("OldStateId", OpcUaBuildInType_OpcUaVariant);
        eventVariables_.registerEventVariable("NewStateId", OpcUaBuildInType_OpcUaVariant);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2315));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditUpdateStateEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditUpdateStateEventType::~AuditUpdateStateEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateStateEventType::oldStateId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("OldStateId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateStateEventType::newStateId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("NewStateId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateStateEventType::getAuditUpdateStateEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditUpdateStateEventType::oldStateId(OpcUaVariant::SPtr& oldStateId)
    {
    	return eventVariables_.setValue("OldStateId", oldStateId);
    }
    
    bool 
    AuditUpdateStateEventType::newStateId(OpcUaVariant::SPtr& newStateId)
    {
    	return eventVariables_.setValue("NewStateId", newStateId);
    }
    
    bool 
    AuditUpdateStateEventType::setAuditUpdateStateEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditUpdateStateEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditUpdateMethodEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditUpdateStateEventType::get(
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
        variant = AuditUpdateMethodEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
