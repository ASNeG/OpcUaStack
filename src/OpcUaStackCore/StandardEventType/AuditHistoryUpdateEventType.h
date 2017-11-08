/*
    EventTypeClass: AuditHistoryUpdateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditHistoryUpdateEventType_h__
#define __OpcUaStackCore_AuditHistoryUpdateEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditUpdateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditHistoryUpdateEventType
    : public AuditUpdateEventType
    {
      public:
        typedef boost::shared_ptr<AuditHistoryUpdateEventType> SPtr;
    
        AuditHistoryUpdateEventType(void);
        virtual ~AuditHistoryUpdateEventType(void);
        bool parameterDataTypeId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr parameterDataTypeId(void);
        
        bool setAuditHistoryUpdateEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getAuditHistoryUpdateEventType(void);
        
        
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
