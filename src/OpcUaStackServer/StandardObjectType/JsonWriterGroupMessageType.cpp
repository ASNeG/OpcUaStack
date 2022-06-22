/*
    VariableTypeClass: JsonWriterGroupMessageType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/JsonWriterGroupMessageType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    JsonWriterGroupMessageType::JsonWriterGroupMessageType(void)
    : ObjectBase()
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21126);
        setServerVariable(networkMessageContentMask_Variable_);
    }
    
    JsonWriterGroupMessageType::JsonWriterGroupMessageType(const JsonWriterGroupMessageType& value)
    : ObjectBase()
    , networkMessageContentMask_Variable_(boost::make_shared<ServerVariable>("NetworkMessageContentMask_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)21126);
        setServerVariable(networkMessageContentMask_Variable_);
    }
    
    JsonWriterGroupMessageType::~JsonWriterGroupMessageType(void)
    {
    }

    ServerVariable::SPtr&
    JsonWriterGroupMessageType::networkMessageContentMask_Variable(void)
    {
        return networkMessageContentMask_Variable_;
    }

    void
    JsonWriterGroupMessageType::networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable)
    {
        networkMessageContentMask_Variable_ = serverVariable;
    }

    bool
    JsonWriterGroupMessageType::get_NetworkMessageContentMask_Variable(OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->getDataValue(dataValue);
    }

    bool
    JsonWriterGroupMessageType::set_NetworkMessageContentMask_Variable(const OpcUaDataValue& dataValue)
    {
        return networkMessageContentMask_Variable_->setDataValue(dataValue);
    }

}
