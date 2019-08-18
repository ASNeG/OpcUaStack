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
        eventVariables_.registerEventVariable("EnabledState", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("EnabledState_Id", OpcUaBuildInType_OpcUaBoolean);
        eventVariables_.registerEventVariable("EnabledState_EffectiveDisplayName", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("EnabledState_TransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EnabledState_EffectiveTransitionTime", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("Quality", OpcUaBuildInType_OpcUaStatusCode);
        eventVariables_.registerEventVariable("Quality_SourceTimestamp", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("LastSeverity", OpcUaBuildInType_OpcUaUInt16);
        eventVariables_.registerEventVariable("LastSeverity_SourceTimestamp", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("Comment", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("Comment_SourceTimestamp", OpcUaBuildInType_OpcUaUtcTime);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2782));
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
    	eventVariables_.getValue("ConditionClassId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::conditionClassName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ConditionClassName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::conditionName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ConditionName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::branchId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("BranchId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::retain(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Retain", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::clientUserId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ClientUserId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::enabledState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::enabledState_Id(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_Id", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::enabledState_EffectiveDisplayName(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_EffectiveDisplayName", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::enabledState_TransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_TransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::enabledState_EffectiveTransitionTime(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EnabledState_EffectiveTransitionTime", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::quality(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Quality", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::quality_SourceTimestamp(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Quality_SourceTimestamp", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::lastSeverity(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LastSeverity", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::lastSeverity_SourceTimestamp(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("LastSeverity_SourceTimestamp", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::comment(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Comment", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::comment_SourceTimestamp(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Comment_SourceTimestamp", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    ConditionType::getConditionType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
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
    
    bool 
    ConditionType::enabledState(OpcUaVariant::SPtr& enabledState)
    {
    	return eventVariables_.setValue("EnabledState", enabledState);
    }
    
    bool 
    ConditionType::enabledState_Id(OpcUaVariant::SPtr& enabledState_Id)
    {
    	return eventVariables_.setValue("EnabledState_Id", enabledState_Id);
    }
    
    bool 
    ConditionType::enabledState_EffectiveDisplayName(OpcUaVariant::SPtr& enabledState_EffectiveDisplayName)
    {
    	return eventVariables_.setValue("EnabledState_EffectiveDisplayName", enabledState_EffectiveDisplayName);
    }
    
    bool 
    ConditionType::enabledState_TransitionTime(OpcUaVariant::SPtr& enabledState_TransitionTime)
    {
    	return eventVariables_.setValue("EnabledState_TransitionTime", enabledState_TransitionTime);
    }
    
    bool 
    ConditionType::enabledState_EffectiveTransitionTime(OpcUaVariant::SPtr& enabledState_EffectiveTransitionTime)
    {
    	return eventVariables_.setValue("EnabledState_EffectiveTransitionTime", enabledState_EffectiveTransitionTime);
    }
    
    bool 
    ConditionType::quality(OpcUaVariant::SPtr& quality)
    {
    	return eventVariables_.setValue("Quality", quality);
    }
    
    bool 
    ConditionType::quality_SourceTimestamp(OpcUaVariant::SPtr& quality_SourceTimestamp)
    {
    	return eventVariables_.setValue("Quality_SourceTimestamp", quality_SourceTimestamp);
    }
    
    bool 
    ConditionType::lastSeverity(OpcUaVariant::SPtr& lastSeverity)
    {
    	return eventVariables_.setValue("LastSeverity", lastSeverity);
    }
    
    bool 
    ConditionType::lastSeverity_SourceTimestamp(OpcUaVariant::SPtr& lastSeverity_SourceTimestamp)
    {
    	return eventVariables_.setValue("LastSeverity_SourceTimestamp", lastSeverity_SourceTimestamp);
    }
    
    bool 
    ConditionType::comment(OpcUaVariant::SPtr& comment)
    {
    	return eventVariables_.setValue("Comment", comment);
    }
    
    bool 
    ConditionType::comment_SourceTimestamp(OpcUaVariant::SPtr& comment_SourceTimestamp)
    {
    	return eventVariables_.setValue("Comment_SourceTimestamp", comment_SourceTimestamp);
    }
    
    bool 
    ConditionType::setConditionType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    ConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
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

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
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
