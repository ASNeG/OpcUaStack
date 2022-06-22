/*
    VariableTypeClass: TransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/TransitionVariableType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TransitionVariableType::TransitionVariableType(void)
    : VariableBase()
    , effectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EffectiveTransitionTime_Variable"))
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , name_Variable_(boost::make_shared<ServerVariable>("Name_Variable"))
    , number_Variable_(boost::make_shared<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(boost::make_shared<ServerVariable>("TransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2762);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    TransitionVariableType::TransitionVariableType(const TransitionVariableType& value)
    : VariableBase()
    , effectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EffectiveTransitionTime_Variable"))
    , id_Variable_(boost::make_shared<ServerVariable>("Id_Variable"))
    , name_Variable_(boost::make_shared<ServerVariable>("Name_Variable"))
    , number_Variable_(boost::make_shared<ServerVariable>("Number_Variable"))
    , transitionTime_Variable_(boost::make_shared<ServerVariable>("TransitionTime_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2762);
        setServerVariable(effectiveTransitionTime_Variable_);
        setServerVariable(id_Variable_);
        setServerVariable(name_Variable_);
        setServerVariable(number_Variable_);
        setServerVariable(transitionTime_Variable_);
        setServerVariable(variable_);
    }
    
    TransitionVariableType::~TransitionVariableType(void)
    {
    }

    ServerVariable::SPtr&
    TransitionVariableType::effectiveTransitionTime_Variable(void)
    {
        return effectiveTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    TransitionVariableType::id_Variable(void)
    {
        return id_Variable_;
    }

    ServerVariable::SPtr&
    TransitionVariableType::name_Variable(void)
    {
        return name_Variable_;
    }

    ServerVariable::SPtr&
    TransitionVariableType::number_Variable(void)
    {
        return number_Variable_;
    }

    ServerVariable::SPtr&
    TransitionVariableType::transitionTime_Variable(void)
    {
        return transitionTime_Variable_;
    }

    ServerVariable::SPtr&
    TransitionVariableType::variable(void)
    {
        return variable_;
    }

    void
    TransitionVariableType::effectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        effectiveTransitionTime_Variable_ = serverVariable;
    }

    void
    TransitionVariableType::id_Variable(ServerVariable::SPtr& serverVariable)
    {
        id_Variable_ = serverVariable;
    }

    void
    TransitionVariableType::name_Variable(ServerVariable::SPtr& serverVariable)
    {
        name_Variable_ = serverVariable;
    }

    void
    TransitionVariableType::number_Variable(ServerVariable::SPtr& serverVariable)
    {
        number_Variable_ = serverVariable;
    }

    void
    TransitionVariableType::transitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        transitionTime_Variable_ = serverVariable;
    }

    void
    TransitionVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    TransitionVariableType::get_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::get_Id_Variable(OpcUaDataValue& dataValue)
    {
        return id_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::get_Name_Variable(OpcUaDataValue& dataValue)
    {
        return name_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::get_Number_Variable(OpcUaDataValue& dataValue)
    {
        return number_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::get_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return effectiveTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return id_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_Name_Variable(const OpcUaDataValue& dataValue)
    {
        return name_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_Number_Variable(const OpcUaDataValue& dataValue)
    {
        return number_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return transitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    TransitionVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
