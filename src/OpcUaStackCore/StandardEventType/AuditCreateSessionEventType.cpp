/*
    EventTypeClass: AuditCreateSessionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditCreateSessionEventType.h"

namespace OpcUaStackCore
{
    
    AuditCreateSessionEventType::AuditCreateSessionEventType(void)
    : AuditSessionEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("SecureChannelId", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("ClientCertificate", OpcUaBuildInType_OpcUaByteString);
        eventVariables_.registerEventVariable("ClientCertificateThumbprint", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("RevisedSessionTimeout", OpcUaBuildInType_OpcUaDuration);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2071));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditCreateSessionEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditCreateSessionEventType::~AuditCreateSessionEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditCreateSessionEventType::secureChannelId(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("SecureChannelId", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCreateSessionEventType::clientCertificate(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ClientCertificate", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCreateSessionEventType::clientCertificateThumbprint(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("ClientCertificateThumbprint", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCreateSessionEventType::revisedSessionTimeout(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("RevisedSessionTimeout", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCreateSessionEventType::getAuditCreateSessionEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditCreateSessionEventType::secureChannelId(OpcUaVariant::SPtr& secureChannelId)
    {
    	return eventVariables_.setValue("SecureChannelId", secureChannelId);
    }
    
    bool 
    AuditCreateSessionEventType::clientCertificate(OpcUaVariant::SPtr& clientCertificate)
    {
    	return eventVariables_.setValue("ClientCertificate", clientCertificate);
    }
    
    bool 
    AuditCreateSessionEventType::clientCertificateThumbprint(OpcUaVariant::SPtr& clientCertificateThumbprint)
    {
    	return eventVariables_.setValue("ClientCertificateThumbprint", clientCertificateThumbprint);
    }
    
    bool 
    AuditCreateSessionEventType::revisedSessionTimeout(OpcUaVariant::SPtr& revisedSessionTimeout)
    {
    	return eventVariables_.setValue("RevisedSessionTimeout", revisedSessionTimeout);
    }
    
    bool 
    AuditCreateSessionEventType::setAuditCreateSessionEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditCreateSessionEventType::mapNamespaceUri(void)
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
    AuditCreateSessionEventType::get(
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
