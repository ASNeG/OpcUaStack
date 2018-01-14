/*
    VariableTypeClass: DiscreteItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DiscreteItemType_h__
#define __OpcUaStackServer_DiscreteItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DataItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT DiscreteItemType
    : public DataItemType
    {
      public:
        typedef boost::shared_ptr<DiscreteItemType> SPtr;
    
        DiscreteItemType(void);
        virtual ~DiscreteItemType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
    
    };

}

#endif
