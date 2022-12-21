/*
    VariableTypeClass: BrokerWriterGroupTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BrokerWriterGroupTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    BrokerWriterGroupTransportType::BrokerWriterGroupTransportType(void)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21136);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerWriterGroupTransportType::BrokerWriterGroupTransportType(const BrokerWriterGroupTransportType& value)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21136);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerWriterGroupTransportType::~BrokerWriterGroupTransportType(void)
    {
    }

    ServerVariable::SPtr&
    BrokerWriterGroupTransportType::authenticationProfileUri_Variable(void)
    {
        return authenticationProfileUri_Variable_;
    }

    ServerVariable::SPtr&
    BrokerWriterGroupTransportType::queueName_Variable(void)
    {
        return queueName_Variable_;
    }

    ServerVariable::SPtr&
    BrokerWriterGroupTransportType::requestedDeliveryGuarantee_Variable(void)
    {
        return requestedDeliveryGuarantee_Variable_;
    }

    ServerVariable::SPtr&
    BrokerWriterGroupTransportType::resourceUri_Variable(void)
    {
        return resourceUri_Variable_;
    }

    void
    BrokerWriterGroupTransportType::authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        authenticationProfileUri_Variable_ = serverVariable;
    }

    void
    BrokerWriterGroupTransportType::queueName_Variable(ServerVariable::SPtr& serverVariable)
    {
        queueName_Variable_ = serverVariable;
    }

    void
    BrokerWriterGroupTransportType::requestedDeliveryGuarantee_Variable(ServerVariable::SPtr& serverVariable)
    {
        requestedDeliveryGuarantee_Variable_ = serverVariable;
    }

    void
    BrokerWriterGroupTransportType::resourceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        resourceUri_Variable_ = serverVariable;
    }

    bool
    BrokerWriterGroupTransportType::get_AuthenticationProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::get_QueueName_Variable(OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::get_RequestedDeliveryGuarantee_Variable(OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::get_ResourceUri_Variable(OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::set_AuthenticationProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::set_QueueName_Variable(const OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::set_RequestedDeliveryGuarantee_Variable(const OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerWriterGroupTransportType::set_ResourceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->setDataValue(dataValue);
    }

}
