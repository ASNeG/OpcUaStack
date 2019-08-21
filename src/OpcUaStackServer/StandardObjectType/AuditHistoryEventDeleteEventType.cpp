/*
    VariableTypeClass: AuditHistoryEventDeleteEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditHistoryEventDeleteEventType.h"

namespace OpcUaStackServer
{
    
    AuditHistoryEventDeleteEventType::AuditHistoryEventDeleteEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventIds_Variable_(boost::make_shared<ServerVariable>("EventIds_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)3022);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventIds_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryEventDeleteEventType::AuditHistoryEventDeleteEventType(const AuditHistoryEventDeleteEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventIds_Variable_(boost::make_shared<ServerVariable>("EventIds_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)3022);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventIds_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryEventDeleteEventType::~AuditHistoryEventDeleteEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::eventIds_Variable(void)
    {
        return eventIds_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::oldValues_Variable(void)
    {
        return oldValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::parameterDataTypeId_Variable(void)
    {
        return parameterDataTypeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryEventDeleteEventType::updatedNode_Variable(void)
    {
        return updatedNode_Variable_;
    }

    void
    AuditHistoryEventDeleteEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::eventIds_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventIds_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::oldValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        oldValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        parameterDataTypeId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    AuditHistoryEventDeleteEventType::updatedNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        updatedNode_Variable_ = serverVariable;
    }

    bool
    AuditHistoryEventDeleteEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_EventIds_Variable(OpcUaDataValue& dataValue)
    {
        return eventIds_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_OldValues_Variable(OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_ParameterDataTypeId_Variable(OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::get_UpdatedNode_Variable(OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_EventIds_Variable(const OpcUaDataValue& dataValue)
    {
        return eventIds_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_OldValues_Variable(const OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ParameterDataTypeId_Variable(const OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryEventDeleteEventType::set_UpdatedNode_Variable(const OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->setDataValue(dataValue);
    }

}
