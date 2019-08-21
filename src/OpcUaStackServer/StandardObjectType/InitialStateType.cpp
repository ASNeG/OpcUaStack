/*
    VariableTypeClass: InitialStateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/InitialStateType.h"

namespace OpcUaStackServer
{
    
    InitialStateType::InitialStateType(void)
    : ObjectBase()
    , stateNumber_Variable_(boost::make_shared<ServerVariable>("StateNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2309);
        setServerVariable(stateNumber_Variable_);
    }
    
    InitialStateType::InitialStateType(const InitialStateType& value)
    : ObjectBase()
    , stateNumber_Variable_(boost::make_shared<ServerVariable>("StateNumber_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2309);
        setServerVariable(stateNumber_Variable_);
    }
    
    InitialStateType::~InitialStateType(void)
    {
    }

    ServerVariable::SPtr&
    InitialStateType::stateNumber_Variable(void)
    {
        return stateNumber_Variable_;
    }

    void
    InitialStateType::stateNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        stateNumber_Variable_ = serverVariable;
    }

    bool
    InitialStateType::get_StateNumber_Variable(OpcUaDataValue& dataValue)
    {
        return stateNumber_Variable_->getDataValue(dataValue);
    }

    bool
    InitialStateType::set_StateNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return stateNumber_Variable_->setDataValue(dataValue);
    }

}
