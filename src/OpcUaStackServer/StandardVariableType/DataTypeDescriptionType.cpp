/*
    VariableTypeClass: DataTypeDescriptionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DataTypeDescriptionType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * The type for variable that represents the description of a data type encoding.
     */
    DataTypeDescriptionType::DataTypeDescriptionType(void)
    : VariableBase()
    , dataTypeVersion_Variable_(boost::make_shared<ServerVariable>("DataTypeVersion_Variable"))
    , dictionaryFragment_Variable_(boost::make_shared<ServerVariable>("DictionaryFragment_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)69);
        setServerVariable(dataTypeVersion_Variable_);
        setServerVariable(dictionaryFragment_Variable_);
        setServerVariable(variable_);
    }
    
    /**
     * The type for variable that represents the description of a data type encoding.
     */
    DataTypeDescriptionType::DataTypeDescriptionType(const DataTypeDescriptionType& value)
    : VariableBase()
    , dataTypeVersion_Variable_(boost::make_shared<ServerVariable>("DataTypeVersion_Variable"))
    , dictionaryFragment_Variable_(boost::make_shared<ServerVariable>("DictionaryFragment_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)69);
        setServerVariable(dataTypeVersion_Variable_);
        setServerVariable(dictionaryFragment_Variable_);
        setServerVariable(variable_);
    }
    
    DataTypeDescriptionType::~DataTypeDescriptionType(void)
    {
    }

    ServerVariable::SPtr&
    DataTypeDescriptionType::dataTypeVersion_Variable(void)
    {
        return dataTypeVersion_Variable_;
    }

    ServerVariable::SPtr&
    DataTypeDescriptionType::dictionaryFragment_Variable(void)
    {
        return dictionaryFragment_Variable_;
    }

    ServerVariable::SPtr&
    DataTypeDescriptionType::variable(void)
    {
        return variable_;
    }

    void
    DataTypeDescriptionType::dataTypeVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataTypeVersion_Variable_ = serverVariable;
    }

    void
    DataTypeDescriptionType::dictionaryFragment_Variable(ServerVariable::SPtr& serverVariable)
    {
        dictionaryFragment_Variable_ = serverVariable;
    }

    void
    DataTypeDescriptionType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    DataTypeDescriptionType::get_DataTypeVersion_Variable(OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_Variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDescriptionType::get_DictionaryFragment_Variable(OpcUaDataValue& dataValue)
    {
        return dictionaryFragment_Variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDescriptionType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    DataTypeDescriptionType::set_DataTypeVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return dataTypeVersion_Variable_->setDataValue(dataValue);
    }

    bool
    DataTypeDescriptionType::set_DictionaryFragment_Variable(const OpcUaDataValue& dataValue)
    {
        return dictionaryFragment_Variable_->setDataValue(dataValue);
    }

    bool
    DataTypeDescriptionType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
