/*
    VariableTypeClass: NetworkAddressUrlType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NetworkAddressUrlType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    NetworkAddressUrlType::NetworkAddressUrlType(void)
    : ObjectBase()
    , networkInterface_Variable_(boost::make_shared<ServerVariable>("NetworkInterface_Variable"))
    , url_Variable_(boost::make_shared<ServerVariable>("Url_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21147);
        setServerVariable(networkInterface_Variable_);
        setServerVariable(url_Variable_);
    }
    
    NetworkAddressUrlType::NetworkAddressUrlType(const NetworkAddressUrlType& value)
    : ObjectBase()
    , networkInterface_Variable_(boost::make_shared<ServerVariable>("NetworkInterface_Variable"))
    , url_Variable_(boost::make_shared<ServerVariable>("Url_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21147);
        setServerVariable(networkInterface_Variable_);
        setServerVariable(url_Variable_);
    }
    
    NetworkAddressUrlType::~NetworkAddressUrlType(void)
    {
    }

    ServerVariable::SPtr&
    NetworkAddressUrlType::networkInterface_Variable(void)
    {
        return networkInterface_Variable_;
    }

    ServerVariable::SPtr&
    NetworkAddressUrlType::url_Variable(void)
    {
        return url_Variable_;
    }

    void
    NetworkAddressUrlType::networkInterface_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkInterface_Variable_ = serverVariable;
    }

    void
    NetworkAddressUrlType::url_Variable(ServerVariable::SPtr& serverVariable)
    {
        url_Variable_ = serverVariable;
    }

    bool
    NetworkAddressUrlType::get_NetworkInterface_Variable(OpcUaDataValue& dataValue)
    {
        return networkInterface_Variable_->getDataValue(dataValue);
    }

    bool
    NetworkAddressUrlType::get_Url_Variable(OpcUaDataValue& dataValue)
    {
        return url_Variable_->getDataValue(dataValue);
    }

    bool
    NetworkAddressUrlType::set_NetworkInterface_Variable(const OpcUaDataValue& dataValue)
    {
        return networkInterface_Variable_->setDataValue(dataValue);
    }

    bool
    NetworkAddressUrlType::set_Url_Variable(const OpcUaDataValue& dataValue)
    {
        return url_Variable_->setDataValue(dataValue);
    }

}
