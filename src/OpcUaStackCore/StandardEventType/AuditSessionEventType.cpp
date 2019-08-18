/*
    EventTypeClass: AuditSessionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditSessionEventType.h"

namespace OpcUaStackCore
{
    
    AuditSessionEventType::AuditSessionEventType(void)
    : AuditEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SessionId", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2069));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditSessionEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditSessionEventType::~AuditSessionEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditSessionEventType::sessionId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SessionId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditSessionEventType::getAuditSessionEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditSessionEventType::sessionId(OpcUaVariant::SPtr& sessionId)
    {
    	return eventVariables_.setValue("SessionId", sessionId);
    }
    
    bool 
    AuditSessionEventType::setAuditSessionEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditSessionEventType::mapNamespaceUri(void)
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
    AuditSessionEventType::get(
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
