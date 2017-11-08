/*
    EventTypeClass: NonExclusiveLimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NonExclusiveLimitAlarmType_h__
#define __OpcUaStackCore_NonExclusiveLimitAlarmType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/LimitAlarmType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NonExclusiveLimitAlarmType
    : public LimitAlarmType
    {
      public:
        typedef boost::shared_ptr<NonExclusiveLimitAlarmType> SPtr;
    
        NonExclusiveLimitAlarmType(void);
        virtual ~NonExclusiveLimitAlarmType(void);
        bool activeState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState(void);
        
        bool activeState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_Id(void);
        
        bool highHighState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highHighState(void);
        
        bool highHighState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highHighState_Id(void);
        
        bool highHighState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highHighState_TransitionTime(void);
        
        bool highState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highState(void);
        
        bool highState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highState_Id(void);
        
        bool highState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highState_TransitionTime(void);
        
        bool lowState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowState(void);
        
        bool lowState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowState_Id(void);
        
        bool lowState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowState_TransitionTime(void);
        
        bool lowLowState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowLowState(void);
        
        bool lowLowState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowLowState_Id(void);
        
        bool lowLowState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowLowState_TransitionTime(void);
        
        
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
