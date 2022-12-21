/*
    VariableTypeClass: SecurityGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SecurityGroupType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SecurityGroupType::SecurityGroupType(void)
    : ObjectBase()
    , keyLifetime_Variable_(boost::make_shared<ServerVariable>("KeyLifetime_Variable"))
    , maxFutureKeyCount_Variable_(boost::make_shared<ServerVariable>("MaxFutureKeyCount_Variable"))
    , maxPastKeyCount_Variable_(boost::make_shared<ServerVariable>("MaxPastKeyCount_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SecurityPolicyUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15471);
        setServerVariable(keyLifetime_Variable_);
        setServerVariable(maxFutureKeyCount_Variable_);
        setServerVariable(maxPastKeyCount_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
    }
    
    SecurityGroupType::SecurityGroupType(const SecurityGroupType& value)
    : ObjectBase()
    , keyLifetime_Variable_(boost::make_shared<ServerVariable>("KeyLifetime_Variable"))
    , maxFutureKeyCount_Variable_(boost::make_shared<ServerVariable>("MaxFutureKeyCount_Variable"))
    , maxPastKeyCount_Variable_(boost::make_shared<ServerVariable>("MaxPastKeyCount_Variable"))
    , securityGroupId_Variable_(boost::make_shared<ServerVariable>("SecurityGroupId_Variable"))
    , securityPolicyUri_Variable_(boost::make_shared<ServerVariable>("SecurityPolicyUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15471);
        setServerVariable(keyLifetime_Variable_);
        setServerVariable(maxFutureKeyCount_Variable_);
        setServerVariable(maxPastKeyCount_Variable_);
        setServerVariable(securityGroupId_Variable_);
        setServerVariable(securityPolicyUri_Variable_);
    }
    
    SecurityGroupType::~SecurityGroupType(void)
    {
    }

    ServerVariable::SPtr&
    SecurityGroupType::keyLifetime_Variable(void)
    {
        return keyLifetime_Variable_;
    }

    ServerVariable::SPtr&
    SecurityGroupType::maxFutureKeyCount_Variable(void)
    {
        return maxFutureKeyCount_Variable_;
    }

    ServerVariable::SPtr&
    SecurityGroupType::maxPastKeyCount_Variable(void)
    {
        return maxPastKeyCount_Variable_;
    }

    ServerVariable::SPtr&
    SecurityGroupType::securityGroupId_Variable(void)
    {
        return securityGroupId_Variable_;
    }

    ServerVariable::SPtr&
    SecurityGroupType::securityPolicyUri_Variable(void)
    {
        return securityPolicyUri_Variable_;
    }

    void
    SecurityGroupType::keyLifetime_Variable(ServerVariable::SPtr& serverVariable)
    {
        keyLifetime_Variable_ = serverVariable;
    }

    void
    SecurityGroupType::maxFutureKeyCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxFutureKeyCount_Variable_ = serverVariable;
    }

    void
    SecurityGroupType::maxPastKeyCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxPastKeyCount_Variable_ = serverVariable;
    }

    void
    SecurityGroupType::securityGroupId_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityGroupId_Variable_ = serverVariable;
    }

    void
    SecurityGroupType::securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityPolicyUri_Variable_ = serverVariable;
    }

    bool
    SecurityGroupType::get_KeyLifetime_Variable(OpcUaDataValue& dataValue)
    {
        return keyLifetime_Variable_->getDataValue(dataValue);
    }

    bool
    SecurityGroupType::get_MaxFutureKeyCount_Variable(OpcUaDataValue& dataValue)
    {
        return maxFutureKeyCount_Variable_->getDataValue(dataValue);
    }

    bool
    SecurityGroupType::get_MaxPastKeyCount_Variable(OpcUaDataValue& dataValue)
    {
        return maxPastKeyCount_Variable_->getDataValue(dataValue);
    }

    bool
    SecurityGroupType::get_SecurityGroupId_Variable(OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->getDataValue(dataValue);
    }

    bool
    SecurityGroupType::get_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->getDataValue(dataValue);
    }

    bool
    SecurityGroupType::set_KeyLifetime_Variable(const OpcUaDataValue& dataValue)
    {
        return keyLifetime_Variable_->setDataValue(dataValue);
    }

    bool
    SecurityGroupType::set_MaxFutureKeyCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maxFutureKeyCount_Variable_->setDataValue(dataValue);
    }

    bool
    SecurityGroupType::set_MaxPastKeyCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maxPastKeyCount_Variable_->setDataValue(dataValue);
    }

    bool
    SecurityGroupType::set_SecurityGroupId_Variable(const OpcUaDataValue& dataValue)
    {
        return securityGroupId_Variable_->setDataValue(dataValue);
    }

    bool
    SecurityGroupType::set_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue)
    {
        return securityPolicyUri_Variable_->setDataValue(dataValue);
    }

}
