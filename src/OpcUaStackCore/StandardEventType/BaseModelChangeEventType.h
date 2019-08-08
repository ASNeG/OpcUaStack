	/*
    EventTypeClass: BaseModelChangeEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BaseModelChangeEventType_h__
#define __OpcUaStackCore_BaseModelChangeEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BaseModelChangeEventType
    : public BaseEventType
    {
      public:
        typedef boost::shared_ptr<BaseModelChangeEventType> SPtr;
    
        BaseModelChangeEventType(void);
        virtual ~BaseModelChangeEventType(void);
        bool setBaseModelChangeEventType(OpcUaVariant::SPtr& variable);
        OpcUaVariant::SPtr getBaseModelChangeEventType(void);
        
        
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
