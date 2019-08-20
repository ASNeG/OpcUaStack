/*
    VariableTypeClass: ConditionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ConditionVariableType.h"

namespace OpcUaStackServer
{
    
    ConditionVariableType::ConditionVariableType(void)
    : VariableBase()
    , sourceTimestamp_Variable_(boost::make_shared<ServerVariable>("SourceTimestamp_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)9002);
        setServerVariable(sourceTimestamp_Variable_);
        setServerVariable(variable_);
    }
    
    ConditionVariableType::ConditionVariableType(const ConditionVariableType& value)
    : VariableBase()
    , sourceTimestamp_Variable_(boost::make_shared<ServerVariable>("SourceTimestamp_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)9002);
        setServerVariable(sourceTimestamp_Variable_);
        setServerVariable(variable_);
    }
    
    ConditionVariableType::~ConditionVariableType(void)
    {
    }

    ServerVariable::SPtr&
    ConditionVariableType::sourceTimestamp_Variable(void)
    {
        return sourceTimestamp_Variable_;
    }

    ServerVariable::SPtr&
    ConditionVariableType::variable(void)
    {
        return variable_;
    }

    void
    ConditionVariableType::sourceTimestamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceTimestamp_Variable_ = serverVariable;
    }

    void
    ConditionVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ConditionVariableType::get_SourceTimestamp_Variable(OpcUaDataValue& dataValue)
    {
        return sourceTimestamp_Variable_->getDataValue(dataValue);
    }

    bool
    ConditionVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ConditionVariableType::set_SourceTimestamp_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceTimestamp_Variable_->setDataValue(dataValue);
    }

    bool
    ConditionVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
