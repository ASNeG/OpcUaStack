/*
    EventTypeClass: AuditHistoryDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditHistoryDeleteEventType_h__
#define __OpcUaStackCore_AuditHistoryDeleteEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditHistoryUpdateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditHistoryDeleteEventType
    : public AuditHistoryUpdateEventType
    {
      public:
        typedef boost::shared_ptr<AuditHistoryDeleteEventType> SPtr;
    
        AuditHistoryDeleteEventType(void);
        virtual ~AuditHistoryDeleteEventType(void);
        bool updatedNode(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr updatedNode(void);
        
        bool setAuditHistoryDeleteEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getAuditHistoryDeleteEventType(void);
        
        
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
