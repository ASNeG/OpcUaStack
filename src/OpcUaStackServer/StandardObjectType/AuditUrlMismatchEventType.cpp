/*
    VariableTypeClass: AuditUrlMismatchEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditUrlMismatchEventType.h"

namespace OpcUaStackServer
{
    
    AuditUrlMismatchEventType::AuditUrlMismatchEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientCertificateThumbprint_Variable_(boost::make_shared<ServerVariable>("ClientCertificateThumbprint_Variable"))
    , clientCertificate_Variable_(boost::make_shared<ServerVariable>("ClientCertificate_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , endpointUrl_Variable_(boost::make_shared<ServerVariable>("EndpointUrl_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , revisedSessionTimeout_Variable_(boost::make_shared<ServerVariable>("RevisedSessionTimeout_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2748);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientCertificateThumbprint_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(revisedSessionTimeout_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditUrlMismatchEventType::AuditUrlMismatchEventType(const AuditUrlMismatchEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientCertificateThumbprint_Variable_(boost::make_shared<ServerVariable>("ClientCertificateThumbprint_Variable"))
    , clientCertificate_Variable_(boost::make_shared<ServerVariable>("ClientCertificate_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , endpointUrl_Variable_(boost::make_shared<ServerVariable>("EndpointUrl_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , revisedSessionTimeout_Variable_(boost::make_shared<ServerVariable>("RevisedSessionTimeout_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2748);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientCertificateThumbprint_Variable_);
        setServerVariable(clientCertificate_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(revisedSessionTimeout_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditUrlMismatchEventType::~AuditUrlMismatchEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::clientCertificateThumbprint_Variable(void)
    {
        return clientCertificateThumbprint_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::clientCertificate_Variable(void)
    {
        return clientCertificate_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::endpointUrl_Variable(void)
    {
        return endpointUrl_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::revisedSessionTimeout_Variable(void)
    {
        return revisedSessionTimeout_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::secureChannelId_Variable(void)
    {
        return secureChannelId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::statusCodeId_Variable(void)
    {
        return statusCodeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditUrlMismatchEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    AuditUrlMismatchEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::clientCertificateThumbprint_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientCertificateThumbprint_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::clientCertificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientCertificate_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::endpointUrl_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpointUrl_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::revisedSessionTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        revisedSessionTimeout_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::secureChannelId_Variable(ServerVariable::SPtr& serverVariable)
    {
        secureChannelId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::statusCodeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        statusCodeId_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditUrlMismatchEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    AuditUrlMismatchEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ClientCertificateThumbprint_Variable(OpcUaDataValue& dataValue)
    {
        return clientCertificateThumbprint_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ClientCertificate_Variable(OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_EndpointUrl_Variable(OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_RevisedSessionTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return revisedSessionTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_SecureChannelId_Variable(OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_StatusCodeId_Variable(OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ClientCertificateThumbprint_Variable(const OpcUaDataValue& dataValue)
    {
        return clientCertificateThumbprint_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ClientCertificate_Variable(const OpcUaDataValue& dataValue)
    {
        return clientCertificate_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_EndpointUrl_Variable(const OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_RevisedSessionTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return revisedSessionTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_SecureChannelId_Variable(const OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_StatusCodeId_Variable(const OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditUrlMismatchEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
