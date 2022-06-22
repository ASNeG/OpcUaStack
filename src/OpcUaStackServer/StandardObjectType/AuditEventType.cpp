/*
    VariableTypeClass: AuditEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * A base type for events used to track client initiated changes to the server state.
     */
    AuditEventType::AuditEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2052);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    /**
     * A base type for events used to track client initiated changes to the server state.
     */
    AuditEventType::AuditEventType(const AuditEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2052);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditEventType::~AuditEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    AuditEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    AuditEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
