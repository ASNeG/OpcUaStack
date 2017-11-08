/*
    EventTypeClass: ProgramTransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ProgramTransitionEventType_h__
#define __OpcUaStackCore_ProgramTransitionEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/TransitionEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ProgramTransitionEventType
    : public TransitionEventType
    {
      public:
        typedef boost::shared_ptr<ProgramTransitionEventType> SPtr;
    
        ProgramTransitionEventType(void);
        virtual ~ProgramTransitionEventType(void);
        bool intermediateResult(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr intermediateResult(void);
        
        bool setProgramTransitionEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getProgramTransitionEventType(void);
        
        
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
