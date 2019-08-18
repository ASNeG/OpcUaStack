/*
    EventTypeClass: AuditHistoryUpdateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditHistoryUpdateEventType.h"

namespace OpcUaStackCore
{
    
    AuditHistoryUpdateEventType::AuditHistoryUpdateEventType(void)
    : AuditUpdateEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ParameterDataTypeId", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2104));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditHistoryUpdateEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditHistoryUpdateEventType::~AuditHistoryUpdateEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryUpdateEventType::parameterDataTypeId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ParameterDataTypeId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditHistoryUpdateEventType::getAuditHistoryUpdateEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditHistoryUpdateEventType::parameterDataTypeId(OpcUaVariant::SPtr& parameterDataTypeId)
    {
    	return eventVariables_.setValue("ParameterDataTypeId", parameterDataTypeId);
    }
    
    bool 
    AuditHistoryUpdateEventType::setAuditHistoryUpdateEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditHistoryUpdateEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditUpdateEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditHistoryUpdateEventType::get(
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
        variant = AuditUpdateEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
