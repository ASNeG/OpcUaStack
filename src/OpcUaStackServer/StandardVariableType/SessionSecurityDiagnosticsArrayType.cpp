/*
    VariableTypeClass: SessionSecurityDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionSecurityDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SessionSecurityDiagnosticsArrayType::SessionSecurityDiagnosticsArrayType(void)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2243);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsArrayType::SessionSecurityDiagnosticsArrayType(const SessionSecurityDiagnosticsArrayType& value)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2243);
        setServerVariable(variable_);
    }
    
    SessionSecurityDiagnosticsArrayType::~SessionSecurityDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SessionSecurityDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SessionSecurityDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SessionSecurityDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionSecurityDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
