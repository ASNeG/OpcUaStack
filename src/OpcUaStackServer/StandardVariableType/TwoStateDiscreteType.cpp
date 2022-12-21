/*
    VariableTypeClass: TwoStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TwoStateDiscreteType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TwoStateDiscreteType::TwoStateDiscreteType(void)
    : VariableBase()
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , falseState_Variable_(boost::make_shared<ServerVariable>("FalseState_Variable"))
    , trueState_Variable_(boost::make_shared<ServerVariable>("TrueState_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2373);
        setServerVariable(definition_Variable_);
        setServerVariable(falseState_Variable_);
        setServerVariable(trueState_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    TwoStateDiscreteType::TwoStateDiscreteType(const TwoStateDiscreteType& value)
    : VariableBase()
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , falseState_Variable_(boost::make_shared<ServerVariable>("FalseState_Variable"))
    , trueState_Variable_(boost::make_shared<ServerVariable>("TrueState_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2373);
        setServerVariable(definition_Variable_);
        setServerVariable(falseState_Variable_);
        setServerVariable(trueState_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    TwoStateDiscreteType::~TwoStateDiscreteType(void)
    {
    }

    ServerVariable::SPtr&
    TwoStateDiscreteType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateDiscreteType::falseState_Variable(void)
    {
        return falseState_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateDiscreteType::trueState_Variable(void)
    {
        return trueState_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateDiscreteType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateDiscreteType::variable(void)
    {
        return variable_;
    }

    void
    TwoStateDiscreteType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    TwoStateDiscreteType::falseState_Variable(ServerVariable::SPtr& serverVariable)
    {
        falseState_Variable_ = serverVariable;
    }

    void
    TwoStateDiscreteType::trueState_Variable(ServerVariable::SPtr& serverVariable)
    {
        trueState_Variable_ = serverVariable;
    }

    void
    TwoStateDiscreteType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    TwoStateDiscreteType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    TwoStateDiscreteType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::get_FalseState_Variable(OpcUaDataValue& dataValue)
    {
        return falseState_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::get_TrueState_Variable(OpcUaDataValue& dataValue)
    {
        return trueState_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::set_FalseState_Variable(const OpcUaDataValue& dataValue)
    {
        return falseState_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::set_TrueState_Variable(const OpcUaDataValue& dataValue)
    {
        return trueState_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateDiscreteType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
