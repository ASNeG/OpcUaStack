/*
    VariableTypeClass: HistoricalDataConfigurationType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/HistoricalDataConfigurationType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    HistoricalDataConfigurationType::HistoricalDataConfigurationType(void)
    : ObjectBase()
    , aggregateConfiguration_PercentDataBad_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_PercentDataBad_Variable"))
    , aggregateConfiguration_PercentDataGood_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_PercentDataGood_Variable"))
    , aggregateConfiguration_TreatUncertainAsBad_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_TreatUncertainAsBad_Variable"))
    , aggregateConfiguration_UseSlopedExtrapolation_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_UseSlopedExtrapolation_Variable"))
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , exceptionDeviationFormat_Variable_(boost::make_shared<ServerVariable>("ExceptionDeviationFormat_Variable"))
    , exceptionDeviation_Variable_(boost::make_shared<ServerVariable>("ExceptionDeviation_Variable"))
    , maxTimeInterval_Variable_(boost::make_shared<ServerVariable>("MaxTimeInterval_Variable"))
    , minTimeInterval_Variable_(boost::make_shared<ServerVariable>("MinTimeInterval_Variable"))
    , startOfArchive_Variable_(boost::make_shared<ServerVariable>("StartOfArchive_Variable"))
    , startOfOnlineArchive_Variable_(boost::make_shared<ServerVariable>("StartOfOnlineArchive_Variable"))
    , stepped_Variable_(boost::make_shared<ServerVariable>("Stepped_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2318);
        setServerVariable(aggregateConfiguration_PercentDataBad_Variable_);
        setServerVariable(aggregateConfiguration_PercentDataGood_Variable_);
        setServerVariable(aggregateConfiguration_TreatUncertainAsBad_Variable_);
        setServerVariable(aggregateConfiguration_UseSlopedExtrapolation_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(exceptionDeviationFormat_Variable_);
        setServerVariable(exceptionDeviation_Variable_);
        setServerVariable(maxTimeInterval_Variable_);
        setServerVariable(minTimeInterval_Variable_);
        setServerVariable(startOfArchive_Variable_);
        setServerVariable(startOfOnlineArchive_Variable_);
        setServerVariable(stepped_Variable_);
    }
    
    HistoricalDataConfigurationType::HistoricalDataConfigurationType(const HistoricalDataConfigurationType& value)
    : ObjectBase()
    , aggregateConfiguration_PercentDataBad_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_PercentDataBad_Variable"))
    , aggregateConfiguration_PercentDataGood_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_PercentDataGood_Variable"))
    , aggregateConfiguration_TreatUncertainAsBad_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_TreatUncertainAsBad_Variable"))
    , aggregateConfiguration_UseSlopedExtrapolation_Variable_(boost::make_shared<ServerVariable>("AggregateConfiguration_UseSlopedExtrapolation_Variable"))
    , definition_Variable_(boost::make_shared<ServerVariable>("Definition_Variable"))
    , exceptionDeviationFormat_Variable_(boost::make_shared<ServerVariable>("ExceptionDeviationFormat_Variable"))
    , exceptionDeviation_Variable_(boost::make_shared<ServerVariable>("ExceptionDeviation_Variable"))
    , maxTimeInterval_Variable_(boost::make_shared<ServerVariable>("MaxTimeInterval_Variable"))
    , minTimeInterval_Variable_(boost::make_shared<ServerVariable>("MinTimeInterval_Variable"))
    , startOfArchive_Variable_(boost::make_shared<ServerVariable>("StartOfArchive_Variable"))
    , startOfOnlineArchive_Variable_(boost::make_shared<ServerVariable>("StartOfOnlineArchive_Variable"))
    , stepped_Variable_(boost::make_shared<ServerVariable>("Stepped_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2318);
        setServerVariable(aggregateConfiguration_PercentDataBad_Variable_);
        setServerVariable(aggregateConfiguration_PercentDataGood_Variable_);
        setServerVariable(aggregateConfiguration_TreatUncertainAsBad_Variable_);
        setServerVariable(aggregateConfiguration_UseSlopedExtrapolation_Variable_);
        setServerVariable(definition_Variable_);
        setServerVariable(exceptionDeviationFormat_Variable_);
        setServerVariable(exceptionDeviation_Variable_);
        setServerVariable(maxTimeInterval_Variable_);
        setServerVariable(minTimeInterval_Variable_);
        setServerVariable(startOfArchive_Variable_);
        setServerVariable(startOfOnlineArchive_Variable_);
        setServerVariable(stepped_Variable_);
    }
    
    HistoricalDataConfigurationType::~HistoricalDataConfigurationType(void)
    {
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::aggregateConfiguration_PercentDataBad_Variable(void)
    {
        return aggregateConfiguration_PercentDataBad_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::aggregateConfiguration_PercentDataGood_Variable(void)
    {
        return aggregateConfiguration_PercentDataGood_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::aggregateConfiguration_TreatUncertainAsBad_Variable(void)
    {
        return aggregateConfiguration_TreatUncertainAsBad_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::aggregateConfiguration_UseSlopedExtrapolation_Variable(void)
    {
        return aggregateConfiguration_UseSlopedExtrapolation_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::definition_Variable(void)
    {
        return definition_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::exceptionDeviationFormat_Variable(void)
    {
        return exceptionDeviationFormat_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::exceptionDeviation_Variable(void)
    {
        return exceptionDeviation_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::maxTimeInterval_Variable(void)
    {
        return maxTimeInterval_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::minTimeInterval_Variable(void)
    {
        return minTimeInterval_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::startOfArchive_Variable(void)
    {
        return startOfArchive_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::startOfOnlineArchive_Variable(void)
    {
        return startOfOnlineArchive_Variable_;
    }

    ServerVariable::SPtr&
    HistoricalDataConfigurationType::stepped_Variable(void)
    {
        return stepped_Variable_;
    }

    void
    HistoricalDataConfigurationType::aggregateConfiguration_PercentDataBad_Variable(ServerVariable::SPtr& serverVariable)
    {
        aggregateConfiguration_PercentDataBad_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::aggregateConfiguration_PercentDataGood_Variable(ServerVariable::SPtr& serverVariable)
    {
        aggregateConfiguration_PercentDataGood_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::aggregateConfiguration_TreatUncertainAsBad_Variable(ServerVariable::SPtr& serverVariable)
    {
        aggregateConfiguration_TreatUncertainAsBad_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::aggregateConfiguration_UseSlopedExtrapolation_Variable(ServerVariable::SPtr& serverVariable)
    {
        aggregateConfiguration_UseSlopedExtrapolation_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::definition_Variable(ServerVariable::SPtr& serverVariable)
    {
        definition_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::exceptionDeviationFormat_Variable(ServerVariable::SPtr& serverVariable)
    {
        exceptionDeviationFormat_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::exceptionDeviation_Variable(ServerVariable::SPtr& serverVariable)
    {
        exceptionDeviation_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::maxTimeInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxTimeInterval_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::minTimeInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        minTimeInterval_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::startOfArchive_Variable(ServerVariable::SPtr& serverVariable)
    {
        startOfArchive_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::startOfOnlineArchive_Variable(ServerVariable::SPtr& serverVariable)
    {
        startOfOnlineArchive_Variable_ = serverVariable;
    }

    void
    HistoricalDataConfigurationType::stepped_Variable(ServerVariable::SPtr& serverVariable)
    {
        stepped_Variable_ = serverVariable;
    }

    bool
    HistoricalDataConfigurationType::get_AggregateConfiguration_PercentDataBad_Variable(OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_PercentDataBad_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_AggregateConfiguration_PercentDataGood_Variable(OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_PercentDataGood_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_AggregateConfiguration_TreatUncertainAsBad_Variable(OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_TreatUncertainAsBad_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_AggregateConfiguration_UseSlopedExtrapolation_Variable(OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_UseSlopedExtrapolation_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_Definition_Variable(OpcUaDataValue& dataValue)
    {
        return definition_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_ExceptionDeviationFormat_Variable(OpcUaDataValue& dataValue)
    {
        return exceptionDeviationFormat_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_ExceptionDeviation_Variable(OpcUaDataValue& dataValue)
    {
        return exceptionDeviation_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_MaxTimeInterval_Variable(OpcUaDataValue& dataValue)
    {
        return maxTimeInterval_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_MinTimeInterval_Variable(OpcUaDataValue& dataValue)
    {
        return minTimeInterval_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_StartOfArchive_Variable(OpcUaDataValue& dataValue)
    {
        return startOfArchive_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_StartOfOnlineArchive_Variable(OpcUaDataValue& dataValue)
    {
        return startOfOnlineArchive_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::get_Stepped_Variable(OpcUaDataValue& dataValue)
    {
        return stepped_Variable_->getDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_AggregateConfiguration_PercentDataBad_Variable(const OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_PercentDataBad_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_AggregateConfiguration_PercentDataGood_Variable(const OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_PercentDataGood_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_AggregateConfiguration_TreatUncertainAsBad_Variable(const OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_TreatUncertainAsBad_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_AggregateConfiguration_UseSlopedExtrapolation_Variable(const OpcUaDataValue& dataValue)
    {
        return aggregateConfiguration_UseSlopedExtrapolation_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_Definition_Variable(const OpcUaDataValue& dataValue)
    {
        return definition_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_ExceptionDeviationFormat_Variable(const OpcUaDataValue& dataValue)
    {
        return exceptionDeviationFormat_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_ExceptionDeviation_Variable(const OpcUaDataValue& dataValue)
    {
        return exceptionDeviation_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_MaxTimeInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return maxTimeInterval_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_MinTimeInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return minTimeInterval_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_StartOfArchive_Variable(const OpcUaDataValue& dataValue)
    {
        return startOfArchive_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_StartOfOnlineArchive_Variable(const OpcUaDataValue& dataValue)
    {
        return startOfOnlineArchive_Variable_->setDataValue(dataValue);
    }

    bool
    HistoricalDataConfigurationType::set_Stepped_Variable(const OpcUaDataValue& dataValue)
    {
        return stepped_Variable_->setDataValue(dataValue);
    }

}
