/*
    VariableTypeClass: ConditionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ConditionVariableType_h__
#define __OpcUaStackServer_ConditionVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ConditionVariableType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<ConditionVariableType> SPtr;
    
        ConditionVariableType(void);
        virtual ~ConditionVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr sourceTimestamp(void);
        bool setSourceTimestamp(const OpcUaDataValue& dataValue);
        bool getSourceTimestamp(OpcUaDataValue& dataValue);
        void setUpdateCallbackSourceTimestamp(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr sourceTimestamp_;
    
    };

}

#endif
