/*
    VariableTypeClass: NetworkAddressType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NetworkAddressType.h"

namespace OpcUaStackServer
{
    
    NetworkAddressType::NetworkAddressType(void)
    : ObjectBase()
    , networkInterface_Variable_(boost::make_shared<ServerVariable>("NetworkInterface_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21145);
        setServerVariable(networkInterface_Variable_);
    }
    
    NetworkAddressType::NetworkAddressType(const NetworkAddressType& value)
    : ObjectBase()
    , networkInterface_Variable_(boost::make_shared<ServerVariable>("NetworkInterface_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21145);
        setServerVariable(networkInterface_Variable_);
    }
    
    NetworkAddressType::~NetworkAddressType(void)
    {
    }

    ServerVariable::SPtr&
    NetworkAddressType::networkInterface_Variable(void)
    {
        return networkInterface_Variable_;
    }

    void
    NetworkAddressType::networkInterface_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkInterface_Variable_ = serverVariable;
    }

    bool
    NetworkAddressType::get_NetworkInterface_Variable(OpcUaDataValue& dataValue)
    {
        return networkInterface_Variable_->getDataValue(dataValue);
    }

    bool
    NetworkAddressType::set_NetworkInterface_Variable(const OpcUaDataValue& dataValue)
    {
        return networkInterface_Variable_->setDataValue(dataValue);
    }

}
