/*
    EventTypeClass: AuditCertificateDataMismatchEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/AuditCertificateDataMismatchEventType.h"

namespace OpcUaStackCore
{
    
    AuditCertificateDataMismatchEventType::AuditCertificateDataMismatchEventType(void)
    : AuditCertificateEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("InvalidHostname", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("InvalidUri", OpcUaBuildInType_OpcUaString);
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2082));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("AuditCertificateDataMismatchEventType"));
        eventVariables_.namespaceUri("");
    }
    
    AuditCertificateDataMismatchEventType::~AuditCertificateDataMismatchEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    AuditCertificateDataMismatchEventType::invalidHostname(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("InvalidHostname", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCertificateDataMismatchEventType::invalidUri(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("InvalidUri", value);
    	return value;
    }
    
    OpcUaVariant::SPtr 
    AuditCertificateDataMismatchEventType::getAuditCertificateDataMismatchEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    AuditCertificateDataMismatchEventType::invalidHostname(OpcUaVariant::SPtr& invalidHostname)
    {
    	return eventVariables_.setValue("InvalidHostname", invalidHostname);
    }
    
    bool 
    AuditCertificateDataMismatchEventType::invalidUri(OpcUaVariant::SPtr& invalidUri)
    {
    	return eventVariables_.setValue("InvalidUri", invalidUri);
    }
    
    bool 
    AuditCertificateDataMismatchEventType::setAuditCertificateDataMismatchEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    AuditCertificateDataMismatchEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        AuditCertificateEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    AuditCertificateDataMismatchEventType::get(
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
        variant = AuditCertificateEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
