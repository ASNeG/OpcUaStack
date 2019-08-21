/*
    VariableTypeClass: UadpDataSetWriterMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/UadpDataSetWriterMessageType.h"

namespace OpcUaStackServer
{
    
    UadpDataSetWriterMessageType::UadpDataSetWriterMessageType(void)
    : ObjectBase()
    , configuredSize_Variable_(boost::make_shared<ServerVariable>("ConfiguredSize_Variable"))
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , dataSetOffset_Variable_(boost::make_shared<ServerVariable>("DataSetOffset_Variable"))
    , networkMessageNumber_Variable_(boost::make_shared<ServerVariable>("NetworkMessageNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21111);
        setServerVariable(configuredSize_Variable_);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(dataSetOffset_Variable_);
        setServerVariable(networkMessageNumber_Variable_);
    }
    
    UadpDataSetWriterMessageType::UadpDataSetWriterMessageType(const UadpDataSetWriterMessageType& value)
    : ObjectBase()
    , configuredSize_Variable_(boost::make_shared<ServerVariable>("ConfiguredSize_Variable"))
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , dataSetOffset_Variable_(boost::make_shared<ServerVariable>("DataSetOffset_Variable"))
    , networkMessageNumber_Variable_(boost::make_shared<ServerVariable>("NetworkMessageNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21111);
        setServerVariable(configuredSize_Variable_);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(dataSetOffset_Variable_);
        setServerVariable(networkMessageNumber_Variable_);
    }
    
    UadpDataSetWriterMessageType::~UadpDataSetWriterMessageType(void)
    {
    }

    ServerVariable::SPtr&
    UadpDataSetWriterMessageType::configuredSize_Variable(void)
    {
        return configuredSize_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetWriterMessageType::dataSetMessageContentMask_Variable(void)
    {
        return dataSetMessageContentMask_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetWriterMessageType::dataSetOffset_Variable(void)
    {
        return dataSetOffset_Variable_;
    }

    ServerVariable::SPtr&
    UadpDataSetWriterMessageType::networkMessageNumber_Variable(void)
    {
        return networkMessageNumber_Variable_;
    }

    void
    UadpDataSetWriterMessageType::configuredSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        configuredSize_Variable_ = serverVariable;
    }

    void
    UadpDataSetWriterMessageType::dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMessageContentMask_Variable_ = serverVariable;
    }

    void
    UadpDataSetWriterMessageType::dataSetOffset_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetOffset_Variable_ = serverVariable;
    }

    void
    UadpDataSetWriterMessageType::networkMessageNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageNumber_Variable_ = serverVariable;
    }

    bool
    UadpDataSetWriterMessageType::get_ConfiguredSize_Variable(OpcUaDataValue& dataValue)
    {
        return configuredSize_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::get_DataSetMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::get_DataSetOffset_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetOffset_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::get_NetworkMessageNumber_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageNumber_Variable_->getDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::set_ConfiguredSize_Variable(const OpcUaDataValue& dataValue)
    {
        return configuredSize_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::set_DataSetMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::set_DataSetOffset_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetOffset_Variable_->setDataValue(dataValue);
    }

    bool
    UadpDataSetWriterMessageType::set_NetworkMessageNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageNumber_Variable_->setDataValue(dataValue);
    }

}
