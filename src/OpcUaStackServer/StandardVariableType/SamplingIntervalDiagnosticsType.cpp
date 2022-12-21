/*
    VariableTypeClass: SamplingIntervalDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SamplingIntervalDiagnosticsType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SamplingIntervalDiagnosticsType::SamplingIntervalDiagnosticsType(void)
    : VariableBase()
    , disabledMonitoredItemsSamplingCount_Variable_(boost::make_shared<ServerVariable>("DisabledMonitoredItemsSamplingCount_Variable"))
    , maxSampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("MaxSampledMonitoredItemsCount_Variable"))
    , sampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SampledMonitoredItemsCount_Variable"))
    , samplingInterval_Variable_(boost::make_shared<ServerVariable>("SamplingInterval_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2165);
        setServerVariable(disabledMonitoredItemsSamplingCount_Variable_);
        setServerVariable(maxSampledMonitoredItemsCount_Variable_);
        setServerVariable(sampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingInterval_Variable_);
        setServerVariable(variable_);
    }
    
    SamplingIntervalDiagnosticsType::SamplingIntervalDiagnosticsType(const SamplingIntervalDiagnosticsType& value)
    : VariableBase()
    , disabledMonitoredItemsSamplingCount_Variable_(boost::make_shared<ServerVariable>("DisabledMonitoredItemsSamplingCount_Variable"))
    , maxSampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("MaxSampledMonitoredItemsCount_Variable"))
    , sampledMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SampledMonitoredItemsCount_Variable"))
    , samplingInterval_Variable_(boost::make_shared<ServerVariable>("SamplingInterval_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2165);
        setServerVariable(disabledMonitoredItemsSamplingCount_Variable_);
        setServerVariable(maxSampledMonitoredItemsCount_Variable_);
        setServerVariable(sampledMonitoredItemsCount_Variable_);
        setServerVariable(samplingInterval_Variable_);
        setServerVariable(variable_);
    }
    
    SamplingIntervalDiagnosticsType::~SamplingIntervalDiagnosticsType(void)
    {
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsType::disabledMonitoredItemsSamplingCount_Variable(void)
    {
        return disabledMonitoredItemsSamplingCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsType::maxSampledMonitoredItemsCount_Variable(void)
    {
        return maxSampledMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsType::sampledMonitoredItemsCount_Variable(void)
    {
        return sampledMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsType::samplingInterval_Variable(void)
    {
        return samplingInterval_Variable_;
    }

    ServerVariable::SPtr&
    SamplingIntervalDiagnosticsType::variable(void)
    {
        return variable_;
    }

    void
    SamplingIntervalDiagnosticsType::disabledMonitoredItemsSamplingCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        disabledMonitoredItemsSamplingCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsType::maxSampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxSampledMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsType::sampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sampledMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsType::samplingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingInterval_Variable_ = serverVariable;
    }

    void
    SamplingIntervalDiagnosticsType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SamplingIntervalDiagnosticsType::get_DisabledMonitoredItemsSamplingCount_Variable(OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemsSamplingCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::get_MaxSampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return maxSampledMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::get_SampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sampledMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::get_SamplingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return samplingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::set_DisabledMonitoredItemsSamplingCount_Variable(const OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemsSamplingCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::set_MaxSampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maxSampledMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::set_SampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sampledMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::set_SamplingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    SamplingIntervalDiagnosticsType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
