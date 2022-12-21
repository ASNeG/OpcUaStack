/*
    VariableTypeClass: NonTransparentNetworkRedundancyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NonTransparentNetworkRedundancyType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    NonTransparentNetworkRedundancyType::NonTransparentNetworkRedundancyType(void)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , serverNetworkGroups_Variable_(boost::make_shared<ServerVariable>("ServerNetworkGroups_Variable"))
    , serverUriArray_Variable_(boost::make_shared<ServerVariable>("ServerUriArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11945);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(serverNetworkGroups_Variable_);
        setServerVariable(serverUriArray_Variable_);
    }
    
    NonTransparentNetworkRedundancyType::NonTransparentNetworkRedundancyType(const NonTransparentNetworkRedundancyType& value)
    : ObjectBase()
    , redundancySupport_Variable_(boost::make_shared<ServerVariable>("RedundancySupport_Variable"))
    , serverNetworkGroups_Variable_(boost::make_shared<ServerVariable>("ServerNetworkGroups_Variable"))
    , serverUriArray_Variable_(boost::make_shared<ServerVariable>("ServerUriArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11945);
        setServerVariable(redundancySupport_Variable_);
        setServerVariable(serverNetworkGroups_Variable_);
        setServerVariable(serverUriArray_Variable_);
    }
    
    NonTransparentNetworkRedundancyType::~NonTransparentNetworkRedundancyType(void)
    {
    }

    ServerVariable::SPtr&
    NonTransparentNetworkRedundancyType::redundancySupport_Variable(void)
    {
        return redundancySupport_Variable_;
    }

    ServerVariable::SPtr&
    NonTransparentNetworkRedundancyType::serverNetworkGroups_Variable(void)
    {
        return serverNetworkGroups_Variable_;
    }

    ServerVariable::SPtr&
    NonTransparentNetworkRedundancyType::serverUriArray_Variable(void)
    {
        return serverUriArray_Variable_;
    }

    void
    NonTransparentNetworkRedundancyType::redundancySupport_Variable(ServerVariable::SPtr& serverVariable)
    {
        redundancySupport_Variable_ = serverVariable;
    }

    void
    NonTransparentNetworkRedundancyType::serverNetworkGroups_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverNetworkGroups_Variable_ = serverVariable;
    }

    void
    NonTransparentNetworkRedundancyType::serverUriArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverUriArray_Variable_ = serverVariable;
    }

    bool
    NonTransparentNetworkRedundancyType::get_RedundancySupport_Variable(OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->getDataValue(dataValue);
    }

    bool
    NonTransparentNetworkRedundancyType::get_ServerNetworkGroups_Variable(OpcUaDataValue& dataValue)
    {
        return serverNetworkGroups_Variable_->getDataValue(dataValue);
    }

    bool
    NonTransparentNetworkRedundancyType::get_ServerUriArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverUriArray_Variable_->getDataValue(dataValue);
    }

    bool
    NonTransparentNetworkRedundancyType::set_RedundancySupport_Variable(const OpcUaDataValue& dataValue)
    {
        return redundancySupport_Variable_->setDataValue(dataValue);
    }

    bool
    NonTransparentNetworkRedundancyType::set_ServerNetworkGroups_Variable(const OpcUaDataValue& dataValue)
    {
        return serverNetworkGroups_Variable_->setDataValue(dataValue);
    }

    bool
    NonTransparentNetworkRedundancyType::set_ServerUriArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverUriArray_Variable_->setDataValue(dataValue);
    }

}
