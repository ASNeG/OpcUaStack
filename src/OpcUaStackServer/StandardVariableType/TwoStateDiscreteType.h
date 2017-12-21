/*
    VariableTypeClass: TwoStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TwoStateDiscreteType_h__
#define __OpcUaStackServer_TwoStateDiscreteType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DiscreteItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT TwoStateDiscreteType
    : public DiscreteItemType
    {
      public:
        typedef boost::shared_ptr<TwoStateDiscreteType> SPtr;
    
        TwoStateDiscreteType(void);
        virtual ~TwoStateDiscreteType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr falseState(void);
        bool setFalseState(const OpcUaDataValue& dataValue);
        bool getFalseState(OpcUaDataValue& dataValue);
        void setUpdateCallbackFalseState(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr trueState(void);
        bool setTrueState(const OpcUaDataValue& dataValue);
        bool getTrueState(OpcUaDataValue& dataValue);
        void setUpdateCallbackTrueState(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr falseState_;
        ServerVariable::SPtr trueState_;
    
    };

}

#endif
