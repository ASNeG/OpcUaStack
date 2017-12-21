/*
    VariableTypeClass: TransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TransitionVariableType_h__
#define __OpcUaStackServer_TransitionVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT TransitionVariableType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<TransitionVariableType> SPtr;
    
        TransitionVariableType(void);
        virtual ~TransitionVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr id(void);
        bool setId(const OpcUaDataValue& dataValue);
        bool getId(OpcUaDataValue& dataValue);
        void setUpdateCallbackId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr name(void);
        bool setName(const OpcUaDataValue& dataValue);
        bool getName(OpcUaDataValue& dataValue);
        void setUpdateCallbackName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr number(void);
        bool setNumber(const OpcUaDataValue& dataValue);
        bool getNumber(OpcUaDataValue& dataValue);
        void setUpdateCallbackNumber(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transitionTime(void);
        bool setTransitionTime(const OpcUaDataValue& dataValue);
        bool getTransitionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransitionTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr effectiveTransitionTime(void);
        bool setEffectiveTransitionTime(const OpcUaDataValue& dataValue);
        bool getEffectiveTransitionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackEffectiveTransitionTime(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr id_;
        ServerVariable::SPtr name_;
        ServerVariable::SPtr number_;
        ServerVariable::SPtr transitionTime_;
        ServerVariable::SPtr effectiveTransitionTime_;
    
    };

}

#endif
