/*
    VariableTypeClass: AuditHistoryRawModifyDeleteEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditHistoryRawModifyDeleteEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AuditHistoryRawModifyDeleteEventType::AuditHistoryRawModifyDeleteEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , endTime_Variable_(boost::make_shared<ServerVariable>("EndTime_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , isDeleteModified_Variable_(boost::make_shared<ServerVariable>("IsDeleteModified_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , updatedNode_Variable_(boost::make_shared<ServerVariable>("UpdatedNode_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)3014);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(endTime_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(isDeleteModified_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(startTime_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryRawModifyDeleteEventType::AuditHistoryRawModifyDeleteEventType(const AuditHistoryRawModifyDeleteEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , endTime_Variable_(boost::make_shared<ServerVariable>("EndTime_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , isDeleteModified_Variable_(boost::make_shared<ServerVariable>("IsDeleteModified_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , oldValues_Variable_(boost::make_shared<ServerVariable>("OldValues_Variable"))
    , parameterDataTypeId_Variable_(boost::make_shared<ServerVariable>("ParameterDataTypeId_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , startTime_Variable_(boost::make_shared<ServerVariable>("StartTime_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , updatedNode_Variable_(boost::make_shared<ServerVariable>("UpdatedNode_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)3014);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(endTime_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(isDeleteModified_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(oldValues_Variable_);
        setServerVariable(parameterDataTypeId_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(startTime_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(updatedNode_Variable_);
    }
    
    AuditHistoryRawModifyDeleteEventType::~AuditHistoryRawModifyDeleteEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::endTime_Variable(void)
    {
        return endTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::isDeleteModified_Variable(void)
    {
        return isDeleteModified_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::oldValues_Variable(void)
    {
        return oldValues_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::parameterDataTypeId_Variable(void)
    {
        return parameterDataTypeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::startTime_Variable(void)
    {
        return startTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    AuditHistoryRawModifyDeleteEventType::updatedNode_Variable(void)
    {
        return updatedNode_Variable_;
    }

    void
    AuditHistoryRawModifyDeleteEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::endTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        endTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::isDeleteModified_Variable(ServerVariable::SPtr& serverVariable)
    {
        isDeleteModified_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::oldValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        oldValues_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        parameterDataTypeId_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::startTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        startTime_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    AuditHistoryRawModifyDeleteEventType::updatedNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        updatedNode_Variable_ = serverVariable;
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_EndTime_Variable(OpcUaDataValue& dataValue)
    {
        return endTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_IsDeleteModified_Variable(OpcUaDataValue& dataValue)
    {
        return isDeleteModified_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_OldValues_Variable(OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ParameterDataTypeId_Variable(OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_StartTime_Variable(OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::get_UpdatedNode_Variable(OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_EndTime_Variable(const OpcUaDataValue& dataValue)
    {
        return endTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_IsDeleteModified_Variable(const OpcUaDataValue& dataValue)
    {
        return isDeleteModified_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_OldValues_Variable(const OpcUaDataValue& dataValue)
    {
        return oldValues_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ParameterDataTypeId_Variable(const OpcUaDataValue& dataValue)
    {
        return parameterDataTypeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_StartTime_Variable(const OpcUaDataValue& dataValue)
    {
        return startTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    AuditHistoryRawModifyDeleteEventType::set_UpdatedNode_Variable(const OpcUaDataValue& dataValue)
    {
        return updatedNode_Variable_->setDataValue(dataValue);
    }

}
