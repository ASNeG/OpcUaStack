/*
    VariableTypeClass: ProgramStateMachineType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ProgramStateMachineType.h"

namespace OpcUaStackServer
{
    
    /**
     * A state machine for a program.
     */
    ProgramStateMachineType::ProgramStateMachineType(void)
    : ObjectBase()
    , autoDelete_Variable_(boost::make_shared<ServerVariable>("AutoDelete_Variable"))
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Number_Variable_(boost::make_shared<ServerVariable>("CurrentState_Number_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , deletable_Variable_(boost::make_shared<ServerVariable>("Deletable_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Number_Variable_(boost::make_shared<ServerVariable>("LastTransition_Number_Variable"))
    , lastTransition_TransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransition_TransitionTime_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , programDiagnostics_CreateClientName_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_CreateClientName_Variable"))
    , programDiagnostics_CreateSessionId_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_CreateSessionId_Variable"))
    , programDiagnostics_InvocationCreationTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_InvocationCreationTime_Variable"))
    , programDiagnostics_LastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodCallTime_Variable"))
    , programDiagnostics_LastMethodCall_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodCall_Variable"))
    , programDiagnostics_LastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodInputArguments_Variable"))
    , programDiagnostics_LastMethodInputValues_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodInputValues_Variable"))
    , programDiagnostics_LastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodOutputArguments_Variable"))
    , programDiagnostics_LastMethodOutputValues_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodOutputValues_Variable"))
    , programDiagnostics_LastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodReturnStatus_Variable"))
    , programDiagnostics_LastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodSessionId_Variable"))
    , programDiagnostics_LastTransitionTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastTransitionTime_Variable"))
    , programDiagnostics_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_Variable"))
    , recycleCount_Variable_(boost::make_shared<ServerVariable>("RecycleCount_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2391);
        setServerVariable(autoDelete_Variable_);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Number_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(deletable_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Number_Variable_);
        setServerVariable(lastTransition_TransitionTime_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerVariable(programDiagnostics_CreateClientName_Variable_);
        setServerVariable(programDiagnostics_CreateSessionId_Variable_);
        setServerVariable(programDiagnostics_InvocationCreationTime_Variable_);
        setServerVariable(programDiagnostics_LastMethodCallTime_Variable_);
        setServerVariable(programDiagnostics_LastMethodCall_Variable_);
        setServerVariable(programDiagnostics_LastMethodInputArguments_Variable_);
        setServerVariable(programDiagnostics_LastMethodInputValues_Variable_);
        setServerVariable(programDiagnostics_LastMethodOutputArguments_Variable_);
        setServerVariable(programDiagnostics_LastMethodOutputValues_Variable_);
        setServerVariable(programDiagnostics_LastMethodReturnStatus_Variable_);
        setServerVariable(programDiagnostics_LastMethodSessionId_Variable_);
        setServerVariable(programDiagnostics_LastTransitionTime_Variable_);
        setServerVariable(programDiagnostics_Variable_);
        setServerVariable(recycleCount_Variable_);
    }
    
    /**
     * A state machine for a program.
     */
    ProgramStateMachineType::ProgramStateMachineType(const ProgramStateMachineType& value)
    : ObjectBase()
    , autoDelete_Variable_(boost::make_shared<ServerVariable>("AutoDelete_Variable"))
    , availableStates_Variable_(boost::make_shared<ServerVariable>("AvailableStates_Variable"))
    , availableTransitions_Variable_(boost::make_shared<ServerVariable>("AvailableTransitions_Variable"))
    , currentState_Id_Variable_(boost::make_shared<ServerVariable>("CurrentState_Id_Variable"))
    , currentState_Number_Variable_(boost::make_shared<ServerVariable>("CurrentState_Number_Variable"))
    , currentState_Variable_(boost::make_shared<ServerVariable>("CurrentState_Variable"))
    , deletable_Variable_(boost::make_shared<ServerVariable>("Deletable_Variable"))
    , lastTransition_Id_Variable_(boost::make_shared<ServerVariable>("LastTransition_Id_Variable"))
    , lastTransition_Number_Variable_(boost::make_shared<ServerVariable>("LastTransition_Number_Variable"))
    , lastTransition_TransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransition_TransitionTime_Variable"))
    , lastTransition_Variable_(boost::make_shared<ServerVariable>("LastTransition_Variable"))
    , programDiagnostics_CreateClientName_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_CreateClientName_Variable"))
    , programDiagnostics_CreateSessionId_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_CreateSessionId_Variable"))
    , programDiagnostics_InvocationCreationTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_InvocationCreationTime_Variable"))
    , programDiagnostics_LastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodCallTime_Variable"))
    , programDiagnostics_LastMethodCall_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodCall_Variable"))
    , programDiagnostics_LastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodInputArguments_Variable"))
    , programDiagnostics_LastMethodInputValues_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodInputValues_Variable"))
    , programDiagnostics_LastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodOutputArguments_Variable"))
    , programDiagnostics_LastMethodOutputValues_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodOutputValues_Variable"))
    , programDiagnostics_LastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodReturnStatus_Variable"))
    , programDiagnostics_LastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastMethodSessionId_Variable"))
    , programDiagnostics_LastTransitionTime_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_LastTransitionTime_Variable"))
    , programDiagnostics_Variable_(boost::make_shared<ServerVariable>("ProgramDiagnostics_Variable"))
    , recycleCount_Variable_(boost::make_shared<ServerVariable>("RecycleCount_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2391);
        setServerVariable(autoDelete_Variable_);
        setServerVariable(availableStates_Variable_);
        setServerVariable(availableTransitions_Variable_);
        setServerVariable(currentState_Id_Variable_);
        setServerVariable(currentState_Number_Variable_);
        setServerVariable(currentState_Variable_);
        setServerVariable(deletable_Variable_);
        setServerVariable(lastTransition_Id_Variable_);
        setServerVariable(lastTransition_Number_Variable_);
        setServerVariable(lastTransition_TransitionTime_Variable_);
        setServerVariable(lastTransition_Variable_);
        setServerVariable(programDiagnostics_CreateClientName_Variable_);
        setServerVariable(programDiagnostics_CreateSessionId_Variable_);
        setServerVariable(programDiagnostics_InvocationCreationTime_Variable_);
        setServerVariable(programDiagnostics_LastMethodCallTime_Variable_);
        setServerVariable(programDiagnostics_LastMethodCall_Variable_);
        setServerVariable(programDiagnostics_LastMethodInputArguments_Variable_);
        setServerVariable(programDiagnostics_LastMethodInputValues_Variable_);
        setServerVariable(programDiagnostics_LastMethodOutputArguments_Variable_);
        setServerVariable(programDiagnostics_LastMethodOutputValues_Variable_);
        setServerVariable(programDiagnostics_LastMethodReturnStatus_Variable_);
        setServerVariable(programDiagnostics_LastMethodSessionId_Variable_);
        setServerVariable(programDiagnostics_LastTransitionTime_Variable_);
        setServerVariable(programDiagnostics_Variable_);
        setServerVariable(recycleCount_Variable_);
    }
    
    ProgramStateMachineType::~ProgramStateMachineType(void)
    {
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::autoDelete_Variable(void)
    {
        return autoDelete_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::availableStates_Variable(void)
    {
        return availableStates_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::availableTransitions_Variable(void)
    {
        return availableTransitions_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::currentState_Id_Variable(void)
    {
        return currentState_Id_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::currentState_Number_Variable(void)
    {
        return currentState_Number_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::currentState_Variable(void)
    {
        return currentState_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::deletable_Variable(void)
    {
        return deletable_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::lastTransition_Id_Variable(void)
    {
        return lastTransition_Id_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::lastTransition_Number_Variable(void)
    {
        return lastTransition_Number_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::lastTransition_TransitionTime_Variable(void)
    {
        return lastTransition_TransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::lastTransition_Variable(void)
    {
        return lastTransition_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_CreateClientName_Variable(void)
    {
        return programDiagnostics_CreateClientName_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_CreateSessionId_Variable(void)
    {
        return programDiagnostics_CreateSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_InvocationCreationTime_Variable(void)
    {
        return programDiagnostics_InvocationCreationTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodCallTime_Variable(void)
    {
        return programDiagnostics_LastMethodCallTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodCall_Variable(void)
    {
        return programDiagnostics_LastMethodCall_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodInputArguments_Variable(void)
    {
        return programDiagnostics_LastMethodInputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodInputValues_Variable(void)
    {
        return programDiagnostics_LastMethodInputValues_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodOutputArguments_Variable(void)
    {
        return programDiagnostics_LastMethodOutputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodOutputValues_Variable(void)
    {
        return programDiagnostics_LastMethodOutputValues_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodReturnStatus_Variable(void)
    {
        return programDiagnostics_LastMethodReturnStatus_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastMethodSessionId_Variable(void)
    {
        return programDiagnostics_LastMethodSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_LastTransitionTime_Variable(void)
    {
        return programDiagnostics_LastTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::programDiagnostics_Variable(void)
    {
        return programDiagnostics_Variable_;
    }

    ServerVariable::SPtr&
    ProgramStateMachineType::recycleCount_Variable(void)
    {
        return recycleCount_Variable_;
    }

    void
    ProgramStateMachineType::autoDelete_Variable(ServerVariable::SPtr& serverVariable)
    {
        autoDelete_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::availableStates_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableStates_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::availableTransitions_Variable(ServerVariable::SPtr& serverVariable)
    {
        availableTransitions_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::currentState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Id_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::currentState_Number_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Number_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::currentState_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentState_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::deletable_Variable(ServerVariable::SPtr& serverVariable)
    {
        deletable_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::lastTransition_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Id_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::lastTransition_Number_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Number_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::lastTransition_TransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_TransitionTime_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::lastTransition_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransition_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_CreateClientName_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_CreateClientName_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_CreateSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_CreateSessionId_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_InvocationCreationTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_InvocationCreationTime_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodCallTime_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodCall_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodCall_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodInputArguments_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodInputValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodInputValues_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodOutputArguments_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodOutputValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodOutputValues_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodReturnStatus_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastMethodSessionId_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_LastTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_LastTransitionTime_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::programDiagnostics_Variable(ServerVariable::SPtr& serverVariable)
    {
        programDiagnostics_Variable_ = serverVariable;
    }

    void
    ProgramStateMachineType::recycleCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        recycleCount_Variable_ = serverVariable;
    }

    bool
    ProgramStateMachineType::get_AutoDelete_Variable(OpcUaDataValue& dataValue)
    {
        return autoDelete_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_AvailableStates_Variable(OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_AvailableTransitions_Variable(OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_CurrentState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_CurrentState_Number_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Number_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_CurrentState_Variable(OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_Deletable_Variable(OpcUaDataValue& dataValue)
    {
        return deletable_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_LastTransition_Id_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_LastTransition_Number_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Number_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_LastTransition_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_TransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_LastTransition_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_CreateClientName_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_CreateClientName_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_CreateSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_CreateSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_InvocationCreationTime_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_InvocationCreationTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodCallTime_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodCallTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodCall_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodCall_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodInputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodInputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodInputValues_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodInputValues_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodOutputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodOutputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodOutputValues_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodOutputValues_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodReturnStatus_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodReturnStatus_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastMethodSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_LastTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_ProgramDiagnostics_Variable(OpcUaDataValue& dataValue)
    {
        return programDiagnostics_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::get_RecycleCount_Variable(OpcUaDataValue& dataValue)
    {
        return recycleCount_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_AutoDelete_Variable(const OpcUaDataValue& dataValue)
    {
        return autoDelete_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_AvailableStates_Variable(const OpcUaDataValue& dataValue)
    {
        return availableStates_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_AvailableTransitions_Variable(const OpcUaDataValue& dataValue)
    {
        return availableTransitions_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_CurrentState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_CurrentState_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Number_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_CurrentState_Variable(const OpcUaDataValue& dataValue)
    {
        return currentState_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_Deletable_Variable(const OpcUaDataValue& dataValue)
    {
        return deletable_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_LastTransition_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Id_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_LastTransition_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Number_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_LastTransition_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_TransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_LastTransition_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransition_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_CreateClientName_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_CreateClientName_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_CreateSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_CreateSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_InvocationCreationTime_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_InvocationCreationTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodCallTime_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodCallTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodCall_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodCall_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodInputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodInputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodInputValues_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodInputValues_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodOutputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodOutputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodOutputValues_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodOutputValues_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodReturnStatus_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodReturnStatus_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastMethodSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastMethodSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_LastTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_LastTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_ProgramDiagnostics_Variable(const OpcUaDataValue& dataValue)
    {
        return programDiagnostics_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramStateMachineType::set_RecycleCount_Variable(const OpcUaDataValue& dataValue)
    {
        return recycleCount_Variable_->setDataValue(dataValue);
    }

}
