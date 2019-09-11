/*
    VariableTypeClass: AuditHistoryValueUpdateEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditHistoryValueUpdateEventType.h"

namespace OpcUaStackServer
{
    
    AuditHistoryValueUpdateEventType::AuditHistoryValueUpdateEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , newValues_Variable_(boost::make_shared<ServerVariable>("NewValues_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
    , performInsertReplace_Variable_(boost::make_shared<ServerVariable>("PerformInsertReplace_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , updatedNode_Variable_(boost::make_shared<ServerVariable>("UpdatedNode_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)3006);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(newValues_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(performInsertReplace_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryValueUpdateEventType::AuditHistoryValueUpdateEventType(const AuditHistoryValueUpdateEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , newValues_Variable_(boost::make_shared<ServerVariable>("NewValues_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
    , performInsertReplace_Variable_(boost::make_shared<ServerVariable>("PerformInsertReplace_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , updatedNode_Variable_(boost::make_shared<ServerVariable>("UpdatedNode_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)3006);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(newValues_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(performInsertReplace_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryValueUpdateEventType::~AuditHistoryValueUpdateEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::newValues_Variable(void)
    {
        return newValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::oldValues_Variable(void)
    {
        return oldValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::parameterDataTypeId_Variable(void)
    {
        return parameterDataTypeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::performInsertReplace_Variable(void)
    {
        return performInsertReplace_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryValueUpdateEventType::updatedNode_Variable(void)
    {
        return updatedNode_Variable_;
    }

    void
    AuditHistoryValueUpdateEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::newValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        newValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::oldValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        oldValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        parameterDataTypeId_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::performInsertReplace_Variable(ServerVariable::SPtr& serverVariable)
    {
        performInsertReplace_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    AuditHistoryValueUpdateEventType::updatedNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        updatedNode_Variable_ = serverVariable;
    }

    bool
    AuditHistoryValueUpdateEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_NewValues_Variable(OpcUaDataValue& dataValue)
    {
        return newValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_OldValues_Variable(OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_ParameterDataTypeId_Variable(OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_PerformInsertReplace_Variable(OpcUaDataValue& dataValue)
    {
        return performInsertReplace_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::get_UpdatedNode_Variable(OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_NewValues_Variable(const OpcUaDataValue& dataValue)
    {
        return newValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_OldValues_Variable(const OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ParameterDataTypeId_Variable(const OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_PerformInsertReplace_Variable(const OpcUaDataValue& dataValue)
    {
        return performInsertReplace_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryValueUpdateEventType::set_UpdatedNode_Variable(const OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->setDataValue(dataValue);
    }

}
