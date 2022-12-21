/*
    VariableTypeClass: BrokerDataSetReaderTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BrokerDataSetReaderTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    BrokerDataSetReaderTransportType::BrokerDataSetReaderTransportType(void)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , metaDataQueueName_Variable_(boost::make_shared<ServerVariable>("MetaDataQueueName_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21142);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(metaDataQueueName_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerDataSetReaderTransportType::BrokerDataSetReaderTransportType(const BrokerDataSetReaderTransportType& value)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , metaDataQueueName_Variable_(boost::make_shared<ServerVariable>("MetaDataQueueName_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21142);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(metaDataQueueName_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerDataSetReaderTransportType::~BrokerDataSetReaderTransportType(void)
    {
    }

    ServerVariable::SPtr&
    BrokerDataSetReaderTransportType::authenticationProfileUri_Variable(void)
    {
        return authenticationProfileUri_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetReaderTransportType::metaDataQueueName_Variable(void)
    {
        return metaDataQueueName_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetReaderTransportType::queueName_Variable(void)
    {
        return queueName_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetReaderTransportType::requestedDeliveryGuarantee_Variable(void)
    {
        return requestedDeliveryGuarantee_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetReaderTransportType::resourceUri_Variable(void)
    {
        return resourceUri_Variable_;
    }

    void
    BrokerDataSetReaderTransportType::authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        authenticationProfileUri_Variable_ = serverVariable;
    }

    void
    BrokerDataSetReaderTransportType::metaDataQueueName_Variable(ServerVariable::SPtr& serverVariable)
    {
        metaDataQueueName_Variable_ = serverVariable;
    }

    void
    BrokerDataSetReaderTransportType::queueName_Variable(ServerVariable::SPtr& serverVariable)
    {
        queueName_Variable_ = serverVariable;
    }

    void
    BrokerDataSetReaderTransportType::requestedDeliveryGuarantee_Variable(ServerVariable::SPtr& serverVariable)
    {
        requestedDeliveryGuarantee_Variable_ = serverVariable;
    }

    void
    BrokerDataSetReaderTransportType::resourceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        resourceUri_Variable_ = serverVariable;
    }

    bool
    BrokerDataSetReaderTransportType::get_AuthenticationProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::get_MetaDataQueueName_Variable(OpcUaDataValue& dataValue)
    {
        return metaDataQueueName_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::get_QueueName_Variable(OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::get_RequestedDeliveryGuarantee_Variable(OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::get_ResourceUri_Variable(OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::set_AuthenticationProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::set_MetaDataQueueName_Variable(const OpcUaDataValue& dataValue)
    {
        return metaDataQueueName_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::set_QueueName_Variable(const OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::set_RequestedDeliveryGuarantee_Variable(const OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetReaderTransportType::set_ResourceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->setDataValue(dataValue);
    }

}
