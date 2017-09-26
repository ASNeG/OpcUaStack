/*
    EventTypeClass: AuditProgramTransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditProgramTransitionEventType_h__
#define __OpcUaStackCore_AuditProgramTransitionEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditUpdateStateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditProgramTransitionEventType
    : public AuditUpdateStateEventType
    {
      public:
        typedef boost::shared_ptr<AuditProgramTransitionEventType> SPtr;
    
        AuditProgramTransitionEventType(void);
        virtual ~AuditProgramTransitionEventType(void);
        
        bool transitionNumber(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr transitionNumber(void);
        
        
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
