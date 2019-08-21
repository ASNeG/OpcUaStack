/*
    VariableTypeClass: SamplingIntervalDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SamplingIntervalDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SamplingIntervalDiagnosticsArrayType::SamplingIntervalDiagnosticsArrayType(void)
    : VariableBase()
    , samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable"))
    , samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable"))
    , samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable"))
    , samplingIntervalDiagnostics_SamplingInterval_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_SamplingInterval_Variable"))
    , samplingIntervalDiagnostics_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2164);
        setServerVariable(samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_SamplingInterval_Variable_);
        setServerVariable(samplingIntervalDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SamplingIntervalDiagnosticsArrayType::SamplingIntervalDiagnosticsArrayType(const SamplingIntervalDiagnosticsArrayType& value)
    : VariableBase()
    , samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable"))
    , samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable"))
    , samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable"))
    , samplingIntervalDiagnostics_SamplingInterval_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_SamplingInterval_Variable"))
    , samplingIntervalDiagnostics_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnostics_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2164);
        setServerVariable(samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingIntervalDiagnostics_SamplingInterval_Variable_);
        setServerVariable(samplingIntervalDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SamplingIntervalDiagnosticsArrayType::~SamplingIntervalDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(void)
    {
        return samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(void)
    {
        return samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(void)
    {
        return samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_SamplingInterval_Variable(void)
    {
        return samplingIntervalDiagnostics_SamplingInterval_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_Variable(void)
    {
        return samplingIntervalDiagnostics_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_SamplingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnostics_SamplingInterval_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsArrayType::samplingIntervalDiagnostics_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnostics_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_SamplingIntervalDiagnostics_SamplingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_SamplingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_SamplingIntervalDiagnostics_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_SamplingIntervalDiagnostics_SamplingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_SamplingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_SamplingIntervalDiagnostics_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnostics_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
