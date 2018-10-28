/*
    VariableTypeClass: TwoStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TwoStateVariableType_h__
#define __OpcUaStackServer_TwoStateVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/StateVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT TwoStateVariableType
    : public StateVariableType
    {
      public:
        typedef boost::shared_ptr<TwoStateVariableType> SPtr;
    
        TwoStateVariableType(void);
        virtual ~TwoStateVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr id(void);
        bool setId(const OpcUaDataValue& dataValue);
        bool getId(OpcUaDataValue& dataValue);
        void setUpdateCallbackId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transitionTime(void);
        bool setTransitionTime(const OpcUaDataValue& dataValue);
        bool getTransitionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransitionTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr effectiveTransitionTime(void);
        bool setEffectiveTransitionTime(const OpcUaDataValue& dataValue);
        bool getEffectiveTransitionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackEffectiveTransitionTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr trueState(void);
        bool setTrueState(const OpcUaDataValue& dataValue);
        bool getTrueState(OpcUaDataValue& dataValue);
        void setUpdateCallbackTrueState(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr falseState(void);
        bool setFalseState(const OpcUaDataValue& dataValue);
        bool getFalseState(OpcUaDataValue& dataValue);
        void setUpdateCallbackFalseState(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr id_;
        ServerVariable::SPtr transitionTime_;
        ServerVariable::SPtr effectiveTransitionTime_;
        ServerVariable::SPtr trueState_;
        ServerVariable::SPtr falseState_;
    
    };

}

#endif
