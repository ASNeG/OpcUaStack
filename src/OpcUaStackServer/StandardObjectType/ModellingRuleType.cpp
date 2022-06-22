/*
    VariableTypeClass: ModellingRuleType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ModellingRuleType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * The type for an object that describes how an instance declaration is used when a type is instantiated.
     */
    ModellingRuleType::ModellingRuleType(void)
    : ObjectBase()
    , namingRule_Variable_(boost::make_shared<ServerVariable>("NamingRule_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)77);
        setServerVariable(namingRule_Variable_);
    }
    
    /**
     * The type for an object that describes how an instance declaration is used when a type is instantiated.
     */
    ModellingRuleType::ModellingRuleType(const ModellingRuleType& value)
    : ObjectBase()
    , namingRule_Variable_(boost::make_shared<ServerVariable>("NamingRule_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)77);
        setServerVariable(namingRule_Variable_);
    }
    
    ModellingRuleType::~ModellingRuleType(void)
    {
    }

    ServerVariable::SPtr&
    ModellingRuleType::namingRule_Variable(void)
    {
        return namingRule_Variable_;
    }

    void
    ModellingRuleType::namingRule_Variable(ServerVariable::SPtr& serverVariable)
    {
        namingRule_Variable_ = serverVariable;
    }

    bool
    ModellingRuleType::get_NamingRule_Variable(OpcUaDataValue& dataValue)
    {
        return namingRule_Variable_->getDataValue(dataValue);
    }

    bool
    ModellingRuleType::set_NamingRule_Variable(const OpcUaDataValue& dataValue)
    {
        return namingRule_Variable_->setDataValue(dataValue);
    }

}
