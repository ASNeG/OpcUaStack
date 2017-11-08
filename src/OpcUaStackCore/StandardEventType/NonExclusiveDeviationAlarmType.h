/*
    EventTypeClass: NonExclusiveDeviationAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NonExclusiveDeviationAlarmType_h__
#define __OpcUaStackCore_NonExclusiveDeviationAlarmType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/NonExclusiveLimitAlarmType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NonExclusiveDeviationAlarmType
    : public NonExclusiveLimitAlarmType
    {
      public:
        typedef boost::shared_ptr<NonExclusiveDeviationAlarmType> SPtr;
    
        NonExclusiveDeviationAlarmType(void);
        virtual ~NonExclusiveDeviationAlarmType(void);
        bool setpointNode(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr setpointNode(void);
        
        
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
