/*
    VariableTypeClass: StateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/StateVariableType.h"

namespace OpcUaStackServer
{
    
    StateVariableType::StateVariableType(void)
    : VariableBase()
    , effectiveDisplayName_Variable_(constructSPtr<ServerVariable>("EffectiveDisplayName_Variable"))
    , id_Variable_(constructSPtr<ServerVariable>("Id_Variable"))
    , name_Variable_(constructSPtr<ServerVariable>("Name_Variable"))
    , number_Variable_(constructSPtr<ServerVariable>("Number_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2755);
        setServerVariable(effectiveDisplayName_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(variable_);
    }
    
    StateVariableType::StateVariableType(const StateVariableType& value)
    : VariableBase()
    , effectiveDisplayName_Variable_(constructSPtr<ServerVariable>("EffectiveDisplayName_Variable"))
    , id_Variable_(constructSPtr<ServerVariable>("Id_Variable"))
    , name_Variable_(constructSPtr<ServerVariable>("Name_Variable"))
    , number_Variable_(constructSPtr<ServerVariable>("Number_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2755);
        setServerVariable(effectiveDisplayName_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(variable_);
    }
    
    StateVariableType::~StateVariableType(void)
    {
    }

    ServerVariable::SPtr&
    StateVariableType::effectiveDisplayName_Variable(void)
    {
        return effectiveDisplayName_Variable_;
    }

    ServerVariable::SPtr&
    StateVariableType::id_Variable(void)
    {
        return id_Variable_;
    }

    ServerVariable::SPtr&
    StateVariableType::name_Variable(void)
    {
        return name_Variable_;
    }

    ServerVariable::SPtr&
    StateVariableType::number_Variable(void)
    {
        return number_Variable_;
    }

    ServerVariable::SPtr&
    StateVariableType::variable(void)
    {
        return variable_;
    }

    void
    StateVariableType::effectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable)
    {
        effectiveDisplayName_Variable_ = serverVariable;
    }

    void
    StateVariableType::id_Variable(ServerVariable::SPtr& serverVariable)
    {
        id_Variable_ = serverVariable;
    }

    void
    StateVariableType::name_Variable(ServerVariable::SPtr& serverVariable)
    {
        name_Variable_ = serverVariable;
    }

    void
    StateVariableType::number_Variable(ServerVariable::SPtr& serverVariable)
    {
        number_Variable_ = serverVariable;
    }

    void
    StateVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    StateVariableType::get_EffectiveDisplayName_Variable(OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_Variable_->getDataValue(dataValue);
    }

    bool
    StateVariableType::get_Id_Variable(OpcUaDataValue& dataValue)
    {
        return id_Variable_->getDataValue(dataValue);
    }

    bool
    StateVariableType::get_Name_Variable(OpcUaDataValue& dataValue)
    {
        return name_Variable_->getDataValue(dataValue);
    }

    bool
    StateVariableType::get_Number_Variable(OpcUaDataValue& dataValue)
    {
        return number_Variable_->getDataValue(dataValue);
    }

    bool
    StateVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    StateVariableType::set_EffectiveDisplayName_Variable(const OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_Variable_->setDataValue(dataValue);
    }

    bool
    StateVariableType::set_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return id_Variable_->setDataValue(dataValue);
    }

    bool
    StateVariableType::set_Name_Variable(const OpcUaDataValue& dataValue)
    {
        return name_Variable_->setDataValue(dataValue);
    }

    bool
    StateVariableType::set_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return number_Variable_->setDataValue(dataValue);
    }

    bool
    StateVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
