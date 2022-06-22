/*
    VariableTypeClass: AuditConditionResetEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditConditionResetEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AuditConditionResetEventType::AuditConditionResetEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)15013);
        setServerVariable(actionTimeStamp_Variable_);
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
    
    AuditConditionResetEventType::AuditConditionResetEventType(const AuditConditionResetEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)15013);
        setServerVariable(actionTimeStamp_Variable_);
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
    
    AuditConditionResetEventType::~AuditConditionResetEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::methodId_Variable(void)
    {
        return methodId_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditConditionResetEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    AuditConditionResetEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::methodId_Variable(ServerVariable::SPtr& serverVariable)
    {
        methodId_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditConditionResetEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    AuditConditionResetEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_MethodId_Variable(OpcUaDataValue& dataValue)
    {
        return methodId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_MethodId_Variable(const OpcUaDataValue& dataValue)
    {
        return methodId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditConditionResetEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
