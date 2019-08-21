/*
    VariableTypeClass: UadpDataSetReaderMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/UadpDataSetReaderMessageType.h"

namespace OpcUaStackServer
{
    
    UadpDataSetReaderMessageType::UadpDataSetReaderMessageType(void)
    : ObjectBase()
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , dataSetOffset_Variable_(boost::make_shared<ServerVariable>("DataSetOffset_Variable"))
    , dataSetOrdering_Variable_(boost::make_shared<ServerVariable>("DataSetOrdering_Variable"))
    , groupVersion_Variable_(boost::make_shared<ServerVariable>("GroupVersion_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    , networkMessageNumber_Variable_(boost::make_shared<ServerVariable>("NetworkMessageNumber_Variable"))
    , processingOffset_Variable_(boost::make_shared<ServerVariable>("ProcessingOffset_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , receiveOffset_Variable_(boost::make_shared<ServerVariable>("ReceiveOffset_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21116);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(dataSetOffset_Variable_);
        setServerVariable(dataSetOrdering_Variable_);
        setServerVariable(groupVersion_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
        setServerVariable(networkMessageNumber_Variable_);
        setServerVariable(processingOffset_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(receiveOffset_Variable_);
    }
    
    UadpDataSetReaderMessageType::UadpDataSetReaderMessageType(const UadpDataSetReaderMessageType& value)
    : ObjectBase()
    , dataSetClassId_Variable_(boost::make_shared<ServerVariable>("DataSetClassId_Variable"))
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , dataSetOffset_Variable_(boost::make_shared<ServerVariable>("DataSetOffset_Variable"))
    , dataSetOrdering_Variable_(boost::make_shared<ServerVariable>("DataSetOrdering_Variable"))
    , groupVersion_Variable_(boost::make_shared<ServerVariable>("GroupVersion_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    , networkMessageNumber_Variable_(boost::make_shared<ServerVariable>("NetworkMessageNumber_Variable"))
    , processingOffset_Variable_(boost::make_shared<ServerVariable>("ProcessingOffset_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , receiveOffset_Variable_(boost::make_shared<ServerVariable>("ReceiveOffset_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21116);
        setServerVariable(dataSetClassId_Variable_);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(dataSetOffset_Variable_);
        setServerVariable(dataSetOrdering_Variable_);
        setServerVariable(groupVersion_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
        setServerVariable(networkMessageNumber_Variable_);
        setServerVariable(processingOffset_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(receiveOffset_Variable_);
    }
    
    UadpDataSetReaderMessageType::~UadpDataSetReaderMessageType(void)
    {
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::dataSetClassId_Variable(void)
    {
        return dataSetClassId_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::dataSetMessageContentMask_Variable(void)
    {
        return dataSetMessageContentMask_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::dataSetOffset_Variable(void)
    {
        return dataSetOffset_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::dataSetOrdering_Variable(void)
    {
        return dataSetOrdering_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::groupVersion_Variable(void)
    {
        return groupVersion_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::networkMessageContentMask_Variable(void)
    {
        return networkMessageContentMask_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::networkMessageNumber_Variable(void)
    {
        return networkMessageNumber_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::processingOffset_Variable(void)
    {
        return processingOffset_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::publishingInterval_Variable(void)
    {
        return publishingInterval_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetReaderMessageType::receiveOffset_Variable(void)
    {
        return receiveOffset_Variable_;
    }

    void
    UadpDataSetReaderMessageType::dataSetClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetClassId_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMessageContentMask_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::dataSetOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetOffset_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::dataSetOrdering_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetOrdering_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::groupVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupVersion_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageContentMask_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::networkMessageNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageNumber_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::processingOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        processingOffset_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::publishingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingInterval_Variable_ = serverVariable;
    }

    void
    UadpDataSetReaderMessageType::receiveOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveOffset_Variable_ = serverVariable;
    }

    bool
    UadpDataSetReaderMessageType::get_DataSetClassId_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_DataSetMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_DataSetOffset_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_DataSetOrdering_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetOrdering_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_GroupVersion_Variable(OpcUaDataValue& dataValue)
    {
        return groupVersion_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_NetworkMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_NetworkMessageNumber_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageNumber_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_ProcessingOffset_Variable(OpcUaDataValue& dataValue)
    {
        return processingOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_PublishingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::get_ReceiveOffset_Variable(OpcUaDataValue& dataValue)
    {
        return receiveOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_DataSetClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetClassId_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_DataSetMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_DataSetOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetOffset_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_DataSetOrdering_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetOrdering_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_GroupVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return groupVersion_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_NetworkMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_NetworkMessageNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageNumber_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_ProcessingOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return processingOffset_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_PublishingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetReaderMessageType::set_ReceiveOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveOffset_Variable_->setDataValue(dataValue);
    }

}
