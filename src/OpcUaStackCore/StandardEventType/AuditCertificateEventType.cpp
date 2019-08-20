/*
    EventTypeClass: AuditCertificateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditCertificateEventType.h"

namespace OpcUaStackCore
{
    
    AuditCertificateEventType::AuditCertificateEventType(void)
    : AuditSecurityEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("Certificate", OpcUaBuildInType_OpcUaByteString);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2080));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditCertificateEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditCertificateEventType::~AuditCertificateEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditCertificateEventType::certificate(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("Certificate", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCertificateEventType::getAuditCertificateEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditCertificateEventType::certificate(OpcUaVariant::SPtr& certificate)
    {
    	return eventVariables_.setValue("Certificate", certificate);
    }
    
    bool 
    AuditCertificateEventType::setAuditCertificateEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditCertificateEventType::mapNamespaceUri(void)
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
    AuditCertificateEventType::get(
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
