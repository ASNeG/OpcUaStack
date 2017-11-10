/*
    EventTypeClass: ProgramTransitionAuditEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ProgramTransitionAuditEventType_h__
#define __OpcUaStackCore_ProgramTransitionAuditEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditUpdateStateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ProgramTransitionAuditEventType
    : public AuditUpdateStateEventType
    {
      public:
        typedef boost::shared_ptr<ProgramTransitionAuditEventType> SPtr;
    
        ProgramTransitionAuditEventType(void);
        virtual ~ProgramTransitionAuditEventType(void);
        bool transition(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr transition(void);
        
        bool transition_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr transition_Id(void);
        
        bool setProgramTransitionAuditEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getProgramTransitionAuditEventType(void);
        
        
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
