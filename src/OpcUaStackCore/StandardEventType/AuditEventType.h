/*
    EventTypeClass: AuditEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditEventType_h__
#define __OpcUaStackCore_AuditEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditEventType
    : public BaseEventType
    {
      public:
        typedef boost::shared_ptr<AuditEventType> SPtr;
    
        AuditEventType(void);
        virtual ~AuditEventType(void);
        bool actionTimeStamp(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr actionTimeStamp(void);
        
        bool status(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr status(void);
        
        bool serverId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr serverId(void);
        
        bool clientAuditEntryId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr clientAuditEntryId(void);
        
        bool clientUserId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr clientUserId(void);
        
        
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
