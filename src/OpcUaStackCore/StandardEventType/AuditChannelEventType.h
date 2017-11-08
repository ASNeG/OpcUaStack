/*
    EventTypeClass: AuditChannelEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditChannelEventType_h__
#define __OpcUaStackCore_AuditChannelEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditSecurityEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditChannelEventType
    : public AuditSecurityEventType
    {
      public:
        typedef boost::shared_ptr<AuditChannelEventType> SPtr;
    
        AuditChannelEventType(void);
        virtual ~AuditChannelEventType(void);
        bool secureChannelId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr secureChannelId(void);
        
        
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
