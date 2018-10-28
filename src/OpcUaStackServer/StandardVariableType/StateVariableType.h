/*
    VariableTypeClass: StateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_StateVariableType_h__
#define __OpcUaStackServer_StateVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT StateVariableType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<StateVariableType> SPtr;
    
        StateVariableType(void);
        virtual ~StateVariableType(void);
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
        
        BaseNodeClass::SPtr effectiveDisplayName(void);
        bool setEffectiveDisplayName(const OpcUaDataValue& dataValue);
        bool getEffectiveDisplayName(OpcUaDataValue& dataValue);
        void setUpdateCallbackEffectiveDisplayName(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr id_;
        ServerVariable::SPtr name_;
        ServerVariable::SPtr number_;
        ServerVariable::SPtr effectiveDisplayName_;
    
    };

}

#endif
