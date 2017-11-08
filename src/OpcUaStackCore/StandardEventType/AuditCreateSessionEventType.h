/*
    EventTypeClass: AuditCreateSessionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditCreateSessionEventType_h__
#define __OpcUaStackCore_AuditCreateSessionEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditSessionEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditCreateSessionEventType
    : public AuditSessionEventType
    {
      public:
        typedef boost::shared_ptr<AuditCreateSessionEventType> SPtr;
    
        AuditCreateSessionEventType(void);
        virtual ~AuditCreateSessionEventType(void);
        bool secureChannelId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr secureChannelId(void);
        
        bool clientCertificate(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr clientCertificate(void);
        
        bool clientCertificateThumbprint(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr clientCertificateThumbprint(void);
        
        bool revisedSessionTimeout(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr revisedSessionTimeout(void);
        
        
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
