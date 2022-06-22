/*
    VariableTypeClass: BrokerConnectionTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BrokerConnectionTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    BrokerConnectionTransportType::BrokerConnectionTransportType(void)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15155);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerConnectionTransportType::BrokerConnectionTransportType(const BrokerConnectionTransportType& value)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15155);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerConnectionTransportType::~BrokerConnectionTransportType(void)
    {
    }

    ServerVariable::SPtr&
    BrokerConnectionTransportType::authenticationProfileUri_Variable(void)
    {
        return authenticationProfileUri_Variable_;
    }

    ServerVariable::SPtr&
    BrokerConnectionTransportType::resourceUri_Variable(void)
    {
        return resourceUri_Variable_;
    }

    void
    BrokerConnectionTransportType::authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        authenticationProfileUri_Variable_ = serverVariable;
    }

    void
    BrokerConnectionTransportType::resourceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        resourceUri_Variable_ = serverVariable;
    }

    bool
    BrokerConnectionTransportType::get_AuthenticationProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerConnectionTransportType::get_ResourceUri_Variable(OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerConnectionTransportType::set_AuthenticationProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerConnectionTransportType::set_ResourceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->setDataValue(dataValue);
    }

}
