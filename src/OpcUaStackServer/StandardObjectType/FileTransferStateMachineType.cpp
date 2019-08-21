/*
    VariableTypeClass: FileTransferStateMachineType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/FileTransferStateMachineType.h"

namespace OpcUaStackServer
{
    
    FileTransferStateMachineType::FileTransferStateMachineType(void)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15803);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&FileTransferStateMachineType::call_Reset_Method, this, _1));
    }
    
    FileTransferStateMachineType::FileTransferStateMachineType(const FileTransferStateMachineType& value)
    : ObjectBase()
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , reset_Method_(boost::make_shared<ServerMethod>("Reset_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15803);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerMethod(reset_Method_);
        reset_Method_->registerMethod(boost::bind(&FileTransferStateMachineType::call_Reset_Method, this, _1));
    }
    
    FileTransferStateMachineType::~FileTransferStateMachineType(void)
    {
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::availableStates_Variable(void)
    {
        return availableStates_Variable_;
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::availableTransitions_Variable(void)
    {
        return availableTransitions_Variable_;
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::currentState_Id_Variable(void)
    {
        return currentState_Id_Variable_;
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::currentState_Variable(void)
    {
        return currentState_Variable_;
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::lastTransition_Id_Variable(void)
    {
        return lastTransition_Id_Variable_;
    }

    ServerVariable::SPtr&
    FileTransferStateMachineType::lastTransition_Variable(void)
    {
        return lastTransition_Variable_;
    }

    void
    FileTransferStateMachineType::availableStates_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableStates_Variable_ = serverVariable;
    }

    void
    FileTransferStateMachineType::availableTransitions_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableTransitions_Variable_ = serverVariable;
    }

    void
    FileTransferStateMachineType::currentState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Id_Variable_ = serverVariable;
    }

    void
    FileTransferStateMachineType::currentState_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Variable_ = serverVariable;
    }

    void
    FileTransferStateMachineType::lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Id_Variable_ = serverVariable;
    }

    void
    FileTransferStateMachineType::lastTransition_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Variable_ = serverVariable;
    }

    bool
    FileTransferStateMachineType::get_AvailableStates_Variable(OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::get_AvailableTransitions_Variable(OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::get_CurrentState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::get_CurrentState_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::get_LastTransition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::get_LastTransition_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->getDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_AvailableStates_Variable(const OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->setDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_AvailableTransitions_Variable(const OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->setDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_CurrentState_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->setDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    FileTransferStateMachineType::set_LastTransition_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->setDataValue(dataValue);
    }

    void
    FileTransferStateMachineType::call_Reset_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
