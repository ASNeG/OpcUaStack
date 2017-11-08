/*
    EventTypeClass: AuditUpdateStateEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditUpdateStateEventType_h__
#define __OpcUaStackCore_AuditUpdateStateEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditUpdateMethodEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditUpdateStateEventType
    : public AuditUpdateMethodEventType
    {
      public:
        typedef boost::shared_ptr<AuditUpdateStateEventType> SPtr;
    
        AuditUpdateStateEventType(void);
        virtual ~AuditUpdateStateEventType(void);
        bool oldStateId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr oldStateId(void);
        
        bool newStateId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr newStateId(void);
        
        bool setAuditUpdateStateEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getAuditUpdateStateEventType(void);
        
        
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
