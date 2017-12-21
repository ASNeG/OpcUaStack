/*
    VariableTypeClass: FiniteStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FiniteStateVariableType_h__
#define __OpcUaStackServer_FiniteStateVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/StateVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT FiniteStateVariableType
    : public StateVariableType
    {
      public:
        typedef boost::shared_ptr<FiniteStateVariableType> SPtr;
    
        FiniteStateVariableType(void);
        virtual ~FiniteStateVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr id(void);
        bool setId(const OpcUaDataValue& dataValue);
        bool getId(OpcUaDataValue& dataValue);
        void setUpdateCallbackId(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr id_;
    
    };

}

#endif
