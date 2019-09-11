/*
    VariableTypeClass: FiniteTransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/FiniteTransitionVariableType.h"

namespace OpcUaStackServer
{
    
    FiniteTransitionVariableType::FiniteTransitionVariableType(void)
    : VariableBase()
    , effectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EffectiveTransitionTime_Variable"))
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , name_Variable_(boost::make_shared<ServerVariable>("Name_Variable"))
    , number_Variable_(boost::make_shared<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(boost::make_shared<ServerVariable>("TransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2767);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    FiniteTransitionVariableType::FiniteTransitionVariableType(const FiniteTransitionVariableType& value)
    : VariableBase()
    , effectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EffectiveTransitionTime_Variable"))
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , name_Variable_(boost::make_shared<ServerVariable>("Name_Variable"))
    , number_Variable_(boost::make_shared<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(boost::make_shared<ServerVariable>("TransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2767);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    FiniteTransitionVariableType::~FiniteTransitionVariableType(void)
    {
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::effectiveTransitionTime_Variable(void)
    {
        return effectiveTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::id_Variable(void)
    {
        return id_Variable_;
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::name_Variable(void)
    {
        return name_Variable_;
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::number_Variable(void)
    {
        return number_Variable_;
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::transitionTime_Variable(void)
    {
        return transitionTime_Variable_;
    }

    ServerVariable::SPtr&
    FiniteTransitionVariableType::variable(void)
    {
        return variable_;
    }

    void
    FiniteTransitionVariableType::effectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        effectiveTransitionTime_Variable_ = serverVariable;
    }

    void
    FiniteTransitionVariableType::id_Variable(ServerVariable::SPtr& serverVariable)
    {
        id_Variable_ = serverVariable;
    }

    void
    FiniteTransitionVariableType::name_Variable(ServerVariable::SPtr& serverVariable)
    {
        name_Variable_ = serverVariable;
    }

    void
    FiniteTransitionVariableType::number_Variable(ServerVariable::SPtr& serverVariable)
    {
        number_Variable_ = serverVariable;
    }

    void
    FiniteTransitionVariableType::transitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        transitionTime_Variable_ = serverVariable;
    }

    void
    FiniteTransitionVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    FiniteTransitionVariableType::get_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::get_Id_Variable(OpcUaDataValue& dataValue)
    {
        return id_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::get_Name_Variable(OpcUaDataValue& dataValue)
    {
        return name_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::get_Number_Variable(OpcUaDataValue& dataValue)
    {
        return number_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::get_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return id_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_Name_Variable(const OpcUaDataValue& dataValue)
    {
        return name_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return number_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    FiniteTransitionVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
