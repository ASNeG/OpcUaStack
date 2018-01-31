/*
    VariableTypeClass: PropertyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PropertyType_h__
#define __OpcUaStackServer_PropertyType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT PropertyType
    : public BaseVariableType
    {
      public:
        typedef boost::shared_ptr<PropertyType> SPtr;
    
        PropertyType(void);
        virtual ~PropertyType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
    
    };

}

#endif
