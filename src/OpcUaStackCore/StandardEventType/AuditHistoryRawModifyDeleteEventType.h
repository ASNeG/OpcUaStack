/*
    EventTypeClass: AuditHistoryRawModifyDeleteEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditHistoryRawModifyDeleteEventType_h__
#define __OpcUaStackCore_AuditHistoryRawModifyDeleteEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditHistoryDeleteEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditHistoryRawModifyDeleteEventType
    : public AuditHistoryDeleteEventType
    {
      public:
        typedef boost::shared_ptr<AuditHistoryRawModifyDeleteEventType> SPtr;
    
        AuditHistoryRawModifyDeleteEventType(void);
        virtual ~AuditHistoryRawModifyDeleteEventType(void);
        
        bool isDeleteModified(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr isDeleteModified(void);
        
        bool startTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr startTime(void);
        
        bool endTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr endTime(void);
        
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
