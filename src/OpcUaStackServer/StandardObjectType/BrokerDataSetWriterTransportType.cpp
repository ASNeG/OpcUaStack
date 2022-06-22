/*
    VariableTypeClass: BrokerDataSetWriterTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BrokerDataSetWriterTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    BrokerDataSetWriterTransportType::BrokerDataSetWriterTransportType(void)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , metaDataQueueName_Variable_(boost::make_shared<ServerVariable>("MetaDataQueueName_Variable"))
    , metaDataUpdateTime_Variable_(boost::make_shared<ServerVariable>("MetaDataUpdateTime_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21138);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(metaDataQueueName_Variable_);
        setServerVariable(metaDataUpdateTime_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerDataSetWriterTransportType::BrokerDataSetWriterTransportType(const BrokerDataSetWriterTransportType& value)
    : ObjectBase()
    , authenticationProfileUri_Variable_(boost::make_shared<ServerVariable>("AuthenticationProfileUri_Variable"))
    , metaDataQueueName_Variable_(boost::make_shared<ServerVariable>("MetaDataQueueName_Variable"))
    , metaDataUpdateTime_Variable_(boost::make_shared<ServerVariable>("MetaDataUpdateTime_Variable"))
    , queueName_Variable_(boost::make_shared<ServerVariable>("QueueName_Variable"))
    , requestedDeliveryGuarantee_Variable_(boost::make_shared<ServerVariable>("RequestedDeliveryGuarantee_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21138);
        setServerVariable(authenticationProfileUri_Variable_);
        setServerVariable(metaDataQueueName_Variable_);
        setServerVariable(metaDataUpdateTime_Variable_);
        setServerVariable(queueName_Variable_);
        setServerVariable(requestedDeliveryGuarantee_Variable_);
        setServerVariable(resourceUri_Variable_);
    }
    
    BrokerDataSetWriterTransportType::~BrokerDataSetWriterTransportType(void)
    {
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::authenticationProfileUri_Variable(void)
    {
        return authenticationProfileUri_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::metaDataQueueName_Variable(void)
    {
        return metaDataQueueName_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::metaDataUpdateTime_Variable(void)
    {
        return metaDataUpdateTime_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::queueName_Variable(void)
    {
        return queueName_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::requestedDeliveryGuarantee_Variable(void)
    {
        return requestedDeliveryGuarantee_Variable_;
    }

    ServerVariable::SPtr&
    BrokerDataSetWriterTransportType::resourceUri_Variable(void)
    {
        return resourceUri_Variable_;
    }

    void
    BrokerDataSetWriterTransportType::authenticationProfileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        authenticationProfileUri_Variable_ = serverVariable;
    }

    void
    BrokerDataSetWriterTransportType::metaDataQueueName_Variable(ServerVariable::SPtr& serverVariable)
    {
        metaDataQueueName_Variable_ = serverVariable;
    }

    void
    BrokerDataSetWriterTransportType::metaDataUpdateTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        metaDataUpdateTime_Variable_ = serverVariable;
    }

    void
    BrokerDataSetWriterTransportType::queueName_Variable(ServerVariable::SPtr& serverVariable)
    {
        queueName_Variable_ = serverVariable;
    }

    void
    BrokerDataSetWriterTransportType::requestedDeliveryGuarantee_Variable(ServerVariable::SPtr& serverVariable)
    {
        requestedDeliveryGuarantee_Variable_ = serverVariable;
    }

    void
    BrokerDataSetWriterTransportType::resourceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        resourceUri_Variable_ = serverVariable;
    }

    bool
    BrokerDataSetWriterTransportType::get_AuthenticationProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::get_MetaDataQueueName_Variable(OpcUaDataValue& dataValue)
    {
        return metaDataQueueName_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::get_MetaDataUpdateTime_Variable(OpcUaDataValue& dataValue)
    {
        return metaDataUpdateTime_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::get_QueueName_Variable(OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::get_RequestedDeliveryGuarantee_Variable(OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::get_ResourceUri_Variable(OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->getDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_AuthenticationProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return authenticationProfileUri_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_MetaDataQueueName_Variable(const OpcUaDataValue& dataValue)
    {
        return metaDataQueueName_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_MetaDataUpdateTime_Variable(const OpcUaDataValue& dataValue)
    {
        return metaDataUpdateTime_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_QueueName_Variable(const OpcUaDataValue& dataValue)
    {
        return queueName_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_RequestedDeliveryGuarantee_Variable(const OpcUaDataValue& dataValue)
    {
        return requestedDeliveryGuarantee_Variable_->setDataValue(dataValue);
    }

    bool
    BrokerDataSetWriterTransportType::set_ResourceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->setDataValue(dataValue);
    }

}
