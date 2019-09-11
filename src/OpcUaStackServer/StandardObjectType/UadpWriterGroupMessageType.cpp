/*
    VariableTypeClass: UadpWriterGroupMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/UadpWriterGroupMessageType.h"

namespace OpcUaStackServer
{
    
    UadpWriterGroupMessageType::UadpWriterGroupMessageType(void)
    : ObjectBase()
    , dataSetOrdering_Variable_(boost::make_shared<ServerVariable>("DataSetOrdering_Variable"))
    , groupVersion_Variable_(boost::make_shared<ServerVariable>("GroupVersion_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    , publishingOffset_Variable_(boost::make_shared<ServerVariable>("PublishingOffset_Variable"))
    , samplingOffset_Variable_(boost::make_shared<ServerVariable>("SamplingOffset_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21105);
        setServerVariable(dataSetOrdering_Variable_);
        setServerVariable(groupVersion_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
        setServerVariable(publishingOffset_Variable_);
        setServerVariable(samplingOffset_Variable_);
    }
    
    UadpWriterGroupMessageType::UadpWriterGroupMessageType(const UadpWriterGroupMessageType& value)
    : ObjectBase()
    , dataSetOrdering_Variable_(boost::make_shared<ServerVariable>("DataSetOrdering_Variable"))
    , groupVersion_Variable_(boost::make_shared<ServerVariable>("GroupVersion_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    , publishingOffset_Variable_(boost::make_shared<ServerVariable>("PublishingOffset_Variable"))
    , samplingOffset_Variable_(boost::make_shared<ServerVariable>("SamplingOffset_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21105);
        setServerVariable(dataSetOrdering_Variable_);
        setServerVariable(groupVersion_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
        setServerVariable(publishingOffset_Variable_);
        setServerVariable(samplingOffset_Variable_);
    }
    
    UadpWriterGroupMessageType::~UadpWriterGroupMessageType(void)
    {
    }

    ServerVariable::SPtr&
    UadpWriterGroupMessageType::dataSetOrdering_Variable(void)
    {
        return dataSetOrdering_Variable_;
    }

    ServerVariable::SPtr&
    UadpWriterGroupMessageType::groupVersion_Variable(void)
    {
        return groupVersion_Variable_;
    }

    ServerVariable::SPtr&
    UadpWriterGroupMessageType::networkMessageContentMask_Variable(void)
    {
        return networkMessageContentMask_Variable_;
    }

    ServerVariable::SPtr&
    UadpWriterGroupMessageType::publishingOffset_Variable(void)
    {
        return publishingOffset_Variable_;
    }

    ServerVariable::SPtr&
    UadpWriterGroupMessageType::samplingOffset_Variable(void)
    {
        return samplingOffset_Variable_;
    }

    void
    UadpWriterGroupMessageType::dataSetOrdering_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetOrdering_Variable_ = serverVariable;
    }

    void
    UadpWriterGroupMessageType::groupVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupVersion_Variable_ = serverVariable;
    }

    void
    UadpWriterGroupMessageType::networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageContentMask_Variable_ = serverVariable;
    }

    void
    UadpWriterGroupMessageType::publishingOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingOffset_Variable_ = serverVariable;
    }

    void
    UadpWriterGroupMessageType::samplingOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingOffset_Variable_ = serverVariable;
    }

    bool
    UadpWriterGroupMessageType::get_DataSetOrdering_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetOrdering_Variable_->getDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::get_GroupVersion_Variable(OpcUaDataValue& dataValue)
    {
        return groupVersion_Variable_->getDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::get_NetworkMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::get_PublishingOffset_Variable(OpcUaDataValue& dataValue)
    {
        return publishingOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::get_SamplingOffset_Variable(OpcUaDataValue& dataValue)
    {
        return samplingOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::set_DataSetOrdering_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetOrdering_Variable_->setDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::set_GroupVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return groupVersion_Variable_->setDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::set_NetworkMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::set_PublishingOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingOffset_Variable_->setDataValue(dataValue);
    }

    bool
    UadpWriterGroupMessageType::set_SamplingOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingOffset_Variable_->setDataValue(dataValue);
    }

}
