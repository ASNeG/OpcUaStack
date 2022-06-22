/*
    VariableTypeClass: ImageItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ImageItemType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ImageItemType::ImageItemType(void)
    : VariableBase()
    , axisScaleType_Variable_(boost::make_shared<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(boost::make_shared<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(boost::make_shared<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(boost::make_shared<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(boost::make_shared<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    , xAxisDefinition_Variable_(boost::make_shared<ServerVariable>("XAxisDefinition_Variable"))
    , yAxisDefinition_Variable_(boost::make_shared<ServerVariable>("YAxisDefinition_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12047);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
        setServerVariable(xAxisDefinition_Variable_);
        setServerVariable(yAxisDefinition_Variable_);
    }
    
    ImageItemType::ImageItemType(const ImageItemType& value)
    : VariableBase()
    , axisScaleType_Variable_(boost::make_shared<ServerVariable>("AxisScaleType_Variable"))
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(boost::make_shared<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(boost::make_shared<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(boost::make_shared<ServerVariable>("InstrumentRange_Variable"))
    , title_Variable_(boost::make_shared<ServerVariable>("Title_Variable"))
    , valuePrecision_Variable_(boost::make_shared<ServerVariable>("ValuePrecision_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    , xAxisDefinition_Variable_(boost::make_shared<ServerVariable>("XAxisDefinition_Variable"))
    , yAxisDefinition_Variable_(boost::make_shared<ServerVariable>("YAxisDefinition_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)12047);
        setServerVariable(axisScaleType_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(eURange_Variable_);
        setServerVariable(engineeringUnits_Variable_);
        setServerVariable(instrumentRange_Variable_);
        setServerVariable(title_Variable_);
        setServerVariable(valuePrecision_Variable_);
        setServerVariable(variable_);
        setServerVariable(xAxisDefinition_Variable_);
        setServerVariable(yAxisDefinition_Variable_);
    }
    
    ImageItemType::~ImageItemType(void)
    {
    }

    ServerVariable::SPtr&
    ImageItemType::axisScaleType_Variable(void)
    {
        return axisScaleType_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::eURange_Variable(void)
    {
        return eURange_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::engineeringUnits_Variable(void)
    {
        return engineeringUnits_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::instrumentRange_Variable(void)
    {
        return instrumentRange_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::title_Variable(void)
    {
        return title_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::valuePrecision_Variable(void)
    {
        return valuePrecision_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::variable(void)
    {
        return variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::xAxisDefinition_Variable(void)
    {
        return xAxisDefinition_Variable_;
    }

    ServerVariable::SPtr&
    ImageItemType::yAxisDefinition_Variable(void)
    {
        return yAxisDefinition_Variable_;
    }

    void
    ImageItemType::axisScaleType_Variable(ServerVariable::SPtr& serverVariable)
    {
        axisScaleType_Variable_ = serverVariable;
    }

    void
    ImageItemType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    ImageItemType::eURange_Variable(ServerVariable::SPtr& serverVariable)
    {
        eURange_Variable_ = serverVariable;
    }

    void
    ImageItemType::engineeringUnits_Variable(ServerVariable::SPtr& serverVariable)
    {
        engineeringUnits_Variable_ = serverVariable;
    }

    void
    ImageItemType::instrumentRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        instrumentRange_Variable_ = serverVariable;
    }

    void
    ImageItemType::title_Variable(ServerVariable::SPtr& serverVariable)
    {
        title_Variable_ = serverVariable;
    }

    void
    ImageItemType::valuePrecision_Variable(ServerVariable::SPtr& serverVariable)
    {
        valuePrecision_Variable_ = serverVariable;
    }

    void
    ImageItemType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    void
    ImageItemType::xAxisDefinition_Variable(ServerVariable::SPtr& serverVariable)
    {
        xAxisDefinition_Variable_ = serverVariable;
    }

    void
    ImageItemType::yAxisDefinition_Variable(ServerVariable::SPtr& serverVariable)
    {
        yAxisDefinition_Variable_ = serverVariable;
    }

    bool
    ImageItemType::get_AxisScaleType_Variable(OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_EURange_Variable(OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_EngineeringUnits_Variable(OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_InstrumentRange_Variable(OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_Title_Variable(OpcUaDataValue& dataValue)
    {
        return title_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_ValuePrecision_Variable(OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_XAxisDefinition_Variable(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::get_YAxisDefinition_Variable(OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_Variable_->getDataValue(dataValue);
    }

    bool
    ImageItemType::set_AxisScaleType_Variable(const OpcUaDataValue& dataValue)
    {
        return axisScaleType_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_EURange_Variable(const OpcUaDataValue& dataValue)
    {
        return eURange_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue)
    {
        return engineeringUnits_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_InstrumentRange_Variable(const OpcUaDataValue& dataValue)
    {
        return instrumentRange_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_Title_Variable(const OpcUaDataValue& dataValue)
    {
        return title_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_ValuePrecision_Variable(const OpcUaDataValue& dataValue)
    {
        return valuePrecision_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_XAxisDefinition_Variable(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_Variable_->setDataValue(dataValue);
    }

    bool
    ImageItemType::set_YAxisDefinition_Variable(const OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_Variable_->setDataValue(dataValue);
    }

}
