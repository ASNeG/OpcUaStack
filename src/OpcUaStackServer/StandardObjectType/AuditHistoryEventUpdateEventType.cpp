/*
    VariableTypeClass: AuditHistoryEventUpdateEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditHistoryEventUpdateEventType.h"

namespace OpcUaStackServer
{
    
    AuditHistoryEventUpdateEventType::AuditHistoryEventUpdateEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , filter_Variable_(boost::make_shared<ServerVariable>("Filter_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)2999);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(filter_Variable_);
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
    
    AuditHistoryEventUpdateEventType::AuditHistoryEventUpdateEventType(const AuditHistoryEventUpdateEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , filter_Variable_(boost::make_shared<ServerVariable>("Filter_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)2999);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(filter_Variable_);
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
    
    AuditHistoryEventUpdateEventType::~AuditHistoryEventUpdateEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::filter_Variable(void)
    {
        return filter_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::newValues_Variable(void)
    {
        return newValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::oldValues_Variable(void)
    {
        return oldValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::parameterDataTypeId_Variable(void)
    {
        return parameterDataTypeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::performInsertReplace_Variable(void)
    {
        return performInsertReplace_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventUpdateEventType::updatedNode_Variable(void)
    {
        return updatedNode_Variable_;
    }

    void
    AuditHistoryEventUpdateEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::filter_Variable(ServerVariable::SPtr& serverVariable)
    {
        filter_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::newValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        newValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::oldValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        oldValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        parameterDataTypeId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::performInsertReplace_Variable(ServerVariable::SPtr& serverVariable)
    {
        performInsertReplace_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventUpdateEventType::updatedNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        updatedNode_Variable_ = serverVariable;
    }

    bool
    AuditHistoryEventUpdateEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_Filter_Variable(OpcUaDataValue& dataValue)
    {
        return filter_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_NewValues_Variable(OpcUaDataValue& dataValue)
    {
        return newValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_OldValues_Variable(OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_ParameterDataTypeId_Variable(OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_PerformInsertReplace_Variable(OpcUaDataValue& dataValue)
    {
        return performInsertReplace_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::get_UpdatedNode_Variable(OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_Filter_Variable(const OpcUaDataValue& dataValue)
    {
        return filter_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_NewValues_Variable(const OpcUaDataValue& dataValue)
    {
        return newValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_OldValues_Variable(const OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ParameterDataTypeId_Variable(const OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_PerformInsertReplace_Variable(const OpcUaDataValue& dataValue)
    {
        return performInsertReplace_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventUpdateEventType::set_UpdatedNode_Variable(const OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->setDataValue(dataValue);
    }

}
