/*
    VariableTypeClass: ShelvedStateMachineType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ShelvedStateMachineType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ShelvedStateMachineType::ShelvedStateMachineType(void)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , unshelveTime_Variable_(boost::make_shared<ServerVariable>("UnshelveTime_Variable"))
    , oneShotShelve_Method_(boost::make_shared<ServerMethod>("OneShotShelve_Method"))
    , timedShelve_Method_(boost::make_shared<ServerMethod>("TimedShelve_Method"))
    , unshelve_Method_(boost::make_shared<ServerMethod>("Unshelve_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2929);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerVariable(unshelveTime_Variable_);
        setServerMethod(oneShotShelve_Method_);
        setServerMethod(timedShelve_Method_);
        setServerMethod(unshelve_Method_);
        oneShotShelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_OneShotShelve_Method, this, boost::placeholders::_1));
        timedShelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_TimedShelve_Method, this, boost::placeholders::_1));
        unshelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_Unshelve_Method, this, boost::placeholders::_1));
    }
    
    ShelvedStateMachineType::ShelvedStateMachineType(const ShelvedStateMachineType& value)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , unshelveTime_Variable_(boost::make_shared<ServerVariable>("UnshelveTime_Variable"))
    , oneShotShelve_Method_(boost::make_shared<ServerMethod>("OneShotShelve_Method"))
    , timedShelve_Method_(boost::make_shared<ServerMethod>("TimedShelve_Method"))
    , unshelve_Method_(boost::make_shared<ServerMethod>("Unshelve_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2929);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerVariable(unshelveTime_Variable_);
        setServerMethod(oneShotShelve_Method_);
        setServerMethod(timedShelve_Method_);
        setServerMethod(unshelve_Method_);
        oneShotShelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_OneShotShelve_Method, this, boost::placeholders::_1));
        timedShelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_TimedShelve_Method, this, boost::placeholders::_1));
        unshelve_Method_->registerMethod(boost::bind(&ShelvedStateMachineType::call_Unshelve_Method, this, boost::placeholders::_1));
    }
    
    ShelvedStateMachineType::~ShelvedStateMachineType(void)
    {
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::availableStates_Variable(void)
    {
        return availableStates_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::availableTransitions_Variable(void)
    {
        return availableTransitions_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::currentState_Id_Variable(void)
    {
        return currentState_Id_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::currentState_Variable(void)
    {
        return currentState_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::lastTransition_Id_Variable(void)
    {
        return lastTransition_Id_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::lastTransition_Variable(void)
    {
        return lastTransition_Variable_;
    }

    ServerVariable::SPtr&
    ShelvedStateMachineType::unshelveTime_Variable(void)
    {
        return unshelveTime_Variable_;
    }

    void
    ShelvedStateMachineType::availableStates_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableStates_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::availableTransitions_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableTransitions_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::currentState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Id_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::currentState_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Id_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::lastTransition_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Variable_ = serverVariable;
    }

    void
    ShelvedStateMachineType::unshelveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        unshelveTime_Variable_ = serverVariable;
    }

    bool
    ShelvedStateMachineType::get_AvailableStates_Variable(OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_AvailableTransitions_Variable(OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_CurrentState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_CurrentState_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_LastTransition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_LastTransition_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::get_UnshelveTime_Variable(OpcUaDataValue& dataValue)
    {
        return unshelveTime_Variable_->getDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_AvailableStates_Variable(const OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_AvailableTransitions_Variable(const OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_CurrentState_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_LastTransition_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->setDataValue(dataValue);
    }

    bool
    ShelvedStateMachineType::set_UnshelveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return unshelveTime_Variable_->setDataValue(dataValue);
    }

    void
    ShelvedStateMachineType::call_OneShotShelve_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ShelvedStateMachineType::call_TimedShelve_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ShelvedStateMachineType::call_Unshelve_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
