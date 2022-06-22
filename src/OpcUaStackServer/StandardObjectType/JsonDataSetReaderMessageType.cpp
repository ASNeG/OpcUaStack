/*
    VariableTypeClass: JsonDataSetReaderMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/JsonDataSetReaderMessageType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    JsonDataSetReaderMessageType::JsonDataSetReaderMessageType(void)
    : ObjectBase()
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21130);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
    }
    
    JsonDataSetReaderMessageType::JsonDataSetReaderMessageType(const JsonDataSetReaderMessageType& value)
    : ObjectBase()
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21130);
        setServerVariable(dataSetMessageContentMask_Variable_);
        setServerVariable(networkMessageContentMask_Variable_);
    }
    
    JsonDataSetReaderMessageType::~JsonDataSetReaderMessageType(void)
    {
    }

    ServerVariable::SPtr&
    JsonDataSetReaderMessageType::dataSetMessageContentMask_Variable(void)
    {
        return dataSetMessageContentMask_Variable_;
    }

    ServerVariable::SPtr&
    JsonDataSetReaderMessageType::networkMessageContentMask_Variable(void)
    {
        return networkMessageContentMask_Variable_;
    }

    void
    JsonDataSetReaderMessageType::dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMessageContentMask_Variable_ = serverVariable;
    }

    void
    JsonDataSetReaderMessageType::networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageContentMask_Variable_ = serverVariable;
    }

    bool
    JsonDataSetReaderMessageType::get_DataSetMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    JsonDataSetReaderMessageType::get_NetworkMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    JsonDataSetReaderMessageType::set_DataSetMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->setDataValue(dataValue);
    }

    bool
    JsonDataSetReaderMessageType::set_NetworkMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->setDataValue(dataValue);
    }

}
