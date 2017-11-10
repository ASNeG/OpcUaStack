/*
    EventTypeClass: DiscreteAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DiscreteAlarmType_h__
#define __OpcUaStackCore_DiscreteAlarmType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AlarmConditionType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DiscreteAlarmType
    : public AlarmConditionType
    {
      public:
        typedef boost::shared_ptr<DiscreteAlarmType> SPtr;
    
        DiscreteAlarmType(void);
        virtual ~DiscreteAlarmType(void);
        bool setDiscreteAlarmType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getDiscreteAlarmType(void);
        
        
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
