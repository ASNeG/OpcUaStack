/*
    EventTypeClass: AuditHistoryAtTimeDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditHistoryAtTimeDeleteEventType_h__
#define __OpcUaStackCore_AuditHistoryAtTimeDeleteEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditHistoryDeleteEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditHistoryAtTimeDeleteEventType
    : public AuditHistoryDeleteEventType
    {
      public:
        typedef boost::shared_ptr<AuditHistoryAtTimeDeleteEventType> SPtr;
    
        AuditHistoryAtTimeDeleteEventType(void);
        virtual ~AuditHistoryAtTimeDeleteEventType(void);
        bool reqTimes(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr reqTimes(void);
        
        bool oldValues(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr oldValues(void);
        
        
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
