/*
    VariableTypeClass: AuditActivateSessionEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditActivateSessionEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AuditActivateSessionEventType::AuditActivateSessionEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientSoftwareCertificates_Variable_(boost::make_shared<ServerVariable>("ClientSoftwareCertificates_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , userIdentityToken_Variable_(boost::make_shared<ServerVariable>("UserIdentityToken_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2075);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientSoftwareCertificates_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(userIdentityToken_Variable_);
    }
    
    AuditActivateSessionEventType::AuditActivateSessionEventType(const AuditActivateSessionEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientSoftwareCertificates_Variable_(boost::make_shared<ServerVariable>("ClientSoftwareCertificates_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , secureChannelId_Variable_(boost::make_shared<ServerVariable>("SecureChannelId_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , userIdentityToken_Variable_(boost::make_shared<ServerVariable>("UserIdentityToken_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2075);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientSoftwareCertificates_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(secureChannelId_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(userIdentityToken_Variable_);
    }
    
    AuditActivateSessionEventType::~AuditActivateSessionEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::clientSoftwareCertificates_Variable(void)
    {
        return clientSoftwareCertificates_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::secureChannelId_Variable(void)
    {
        return secureChannelId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::statusCodeId_Variable(void)
    {
        return statusCodeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    AuditActivateSessionEventType::userIdentityToken_Variable(void)
    {
        return userIdentityToken_Variable_;
    }

    void
    AuditActivateSessionEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::clientSoftwareCertificates_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientSoftwareCertificates_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::secureChannelId_Variable(ServerVariable::SPtr& serverVariable)
    {
        secureChannelId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::statusCodeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        statusCodeId_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    AuditActivateSessionEventType::userIdentityToken_Variable(ServerVariable::SPtr& serverVariable)
    {
        userIdentityToken_Variable_ = serverVariable;
    }

    bool
    AuditActivateSessionEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_ClientSoftwareCertificates_Variable(OpcUaDataValue& dataValue)
    {
        return clientSoftwareCertificates_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_SecureChannelId_Variable(OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_StatusCodeId_Variable(OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::get_UserIdentityToken_Variable(OpcUaDataValue& dataValue)
    {
        return userIdentityToken_Variable_->getDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ClientSoftwareCertificates_Variable(const OpcUaDataValue& dataValue)
    {
        return clientSoftwareCertificates_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_SecureChannelId_Variable(const OpcUaDataValue& dataValue)
    {
        return secureChannelId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_StatusCodeId_Variable(const OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    AuditActivateSessionEventType::set_UserIdentityToken_Variable(const OpcUaDataValue& dataValue)
    {
        return userIdentityToken_Variable_->setDataValue(dataValue);
    }

}
