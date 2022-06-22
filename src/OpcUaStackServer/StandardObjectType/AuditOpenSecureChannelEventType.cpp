/*
    VariableTypeClass: AuditOpenSecureChannelEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditOpenSecureChannelEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * An event that is raised when a secure channel is opened.
     */
    AuditOpenSecureChannelEventType::AuditOpenSecureChannelEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientCertificateThumbprint_Variable_(boost::make_shared<ServerVariable>("ClientCertificateThumbprint_Variable"))
    , clientCertificate_Variable_(boost::make_shared<ServerVariable>("ClientCertificate_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , requestType_Variable_(boost::make_shared<ServerVariable>("RequestType_Variable"))
    , requestedLifetime_Variable_(boost::make_shared<ServerVariable>("RequestedLifetime_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , securityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SecurityPolicyUri_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2060);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientCertificateThumbprint_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(requestType_Variable_);
        setServerVariable(requestedLifetime_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    /**
     * An event that is raised when a secure channel is opened.
     */
    AuditOpenSecureChannelEventType::AuditOpenSecureChannelEventType(const AuditOpenSecureChannelEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientCertificateThumbprint_Variable_(boost::make_shared<ServerVariable>("ClientCertificateThumbprint_Variable"))
    , clientCertificate_Variable_(boost::make_shared<ServerVariable>("ClientCertificate_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , requestType_Variable_(boost::make_shared<ServerVariable>("RequestType_Variable"))
    , requestedLifetime_Variable_(boost::make_shared<ServerVariable>("RequestedLifetime_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , securityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SecurityPolicyUri_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2060);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientCertificateThumbprint_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(requestType_Variable_);
        setServerVariable(requestedLifetime_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditOpenSecureChannelEventType::~AuditOpenSecureChannelEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::clientCertificateThumbprint_Variable(void)
    {
        return clientCertificateThumbprint_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::clientCertificate_Variable(void)
    {
        return clientCertificate_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::requestType_Variable(void)
    {
        return requestType_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::requestedLifetime_Variable(void)
    {
        return requestedLifetime_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::secureChannelId_Variable(void)
    {
        return secureChannelId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::securityPolicyUri_Variable(void)
    {
        return securityPolicyUri_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::statusCodeId_Variable(void)
    {
        return statusCodeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditOpenSecureChannelEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    AuditOpenSecureChannelEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::clientCertificateThumbprint_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientCertificateThumbprint_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::clientCertificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientCertificate_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::requestType_Variable(ServerVariable::SPtr& serverVariable)
    {
        requestType_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::requestedLifetime_Variable(ServerVariable::SPtr& serverVariable)
    {
        requestedLifetime_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::secureChannelId_Variable(ServerVariable::SPtr& serverVariable)
    {
        secureChannelId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityPolicyUri_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::statusCodeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        statusCodeId_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditOpenSecureChannelEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    AuditOpenSecureChannelEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ClientCertificateThumbprint_Variable(OpcUaDataValue& dataValue)
    {
        return clientCertificateThumbprint_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ClientCertificate_Variable(OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_RequestType_Variable(OpcUaDataValue& dataValue)
    {
        return requestType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_RequestedLifetime_Variable(OpcUaDataValue& dataValue)
    {
        return requestedLifetime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_SecureChannelId_Variable(OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_StatusCodeId_Variable(OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ClientCertificateThumbprint_Variable(const OpcUaDataValue& dataValue)
    {
        return clientCertificateThumbprint_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ClientCertificate_Variable(const OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_RequestType_Variable(const OpcUaDataValue& dataValue)
    {
        return requestType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_RequestedLifetime_Variable(const OpcUaDataValue& dataValue)
    {
        return requestedLifetime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_SecureChannelId_Variable(const OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_StatusCodeId_Variable(const OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditOpenSecureChannelEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
