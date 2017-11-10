/*
    EventTypeClass: TransitionEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_TransitionEventType_h__
#define __OpcUaStackCore_TransitionEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT TransitionEventType
    : public BaseEventType
    {
      public:
        typedef boost::shared_ptr<TransitionEventType> SPtr;
    
        TransitionEventType(void);
        virtual ~TransitionEventType(void);
        bool transition(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr transition(void);
        
        bool transition_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr transition_Id(void);
        
        bool fromState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr fromState(void);
        
        bool fromState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr fromState_Id(void);
        
        bool toState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr toState(void);
        
        bool toState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr toState_Id(void);
        
        bool setTransitionEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getTransitionEventType(void);
        
        
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
