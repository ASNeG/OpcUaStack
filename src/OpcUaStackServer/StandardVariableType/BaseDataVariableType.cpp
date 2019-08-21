/*
    VariableTypeClass: BaseDataVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    /**
     * The type for variable that represents a process value.
     */
    BaseDataVariableType::BaseDataVariableType(void)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)63);
        setServerVariable(variable_);
    }
    
    /**
     * The type for variable that represents a process value.
     */
    BaseDataVariableType::BaseDataVariableType(const BaseDataVariableType& value)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)63);
        setServerVariable(variable_);
    }
    
    BaseDataVariableType::~BaseDataVariableType(void)
    {
    }

    ServerVariable::SPtr&
    BaseDataVariableType::variable(void)
    {
        return variable_;
    }

    void
    BaseDataVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    BaseDataVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    BaseDataVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
