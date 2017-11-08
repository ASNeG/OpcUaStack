/*
    EventTypeClass: AuditCertificateDataMismatchEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditCertificateDataMismatchEventType_h__
#define __OpcUaStackCore_AuditCertificateDataMismatchEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditCertificateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditCertificateDataMismatchEventType
    : public AuditCertificateEventType
    {
      public:
        typedef boost::shared_ptr<AuditCertificateDataMismatchEventType> SPtr;
    
        AuditCertificateDataMismatchEventType(void);
        virtual ~AuditCertificateDataMismatchEventType(void);
        bool invalidHostname(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr invalidHostname(void);
        
        bool invalidUri(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr invalidUri(void);
        
        bool setAuditCertificateDataMismatchEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getAuditCertificateDataMismatchEventType(void);
        
        
        //- EventBase interface
        virtual void mapNamespaceUri(void);
        
        virtual OpcUaVariant::SPtr get(
            OpcUaNodeId& eventType,
            std::list<OpcUaQualifiedName::SPtr>& browseNameList,
            EventResult::Code& resultCode
        );
        //- EventBase interface
        
    
      private:
        EventVariables eventVariables_;
    
    };

}

#endif
