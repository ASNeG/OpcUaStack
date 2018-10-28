/*
    VariableTypeClass: ProgramDiagnosticType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ProgramDiagnosticType_h__
#define __OpcUaStackServer_ProgramDiagnosticType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ProgramDiagnosticType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<ProgramDiagnosticType> SPtr;
    
        ProgramDiagnosticType(void);
        virtual ~ProgramDiagnosticType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr createSessionId(void);
        bool setCreateSessionId(const OpcUaDataValue& dataValue);
        bool getCreateSessionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackCreateSessionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr createClientName(void);
        bool setCreateClientName(const OpcUaDataValue& dataValue);
        bool getCreateClientName(OpcUaDataValue& dataValue);
        void setUpdateCallbackCreateClientName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr invocationCreationTime(void);
        bool setInvocationCreationTime(const OpcUaDataValue& dataValue);
        bool getInvocationCreationTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackInvocationCreationTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastTransitionTime(void);
        bool setLastTransitionTime(const OpcUaDataValue& dataValue);
        bool getLastTransitionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastTransitionTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodCall(void);
        bool setLastMethodCall(const OpcUaDataValue& dataValue);
        bool getLastMethodCall(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodCall(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodSessionId(void);
        bool setLastMethodSessionId(const OpcUaDataValue& dataValue);
        bool getLastMethodSessionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodSessionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodInputArguments(void);
        bool setLastMethodInputArguments(const OpcUaDataValue& dataValue);
        bool getLastMethodInputArguments(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodInputArguments(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodOutputArguments(void);
        bool setLastMethodOutputArguments(const OpcUaDataValue& dataValue);
        bool getLastMethodOutputArguments(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodOutputArguments(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodCallTime(void);
        bool setLastMethodCallTime(const OpcUaDataValue& dataValue);
        bool getLastMethodCallTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodCallTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr lastMethodReturnStatus(void);
        bool setLastMethodReturnStatus(const OpcUaDataValue& dataValue);
        bool getLastMethodReturnStatus(OpcUaDataValue& dataValue);
        void setUpdateCallbackLastMethodReturnStatus(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr createSessionId_;
        ServerVariable::SPtr createClientName_;
        ServerVariable::SPtr invocationCreationTime_;
        ServerVariable::SPtr lastTransitionTime_;
        ServerVariable::SPtr lastMethodCall_;
        ServerVariable::SPtr lastMethodSessionId_;
        ServerVariable::SPtr lastMethodInputArguments_;
        ServerVariable::SPtr lastMethodOutputArguments_;
        ServerVariable::SPtr lastMethodCallTime_;
        ServerVariable::SPtr lastMethodReturnStatus_;
    
    };

}

#endif
