/*
    VariableTypeClass: OptionSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/OptionSetType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    OptionSetType::OptionSetType(void)
    : VariableBase()
    , bitMask_Variable_(boost::make_shared<ServerVariable>("BitMask_Variable"))
    , optionSetValues_Variable_(boost::make_shared<ServerVariable>("OptionSetValues_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)11487);
        setServerVariable(bitMask_Variable_);
        setServerVariable(optionSetValues_Variable_);
        setServerVariable(variable_);
    }
    
    OptionSetType::OptionSetType(const OptionSetType& value)
    : VariableBase()
    , bitMask_Variable_(boost::make_shared<ServerVariable>("BitMask_Variable"))
    , optionSetValues_Variable_(boost::make_shared<ServerVariable>("OptionSetValues_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)11487);
        setServerVariable(bitMask_Variable_);
        setServerVariable(optionSetValues_Variable_);
        setServerVariable(variable_);
    }
    
    OptionSetType::~OptionSetType(void)
    {
    }

    ServerVariable::SPtr&
    OptionSetType::bitMask_Variable(void)
    {
        return bitMask_Variable_;
    }

    ServerVariable::SPtr&
    OptionSetType::optionSetValues_Variable(void)
    {
        return optionSetValues_Variable_;
    }

    ServerVariable::SPtr&
    OptionSetType::variable(void)
    {
        return variable_;
    }

    void
    OptionSetType::bitMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        bitMask_Variable_ = serverVariable;
    }

    void
    OptionSetType::optionSetValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        optionSetValues_Variable_ = serverVariable;
    }

    void
    OptionSetType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    OptionSetType::get_BitMask_Variable(OpcUaDataValue& dataValue)
    {
        return bitMask_Variable_->getDataValue(dataValue);
    }

    bool
    OptionSetType::get_OptionSetValues_Variable(OpcUaDataValue& dataValue)
    {
        return optionSetValues_Variable_->getDataValue(dataValue);
    }

    bool
    OptionSetType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    OptionSetType::set_BitMask_Variable(const OpcUaDataValue& dataValue)
    {
        return bitMask_Variable_->setDataValue(dataValue);
    }

    bool
    OptionSetType::set_OptionSetValues_Variable(const OpcUaDataValue& dataValue)
    {
        return optionSetValues_Variable_->setDataValue(dataValue);
    }

    bool
    OptionSetType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
