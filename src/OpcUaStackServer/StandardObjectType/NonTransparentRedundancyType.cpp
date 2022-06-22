/*
    VariableTypeClass: NonTransparentRedundancyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NonTransparentRedundancyType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * Identifies the capabilties of server that supports non-transparent redundancy.
     */
    NonTransparentRedundancyType::NonTransparentRedundancyType(void)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , serverUriArray_Variable_(boost::make_shared<ServerVariable>("ServerUriArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2039);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(serverUriArray_Variable_);
    }
    
    /**
     * Identifies the capabilties of server that supports non-transparent redundancy.
     */
    NonTransparentRedundancyType::NonTransparentRedundancyType(const NonTransparentRedundancyType& value)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , serverUriArray_Variable_(boost::make_shared<ServerVariable>("ServerUriArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2039);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(serverUriArray_Variable_);
    }
    
    NonTransparentRedundancyType::~NonTransparentRedundancyType(void)
    {
    }

    ServerVariable::SPtr&
    NonTransparentRedundancyType::redundancySupport_Variable(void)
    {
        return redundancySupport_Variable_;
    }

    ServerVariable::SPtr&
    NonTransparentRedundancyType::serverUriArray_Variable(void)
    {
        return serverUriArray_Variable_;
    }

    void
    NonTransparentRedundancyType::redundancySupport_Variable(ServerVariable::SPtr& serverVariable)
    {
        redundancySupport_Variable_ = serverVariable;
    }

    void
    NonTransparentRedundancyType::serverUriArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverUriArray_Variable_ = serverVariable;
    }

    bool
    NonTransparentRedundancyType::get_RedundancySupport_Variable(OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->getDataValue(dataValue);
    }

    bool
    NonTransparentRedundancyType::get_ServerUriArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverUriArray_Variable_->getDataValue(dataValue);
    }

    bool
    NonTransparentRedundancyType::set_RedundancySupport_Variable(const OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->setDataValue(dataValue);
    }

    bool
    NonTransparentRedundancyType::set_ServerUriArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverUriArray_Variable_->setDataValue(dataValue);
    }

}
