/*
    EventTypeClass: AlarmConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AlarmConditionType_h__
#define __OpcUaStackCore_AlarmConditionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AcknowledgeableConditionType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AlarmConditionType
    : public AcknowledgeableConditionType
    {
      public:
        typedef boost::shared_ptr<AlarmConditionType> SPtr;
    
        AlarmConditionType(void);
        virtual ~AlarmConditionType(void);
        bool inputNode(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr inputNode(void);
        
        bool suppressedOrShelved(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr suppressedOrShelved(void);
        
        bool maxTimeShelved(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr maxTimeShelved(void);
        
        bool enabledState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState(void);
        
        bool enabledState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_Id(void);
        
        bool activeState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState(void);
        
        bool activeState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_Id(void);
        
        bool activeState_EffectiveDisplayName(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_EffectiveDisplayName(void);
        
        bool activeState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_TransitionTime(void);
        
        bool activeState_EffectiveTransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_EffectiveTransitionTime(void);
        
        bool suppressedState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr suppressedState(void);
        
        bool suppressedState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr suppressedState_Id(void);
        
        bool suppressedState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr suppressedState_TransitionTime(void);
        
        
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
