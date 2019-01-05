/*
    VariableTypeClass: MultiStateValueDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/MultiStateValueDiscreteType.h"

namespace OpcUaStackServer
{
    
    MultiStateValueDiscreteType::MultiStateValueDiscreteType(void)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , enumValues_Variable_(constructSPtr<ServerVariable>("EnumValues_Variable"))
    , valueAsText_Variable_(constructSPtr<ServerVariable>("ValueAsText_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)11238);
        setServerVariable(definition_Variable_);
        setServerVariable(enumValues_Variable_);
        setServerVariable(valueAsText_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    MultiStateValueDiscreteType::MultiStateValueDiscreteType(const MultiStateValueDiscreteType& value)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , enumValues_Variable_(constructSPtr<ServerVariable>("EnumValues_Variable"))
    , valueAsText_Variable_(constructSPtr<ServerVariable>("ValueAsText_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)11238);
        setServerVariable(definition_Variable_);
        setServerVariable(enumValues_Variable_);
        setServerVariable(valueAsText_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    MultiStateValueDiscreteType::~MultiStateValueDiscreteType(void)
    {
    }

    ServerVariable::SPtr&
    MultiStateValueDiscreteType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateValueDiscreteType::enumValues_Variable(void)
    {
        return enumValues_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateValueDiscreteType::valueAsText_Variable(void)
    {
        return valueAsText_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateValueDiscreteType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateValueDiscreteType::variable(void)
    {
        return variable_;
    }

    void
    MultiStateValueDiscreteType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    MultiStateValueDiscreteType::enumValues_Variable(ServerVariable::SPtr& serverVariable)
    {
        enumValues_Variable_ = serverVariable;
    }

    void
    MultiStateValueDiscreteType::valueAsText_Variable(ServerVariable::SPtr& serverVariable)
    {
        valueAsText_Variable_ = serverVariable;
    }

    void
    MultiStateValueDiscreteType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    MultiStateValueDiscreteType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    MultiStateValueDiscreteType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::get_EnumValues_Variable(OpcUaDataValue& dataValue)
    {
        return enumValues_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::get_ValueAsText_Variable(OpcUaDataValue& dataValue)
    {
        return valueAsText_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::set_EnumValues_Variable(const OpcUaDataValue& dataValue)
    {
        return enumValues_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::set_ValueAsText_Variable(const OpcUaDataValue& dataValue)
    {
        return valueAsText_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateValueDiscreteType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
