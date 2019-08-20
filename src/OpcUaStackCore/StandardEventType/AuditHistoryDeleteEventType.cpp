/*
    EventTypeClass: AuditHistoryDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditHistoryDeleteEventType.h"

namespace OpcUaStackCore
{
    
    AuditHistoryDeleteEventType::AuditHistoryDeleteEventType(void)
    : AuditHistoryUpdateEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("UpdatedNode", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)3012));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditHistoryDeleteEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditHistoryDeleteEventType::~AuditHistoryDeleteEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryDeleteEventType::updatedNode(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("UpdatedNode", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryDeleteEventType::getAuditHistoryDeleteEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditHistoryDeleteEventType::updatedNode(OpcUaVariant::SPtr& updatedNode)
    {
    	return eventVariables_.setValue("UpdatedNode", updatedNode);
    }
    
    bool 
    AuditHistoryDeleteEventType::setAuditHistoryDeleteEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditHistoryDeleteEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditHistoryUpdateEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditHistoryDeleteEventType::get(
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
        variant = AuditHistoryUpdateEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
