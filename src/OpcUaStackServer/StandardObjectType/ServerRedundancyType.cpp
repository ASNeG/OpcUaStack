/*
    VariableTypeClass: ServerRedundancyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ServerRedundancyType.h"

namespace OpcUaStackServer
{
    
    /**
     * A base type for an object that describe how a server supports redundancy.
     */
    ServerRedundancyType::ServerRedundancyType(void)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2034);
        setServerVariable(redundancySupport_Variable_);
    }
    
    /**
     * A base type for an object that describe how a server supports redundancy.
     */
    ServerRedundancyType::ServerRedundancyType(const ServerRedundancyType& value)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2034);
        setServerVariable(redundancySupport_Variable_);
    }
    
    ServerRedundancyType::~ServerRedundancyType(void)
    {
    }

    ServerVariable::SPtr&
    ServerRedundancyType::redundancySupport_Variable(void)
    {
        return redundancySupport_Variable_;
    }

    void
    ServerRedundancyType::redundancySupport_Variable(ServerVariable::SPtr& serverVariable)
    {
        redundancySupport_Variable_ = serverVariable;
    }

    bool
    ServerRedundancyType::get_RedundancySupport_Variable(OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->getDataValue(dataValue);
    }

    bool
    ServerRedundancyType::set_RedundancySupport_Variable(const OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->setDataValue(dataValue);
    }

}
