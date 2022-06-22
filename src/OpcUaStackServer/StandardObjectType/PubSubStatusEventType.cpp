/*
    VariableTypeClass: PubSubStatusEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubStatusEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubStatusEventType::PubSubStatusEventType(void)
    : ObjectBase()
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , groupId_Variable_(boost::make_shared<ServerVariable>("GroupId_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15535);
        setServerVariable(connectionId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(groupId_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(time_Variable_);
    }
    
    PubSubStatusEventType::PubSubStatusEventType(const PubSubStatusEventType& value)
    : ObjectBase()
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , groupId_Variable_(boost::make_shared<ServerVariable>("GroupId_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15535);
        setServerVariable(connectionId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(groupId_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(time_Variable_);
    }
    
    PubSubStatusEventType::~PubSubStatusEventType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::connectionId_Variable(void)
    {
        return connectionId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::groupId_Variable(void)
    {
        return groupId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::state_Variable(void)
    {
        return state_Variable_;
    }

    ServerVariable::SPtr&
    PubSubStatusEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    PubSubStatusEventType::connectionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        connectionId_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::groupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupId_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::state_Variable(ServerVariable::SPtr& serverVariable)
    {
        state_Variable_ = serverVariable;
    }

    void
    PubSubStatusEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    PubSubStatusEventType::get_ConnectionId_Variable(OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_GroupId_Variable(OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_State_Variable(OpcUaDataValue& dataValue)
    {
        return state_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_ConnectionId_Variable(const OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_GroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_State_Variable(const OpcUaDataValue& dataValue)
    {
        return state_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubStatusEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
