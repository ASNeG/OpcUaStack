/*
    EventTypeClass: LimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_LimitAlarmType_h__
#define __OpcUaStackCore_LimitAlarmType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AlarmConditionType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT LimitAlarmType
    : public AlarmConditionType
    {
      public:
        typedef boost::shared_ptr<LimitAlarmType> SPtr;
    
        LimitAlarmType(void);
        virtual ~LimitAlarmType(void);
        
        bool highHighLimit(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highHighLimit(void);
        
        bool highLimit(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr highLimit(void);
        
        bool lowLimit(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowLimit(void);
        
        bool lowLowLimit(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr lowLowLimit(void);
        
        
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
