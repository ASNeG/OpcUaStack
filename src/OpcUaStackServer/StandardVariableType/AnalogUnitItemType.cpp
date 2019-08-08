/*
    VariableTypeClass: AnalogUnitItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/AnalogUnitItemType.h"

namespace OpcUaStackServer
{
    
    AnalogUnitItemType::AnalogUnitItemType(void)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17503);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    AnalogUnitItemType::AnalogUnitItemType(const AnalogUnitItemType& value)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17503);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    AnalogUnitItemType::~AnalogUnitItemType(void)
    {
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::eURange_Variable(void)
    {
        return eURange_Variable_;
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::engineeringUnits_Variable(void)
    {
        return engineeringUnits_Variable_;
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::instrumentRange_Variable(void)
    {
        return instrumentRange_Variable_;
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    AnalogUnitItemType::variable(void)
    {
        return variable_;
    }

    void
    AnalogUnitItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    AnalogUnitItemType::eURange_Variable(ServerVariable::SPtr& serverVariable)
    {
        eURange_Variable_ = serverVariable;
    }

    void
    AnalogUnitItemType::engineeringUnits_Variable(ServerVariable::SPtr& serverVariable)
    {
        engineeringUnits_Variable_ = serverVariable;
    }

    void
    AnalogUnitItemType::instrumentRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        instrumentRange_Variable_ = serverVariable;
    }

    void
    AnalogUnitItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    AnalogUnitItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    AnalogUnitItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::get_EURange_Variable(OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::get_EngineeringUnits_Variable(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::get_InstrumentRange_Variable(OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_EURange_Variable(const OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->setDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->setDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_InstrumentRange_Variable(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->setDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    AnalogUnitItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
