/*
    EventTypeClass: AuditUpdateMethodEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditUpdateMethodEventType.h"

namespace OpcUaStackCore
{
    
    AuditUpdateMethodEventType::AuditUpdateMethodEventType(void)
    : AuditEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("MethodId", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("InputArguments", OpcUaBuildInType_OpcUaVariant);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2127));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditUpdateMethodEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditUpdateMethodEventType::~AuditUpdateMethodEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateMethodEventType::methodId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("MethodId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateMethodEventType::inputArguments(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("InputArguments", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditUpdateMethodEventType::getAuditUpdateMethodEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditUpdateMethodEventType::methodId(OpcUaVariant::SPtr& methodId)
    {
    	return eventVariables_.setValue("MethodId", methodId);
    }
    
    bool 
    AuditUpdateMethodEventType::inputArguments(OpcUaVariant::SPtr& inputArguments)
    {
    	return eventVariables_.setValue("InputArguments", inputArguments);
    }
    
    bool 
    AuditUpdateMethodEventType::setAuditUpdateMethodEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditUpdateMethodEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditUpdateMethodEventType::get(
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
        variant = AuditEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
