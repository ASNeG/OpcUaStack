/*
    EventTypeClass: RefreshRequiredEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RefreshRequiredEventType_h__
#define __OpcUaStackCore_RefreshRequiredEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/SystemEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RefreshRequiredEventType
    : public SystemEventType
    {
      public:
        typedef boost::shared_ptr<RefreshRequiredEventType> SPtr;
    
        RefreshRequiredEventType(void);
        virtual ~RefreshRequiredEventType(void);
        
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
