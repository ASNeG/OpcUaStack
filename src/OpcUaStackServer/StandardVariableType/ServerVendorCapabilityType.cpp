/*
    VariableTypeClass: ServerVendorCapabilityType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerVendorCapabilityType.h"

namespace OpcUaStackServer
{
    
    ServerVendorCapabilityType::ServerVendorCapabilityType(void)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2137);
        setServerVariable(variable_);
    }
    
    ServerVendorCapabilityType::ServerVendorCapabilityType(const ServerVendorCapabilityType& value)
    : VariableBase()
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2137);
        setServerVariable(variable_);
    }
    
    ServerVendorCapabilityType::~ServerVendorCapabilityType(void)
    {
    }

    ServerVariable::SPtr&
    ServerVendorCapabilityType::variable(void)
    {
        return variable_;
    }

    void
    ServerVendorCapabilityType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ServerVendorCapabilityType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ServerVendorCapabilityType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
