/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SubscriptionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SubscriptionDiagnosticsArrayType::SubscriptionDiagnosticsArrayType(void)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2171);
    }
    
    SubscriptionDiagnosticsArrayType::SubscriptionDiagnosticsArrayType(const SubscriptionDiagnosticsArrayType& value)
    : VariableBase()
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2171);
    }
    
    SubscriptionDiagnosticsArrayType::~SubscriptionDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SubscriptionDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SubscriptionDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
