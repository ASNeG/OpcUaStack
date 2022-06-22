/*
    VariableTypeClass: MultiStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/MultiStateDiscreteType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    MultiStateDiscreteType::MultiStateDiscreteType(void)
    : VariableBase()
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , enumStrings_Variable_(boost::make_shared<ServerVariable>("EnumStrings_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2376);
        setServerVariable(definition_Variable_);
        setServerVariable(enumStrings_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    MultiStateDiscreteType::MultiStateDiscreteType(const MultiStateDiscreteType& value)
    : VariableBase()
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , enumStrings_Variable_(boost::make_shared<ServerVariable>("EnumStrings_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2376);
        setServerVariable(definition_Variable_);
        setServerVariable(enumStrings_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    MultiStateDiscreteType::~MultiStateDiscreteType(void)
    {
    }

    ServerVariable::SPtr&
    MultiStateDiscreteType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateDiscreteType::enumStrings_Variable(void)
    {
        return enumStrings_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateDiscreteType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    MultiStateDiscreteType::variable(void)
    {
        return variable_;
    }

    void
    MultiStateDiscreteType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    MultiStateDiscreteType::enumStrings_Variable(ServerVariable::SPtr& serverVariable)
    {
        enumStrings_Variable_ = serverVariable;
    }

    void
    MultiStateDiscreteType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    MultiStateDiscreteType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    MultiStateDiscreteType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::get_EnumStrings_Variable(OpcUaDataValue& dataValue)
    {
        return enumStrings_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::set_EnumStrings_Variable(const OpcUaDataValue& dataValue)
    {
        return enumStrings_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    MultiStateDiscreteType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
