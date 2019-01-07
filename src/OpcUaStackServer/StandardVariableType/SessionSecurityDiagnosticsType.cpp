/*
    VariableTypeClass: SessionSecurityDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionSecurityDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    SessionSecurityDiagnosticsType::SessionSecurityDiagnosticsType(void)
    : VariableBase()
    , authenticationMechanism_Variable_(constructSPtr<ServerVariable>("AuthenticationMechanism_Variable"))
    , clientCertificate_Variable_(constructSPtr<ServerVariable>("ClientCertificate_Variable"))
    , clientUserIdHistory_Variable_(constructSPtr<ServerVariable>("ClientUserIdHistory_Variable"))
    , clientUserIdOfSession_Variable_(constructSPtr<ServerVariable>("ClientUserIdOfSession_Variable"))
    , encoding_Variable_(constructSPtr<ServerVariable>("Encoding_Variable"))
    , securityMode_Variable_(constructSPtr<ServerVariable>("SecurityMode_Variable"))
    , securityPolicyUri_Variable_(constructSPtr<ServerVariable>("SecurityPolicyUri_Variable"))
    , sessionId_Variable_(constructSPtr<ServerVariable>("SessionId_Variable"))
    , transportProtocol_Variable_(constructSPtr<ServerVariable>("TransportProtocol_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2244);
        setServerVariable(authenticationMechanism_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserIdHistory_Variable_);
        setServerVariable(clientUserIdOfSession_Variable_);
        setServerVariable(encoding_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(transportProtocol_Variable_);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsType::SessionSecurityDiagnosticsType(const SessionSecurityDiagnosticsType& value)
    : VariableBase()
    , authenticationMechanism_Variable_(constructSPtr<ServerVariable>("AuthenticationMechanism_Variable"))
    , clientCertificate_Variable_(constructSPtr<ServerVariable>("ClientCertificate_Variable"))
    , clientUserIdHistory_Variable_(constructSPtr<ServerVariable>("ClientUserIdHistory_Variable"))
    , clientUserIdOfSession_Variable_(constructSPtr<ServerVariable>("ClientUserIdOfSession_Variable"))
    , encoding_Variable_(constructSPtr<ServerVariable>("Encoding_Variable"))
    , securityMode_Variable_(constructSPtr<ServerVariable>("SecurityMode_Variable"))
    , securityPolicyUri_Variable_(constructSPtr<ServerVariable>("SecurityPolicyUri_Variable"))
    , sessionId_Variable_(constructSPtr<ServerVariable>("SessionId_Variable"))
    , transportProtocol_Variable_(constructSPtr<ServerVariable>("TransportProtocol_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2244);
        setServerVariable(authenticationMechanism_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserIdHistory_Variable_);
        setServerVariable(clientUserIdOfSession_Variable_);
        setServerVariable(encoding_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(transportProtocol_Variable_);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsType::~SessionSecurityDiagnosticsType(void)
    {
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::authenticationMechanism_Variable(void)
    {
        return authenticationMechanism_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::clientCertificate_Variable(void)
    {
        return clientCertificate_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::clientUserIdHistory_Variable(void)
    {
        return clientUserIdHistory_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::clientUserIdOfSession_Variable(void)
    {
        return clientUserIdOfSession_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::encoding_Variable(void)
    {
        return encoding_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::securityPolicyUri_Variable(void)
    {
        return securityPolicyUri_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::transportProtocol_Variable(void)
    {
        return transportProtocol_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsType::variable(void)
    {
        return variable_;
    }

    void
    SessionSecurityDiagnosticsType::authenticationMechanism_Variable(ServerVariable::SPtr& serverVariable)
    {
        authenticationMechanism_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::clientCertificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientCertificate_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::clientUserIdHistory_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserIdHistory_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::clientUserIdOfSession_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserIdOfSession_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::encoding_Variable(ServerVariable::SPtr& serverVariable)
    {
        encoding_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityPolicyUri_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::transportProtocol_Variable(ServerVariable::SPtr& serverVariable)
    {
        transportProtocol_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SessionSecurityDiagnosticsType::get_AuthenticationMechanism_Variable(OpcUaDataValue& dataValue)
    {
        return authenticationMechanism_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_ClientCertificate_Variable(OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_ClientUserIdHistory_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserIdHistory_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_ClientUserIdOfSession_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserIdOfSession_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_Encoding_Variable(OpcUaDataValue& dataValue)
    {
        return encoding_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_TransportProtocol_Variable(OpcUaDataValue& dataValue)
    {
        return transportProtocol_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_AuthenticationMechanism_Variable(const OpcUaDataValue& dataValue)
    {
        return authenticationMechanism_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_ClientCertificate_Variable(const OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_ClientUserIdHistory_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserIdHistory_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_ClientUserIdOfSession_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserIdOfSession_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_Encoding_Variable(const OpcUaDataValue& dataValue)
    {
        return encoding_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_TransportProtocol_Variable(const OpcUaDataValue& dataValue)
    {
        return transportProtocol_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
