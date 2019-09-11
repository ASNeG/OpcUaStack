/*
    VariableTypeClass: DataTypeDictionaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataTypeDictionaryType.h"

namespace OpcUaStackServer
{
    
    /**
     * The type for variable that represents the collection of data type decriptions.
     */
    DataTypeDictionaryType::DataTypeDictionaryType(void)
    : VariableBase()
    , dataTypeVersion_Variable_(boost::make_shared<ServerVariable>("DataTypeVersion_Variable"))
    , deprecated_Variable_(boost::make_shared<ServerVariable>("Deprecated_Variable"))
    , namespaceUri_Variable_(boost::make_shared<ServerVariable>("NamespaceUri_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)72);
        setServerVariable(dataTypeVersion_Variable_);
        setServerVariable(deprecated_Variable_);
        setServerVariable(namespaceUri_Variable_);
        setServerVariable(variable_);
    }
    
    /**
     * The type for variable that represents the collection of data type decriptions.
     */
    DataTypeDictionaryType::DataTypeDictionaryType(const DataTypeDictionaryType& value)
    : VariableBase()
    , dataTypeVersion_Variable_(boost::make_shared<ServerVariable>("DataTypeVersion_Variable"))
    , deprecated_Variable_(boost::make_shared<ServerVariable>("Deprecated_Variable"))
    , namespaceUri_Variable_(boost::make_shared<ServerVariable>("NamespaceUri_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)72);
        setServerVariable(dataTypeVersion_Variable_);
        setServerVariable(deprecated_Variable_);
        setServerVariable(namespaceUri_Variable_);
        setServerVariable(variable_);
    }
    
    DataTypeDictionaryType::~DataTypeDictionaryType(void)
    {
    }

    ServerVariable::SPtr&
    DataTypeDictionaryType::dataTypeVersion_Variable(void)
    {
        return dataTypeVersion_Variable_;
    }

    ServerVariable::SPtr&
    DataTypeDictionaryType::deprecated_Variable(void)
    {
        return deprecated_Variable_;
    }

    ServerVariable::SPtr&
    DataTypeDictionaryType::namespaceUri_Variable(void)
    {
        return namespaceUri_Variable_;
    }

    ServerVariable::SPtr&
    DataTypeDictionaryType::variable(void)
    {
        return variable_;
    }

    void
    DataTypeDictionaryType::dataTypeVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataTypeVersion_Variable_ = serverVariable;
    }

    void
    DataTypeDictionaryType::deprecated_Variable(ServerVariable::SPtr& serverVariable)
    {
        deprecated_Variable_ = serverVariable;
    }

    void
    DataTypeDictionaryType::namespaceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceUri_Variable_ = serverVariable;
    }

    void
    DataTypeDictionaryType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    DataTypeDictionaryType::get_DataTypeVersion_Variable(OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_Variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::get_Deprecated_Variable(OpcUaDataValue& dataValue)
    {
        return deprecated_Variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::get_NamespaceUri_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceUri_Variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::set_DataTypeVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_Variable_->setDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::set_Deprecated_Variable(const OpcUaDataValue& dataValue)
    {
        return deprecated_Variable_->setDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::set_NamespaceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceUri_Variable_->setDataValue(dataValue);
    }

    bool
    DataTypeDictionaryType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
