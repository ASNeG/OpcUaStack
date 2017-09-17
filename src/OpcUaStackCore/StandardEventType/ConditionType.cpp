/*
    EventTypeClass: ConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/ConditionType.h"

namespace OpcUaStackCore
{
    
    ConditionType::ConditionType(void)
    : BaseEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("ConditionClassId", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("ConditionClassName", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ConditionName", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("BranchId", OpcUaBuildInType_OpcUaNodeId);
        eventVariables_.registerEventVariable("Retain", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("ClientUserId", OpcUaBuildInType_OpcUaString);
    
        OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();
        eventType->setValue(OpcUaNodeId((OpcUaUInt32)2782));
        eventVariables_.setValue("ConditionType", eventType);
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("ConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    ConditionType::~ConditionType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    ConditionType::conditionClassId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("conditionClassId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::conditionClassName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("conditionClassName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::conditionName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("conditionName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::branchId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("branchId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::retain(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("retain", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::clientUserId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("clientUserId", value);
    	return value;
    }
    
    bool 
    ConditionType::conditionClassId(OpcUaVariant::SPtr& conditionClassId)
    {
    	return eventVariables_.setValue("ConditionClassId", conditionClassId);
    }
    
    bool 
    ConditionType::conditionClassName(OpcUaVariant::SPtr& conditionClassName)
    {
    	return eventVariables_.setValue("ConditionClassName", conditionClassName);
    }
    
    bool 
    ConditionType::conditionName(OpcUaVariant::SPtr& conditionName)
    {
    	return eventVariables_.setValue("ConditionName", conditionName);
    }
    
    bool 
    ConditionType::branchId(OpcUaVariant::SPtr& branchId)
    {
    	return eventVariables_.setValue("BranchId", branchId);
    }
    
    bool 
    ConditionType::retain(OpcUaVariant::SPtr& retain)
    {
    	return eventVariables_.setValue("Retain", retain);
    }
    
    bool 
    ConditionType::clientUserId(OpcUaVariant::SPtr& clientUserId)
    {
    	return eventVariables_.setValue("ClientUserId", clientUserId);
    }
    
    void
    ConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventType;
        eventVariables_.getValue("ConditionType", eventType);
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);
    
    	eventVariables_.setValue("ConditionType", eventType);
    	eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    ConditionType::get(
    	OpcUaNodeId& eventType,
    	std::list<OpcUaQualifiedName::SPtr>& browseNameList,
    	EventResult::Code& resultCode
    )
    {
    	resultCode = EventResult::Success;

    	OpcUaNodeId typeNodeId;
    	OpcUaVariant::SPtr tmpVariant;
    	eventVariables_.getValue("ConditionType", tmpVariant);
    	tmpVariant->getValue(typeNodeId);

    	// check whether eventType and typeNodeId are identical
    	if (eventType == typeNodeId) {
    		return eventVariables_.get(browseNameList, resultCode);
    	}

    	// the start item was not found. We delegate the search to the base class
    	OpcUaVariant::SPtr variant;
    	variant = BaseEventType::get(eventType, browseNameList, resultCode);
    	if (resultCode != EventResult::Success || browseNameList.empty()) {
    		return variant;
    	}

    	return eventVariables_.get(browseNameList, resultCode);
    }

}
