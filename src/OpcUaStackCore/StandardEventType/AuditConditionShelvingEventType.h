/*
    EventTypeClass: AuditConditionShelvingEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditConditionShelvingEventType_h__
#define __OpcUaStackCore_AuditConditionShelvingEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditConditionEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditConditionShelvingEventType
    : public AuditConditionEventType
    {
      public:
        typedef boost::shared_ptr<AuditConditionShelvingEventType> SPtr;
    
        AuditConditionShelvingEventType(void);
        virtual ~AuditConditionShelvingEventType(void);
        bool shelvingTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr shelvingTime(void);
        
        
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
