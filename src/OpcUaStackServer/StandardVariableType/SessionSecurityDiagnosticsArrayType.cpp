/*
    VariableTypeClass: SessionSecurityDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionSecurityDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SessionSecurityDiagnosticsArrayType::SessionSecurityDiagnosticsArrayType(void)
    : VariableBase()
    , sessionSecurityDiagnostics_AuthenticationMechanism_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_AuthenticationMechanism_Variable"))
    , sessionSecurityDiagnostics_ClientCertificate_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientCertificate_Variable"))
    , sessionSecurityDiagnostics_ClientUserIdHistory_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientUserIdHistory_Variable"))
    , sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientUserIdOfSession_Variable"))
    , sessionSecurityDiagnostics_Encoding_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_Encoding_Variable"))
    , sessionSecurityDiagnostics_SecurityMode_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SecurityMode_Variable"))
    , sessionSecurityDiagnostics_SecurityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SecurityPolicyUri_Variable"))
    , sessionSecurityDiagnostics_SessionId_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SessionId_Variable"))
    , sessionSecurityDiagnostics_TransportProtocol_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_TransportProtocol_Variable"))
    , sessionSecurityDiagnostics_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2243);
        setServerVariable(sessionSecurityDiagnostics_AuthenticationMechanism_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientCertificate_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientUserIdHistory_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_);
        setServerVariable(sessionSecurityDiagnostics_Encoding_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SecurityMode_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SecurityPolicyUri_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SessionId_Variable_);
        setServerVariable(sessionSecurityDiagnostics_TransportProtocol_Variable_);
        setServerVariable(sessionSecurityDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsArrayType::SessionSecurityDiagnosticsArrayType(const SessionSecurityDiagnosticsArrayType& value)
    : VariableBase()
    , sessionSecurityDiagnostics_AuthenticationMechanism_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_AuthenticationMechanism_Variable"))
    , sessionSecurityDiagnostics_ClientCertificate_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientCertificate_Variable"))
    , sessionSecurityDiagnostics_ClientUserIdHistory_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientUserIdHistory_Variable"))
    , sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_ClientUserIdOfSession_Variable"))
    , sessionSecurityDiagnostics_Encoding_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_Encoding_Variable"))
    , sessionSecurityDiagnostics_SecurityMode_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SecurityMode_Variable"))
    , sessionSecurityDiagnostics_SecurityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SecurityPolicyUri_Variable"))
    , sessionSecurityDiagnostics_SessionId_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_SessionId_Variable"))
    , sessionSecurityDiagnostics_TransportProtocol_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_TransportProtocol_Variable"))
    , sessionSecurityDiagnostics_Variable_(boost::make_shared<ServerVariable>("SessionSecurityDiagnostics_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2243);
        setServerVariable(sessionSecurityDiagnostics_AuthenticationMechanism_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientCertificate_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientUserIdHistory_Variable_);
        setServerVariable(sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_);
        setServerVariable(sessionSecurityDiagnostics_Encoding_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SecurityMode_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SecurityPolicyUri_Variable_);
        setServerVariable(sessionSecurityDiagnostics_SessionId_Variable_);
        setServerVariable(sessionSecurityDiagnostics_TransportProtocol_Variable_);
        setServerVariable(sessionSecurityDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsArrayType::~SessionSecurityDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_AuthenticationMechanism_Variable(void)
    {
        return sessionSecurityDiagnostics_AuthenticationMechanism_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientCertificate_Variable(void)
    {
        return sessionSecurityDiagnostics_ClientCertificate_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientUserIdHistory_Variable(void)
    {
        return sessionSecurityDiagnostics_ClientUserIdHistory_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(void)
    {
        return sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_Encoding_Variable(void)
    {
        return sessionSecurityDiagnostics_Encoding_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SecurityMode_Variable(void)
    {
        return sessionSecurityDiagnostics_SecurityMode_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SecurityPolicyUri_Variable(void)
    {
        return sessionSecurityDiagnostics_SecurityPolicyUri_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SessionId_Variable(void)
    {
        return sessionSecurityDiagnostics_SessionId_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_TransportProtocol_Variable(void)
    {
        return sessionSecurityDiagnostics_TransportProtocol_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_Variable(void)
    {
        return sessionSecurityDiagnostics_Variable_;
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_AuthenticationMechanism_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_AuthenticationMechanism_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientCertificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_ClientCertificate_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientUserIdHistory_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_ClientUserIdHistory_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_Encoding_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_Encoding_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SecurityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_SecurityMode_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SecurityPolicyUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_SecurityPolicyUri_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_SessionId_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_TransportProtocol_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_TransportProtocol_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::sessionSecurityDiagnostics_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionSecurityDiagnostics_Variable_ = serverVariable;
    }

    void
    SessionSecurityDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_AuthenticationMechanism_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_ClientCertificate_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientCertificate_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientUserIdHistory_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_Encoding_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_Encoding_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SecurityMode_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SecurityPolicyUri_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_TransportProtocol_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_TransportProtocol_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_SessionSecurityDiagnostics_Variable(OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_Variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_AuthenticationMechanism_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_ClientCertificate_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientCertificate_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientUserIdHistory_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_Encoding_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_Encoding_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SecurityMode_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SecurityPolicyUri_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_SessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_TransportProtocol_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_TransportProtocol_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_SessionSecurityDiagnostics_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionSecurityDiagnostics_Variable_->setDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
