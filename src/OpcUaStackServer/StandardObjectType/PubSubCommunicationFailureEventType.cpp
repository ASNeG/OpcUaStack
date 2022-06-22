/*
    VariableTypeClass: PubSubCommunicationFailureEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubCommunicationFailureEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubCommunicationFailureEventType::PubSubCommunicationFailureEventType(void)
    : ObjectBase()
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , error_Variable_(boost::make_shared<ServerVariable>("Error_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)15563);
        setServerVariable(connectionId_Variable_);
        setServerVariable(error_Variable_);
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
    
    PubSubCommunicationFailureEventType::PubSubCommunicationFailureEventType(const PubSubCommunicationFailureEventType& value)
    : ObjectBase()
    , connectionId_Variable_(boost::make_shared<ServerVariable>("ConnectionId_Variable"))
    , error_Variable_(boost::make_shared<ServerVariable>("Error_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)15563);
        setServerVariable(connectionId_Variable_);
        setServerVariable(error_Variable_);
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
    
    PubSubCommunicationFailureEventType::~PubSubCommunicationFailureEventType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::connectionId_Variable(void)
    {
        return connectionId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::error_Variable(void)
    {
        return error_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::groupId_Variable(void)
    {
        return groupId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::state_Variable(void)
    {
        return state_Variable_;
    }

    ServerVariable::SPtr&
    PubSubCommunicationFailureEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    PubSubCommunicationFailureEventType::connectionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        connectionId_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::error_Variable(ServerVariable::SPtr& serverVariable)
    {
        error_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::groupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupId_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::state_Variable(ServerVariable::SPtr& serverVariable)
    {
        state_Variable_ = serverVariable;
    }

    void
    PubSubCommunicationFailureEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    PubSubCommunicationFailureEventType::get_ConnectionId_Variable(OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_Error_Variable(OpcUaDataValue& dataValue)
    {
        return error_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_GroupId_Variable(OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_State_Variable(OpcUaDataValue& dataValue)
    {
        return state_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_ConnectionId_Variable(const OpcUaDataValue& dataValue)
    {
        return connectionId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_Error_Variable(const OpcUaDataValue& dataValue)
    {
        return error_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_GroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return groupId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_State_Variable(const OpcUaDataValue& dataValue)
    {
        return state_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubCommunicationFailureEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}
