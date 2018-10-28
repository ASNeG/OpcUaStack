/*
    VariableTypeClass: FiniteTransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FiniteTransitionVariableType_h__
#define __OpcUaStackServer_FiniteTransitionVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/TransitionVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT FiniteTransitionVariableType
    : public TransitionVariableType
    {
      public:
        typedef boost::shared_ptr<FiniteTransitionVariableType> SPtr;
    
        FiniteTransitionVariableType(void);
        virtual ~FiniteTransitionVariableType(void);
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
