/*
    VariableTypeClass: PubSubTransportLimitsExceedEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubTransportLimitsExceedEventType.h"

namespace OpcUaStackServer
{
    
    PubSubTransportLimitsExceedEventType::PubSubTransportLimitsExceedEventType(void)
    : ObjectBase()
    , actual_Variable_(boost::make_shared<ServerVariable>("Actual_Variable"))
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , groupId_Variable_(boost::make_shared<ServerVariable>("GroupId_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , maximum_Variable_(boost::make_shared<ServerVariable>("Maximum_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15548);
        setServerVariable(actual_Variable_);
        setServerVariable(connectionId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(groupId_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(maximum_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(time_Variable_);
    }
    
    PubSubTransportLimitsExceedEventType::PubSubTransportLimitsExceedEventType(const PubSubTransportLimitsExceedEventType& value)
    : ObjectBase()
    , actual_Variable_(boost::make_shared<ServerVariable>("Actual_Variable"))
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , groupId_Variable_(boost::make_shared<ServerVariable>("GroupId_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , maximum_Variable_(boost::make_shared<ServerVariable>("Maximum_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , state_Variable_(boost::make_shared<ServerVariable>("State_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15548);
        setServerVariable(actual_Variable_);
        setServerVariable(connectionId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(groupId_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(maximum_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(state_Variable_);
        setServerVariable(time_Variable_);
    }
    
    PubSubTransportLimitsExceedEventType::~PubSubTransportLimitsExceedEventType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::actual_Variable(void)
    {
        return actual_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::connectionId_Variable(void)
    {
        return connectionId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::groupId_Variable(void)
    {
        return groupId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::maximum_Variable(void)
    {
        return maximum_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::state_Variable(void)
    {
        return state_Variable_;
    }

    ServerVariable::SPtr&
    PubSubTransportLimitsExceedEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    PubSubTransportLimitsExceedEventType::actual_Variable(ServerVariable::SPtr& serverVariable)
    {
        actual_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::connectionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        connectionId_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::groupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupId_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::maximum_Variable(ServerVariable::SPtr& serverVariable)
    {
        maximum_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::state_Variable(ServerVariable::SPtr& serverVariable)
    {
        state_Variable_ = serverVariable;
    }

    void
    PubSubTransportLimitsExceedEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    PubSubTransportLimitsExceedEventType::get_Actual_Variable(OpcUaDataValue& dataValue)
    {
        return actual_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_ConnectionId_Variable(OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_GroupId_Variable(OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_Maximum_Variable(OpcUaDataValue& dataValue)
    {
        return maximum_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_State_Variable(OpcUaDataValue& dataValue)
    {
        return state_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_Actual_Variable(const OpcUaDataValue& dataValue)
    {
        return actual_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_ConnectionId_Variable(const OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_GroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_Maximum_Variable(const OpcUaDataValue& dataValue)
    {
        return maximum_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_State_Variable(const OpcUaDataValue& dataValue)
    {
        return state_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubTransportLimitsExceedEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
