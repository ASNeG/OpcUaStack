/*
    EventTypeClass: ConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ConditionType_h__
#define __OpcUaStackCore_ConditionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ConditionType
    : public BaseEventType
    {
      public:
        typedef boost::shared_ptr<ConditionType> SPtr;
    
        ConditionType(void);
        virtual ~ConditionType(void);
        bool conditionClassId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr conditionClassId(void);
        
        bool conditionClassName(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr conditionClassName(void);
        
        bool conditionName(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr conditionName(void);
        
        bool branchId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr branchId(void);
        
        bool retain(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr retain(void);
        
        bool clientUserId(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr clientUserId(void);
        
        bool enabledState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState(void);
        
        bool enabledState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_Id(void);
        
        bool enabledState_EffectiveDisplayName(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_EffectiveDisplayName(void);
        
        bool enabledState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_TransitionTime(void);
        
        bool enabledState_EffectiveTransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_EffectiveTransitionTime(void);
        
        bool quality(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr quality(void);
        
        bool quality_SourceTimestamp(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr quality_SourceTimestamp(void);
        
        bool lastSeverity(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lastSeverity(void);
        
        bool lastSeverity_SourceTimestamp(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lastSeverity_SourceTimestamp(void);
        
        bool comment(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr comment(void);
        
        bool comment_SourceTimestamp(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr comment_SourceTimestamp(void);
        
        bool setConditionType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getConditionType(void);
        
        
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
