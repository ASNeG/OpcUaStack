/*
    VariableTypeClass: AggregateConfigurationType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AggregateConfigurationType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AggregateConfigurationType::AggregateConfigurationType(void)
    : ObjectBase()
    , percentDataBad_Variable_(boost::make_shared<ServerVariable>("PercentDataBad_Variable"))
    , percentDataGood_Variable_(boost::make_shared<ServerVariable>("PercentDataGood_Variable"))
    , treatUncertainAsBad_Variable_(boost::make_shared<ServerVariable>("TreatUncertainAsBad_Variable"))
    , useSlopedExtrapolation_Variable_(boost::make_shared<ServerVariable>("UseSlopedExtrapolation_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11187);
        setServerVariable(percentDataBad_Variable_);
        setServerVariable(percentDataGood_Variable_);
        setServerVariable(treatUncertainAsBad_Variable_);
        setServerVariable(useSlopedExtrapolation_Variable_);
    }
    
    AggregateConfigurationType::AggregateConfigurationType(const AggregateConfigurationType& value)
    : ObjectBase()
    , percentDataBad_Variable_(boost::make_shared<ServerVariable>("PercentDataBad_Variable"))
    , percentDataGood_Variable_(boost::make_shared<ServerVariable>("PercentDataGood_Variable"))
    , treatUncertainAsBad_Variable_(boost::make_shared<ServerVariable>("TreatUncertainAsBad_Variable"))
    , useSlopedExtrapolation_Variable_(boost::make_shared<ServerVariable>("UseSlopedExtrapolation_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11187);
        setServerVariable(percentDataBad_Variable_);
        setServerVariable(percentDataGood_Variable_);
        setServerVariable(treatUncertainAsBad_Variable_);
        setServerVariable(useSlopedExtrapolation_Variable_);
    }
    
    AggregateConfigurationType::~AggregateConfigurationType(void)
    {
    }

    ServerVariable::SPtr&
    AggregateConfigurationType::percentDataBad_Variable(void)
    {
        return percentDataBad_Variable_;
    }

    ServerVariable::SPtr&
    AggregateConfigurationType::percentDataGood_Variable(void)
    {
        return percentDataGood_Variable_;
    }

    ServerVariable::SPtr&
    AggregateConfigurationType::treatUncertainAsBad_Variable(void)
    {
        return treatUncertainAsBad_Variable_;
    }

    ServerVariable::SPtr&
    AggregateConfigurationType::useSlopedExtrapolation_Variable(void)
    {
        return useSlopedExtrapolation_Variable_;
    }

    void
    AggregateConfigurationType::percentDataBad_Variable(ServerVariable::SPtr& serverVariable)
    {
        percentDataBad_Variable_ = serverVariable;
    }

    void
    AggregateConfigurationType::percentDataGood_Variable(ServerVariable::SPtr& serverVariable)
    {
        percentDataGood_Variable_ = serverVariable;
    }

    void
    AggregateConfigurationType::treatUncertainAsBad_Variable(ServerVariable::SPtr& serverVariable)
    {
        treatUncertainAsBad_Variable_ = serverVariable;
    }

    void
    AggregateConfigurationType::useSlopedExtrapolation_Variable(ServerVariable::SPtr& serverVariable)
    {
        useSlopedExtrapolation_Variable_ = serverVariable;
    }

    bool
    AggregateConfigurationType::get_PercentDataBad_Variable(OpcUaDataValue& dataValue)
    {
        return percentDataBad_Variable_->getDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::get_PercentDataGood_Variable(OpcUaDataValue& dataValue)
    {
        return percentDataGood_Variable_->getDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::get_TreatUncertainAsBad_Variable(OpcUaDataValue& dataValue)
    {
        return treatUncertainAsBad_Variable_->getDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::get_UseSlopedExtrapolation_Variable(OpcUaDataValue& dataValue)
    {
        return useSlopedExtrapolation_Variable_->getDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::set_PercentDataBad_Variable(const OpcUaDataValue& dataValue)
    {
        return percentDataBad_Variable_->setDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::set_PercentDataGood_Variable(const OpcUaDataValue& dataValue)
    {
        return percentDataGood_Variable_->setDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::set_TreatUncertainAsBad_Variable(const OpcUaDataValue& dataValue)
    {
        return treatUncertainAsBad_Variable_->setDataValue(dataValue);
    }

    bool
    AggregateConfigurationType::set_UseSlopedExtrapolation_Variable(const OpcUaDataValue& dataValue)
    {
        return useSlopedExtrapolation_Variable_->setDataValue(dataValue);
    }

}
