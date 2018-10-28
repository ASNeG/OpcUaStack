/*
    VariableTypeClass: SamplingIntervalDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SamplingIntervalDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    SamplingIntervalDiagnosticsType::SamplingIntervalDiagnosticsType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , samplingInterval_(constructSPtr<ServerVariable>("SamplingInterval"))
    , sampledMonitoredItemsCount_(constructSPtr<ServerVariable>("SampledMonitoredItemsCount"))
    , maxSampledMonitoredItemsCount_(constructSPtr<ServerVariable>("MaxSampledMonitoredItemsCount"))
    , disabledMonitoredItemsSamplingCount_(constructSPtr<ServerVariable>("DisabledMonitoredItemsSamplingCount"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2165));
        serverVariables().registerServerVariable(samplingInterval_);
        serverVariables().registerServerVariable(sampledMonitoredItemsCount_);
        serverVariables().registerServerVariable(maxSampledMonitoredItemsCount_);
        serverVariables().registerServerVariable(disabledMonitoredItemsSamplingCount_);
    }
    
    SamplingIntervalDiagnosticsType::~SamplingIntervalDiagnosticsType(void)
    {
    }
    
    bool
    SamplingIntervalDiagnosticsType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        samplingInterval_->addBrowsePath(nodeId, OpcUaQualifiedName("SamplingInterval", namespaceIndex_));
        sampledMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SampledMonitoredItemsCount", namespaceIndex_));
        maxSampledMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("MaxSampledMonitoredItemsCount", namespaceIndex_));
        disabledMonitoredItemsSamplingCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DisabledMonitoredItemsSamplingCount", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    SamplingIntervalDiagnosticsType::samplingInterval(void)
    {
        return samplingInterval_->baseNode().lock();
    }
    
    bool
    SamplingIntervalDiagnosticsType::setSamplingInterval(const OpcUaDataValue& dataValue)
    {
        return samplingInterval_->setDataValue(dataValue);
    }
    
    bool
    SamplingIntervalDiagnosticsType::getSamplingInterval(OpcUaDataValue& dataValue)
    {
        return samplingInterval_->getDataValue(dataValue);
    }
    
    void
    SamplingIntervalDiagnosticsType::setUpdateCallbackSamplingInterval(Callback::SPtr& callback)
    {
        samplingInterval_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SamplingIntervalDiagnosticsType::sampledMonitoredItemsCount(void)
    {
        return sampledMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SamplingIntervalDiagnosticsType::setSampledMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return sampledMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SamplingIntervalDiagnosticsType::getSampledMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return sampledMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SamplingIntervalDiagnosticsType::setUpdateCallbackSampledMonitoredItemsCount(Callback::SPtr& callback)
    {
        sampledMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SamplingIntervalDiagnosticsType::maxSampledMonitoredItemsCount(void)
    {
        return maxSampledMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SamplingIntervalDiagnosticsType::setMaxSampledMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return maxSampledMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SamplingIntervalDiagnosticsType::getMaxSampledMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return maxSampledMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SamplingIntervalDiagnosticsType::setUpdateCallbackMaxSampledMonitoredItemsCount(Callback::SPtr& callback)
    {
        maxSampledMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SamplingIntervalDiagnosticsType::disabledMonitoredItemsSamplingCount(void)
    {
        return disabledMonitoredItemsSamplingCount_->baseNode().lock();
    }
    
    bool
    SamplingIntervalDiagnosticsType::setDisabledMonitoredItemsSamplingCount(const OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemsSamplingCount_->setDataValue(dataValue);
    }
    
    bool
    SamplingIntervalDiagnosticsType::getDisabledMonitoredItemsSamplingCount(OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemsSamplingCount_->getDataValue(dataValue);
    }
    
    void
    SamplingIntervalDiagnosticsType::setUpdateCallbackDisabledMonitoredItemsSamplingCount(Callback::SPtr& callback)
    {
        disabledMonitoredItemsSamplingCount_->callback(callback);
    }

}
