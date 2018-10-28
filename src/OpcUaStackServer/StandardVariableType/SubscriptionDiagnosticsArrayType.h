/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__
#define __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SubscriptionDiagnosticsArrayType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<SubscriptionDiagnosticsArrayType> SPtr;
    
        SubscriptionDiagnosticsArrayType(void);
        virtual ~SubscriptionDiagnosticsArrayType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
    
    };

}

#endif
