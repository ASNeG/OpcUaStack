/*
    VariableTypeClass: DataItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataItemType.h"

namespace OpcUaStackServer
{
    
    /**
     * A variable that contains live automation data.
     */
    DataItemType::DataItemType(void)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2365);
        setServerVariable(definition_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    /**
     * A variable that contains live automation data.
     */
    DataItemType::DataItemType(const DataItemType& value)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2365);
        setServerVariable(definition_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    DataItemType::~DataItemType(void)
    {
    }

    ServerVariable::SPtr&
    DataItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    DataItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    DataItemType::variable(void)
    {
        return variable_;
    }

    void
    DataItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    DataItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    DataItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    DataItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    DataItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    DataItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    DataItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    DataItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    DataItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
