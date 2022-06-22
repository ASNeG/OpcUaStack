/*
    VariableTypeClass: PropertyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/PropertyType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * The type for variable that represents a property of another node.
     */
    PropertyType::PropertyType(void)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)68);
        setServerVariable(variable_);
    }
    
    /**
     * The type for variable that represents a property of another node.
     */
    PropertyType::PropertyType(const PropertyType& value)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)68);
        setServerVariable(variable_);
    }
    
    PropertyType::~PropertyType(void)
    {
    }

    ServerVariable::SPtr&
    PropertyType::variable(void)
    {
        return variable_;
    }

    void
    PropertyType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    PropertyType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    PropertyType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
