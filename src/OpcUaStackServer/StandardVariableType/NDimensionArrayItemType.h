/*
    VariableTypeClass: NDimensionArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NDimensionArrayItemType_h__
#define __OpcUaStackServer_NDimensionArrayItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/ArrayItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT NDimensionArrayItemType
    : public ArrayItemType
    {
      public:
        typedef boost::shared_ptr<NDimensionArrayItemType> SPtr;
    
        NDimensionArrayItemType(void);
        virtual ~NDimensionArrayItemType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr axisDefinition(void);
        bool setAxisDefinition(const OpcUaDataValue& dataValue);
        bool getAxisDefinition(OpcUaDataValue& dataValue);
        void setUpdateCallbackAxisDefinition(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr axisDefinition_;
    
    };

}

#endif
