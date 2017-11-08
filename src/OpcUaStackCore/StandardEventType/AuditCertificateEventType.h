/*
    EventTypeClass: AuditCertificateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditCertificateEventType_h__
#define __OpcUaStackCore_AuditCertificateEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditSecurityEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditCertificateEventType
    : public AuditSecurityEventType
    {
      public:
        typedef boost::shared_ptr<AuditCertificateEventType> SPtr;
    
        AuditCertificateEventType(void);
        virtual ~AuditCertificateEventType(void);
        bool certificate(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr certificate(void);
        
        bool setAuditCertificateEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getAuditCertificateEventType(void);
        
        
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
