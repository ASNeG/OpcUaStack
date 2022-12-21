/*
    VariableTypeClass: PubSubGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/PubSubGroupType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    PubSubGroupType::PubSubGroupType(void)
    : ObjectBase()
    , groupProperties_Variable_(boost::make_shared<ServerVariable>("GroupProperties_Variable"))
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14232);
        setServerVariable(groupProperties_Variable_);
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
    }
    
    PubSubGroupType::PubSubGroupType(const PubSubGroupType& value)
    : ObjectBase()
    , groupProperties_Variable_(boost::make_shared<ServerVariable>("GroupProperties_Variable"))
    , maxNetworkMessageSize_Variable_(boost::make_shared<ServerVariable>("MaxNetworkMessageSize_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityKeyServices_Variable_(boost::make_shared<ServerVariable>("SecurityKeyServices_Variable"))
    , securityMode_Variable_(boost::make_shared<ServerVariable>("SecurityMode_Variable"))
    , status_State_Variable_(boost::make_shared<ServerVariable>("Status_State_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14232);
        setServerVariable(groupProperties_Variable_);
        setServerVariable(maxNetworkMessageSize_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityKeyServices_Variable_);
        setServerVariable(securityMode_Variable_);
        setServerVariable(status_State_Variable_);
    }
    
    PubSubGroupType::~PubSubGroupType(void)
    {
    }

    ServerVariable::SPtr&
    PubSubGroupType::groupProperties_Variable(void)
    {
        return groupProperties_Variable_;
    }

    ServerVariable::SPtr&
    PubSubGroupType::maxNetworkMessageSize_Variable(void)
    {
        return maxNetworkMessageSize_Variable_;
    }

    ServerVariable::SPtr&
    PubSubGroupType::securityGroupId_Variable(void)
    {
        return securityGroupId_Variable_;
    }

    ServerVariable::SPtr&
    PubSubGroupType::securityKeyServices_Variable(void)
    {
        return securityKeyServices_Variable_;
    }

    ServerVariable::SPtr&
    PubSubGroupType::securityMode_Variable(void)
    {
        return securityMode_Variable_;
    }

    ServerVariable::SPtr&
    PubSubGroupType::status_State_Variable(void)
    {
        return status_State_Variable_;
    }

    void
    PubSubGroupType::groupProperties_Variable(ServerVariable::SPtr& serverVariable)
    {
        groupProperties_Variable_ = serverVariable;
    }

    void
    PubSubGroupType::maxNetworkMessageSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNetworkMessageSize_Variable_ = serverVariable;
    }

    void
    PubSubGroupType::securityGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityGroupId_Variable_ = serverVariable;
    }

    void
    PubSubGroupType::securityKeyServices_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityKeyServices_Variable_ = serverVariable;
    }

    void
    PubSubGroupType::securityMode_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityMode_Variable_ = serverVariable;
    }

    void
    PubSubGroupType::status_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_State_Variable_ = serverVariable;
    }

    bool
    PubSubGroupType::get_GroupProperties_Variable(OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::get_MaxNetworkMessageSize_Variable(OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::get_SecurityGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::get_SecurityKeyServices_Variable(OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::get_SecurityMode_Variable(OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::get_Status_State_Variable(OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->getDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_GroupProperties_Variable(const OpcUaDataValue& dataValue)
    {
        return groupProperties_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_MaxNetworkMessageSize_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNetworkMessageSize_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_SecurityKeyServices_Variable(const OpcUaDataValue& dataValue)
    {
        return securityKeyServices_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_SecurityMode_Variable(const OpcUaDataValue& dataValue)
    {
        return securityMode_Variable_->setDataValue(dataValue);
    }

    bool
    PubSubGroupType::set_Status_State_Variable(const OpcUaDataValue& dataValue)
    {
        return status_State_Variable_->setDataValue(dataValue);
    }

}
