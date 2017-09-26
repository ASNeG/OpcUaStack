/*
    EventTypeClass: AuditConditionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditConditionEventType_h__
#define __OpcUaStackCore_AuditConditionEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditUpdateMethodEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditConditionEventType
    : public AuditUpdateMethodEventType
    {
      public:
        typedef boost::shared_ptr<AuditConditionEventType> SPtr;
    
        AuditConditionEventType(void);
        virtual ~AuditConditionEventType(void);
        
        
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
