/*
    VariableTypeClass: ProgramTransitionEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ProgramTransitionEventType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ProgramTransitionEventType::ProgramTransitionEventType(void)
    : ObjectBase()
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , fromState_Id_Variable_(boost::make_shared<ServerVariable>("FromState_Id_Variable"))
    , fromState_Variable_(boost::make_shared<ServerVariable>("FromState_Variable"))
    , intermediateResult_Variable_(boost::make_shared<ServerVariable>("IntermediateResult_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)2378);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(fromState_Id_Variable_);
        setServerVariable(fromState_Variable_);
        setServerVariable(intermediateResult_Variable_);
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
    
    ProgramTransitionEventType::ProgramTransitionEventType(const ProgramTransitionEventType& value)
    : ObjectBase()
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , fromState_Id_Variable_(boost::make_shared<ServerVariable>("FromState_Id_Variable"))
    , fromState_Variable_(boost::make_shared<ServerVariable>("FromState_Variable"))
    , intermediateResult_Variable_(boost::make_shared<ServerVariable>("IntermediateResult_Variable"))
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
        objectTypeNodeId((OpcUaUInt32)2378);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(fromState_Id_Variable_);
        setServerVariable(fromState_Variable_);
        setServerVariable(intermediateResult_Variable_);
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
    
    ProgramTransitionEventType::~ProgramTransitionEventType(void)
    {
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::fromState_Id_Variable(void)
    {
        return fromState_Id_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::fromState_Variable(void)
    {
        return fromState_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::intermediateResult_Variable(void)
    {
        return intermediateResult_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::toState_Id_Variable(void)
    {
        return toState_Id_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::toState_Variable(void)
    {
        return toState_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::transition_Id_Variable(void)
    {
        return transition_Id_Variable_;
    }

    ServerVariable::SPtr&
    ProgramTransitionEventType::transition_Variable(void)
    {
        return transition_Variable_;
    }

    void
    ProgramTransitionEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::fromState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        fromState_Id_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::fromState_Variable(ServerVariable::SPtr& serverVariable)
    {
        fromState_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::intermediateResult_Variable(ServerVariable::SPtr& serverVariable)
    {
        intermediateResult_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::toState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        toState_Id_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::toState_Variable(ServerVariable::SPtr& serverVariable)
    {
        toState_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::transition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        transition_Id_Variable_ = serverVariable;
    }

    void
    ProgramTransitionEventType::transition_Variable(ServerVariable::SPtr& serverVariable)
    {
        transition_Variable_ = serverVariable;
    }

    bool
    ProgramTransitionEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_FromState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return fromState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_FromState_Variable(OpcUaDataValue& dataValue)
    {
        return fromState_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_IntermediateResult_Variable(OpcUaDataValue& dataValue)
    {
        return intermediateResult_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_ToState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return toState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_ToState_Variable(OpcUaDataValue& dataValue)
    {
        return toState_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_Transition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return transition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::get_Transition_Variable(OpcUaDataValue& dataValue)
    {
        return transition_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_FromState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return fromState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_FromState_Variable(const OpcUaDataValue& dataValue)
    {
        return fromState_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_IntermediateResult_Variable(const OpcUaDataValue& dataValue)
    {
        return intermediateResult_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_ToState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return toState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_ToState_Variable(const OpcUaDataValue& dataValue)
    {
        return toState_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_Transition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return transition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramTransitionEventType::set_Transition_Variable(const OpcUaDataValue& dataValue)
    {
        return transition_Variable_->setDataValue(dataValue);
    }

}
