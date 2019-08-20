/*
    VariableTypeClass: AlarmRateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/AlarmRateVariableType.h"

namespace OpcUaStackServer
{
    
    AlarmRateVariableType::AlarmRateVariableType(void)
    : VariableBase()
    , rate_Variable_(boost::make_shared<ServerVariable>("Rate_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17277);
        setServerVariable(rate_Variable_);
        setServerVariable(variable_);
    }
    
    AlarmRateVariableType::AlarmRateVariableType(const AlarmRateVariableType& value)
    : VariableBase()
    , rate_Variable_(boost::make_shared<ServerVariable>("Rate_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17277);
        setServerVariable(rate_Variable_);
        setServerVariable(variable_);
    }
    
    AlarmRateVariableType::~AlarmRateVariableType(void)
    {
    }

    ServerVariable::SPtr&
    AlarmRateVariableType::rate_Variable(void)
    {
        return rate_Variable_;
    }

    ServerVariable::SPtr&
    AlarmRateVariableType::variable(void)
    {
        return variable_;
    }

    void
    AlarmRateVariableType::rate_Variable(ServerVariable::SPtr& serverVariable)
    {
        rate_Variable_ = serverVariable;
    }

    void
    AlarmRateVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    AlarmRateVariableType::get_Rate_Variable(OpcUaDataValue& dataValue)
    {
        return rate_Variable_->getDataValue(dataValue);
    }

    bool
    AlarmRateVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    AlarmRateVariableType::set_Rate_Variable(const OpcUaDataValue& dataValue)
    {
        return rate_Variable_->setDataValue(dataValue);
    }

    bool
    AlarmRateVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
