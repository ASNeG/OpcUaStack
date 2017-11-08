/*
    EventTypeClass: DialogConditionType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DialogConditionType_h__
#define __OpcUaStackCore_DialogConditionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/ConditionType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DialogConditionType
    : public ConditionType
    {
      public:
        typedef boost::shared_ptr<DialogConditionType> SPtr;
    
        DialogConditionType(void);
        virtual ~DialogConditionType(void);
        bool prompt(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr prompt(void);
        
        bool responseOptionSet(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr responseOptionSet(void);
        
        bool defaultResponse(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr defaultResponse(void);
        
        bool okResponse(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr okResponse(void);
        
        bool cancelResponse(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr cancelResponse(void);
        
        bool lastResponse(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lastResponse(void);
        
        bool enabledState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState(void);
        
        bool enabledState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr enabledState_Id(void);
        
        bool dialogState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr dialogState(void);
        
        bool dialogState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr dialogState_Id(void);
        
        bool dialogState_TransitionTime(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr dialogState_TransitionTime(void);
        
        
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
