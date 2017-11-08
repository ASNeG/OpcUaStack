/*
    EventTypeClass: ExclusiveLimitAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ExclusiveLimitAlarmType_h__
#define __OpcUaStackCore_ExclusiveLimitAlarmType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/LimitAlarmType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ExclusiveLimitAlarmType
    : public LimitAlarmType
    {
      public:
        typedef boost::shared_ptr<ExclusiveLimitAlarmType> SPtr;
    
        ExclusiveLimitAlarmType(void);
        virtual ~ExclusiveLimitAlarmType(void);
        bool activeState(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState(void);
        
        bool activeState_Id(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr activeState_Id(void);
        
        bool setExclusiveLimitAlarmType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getExclusiveLimitAlarmType(void);
        
        
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
