/*
    VariableTypeClass: StateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/StateType.h"

namespace OpcUaStackServer
{
    
    StateType::StateType(void)
    : ObjectBase()
    , stateNumber_Variable_(boost::make_shared<ServerVariable>("StateNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2307);
        setServerVariable(stateNumber_Variable_);
    }
    
    StateType::StateType(const StateType& value)
    : ObjectBase()
    , stateNumber_Variable_(boost::make_shared<ServerVariable>("StateNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2307);
        setServerVariable(stateNumber_Variable_);
    }
    
    StateType::~StateType(void)
    {
    }

    ServerVariable::SPtr&
    StateType::stateNumber_Variable(void)
    {
        return stateNumber_Variable_;
    }

    void
    StateType::stateNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        stateNumber_Variable_ = serverVariable;
    }

    bool
    StateType::get_StateNumber_Variable(OpcUaDataValue& dataValue)
    {
        return stateNumber_Variable_->getDataValue(dataValue);
    }

    bool
    StateType::set_StateNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return stateNumber_Variable_->setDataValue(dataValue);
    }

}
