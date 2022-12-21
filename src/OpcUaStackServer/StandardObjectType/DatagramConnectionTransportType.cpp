/*
    VariableTypeClass: DatagramConnectionTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DatagramConnectionTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    DatagramConnectionTransportType::DatagramConnectionTransportType(void)
    : ObjectBase()
    , discoveryAddress_NetworkInterface_Variable_(boost::make_shared<ServerVariable>("DiscoveryAddress_NetworkInterface_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15064);
        setServerVariable(discoveryAddress_NetworkInterface_Variable_);
    }
    
    DatagramConnectionTransportType::DatagramConnectionTransportType(const DatagramConnectionTransportType& value)
    : ObjectBase()
    , discoveryAddress_NetworkInterface_Variable_(boost::make_shared<ServerVariable>("DiscoveryAddress_NetworkInterface_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15064);
        setServerVariable(discoveryAddress_NetworkInterface_Variable_);
    }
    
    DatagramConnectionTransportType::~DatagramConnectionTransportType(void)
    {
    }

    ServerVariable::SPtr&
    DatagramConnectionTransportType::discoveryAddress_NetworkInterface_Variable(void)
    {
        return discoveryAddress_NetworkInterface_Variable_;
    }

    void
    DatagramConnectionTransportType::discoveryAddress_NetworkInterface_Variable(ServerVariable::SPtr& serverVariable)
    {
        discoveryAddress_NetworkInterface_Variable_ = serverVariable;
    }

    bool
    DatagramConnectionTransportType::get_DiscoveryAddress_NetworkInterface_Variable(OpcUaDataValue& dataValue)
    {
        return discoveryAddress_NetworkInterface_Variable_->getDataValue(dataValue);
    }

    bool
    DatagramConnectionTransportType::set_DiscoveryAddress_NetworkInterface_Variable(const OpcUaDataValue& dataValue)
    {
        return discoveryAddress_NetworkInterface_Variable_->setDataValue(dataValue);
    }

}
