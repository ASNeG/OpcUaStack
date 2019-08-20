/*
    EventTypeClass: AuditCancelEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditCancelEventType.h"

namespace OpcUaStackCore
{
    
    AuditCancelEventType::AuditCancelEventType(void)
    : AuditSessionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("RequestHandle", OpcUaBuildInType_OpcUaUInt32);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2078));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditCancelEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditCancelEventType::~AuditCancelEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditCancelEventType::requestHandle(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("RequestHandle", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCancelEventType::getAuditCancelEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditCancelEventType::requestHandle(OpcUaVariant::SPtr& requestHandle)
    {
    	return eventVariables_.setValue("RequestHandle", requestHandle);
    }
    
    bool 
    AuditCancelEventType::setAuditCancelEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditCancelEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditSessionEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditCancelEventType::get(
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
        variant = AuditSessionEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
