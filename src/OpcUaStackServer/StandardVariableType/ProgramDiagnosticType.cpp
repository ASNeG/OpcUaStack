/*
    VariableTypeClass: ProgramDiagnosticType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ProgramDiagnosticType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ProgramDiagnosticType::ProgramDiagnosticType(void)
    : VariableBase()
    , createClientName_Variable_(boost::make_shared<ServerVariable>("CreateClientName_Variable"))
    , createSessionId_Variable_(boost::make_shared<ServerVariable>("CreateSessionId_Variable"))
    , invocationCreationTime_Variable_(boost::make_shared<ServerVariable>("InvocationCreationTime_Variable"))
    , lastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("LastMethodCallTime_Variable"))
    , lastMethodCall_Variable_(boost::make_shared<ServerVariable>("LastMethodCall_Variable"))
    , lastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodInputArguments_Variable"))
    , lastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputArguments_Variable"))
    , lastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("LastMethodReturnStatus_Variable"))
    , lastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("LastMethodSessionId_Variable"))
    , lastTransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2380);
        setServerVariable(createClientName_Variable_);
        setServerVariable(createSessionId_Variable_);
        setServerVariable(invocationCreationTime_Variable_);
        setServerVariable(lastMethodCallTime_Variable_);
        setServerVariable(lastMethodCall_Variable_);
        setServerVariable(lastMethodInputArguments_Variable_);
        setServerVariable(lastMethodOutputArguments_Variable_);
        setServerVariable(lastMethodReturnStatus_Variable_);
        setServerVariable(lastMethodSessionId_Variable_);
        setServerVariable(lastTransitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    ProgramDiagnosticType::ProgramDiagnosticType(const ProgramDiagnosticType& value)
    : VariableBase()
    , createClientName_Variable_(boost::make_shared<ServerVariable>("CreateClientName_Variable"))
    , createSessionId_Variable_(boost::make_shared<ServerVariable>("CreateSessionId_Variable"))
    , invocationCreationTime_Variable_(boost::make_shared<ServerVariable>("InvocationCreationTime_Variable"))
    , lastMethodCallTime_Variable_(boost::make_shared<ServerVariable>("LastMethodCallTime_Variable"))
    , lastMethodCall_Variable_(boost::make_shared<ServerVariable>("LastMethodCall_Variable"))
    , lastMethodInputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodInputArguments_Variable"))
    , lastMethodOutputArguments_Variable_(boost::make_shared<ServerVariable>("LastMethodOutputArguments_Variable"))
    , lastMethodReturnStatus_Variable_(boost::make_shared<ServerVariable>("LastMethodReturnStatus_Variable"))
    , lastMethodSessionId_Variable_(boost::make_shared<ServerVariable>("LastMethodSessionId_Variable"))
    , lastTransitionTime_Variable_(boost::make_shared<ServerVariable>("LastTransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2380);
        setServerVariable(createClientName_Variable_);
        setServerVariable(createSessionId_Variable_);
        setServerVariable(invocationCreationTime_Variable_);
        setServerVariable(lastMethodCallTime_Variable_);
        setServerVariable(lastMethodCall_Variable_);
        setServerVariable(lastMethodInputArguments_Variable_);
        setServerVariable(lastMethodOutputArguments_Variable_);
        setServerVariable(lastMethodReturnStatus_Variable_);
        setServerVariable(lastMethodSessionId_Variable_);
        setServerVariable(lastTransitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    ProgramDiagnosticType::~ProgramDiagnosticType(void)
    {
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::createClientName_Variable(void)
    {
        return createClientName_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::createSessionId_Variable(void)
    {
        return createSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::invocationCreationTime_Variable(void)
    {
        return invocationCreationTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodCallTime_Variable(void)
    {
        return lastMethodCallTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodCall_Variable(void)
    {
        return lastMethodCall_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodInputArguments_Variable(void)
    {
        return lastMethodInputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodOutputArguments_Variable(void)
    {
        return lastMethodOutputArguments_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodReturnStatus_Variable(void)
    {
        return lastMethodReturnStatus_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastMethodSessionId_Variable(void)
    {
        return lastMethodSessionId_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::lastTransitionTime_Variable(void)
    {
        return lastTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    ProgramDiagnosticType::variable(void)
    {
        return variable_;
    }

    void
    ProgramDiagnosticType::createClientName_Variable(ServerVariable::SPtr& serverVariable)
    {
        createClientName_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::createSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        createSessionId_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::invocationCreationTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        invocationCreationTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodCallTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodCall_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodCall_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodInputArguments_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodOutputArguments_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodReturnStatus_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastMethodSessionId_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::lastTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastTransitionTime_Variable_ = serverVariable;
    }

    void
    ProgramDiagnosticType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ProgramDiagnosticType::get_CreateClientName_Variable(OpcUaDataValue& dataValue)
    {
        return createClientName_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_CreateSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return createSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_InvocationCreationTime_Variable(OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodCallTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodCall_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodCall_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodInputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodOutputArguments_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodReturnStatus_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastMethodSessionId_Variable(OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_LastTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_CreateClientName_Variable(const OpcUaDataValue& dataValue)
    {
        return createClientName_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_CreateSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return createSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_InvocationCreationTime_Variable(const OpcUaDataValue& dataValue)
    {
        return invocationCreationTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodCallTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodCallTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodCall_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodCall_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodInputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodInputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodOutputArguments_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodOutputArguments_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodReturnStatus_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodReturnStatus_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastMethodSessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return lastMethodSessionId_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_LastTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return lastTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    ProgramDiagnosticType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
