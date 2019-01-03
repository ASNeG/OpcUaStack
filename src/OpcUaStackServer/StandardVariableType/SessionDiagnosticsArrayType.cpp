/*
    VariableTypeClass: SessionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SessionDiagnosticsArrayType::SessionDiagnosticsArrayType(void)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2196);
    }
    
    SessionDiagnosticsArrayType::SessionDiagnosticsArrayType(const SessionDiagnosticsArrayType& value)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2196);
    }
    
    SessionDiagnosticsArrayType::~SessionDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SessionDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SessionDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
