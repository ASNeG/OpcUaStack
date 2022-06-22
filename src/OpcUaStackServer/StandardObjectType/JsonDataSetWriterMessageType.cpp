/*
    VariableTypeClass: JsonDataSetWriterMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/JsonDataSetWriterMessageType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    JsonDataSetWriterMessageType::JsonDataSetWriterMessageType(void)
    : ObjectBase()
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21128);
        setServerVariable(dataSetMessageContentMask_Variable_);
    }
    
    JsonDataSetWriterMessageType::JsonDataSetWriterMessageType(const JsonDataSetWriterMessageType& value)
    : ObjectBase()
    , dataSetMessageContentMask_Variable_(boost::make_shared<ServerVariable>("DataSetMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21128);
        setServerVariable(dataSetMessageContentMask_Variable_);
    }
    
    JsonDataSetWriterMessageType::~JsonDataSetWriterMessageType(void)
    {
    }

    ServerVariable::SPtr&
    JsonDataSetWriterMessageType::dataSetMessageContentMask_Variable(void)
    {
        return dataSetMessageContentMask_Variable_;
    }

    void
    JsonDataSetWriterMessageType::dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataSetMessageContentMask_Variable_ = serverVariable;
    }

    bool
    JsonDataSetWriterMessageType::get_DataSetMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    JsonDataSetWriterMessageType::set_DataSetMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return dataSetMessageContentMask_Variable_->setDataValue(dataValue);
    }

}
