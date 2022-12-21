/*
    VariableTypeClass: TransparentRedundancyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TransparentRedundancyType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * Identifies the capabilties of server that supports transparent redundancy.
     */
    TransparentRedundancyType::TransparentRedundancyType(void)
    : ObjectBase()
    , currentServerId_Variable_(boost::make_shared<ServerVariable>("CurrentServerId_Variable"))
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , redundantServerArray_Variable_(boost::make_shared<ServerVariable>("RedundantServerArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2036);
        setServerVariable(currentServerId_Variable_);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(redundantServerArray_Variable_);
    }
    
    /**
     * Identifies the capabilties of server that supports transparent redundancy.
     */
    TransparentRedundancyType::TransparentRedundancyType(const TransparentRedundancyType& value)
    : ObjectBase()
    , currentServerId_Variable_(boost::make_shared<ServerVariable>("CurrentServerId_Variable"))
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , redundantServerArray_Variable_(boost::make_shared<ServerVariable>("RedundantServerArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2036);
        setServerVariable(currentServerId_Variable_);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(redundantServerArray_Variable_);
    }
    
    TransparentRedundancyType::~TransparentRedundancyType(void)
    {
    }

    ServerVariable::SPtr&
    TransparentRedundancyType::currentServerId_Variable(void)
    {
        return currentServerId_Variable_;
    }

    ServerVariable::SPtr&
    TransparentRedundancyType::redundancySupport_Variable(void)
    {
        return redundancySupport_Variable_;
    }

    ServerVariable::SPtr&
    TransparentRedundancyType::redundantServerArray_Variable(void)
    {
        return redundantServerArray_Variable_;
    }

    void
    TransparentRedundancyType::currentServerId_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentServerId_Variable_ = serverVariable;
    }

    void
    TransparentRedundancyType::redundancySupport_Variable(ServerVariable::SPtr& serverVariable)
    {
        redundancySupport_Variable_ = serverVariable;
    }

    void
    TransparentRedundancyType::redundantServerArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        redundantServerArray_Variable_ = serverVariable;
    }

    bool
    TransparentRedundancyType::get_CurrentServerId_Variable(OpcUaDataValue& dataValue)
    {
        return currentServerId_Variable_->getDataValue(dataValue);
    }

    bool
    TransparentRedundancyType::get_RedundancySupport_Variable(OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->getDataValue(dataValue);
    }

    bool
    TransparentRedundancyType::get_RedundantServerArray_Variable(OpcUaDataValue& dataValue)
    {
        return redundantServerArray_Variable_->getDataValue(dataValue);
    }

    bool
    TransparentRedundancyType::set_CurrentServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return currentServerId_Variable_->setDataValue(dataValue);
    }

    bool
    TransparentRedundancyType::set_RedundancySupport_Variable(const OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->setDataValue(dataValue);
    }

    bool
    TransparentRedundancyType::set_RedundantServerArray_Variable(const OpcUaDataValue& dataValue)
    {
        return redundantServerArray_Variable_->setDataValue(dataValue);
    }

}
