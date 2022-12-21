/*
    VariableTypeClass: TransitionEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TransitionEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TransitionEventType::TransitionEventType(void)
    : ObjectBase()
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , fromState_Id_Variable_(boost::make_shared<ServerVariable>("FromState_Id_Variable"))
    , fromState_Variable_(boost::make_shared<ServerVariable>("FromState_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , toState_Id_Variable_(boost::make_shared<ServerVariable>("ToState_Id_Variable"))
    , toState_Variable_(boost::make_shared<ServerVariable>("ToState_Variable"))
    , transition_Id_Variable_(boost::make_shared<ServerVariable>("Transition_Id_Variable"))
    , transition_Variable_(boost::make_shared<ServerVariable>("Transition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2311);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(fromState_Id_Variable_);
        setServerVariable(fromState_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(toState_Id_Variable_);
        setServerVariable(toState_Variable_);
        setServerVariable(transition_Id_Variable_);
        setServerVariable(transition_Variable_);
    }
    
    TransitionEventType::TransitionEventType(const TransitionEventType& value)
    : ObjectBase()
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , fromState_Id_Variable_(boost::make_shared<ServerVariable>("FromState_Id_Variable"))
    , fromState_Variable_(boost::make_shared<ServerVariable>("FromState_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , toState_Id_Variable_(boost::make_shared<ServerVariable>("ToState_Id_Variable"))
    , toState_Variable_(boost::make_shared<ServerVariable>("ToState_Variable"))
    , transition_Id_Variable_(boost::make_shared<ServerVariable>("Transition_Id_Variable"))
    , transition_Variable_(boost::make_shared<ServerVariable>("Transition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2311);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(fromState_Id_Variable_);
        setServerVariable(fromState_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(time_Variable_);
        setServerVariable(toState_Id_Variable_);
        setServerVariable(toState_Variable_);
        setServerVariable(transition_Id_Variable_);
        setServerVariable(transition_Variable_);
    }
    
    TransitionEventType::~TransitionEventType(void)
    {
    }

    ServerVariable::SPtr&
    TransitionEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::fromState_Id_Variable(void)
    {
        return fromState_Id_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::fromState_Variable(void)
    {
        return fromState_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::toState_Id_Variable(void)
    {
        return toState_Id_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::toState_Variable(void)
    {
        return toState_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::transition_Id_Variable(void)
    {
        return transition_Id_Variable_;
    }

    ServerVariable::SPtr&
    TransitionEventType::transition_Variable(void)
    {
        return transition_Variable_;
    }

    void
    TransitionEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    TransitionEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    TransitionEventType::fromState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        fromState_Id_Variable_ = serverVariable;
    }

    void
    TransitionEventType::fromState_Variable(ServerVariable::SPtr& serverVariable)
    {
        fromState_Variable_ = serverVariable;
    }

    void
    TransitionEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    TransitionEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    TransitionEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    TransitionEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    TransitionEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    TransitionEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    TransitionEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    TransitionEventType::toState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        toState_Id_Variable_ = serverVariable;
    }

    void
    TransitionEventType::toState_Variable(ServerVariable::SPtr& serverVariable)
    {
        toState_Variable_ = serverVariable;
    }

    void
    TransitionEventType::transition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        transition_Id_Variable_ = serverVariable;
    }

    void
    TransitionEventType::transition_Variable(ServerVariable::SPtr& serverVariable)
    {
        transition_Variable_ = serverVariable;
    }

    bool
    TransitionEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_FromState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return fromState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_FromState_Variable(OpcUaDataValue& dataValue)
    {
        return fromState_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_ToState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return toState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_ToState_Variable(OpcUaDataValue& dataValue)
    {
        return toState_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_Transition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return transition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::get_Transition_Variable(OpcUaDataValue& dataValue)
    {
        return transition_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_FromState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return fromState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_FromState_Variable(const OpcUaDataValue& dataValue)
    {
        return fromState_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_ToState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return toState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_ToState_Variable(const OpcUaDataValue& dataValue)
    {
        return toState_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_Transition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return transition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionEventType::set_Transition_Variable(const OpcUaDataValue& dataValue)
    {
        return transition_Variable_->setDataValue(dataValue);
    }

}
