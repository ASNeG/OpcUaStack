/*
    EventTypeClass: AuditChannelEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditChannelEventType.h"

namespace OpcUaStackCore
{
    
    AuditChannelEventType::AuditChannelEventType(void)
    : AuditSecurityEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SecureChannelId", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2059));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditChannelEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditChannelEventType::~AuditChannelEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditChannelEventType::secureChannelId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SecureChannelId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditChannelEventType::getAuditChannelEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditChannelEventType::secureChannelId(OpcUaVariant::SPtr& secureChannelId)
    {
    	return eventVariables_.setValue("SecureChannelId", secureChannelId);
    }
    
    bool 
    AuditChannelEventType::setAuditChannelEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditChannelEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditSecurityEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditChannelEventType::get(
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
        variant = AuditSecurityEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
