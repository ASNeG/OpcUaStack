/*
    VariableTypeClass: SessionSecurityDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionSecurityDiagnosticsType_h__
#define __OpcUaStackServer_SessionSecurityDiagnosticsType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SessionSecurityDiagnosticsType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<SessionSecurityDiagnosticsType> SPtr;
    
        SessionSecurityDiagnosticsType(void);
        virtual ~SessionSecurityDiagnosticsType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr sessionId(void);
        bool setSessionId(const OpcUaDataValue& dataValue);
        bool getSessionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientUserIdOfSession(void);
        bool setClientUserIdOfSession(const OpcUaDataValue& dataValue);
        bool getClientUserIdOfSession(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientUserIdOfSession(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientUserIdHistory(void);
        bool setClientUserIdHistory(const OpcUaDataValue& dataValue);
        bool getClientUserIdHistory(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientUserIdHistory(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr authenticationMechanism(void);
        bool setAuthenticationMechanism(const OpcUaDataValue& dataValue);
        bool getAuthenticationMechanism(OpcUaDataValue& dataValue);
        void setUpdateCallbackAuthenticationMechanism(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr encoding(void);
        bool setEncoding(const OpcUaDataValue& dataValue);
        bool getEncoding(OpcUaDataValue& dataValue);
        void setUpdateCallbackEncoding(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transportProtocol(void);
        bool setTransportProtocol(const OpcUaDataValue& dataValue);
        bool getTransportProtocol(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransportProtocol(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr securityMode(void);
        bool setSecurityMode(const OpcUaDataValue& dataValue);
        bool getSecurityMode(OpcUaDataValue& dataValue);
        void setUpdateCallbackSecurityMode(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr securityPolicyUri(void);
        bool setSecurityPolicyUri(const OpcUaDataValue& dataValue);
        bool getSecurityPolicyUri(OpcUaDataValue& dataValue);
        void setUpdateCallbackSecurityPolicyUri(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientCertificate(void);
        bool setClientCertificate(const OpcUaDataValue& dataValue);
        bool getClientCertificate(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientCertificate(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr sessionId_;
        ServerVariable::SPtr clientUserIdOfSession_;
        ServerVariable::SPtr clientUserIdHistory_;
        ServerVariable::SPtr authenticationMechanism_;
        ServerVariable::SPtr encoding_;
        ServerVariable::SPtr transportProtocol_;
        ServerVariable::SPtr securityMode_;
        ServerVariable::SPtr securityPolicyUri_;
        ServerVariable::SPtr clientCertificate_;
    
    };

}

#endif
