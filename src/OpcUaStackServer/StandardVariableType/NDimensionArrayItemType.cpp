/*
    VariableTypeClass: NDimensionArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/NDimensionArrayItemType.h"

namespace OpcUaStackServer
{
    
    NDimensionArrayItemType::NDimensionArrayItemType(void)
    : VariableBase()
    , axisDefinition_Variable_(constructSPtr<ServerVariable>("AxisDefinition_Variable"))
    , axisScaleType_Variable_(constructSPtr<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(constructSPtr<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12068);
        setServerVariable(axisDefinition_Variable_);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    NDimensionArrayItemType::NDimensionArrayItemType(const NDimensionArrayItemType& value)
    : VariableBase()
    , axisDefinition_Variable_(constructSPtr<ServerVariable>("AxisDefinition_Variable"))
    , axisScaleType_Variable_(constructSPtr<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(constructSPtr<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12068);
        setServerVariable(axisDefinition_Variable_);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
    }
    
    NDimensionArrayItemType::~NDimensionArrayItemType(void)
    {
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::axisDefinition_Variable(void)
    {
        return axisDefinition_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::axisScaleType_Variable(void)
    {
        return axisScaleType_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::eURange_Variable(void)
    {
        return eURange_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::engineeringUnits_Variable(void)
    {
        return engineeringUnits_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::instrumentRange_Variable(void)
    {
        return instrumentRange_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::title_Variable(void)
    {
        return title_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    NDimensionArrayItemType::variable(void)
    {
        return variable_;
    }

    void
    NDimensionArrayItemType::axisDefinition_Variable(ServerVariable::SPtr& serverVariable)
    {
        axisDefinition_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::axisScaleType_Variable(ServerVariable::SPtr& serverVariable)
    {
        axisScaleType_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::eURange_Variable(ServerVariable::SPtr& serverVariable)
    {
        eURange_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::engineeringUnits_Variable(ServerVariable::SPtr& serverVariable)
    {
        engineeringUnits_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::instrumentRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        instrumentRange_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::title_Variable(ServerVariable::SPtr& serverVariable)
    {
        title_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    NDimensionArrayItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    NDimensionArrayItemType::get_AxisDefinition_Variable(OpcUaDataValue& dataValue)
    {
        return axisDefinition_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_AxisScaleType_Variable(OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_EURange_Variable(OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_EngineeringUnits_Variable(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_InstrumentRange_Variable(OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_Title_Variable(OpcUaDataValue& dataValue)
    {
        return title_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_AxisDefinition_Variable(const OpcUaDataValue& dataValue)
    {
        return axisDefinition_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_AxisScaleType_Variable(const OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_EURange_Variable(const OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_InstrumentRange_Variable(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_Title_Variable(const OpcUaDataValue& dataValue)
    {
        return title_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    NDimensionArrayItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
