/*
    VariableTypeClass: XYArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/XYArrayItemType.h"

namespace OpcUaStackServer
{
    
    XYArrayItemType::XYArrayItemType(void)
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
        variableTypeNodeId((OpcUaUInt32)12038);
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
    
    XYArrayItemType::XYArrayItemType(const XYArrayItemType& value)
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
        variableTypeNodeId((OpcUaUInt32)12038);
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
    
    XYArrayItemType::~XYArrayItemType(void)
    {
    }

    ServerVariable::SPtr&
    XYArrayItemType::axisScaleType_Variable(void)
    {
        return axisScaleType_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::eURange_Variable(void)
    {
        return eURange_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::engineeringUnits_Variable(void)
    {
        return engineeringUnits_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::instrumentRange_Variable(void)
    {
        return instrumentRange_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::title_Variable(void)
    {
        return title_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::variable(void)
    {
        return variable_;
    }

    ServerVariable::SPtr&
    XYArrayItemType::xAxisDefinition_Variable(void)
    {
        return xAxisDefinition_Variable_;
    }

    void
    XYArrayItemType::axisScaleType_Variable(ServerVariable::SPtr& serverVariable)
    {
        axisScaleType_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::eURange_Variable(ServerVariable::SPtr& serverVariable)
    {
        eURange_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::engineeringUnits_Variable(ServerVariable::SPtr& serverVariable)
    {
        engineeringUnits_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::instrumentRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        instrumentRange_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::title_Variable(ServerVariable::SPtr& serverVariable)
    {
        title_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    XYArrayItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    void
    XYArrayItemType::xAxisDefinition_Variable(ServerVariable::SPtr& serverVariable)
    {
        xAxisDefinition_Variable_ = serverVariable;
    }

    bool
    XYArrayItemType::get_AxisScaleType_Variable(OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_EURange_Variable(OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_EngineeringUnits_Variable(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_InstrumentRange_Variable(OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_Title_Variable(OpcUaDataValue& dataValue)
    {
        return title_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::get_XAxisDefinition_Variable(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->getDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_AxisScaleType_Variable(const OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_EURange_Variable(const OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_InstrumentRange_Variable(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_Title_Variable(const OpcUaDataValue& dataValue)
    {
        return title_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

    bool
    XYArrayItemType::set_XAxisDefinition_Variable(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->setDataValue(dataValue);
    }

}
