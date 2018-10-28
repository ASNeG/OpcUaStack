/*
    VariableTypeClass: SessionSecurityDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionSecurityDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    SessionSecurityDiagnosticsType::SessionSecurityDiagnosticsType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , sessionId_(constructSPtr<ServerVariable>("SessionId"))
    , clientUserIdOfSession_(constructSPtr<ServerVariable>("ClientUserIdOfSession"))
    , clientUserIdHistory_(constructSPtr<ServerVariable>("ClientUserIdHistory"))
    , authenticationMechanism_(constructSPtr<ServerVariable>("AuthenticationMechanism"))
    , encoding_(constructSPtr<ServerVariable>("Encoding"))
    , transportProtocol_(constructSPtr<ServerVariable>("TransportProtocol"))
    , securityMode_(constructSPtr<ServerVariable>("SecurityMode"))
    , securityPolicyUri_(constructSPtr<ServerVariable>("SecurityPolicyUri"))
    , clientCertificate_(constructSPtr<ServerVariable>("ClientCertificate"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2244));
        serverVariables().registerServerVariable(sessionId_);
        serverVariables().registerServerVariable(clientUserIdOfSession_);
        serverVariables().registerServerVariable(clientUserIdHistory_);
        serverVariables().registerServerVariable(authenticationMechanism_);
        serverVariables().registerServerVariable(encoding_);
        serverVariables().registerServerVariable(transportProtocol_);
        serverVariables().registerServerVariable(securityMode_);
        serverVariables().registerServerVariable(securityPolicyUri_);
        serverVariables().registerServerVariable(clientCertificate_);
    }
    
    SessionSecurityDiagnosticsType::~SessionSecurityDiagnosticsType(void)
    {
    }
    
    bool
    SessionSecurityDiagnosticsType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        sessionId_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionId", namespaceIndex_));
        clientUserIdOfSession_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientUserIdOfSession", namespaceIndex_));
        clientUserIdHistory_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientUserIdHistory", namespaceIndex_));
        authenticationMechanism_->addBrowsePath(nodeId, OpcUaQualifiedName("AuthenticationMechanism", namespaceIndex_));
        encoding_->addBrowsePath(nodeId, OpcUaQualifiedName("Encoding", namespaceIndex_));
        transportProtocol_->addBrowsePath(nodeId, OpcUaQualifiedName("TransportProtocol", namespaceIndex_));
        securityMode_->addBrowsePath(nodeId, OpcUaQualifiedName("SecurityMode", namespaceIndex_));
        securityPolicyUri_->addBrowsePath(nodeId, OpcUaQualifiedName("SecurityPolicyUri", namespaceIndex_));
        clientCertificate_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientCertificate", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::sessionId(void)
    {
        return sessionId_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setSessionId(const OpcUaDataValue& dataValue)
    {
        return sessionId_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getSessionId(OpcUaDataValue& dataValue)
    {
        return sessionId_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackSessionId(Callback::SPtr& callback)
    {
        sessionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::clientUserIdOfSession(void)
    {
        return clientUserIdOfSession_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setClientUserIdOfSession(const OpcUaDataValue& dataValue)
    {
        return clientUserIdOfSession_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getClientUserIdOfSession(OpcUaDataValue& dataValue)
    {
        return clientUserIdOfSession_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackClientUserIdOfSession(Callback::SPtr& callback)
    {
        clientUserIdOfSession_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::clientUserIdHistory(void)
    {
        return clientUserIdHistory_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setClientUserIdHistory(const OpcUaDataValue& dataValue)
    {
        return clientUserIdHistory_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getClientUserIdHistory(OpcUaDataValue& dataValue)
    {
        return clientUserIdHistory_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackClientUserIdHistory(Callback::SPtr& callback)
    {
        clientUserIdHistory_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::authenticationMechanism(void)
    {
        return authenticationMechanism_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setAuthenticationMechanism(const OpcUaDataValue& dataValue)
    {
        return authenticationMechanism_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getAuthenticationMechanism(OpcUaDataValue& dataValue)
    {
        return authenticationMechanism_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackAuthenticationMechanism(Callback::SPtr& callback)
    {
        authenticationMechanism_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::encoding(void)
    {
        return encoding_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setEncoding(const OpcUaDataValue& dataValue)
    {
        return encoding_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getEncoding(OpcUaDataValue& dataValue)
    {
        return encoding_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackEncoding(Callback::SPtr& callback)
    {
        encoding_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::transportProtocol(void)
    {
        return transportProtocol_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setTransportProtocol(const OpcUaDataValue& dataValue)
    {
        return transportProtocol_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getTransportProtocol(OpcUaDataValue& dataValue)
    {
        return transportProtocol_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackTransportProtocol(Callback::SPtr& callback)
    {
        transportProtocol_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::securityMode(void)
    {
        return securityMode_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setSecurityMode(const OpcUaDataValue& dataValue)
    {
        return securityMode_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getSecurityMode(OpcUaDataValue& dataValue)
    {
        return securityMode_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackSecurityMode(Callback::SPtr& callback)
    {
        securityMode_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::securityPolicyUri(void)
    {
        return securityPolicyUri_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setSecurityPolicyUri(const OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getSecurityPolicyUri(OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackSecurityPolicyUri(Callback::SPtr& callback)
    {
        securityPolicyUri_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionSecurityDiagnosticsType::clientCertificate(void)
    {
        return clientCertificate_->baseNode().lock();
    }
    
    bool
    SessionSecurityDiagnosticsType::setClientCertificate(const OpcUaDataValue& dataValue)
    {
        return clientCertificate_->setDataValue(dataValue);
    }
    
    bool
    SessionSecurityDiagnosticsType::getClientCertificate(OpcUaDataValue& dataValue)
    {
        return clientCertificate_->getDataValue(dataValue);
    }
    
    void
    SessionSecurityDiagnosticsType::setUpdateCallbackClientCertificate(Callback::SPtr& callback)
    {
        clientCertificate_->callback(callback);
    }

}
