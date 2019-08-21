/*
    VariableTypeClass: StateMachineType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/StateMachineType.h"

namespace OpcUaStackServer
{
    
    StateMachineType::StateMachineType(void)
    : ObjectBase()
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2299);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
    }
    
    StateMachineType::StateMachineType(const StateMachineType& value)
    : ObjectBase()
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2299);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
    }
    
    StateMachineType::~StateMachineType(void)
    {
    }

    ServerVariable::SPtr&
    StateMachineType::currentState_Id_Variable(void)
    {
        return currentState_Id_Variable_;
    }

    ServerVariable::SPtr&
    StateMachineType::currentState_Variable(void)
    {
        return currentState_Variable_;
    }

    ServerVariable::SPtr&
    StateMachineType::lastTransition_Id_Variable(void)
    {
        return lastTransition_Id_Variable_;
    }

    ServerVariable::SPtr&
    StateMachineType::lastTransition_Variable(void)
    {
        return lastTransition_Variable_;
    }

    void
    StateMachineType::currentState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Id_Variable_ = serverVariable;
    }

    void
    StateMachineType::currentState_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Variable_ = serverVariable;
    }

    void
    StateMachineType::lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Id_Variable_ = serverVariable;
    }

    void
    StateMachineType::lastTransition_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Variable_ = serverVariable;
    }

    bool
    StateMachineType::get_CurrentState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    StateMachineType::get_CurrentState_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->getDataValue(dataValue);
    }

    bool
    StateMachineType::get_LastTransition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    StateMachineType::get_LastTransition_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->getDataValue(dataValue);
    }

    bool
    StateMachineType::set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    StateMachineType::set_CurrentState_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->setDataValue(dataValue);
    }

    bool
    StateMachineType::set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    StateMachineType::set_LastTransition_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->setDataValue(dataValue);
    }

}
