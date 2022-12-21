/*
    VariableTypeClass: ProgramDiagnostic2Type

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ProgramDiagnostic2Type.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ProgramDiagnostic2Type::ProgramDiagnostic2Type(void)
    : VariableBase()
    , createClientName_Variable_(boost::make_shared<ServerVariable>("CreateClientName_Variable"))
    , createSessionId_Variable_(boost::make_shared<ServerVariable>("CreateSessionId_Variable"))
    , invocationCreationTime_Variable_(boost::make_shared<ServerVariable>("InvocationCreationTime_Variable"))
    , lastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("LastMethodCallTime_Variable"))
    , lastMethodCall_Variable_(boost::make_shared<ServerVariable>("LastMethodCall_Variable"))
    , lastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodInputArguments_Variable"))
    , lastMethodInputValues_Variable_(boost::make_shared<ServerVariable>("LastMethodInputValues_Variable"))
    , lastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputArguments_Variable"))
    , lastMethodOutputValues_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputValues_Variable"))
    , lastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("LastMethodReturnStatus_Variable"))
    , lastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("LastMethodSessionId_Variable"))
    , lastTransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)15383);
        setServerVariable(createClientName_Variable_);
        setServerVariable(createSessionId_Variable_);
        setServerVariable(invocationCreationTime_Variable_);
        setServerVariable(lastMethodCallTime_Variable_);
        setServerVariable(lastMethodCall_Variable_);
        setServerVariable(lastMethodInputArguments_Variable_);
        setServerVariable(lastMethodInputValues_Variable_);
        setServerVariable(lastMethodOutputArguments_Variable_);
        setServerVariable(lastMethodOutputValues_Variable_);
        setServerVariable(lastMethodReturnStatus_Variable_);
        setServerVariable(lastMethodSessionId_Variable_);
        setServerVariable(lastTransitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    ProgramDiagnostic2Type::ProgramDiagnostic2Type(const ProgramDiagnostic2Type& value)
    : VariableBase()
    , createClientName_Variable_(boost::make_shared<ServerVariable>("CreateClientName_Variable"))
    , createSessionId_Variable_(boost::make_shared<ServerVariable>("CreateSessionId_Variable"))
    , invocationCreationTime_Variable_(boost::make_shared<ServerVariable>("InvocationCreationTime_Variable"))
    , lastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("LastMethodCallTime_Variable"))
    , lastMethodCall_Variable_(boost::make_shared<ServerVariable>("LastMethodCall_Variable"))
    , lastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodInputArguments_Variable"))
    , lastMethodInputValues_Variable_(boost::make_shared<ServerVariable>("LastMethodInputValues_Variable"))
    , lastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputArguments_Variable"))
    , lastMethodOutputValues_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputValues_Variable"))
    , lastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("LastMethodReturnStatus_Variable"))
    , lastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("LastMethodSessionId_Variable"))
    , lastTransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)15383);
        setServerVariable(createClientName_Variable_);
        setServerVariable(createSessionId_Variable_);
        setServerVariable(invocationCreationTime_Variable_);
        setServerVariable(lastMethodCallTime_Variable_);
        setServerVariable(lastMethodCall_Variable_);
        setServerVariable(lastMethodInputArguments_Variable_);
        setServerVariable(lastMethodInputValues_Variable_);
        setServerVariable(lastMethodOutputArguments_Variable_);
        setServerVariable(lastMethodOutputValues_Variable_);
        setServerVariable(lastMethodReturnStatus_Variable_);
        setServerVariable(lastMethodSessionId_Variable_);
        setServerVariable(lastTransitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    ProgramDiagnostic2Type::~ProgramDiagnostic2Type(void)
    {
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::createClientName_Variable(void)
    {
        return createClientName_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::createSessionId_Variable(void)
    {
        return createSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::invocationCreationTime_Variable(void)
    {
        return invocationCreationTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodCallTime_Variable(void)
    {
        return lastMethodCallTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodCall_Variable(void)
    {
        return lastMethodCall_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodInputArguments_Variable(void)
    {
        return lastMethodInputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodInputValues_Variable(void)
    {
        return lastMethodInputValues_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodOutputArguments_Variable(void)
    {
        return lastMethodOutputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodOutputValues_Variable(void)
    {
        return lastMethodOutputValues_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodReturnStatus_Variable(void)
    {
        return lastMethodReturnStatus_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastMethodSessionId_Variable(void)
    {
        return lastMethodSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::lastTransitionTime_Variable(void)
    {
        return lastTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnostic2Type::variable(void)
    {
        return variable_;
    }

    void
    ProgramDiagnostic2Type::createClientName_Variable(ServerVariable::SPtr& serverVariable)
    {
        createClientName_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::createSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        createSessionId_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::invocationCreationTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        invocationCreationTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodCallTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodCall_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodCall_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodInputArguments_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodInputValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodInputValues_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodOutputArguments_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodOutputValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodOutputValues_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodReturnStatus_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodSessionId_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::lastTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransitionTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnostic2Type::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ProgramDiagnostic2Type::get_CreateClientName_Variable(OpcUaDataValue& dataValue)
    {
        return createClientName_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_CreateSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return createSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_InvocationCreationTime_Variable(OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodCallTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodCall_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodCall_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodInputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodInputValues_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodInputValues_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodOutputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodOutputValues_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodOutputValues_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodReturnStatus_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastMethodSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_LastTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_CreateClientName_Variable(const OpcUaDataValue& dataValue)
    {
        return createClientName_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_CreateSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return createSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_InvocationCreationTime_Variable(const OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodCallTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodCall_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodCall_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodInputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodInputValues_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodInputValues_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodOutputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodOutputValues_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodOutputValues_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodReturnStatus_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastMethodSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_LastTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnostic2Type::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
