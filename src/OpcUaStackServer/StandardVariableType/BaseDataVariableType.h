/*
    VariableTypeClass: BaseDataVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BaseDataVariableType_h__
#define __OpcUaStackServer_BaseDataVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT BaseDataVariableType
    : public BaseVariableType
    {
      public:
        typedef boost::shared_ptr<BaseDataVariableType> SPtr;
    
        BaseDataVariableType(void);
        virtual ~BaseDataVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
    
    };

}

#endif
