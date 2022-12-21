/*
    VariableTypeClass: BaseVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/BaseVariableType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * The abstract base type for all variable nodes.
     */
    BaseVariableType::BaseVariableType(void)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)62);
        setServerVariable(variable_);
    }
    
    /**
     * The abstract base type for all variable nodes.
     */
    BaseVariableType::BaseVariableType(const BaseVariableType& value)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)62);
        setServerVariable(variable_);
    }
    
    BaseVariableType::~BaseVariableType(void)
    {
    }

    ServerVariable::SPtr&
    BaseVariableType::variable(void)
    {
        return variable_;
    }

    void
    BaseVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    BaseVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    BaseVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
