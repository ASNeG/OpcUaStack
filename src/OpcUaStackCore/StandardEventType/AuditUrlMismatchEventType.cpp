/*
    EventTypeClass: AuditUrlMismatchEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditUrlMismatchEventType.h"

namespace OpcUaStackCore
{
    
    AuditUrlMismatchEventType::AuditUrlMismatchEventType(void)
    : AuditCreateSessionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("EndpointUrl", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2748));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditUrlMismatchEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditUrlMismatchEventType::~AuditUrlMismatchEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditUrlMismatchEventType::endpointUrl(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EndpointUrl", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditUrlMismatchEventType::getAuditUrlMismatchEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditUrlMismatchEventType::endpointUrl(OpcUaVariant::SPtr& endpointUrl)
    {
    	return eventVariables_.setValue("EndpointUrl", endpointUrl);
    }
    
    bool 
    AuditUrlMismatchEventType::setAuditUrlMismatchEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditUrlMismatchEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditCreateSessionEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditUrlMismatchEventType::get(
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
        variant = AuditCreateSessionEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
