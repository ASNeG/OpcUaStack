/*
    VariableTypeClass: TwoStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TwoStateVariableType.h"

namespace OpcUaStackServer
{
    
    TwoStateVariableType::TwoStateVariableType(void)
    : VariableBase()
    , effectiveDisplayName_Variable_(constructSPtr<ServerVariable>("EffectiveDisplayName_Variable"))
    , effectiveTransitionTime_Variable_(constructSPtr<ServerVariable>("EffectiveTransitionTime_Variable"))
    , falseState_Variable_(constructSPtr<ServerVariable>("FalseState_Variable"))
    , id_Variable_(constructSPtr<ServerVariable>("Id_Variable"))
    , name_Variable_(constructSPtr<ServerVariable>("Name_Variable"))
    , number_Variable_(constructSPtr<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(constructSPtr<ServerVariable>("TransitionTime_Variable"))
    , trueState_Variable_(constructSPtr<ServerVariable>("TrueState_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)8995);
        setServerVariable(effectiveDisplayName_Variable_);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(falseState_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(trueState_Variable_);
        setServerVariable(variable_);
    }
    
    TwoStateVariableType::TwoStateVariableType(const TwoStateVariableType& value)
    : VariableBase()
    , effectiveDisplayName_Variable_(constructSPtr<ServerVariable>("EffectiveDisplayName_Variable"))
    , effectiveTransitionTime_Variable_(constructSPtr<ServerVariable>("EffectiveTransitionTime_Variable"))
    , falseState_Variable_(constructSPtr<ServerVariable>("FalseState_Variable"))
    , id_Variable_(constructSPtr<ServerVariable>("Id_Variable"))
    , name_Variable_(constructSPtr<ServerVariable>("Name_Variable"))
    , number_Variable_(constructSPtr<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(constructSPtr<ServerVariable>("TransitionTime_Variable"))
    , trueState_Variable_(constructSPtr<ServerVariable>("TrueState_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)8995);
        setServerVariable(effectiveDisplayName_Variable_);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(falseState_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(trueState_Variable_);
        setServerVariable(variable_);
    }
    
    TwoStateVariableType::~TwoStateVariableType(void)
    {
    }

    ServerVariable::SPtr&
    TwoStateVariableType::effectiveDisplayName_Variable(void)
    {
        return effectiveDisplayName_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::effectiveTransitionTime_Variable(void)
    {
        return effectiveTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::falseState_Variable(void)
    {
        return falseState_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::id_Variable(void)
    {
        return id_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::name_Variable(void)
    {
        return name_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::number_Variable(void)
    {
        return number_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::transitionTime_Variable(void)
    {
        return transitionTime_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::trueState_Variable(void)
    {
        return trueState_Variable_;
    }

    ServerVariable::SPtr&
    TwoStateVariableType::variable(void)
    {
        return variable_;
    }

    void
    TwoStateVariableType::effectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable)
    {
        effectiveDisplayName_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::effectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        effectiveTransitionTime_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::falseState_Variable(ServerVariable::SPtr& serverVariable)
    {
        falseState_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::id_Variable(ServerVariable::SPtr& serverVariable)
    {
        id_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::name_Variable(ServerVariable::SPtr& serverVariable)
    {
        name_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::number_Variable(ServerVariable::SPtr& serverVariable)
    {
        number_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::transitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        transitionTime_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::trueState_Variable(ServerVariable::SPtr& serverVariable)
    {
        trueState_Variable_ = serverVariable;
    }

    void
    TwoStateVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    TwoStateVariableType::get_EffectiveDisplayName_Variable(OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_FalseState_Variable(OpcUaDataValue& dataValue)
    {
        return falseState_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_Id_Variable(OpcUaDataValue& dataValue)
    {
        return id_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_Name_Variable(OpcUaDataValue& dataValue)
    {
        return name_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_Number_Variable(OpcUaDataValue& dataValue)
    {
        return number_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_TrueState_Variable(OpcUaDataValue& dataValue)
    {
        return trueState_Variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_EffectiveDisplayName_Variable(const OpcUaDataValue& dataValue)
    {
        return effectiveDisplayName_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_FalseState_Variable(const OpcUaDataValue& dataValue)
    {
        return falseState_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return id_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_Name_Variable(const OpcUaDataValue& dataValue)
    {
        return name_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return number_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_TrueState_Variable(const OpcUaDataValue& dataValue)
    {
        return trueState_Variable_->setDataValue(dataValue);
    }

    bool
    TwoStateVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
