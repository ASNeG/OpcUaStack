/*
    VariableTypeClass: YArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/YArrayItemType.h"

namespace OpcUaStackServer
{
    
    YArrayItemType::YArrayItemType(void)
    : VariableBase()
    , axisScaleType_Variable_(constructSPtr<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(constructSPtr<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    , xAxisDefinition_Variable_(constructSPtr<ServerVariable>("XAxisDefinition_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12029);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
        setServerVariable(xAxisDefinition_Variable_);
    }
    
    YArrayItemType::YArrayItemType(const YArrayItemType& value)
    : VariableBase()
    , axisScaleType_Variable_(constructSPtr<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(constructSPtr<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    , xAxisDefinition_Variable_(constructSPtr<ServerVariable>("XAxisDefinition_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12029);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
        setServerVariable(xAxisDefinition_Variable_);
    }
    
    YArrayItemType::~YArrayItemType(void)
    {
    }

    ServerVariable::SPtr&
    YArrayItemType::axisScaleType_Variable(void)
    {
        return axisScaleType_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::eURange_Variable(void)
    {
        return eURange_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::engineeringUnits_Variable(void)
    {
        return engineeringUnits_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::instrumentRange_Variable(void)
    {
        return instrumentRange_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::title_Variable(void)
    {
        return title_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::variable(void)
    {
        return variable_;
    }

    ServerVariable::SPtr&
    YArrayItemType::xAxisDefinition_Variable(void)
    {
        return xAxisDefinition_Variable_;
    }

    void
    YArrayItemType::axisScaleType_Variable(ServerVariable::SPtr& serverVariable)
    {
        axisScaleType_Variable_ = serverVariable;
    }

    void
    YArrayItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    YArrayItemType::eURange_Variable(ServerVariable::SPtr& serverVariable)
    {
        eURange_Variable_ = serverVariable;
    }

    void
    YArrayItemType::engineeringUnits_Variable(ServerVariable::SPtr& serverVariable)
    {
        engineeringUnits_Variable_ = serverVariable;
    }

    void
    YArrayItemType::instrumentRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        instrumentRange_Variable_ = serverVariable;
    }

    void
    YArrayItemType::title_Variable(ServerVariable::SPtr& serverVariable)
    {
        title_Variable_ = serverVariable;
    }

    void
    YArrayItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    YArrayItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    void
    YArrayItemType::xAxisDefinition_Variable(ServerVariable::SPtr& serverVariable)
    {
        xAxisDefinition_Variable_ = serverVariable;
    }

    bool
    YArrayItemType::get_AxisScaleType_Variable(OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_EURange_Variable(OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_EngineeringUnits_Variable(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_InstrumentRange_Variable(OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_Title_Variable(OpcUaDataValue& dataValue)
    {
        return title_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::get_XAxisDefinition_Variable(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->getDataValue(dataValue);
    }

    bool
    YArrayItemType::set_AxisScaleType_Variable(const OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_EURange_Variable(const OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_InstrumentRange_Variable(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_Title_Variable(const OpcUaDataValue& dataValue)
    {
        return title_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

    bool
    YArrayItemType::set_XAxisDefinition_Variable(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->setDataValue(dataValue);
    }

}
