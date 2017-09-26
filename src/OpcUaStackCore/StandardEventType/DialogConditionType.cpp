/*
    EventTypeClass: DialogConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/DialogConditionType.h"

namespace OpcUaStackCore
{
    
    DialogConditionType::DialogConditionType(void)
    : ConditionType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("Prompt", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("ResponseOptionSet", OpcUaBuildInType_OpcUaLocalizedText);
        eventVariables_.registerEventVariable("DefaultResponse", OpcUaBuildInType_OpcUaInt32);
        eventVariables_.registerEventVariable("OkResponse", OpcUaBuildInType_OpcUaInt32);
        eventVariables_.registerEventVariable("CancelResponse", OpcUaBuildInType_OpcUaInt32);
        eventVariables_.registerEventVariable("LastResponse", OpcUaBuildInType_OpcUaInt32);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2830));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("DialogConditionType"));
        eventVariables_.namespaceUri("");
    }
    
    DialogConditionType::~DialogConditionType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::prompt(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("prompt", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::responseOptionSet(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("responseOptionSet", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::defaultResponse(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("defaultResponse", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::okResponse(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("okResponse", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::cancelResponse(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("cancelResponse", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    DialogConditionType::lastResponse(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("lastResponse", value);
    	return value;
    }
    
    bool 
    DialogConditionType::prompt(OpcUaVariant::SPtr& prompt)
    {
    	return eventVariables_.setValue("Prompt", prompt);
    }
    
    bool 
    DialogConditionType::responseOptionSet(OpcUaVariant::SPtr& responseOptionSet)
    {
    	return eventVariables_.setValue("ResponseOptionSet", responseOptionSet);
    }
    
    bool 
    DialogConditionType::defaultResponse(OpcUaVariant::SPtr& defaultResponse)
    {
    	return eventVariables_.setValue("DefaultResponse", defaultResponse);
    }
    
    bool 
    DialogConditionType::okResponse(OpcUaVariant::SPtr& okResponse)
    {
    	return eventVariables_.setValue("OkResponse", okResponse);
    }
    
    bool 
    DialogConditionType::cancelResponse(OpcUaVariant::SPtr& cancelResponse)
    {
    	return eventVariables_.setValue("CancelResponse", cancelResponse);
    }
    
    bool 
    DialogConditionType::lastResponse(OpcUaVariant::SPtr& lastResponse)
    {
    	return eventVariables_.setValue("LastResponse", lastResponse);
    }
    
    void
    DialogConditionType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        ConditionType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    DialogConditionType::get(
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
        variant = ConditionType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
