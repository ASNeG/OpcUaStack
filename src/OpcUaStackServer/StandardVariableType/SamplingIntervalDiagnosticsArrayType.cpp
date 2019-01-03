/*
    VariableTypeClass: SamplingIntervalDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SamplingIntervalDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SamplingIntervalDiagnosticsArrayType::SamplingIntervalDiagnosticsArrayType(void)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2164);
    }
    
    SamplingIntervalDiagnosticsArrayType::SamplingIntervalDiagnosticsArrayType(const SamplingIntervalDiagnosticsArrayType& value)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2164);
    }
    
    SamplingIntervalDiagnosticsArrayType::~SamplingIntervalDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SamplingIntervalDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
