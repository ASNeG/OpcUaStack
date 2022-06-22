/*
    VariableTypeClass: CertificateUpdatedAuditEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/CertificateUpdatedAuditEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    CertificateUpdatedAuditEventType::CertificateUpdatedAuditEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , certificateGroup_Variable_(boost::make_shared<ServerVariable>("CertificateGroup_Variable"))
    , certificateType_Variable_(boost::make_shared<ServerVariable>("CertificateType_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , methodId_Variable_(boost::make_shared<ServerVariable>("MethodId_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12620);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(certificateGroup_Variable_);
        setServerVariable(certificateType_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(methodId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    CertificateUpdatedAuditEventType::CertificateUpdatedAuditEventType(const CertificateUpdatedAuditEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , certificateGroup_Variable_(boost::make_shared<ServerVariable>("CertificateGroup_Variable"))
    , certificateType_Variable_(boost::make_shared<ServerVariable>("CertificateType_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , methodId_Variable_(boost::make_shared<ServerVariable>("MethodId_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12620);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(certificateGroup_Variable_);
        setServerVariable(certificateType_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(methodId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    CertificateUpdatedAuditEventType::~CertificateUpdatedAuditEventType(void)
    {
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::certificateGroup_Variable(void)
    {
        return certificateGroup_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::certificateType_Variable(void)
    {
        return certificateType_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::methodId_Variable(void)
    {
        return methodId_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    CertificateUpdatedAuditEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    CertificateUpdatedAuditEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::certificateGroup_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateGroup_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::certificateType_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificateType_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::methodId_Variable(ServerVariable::SPtr& serverVariable)
    {
        methodId_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    CertificateUpdatedAuditEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    CertificateUpdatedAuditEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_CertificateGroup_Variable(OpcUaDataValue& dataValue)
    {
        return certificateGroup_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_CertificateType_Variable(OpcUaDataValue& dataValue)
    {
        return certificateType_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_MethodId_Variable(OpcUaDataValue& dataValue)
    {
        return methodId_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_CertificateGroup_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateGroup_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_CertificateType_Variable(const OpcUaDataValue& dataValue)
    {
        return certificateType_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_MethodId_Variable(const OpcUaDataValue& dataValue)
    {
        return methodId_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    CertificateUpdatedAuditEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
