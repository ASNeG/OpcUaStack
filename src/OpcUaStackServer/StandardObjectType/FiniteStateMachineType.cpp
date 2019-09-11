/*
    VariableTypeClass: FiniteStateMachineType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/FiniteStateMachineType.h"

namespace OpcUaStackServer
{
    
    FiniteStateMachineType::FiniteStateMachineType(void)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2771);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
    }
    
    FiniteStateMachineType::FiniteStateMachineType(const FiniteStateMachineType& value)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2771);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
    }
    
    FiniteStateMachineType::~FiniteStateMachineType(void)
    {
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::availableStates_Variable(void)
    {
        return availableStates_Variable_;
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::availableTransitions_Variable(void)
    {
        return availableTransitions_Variable_;
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::currentState_Id_Variable(void)
    {
        return currentState_Id_Variable_;
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::currentState_Variable(void)
    {
        return currentState_Variable_;
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::lastTransition_Id_Variable(void)
    {
        return lastTransition_Id_Variable_;
    }

    ServerVariable::SPtr&
    FiniteStateMachineType::lastTransition_Variable(void)
    {
        return lastTransition_Variable_;
    }

    void
    FiniteStateMachineType::availableStates_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableStates_Variable_ = serverVariable;
    }

    void
    FiniteStateMachineType::availableTransitions_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableTransitions_Variable_ = serverVariable;
    }

    void
    FiniteStateMachineType::currentState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Id_Variable_ = serverVariable;
    }

    void
    FiniteStateMachineType::currentState_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Variable_ = serverVariable;
    }

    void
    FiniteStateMachineType::lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Id_Variable_ = serverVariable;
    }

    void
    FiniteStateMachineType::lastTransition_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Variable_ = serverVariable;
    }

    bool
    FiniteStateMachineType::get_AvailableStates_Variable(OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::get_AvailableTransitions_Variable(OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::get_CurrentState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::get_CurrentState_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::get_LastTransition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::get_LastTransition_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_AvailableStates_Variable(const OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_AvailableTransitions_Variable(const OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_CurrentState_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteStateMachineType::set_LastTransition_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->setDataValue(dataValue);
    }

}
