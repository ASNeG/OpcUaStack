/*
    VariableTypeClass: ServerStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerStatusType.h"

namespace OpcUaStackServer
{
    
    ServerStatusType::ServerStatusType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , startTime_(constructSPtr<ServerVariable>("StartTime"))
    , currentTime_(constructSPtr<ServerVariable>("CurrentTime"))
    , state_(constructSPtr<ServerVariable>("State"))
    , buildInfo_(constructSPtr<ServerVariable>("BuildInfo"))
    , buildInfo_ProductUri_(constructSPtr<ServerVariable>("ProductUri"))
    , buildInfo_ManufacturerName_(constructSPtr<ServerVariable>("ManufacturerName"))
    , buildInfo_ProductName_(constructSPtr<ServerVariable>("ProductName"))
    , buildInfo_SoftwareVersion_(constructSPtr<ServerVariable>("SoftwareVersion"))
    , buildInfo_BuildNumber_(constructSPtr<ServerVariable>("BuildNumber"))
    , buildInfo_BuildDate_(constructSPtr<ServerVariable>("BuildDate"))
    , secondsTillShutdown_(constructSPtr<ServerVariable>("SecondsTillShutdown"))
    , shutdownReason_(constructSPtr<ServerVariable>("ShutdownReason"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2138));
        serverVariables().registerServerVariable(startTime_);
        serverVariables().registerServerVariable(currentTime_);
        serverVariables().registerServerVariable(state_);
        serverVariables().registerServerVariable(buildInfo_);
        serverVariables().registerServerVariable(buildInfo_ProductUri_);
        serverVariables().registerServerVariable(buildInfo_ManufacturerName_);
        serverVariables().registerServerVariable(buildInfo_ProductName_);
        serverVariables().registerServerVariable(buildInfo_SoftwareVersion_);
        serverVariables().registerServerVariable(buildInfo_BuildNumber_);
        serverVariables().registerServerVariable(buildInfo_BuildDate_);
        serverVariables().registerServerVariable(secondsTillShutdown_);
        serverVariables().registerServerVariable(shutdownReason_);
    }
    
    ServerStatusType::~ServerStatusType(void)
    {
    }
    
    bool
    ServerStatusType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        startTime_->addBrowsePath(nodeId, OpcUaQualifiedName("StartTime", namespaceIndex_));
        currentTime_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentTime", namespaceIndex_));
        state_->addBrowsePath(nodeId, OpcUaQualifiedName("State", namespaceIndex_));
        buildInfo_->addBrowsePath(nodeId, OpcUaQualifiedName("BuildInfo", namespaceIndex_));
        buildInfo_ProductUri_->addBrowsePath(nodeId, OpcUaQualifiedName("ProductUri", namespaceIndex_));
        buildInfo_ManufacturerName_->addBrowsePath(nodeId, OpcUaQualifiedName("ManufacturerName", namespaceIndex_));
        buildInfo_ProductName_->addBrowsePath(nodeId, OpcUaQualifiedName("ProductName", namespaceIndex_));
        buildInfo_SoftwareVersion_->addBrowsePath(nodeId, OpcUaQualifiedName("SoftwareVersion", namespaceIndex_));
        buildInfo_BuildNumber_->addBrowsePath(nodeId, OpcUaQualifiedName("BuildNumber", namespaceIndex_));
        buildInfo_BuildDate_->addBrowsePath(nodeId, OpcUaQualifiedName("BuildDate", namespaceIndex_));
        secondsTillShutdown_->addBrowsePath(nodeId, OpcUaQualifiedName("SecondsTillShutdown", namespaceIndex_));
        shutdownReason_->addBrowsePath(nodeId, OpcUaQualifiedName("ShutdownReason", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::startTime(void)
    {
        return startTime_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setStartTime(const OpcUaDataValue& dataValue)
    {
        return startTime_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getStartTime(OpcUaDataValue& dataValue)
    {
        return startTime_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackStartTime(Callback::SPtr& callback)
    {
        startTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::currentTime(void)
    {
        return currentTime_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setCurrentTime(const OpcUaDataValue& dataValue)
    {
        return currentTime_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getCurrentTime(OpcUaDataValue& dataValue)
    {
        return currentTime_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackCurrentTime(Callback::SPtr& callback)
    {
        currentTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::state(void)
    {
        return state_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setState(const OpcUaDataValue& dataValue)
    {
        return state_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getState(OpcUaDataValue& dataValue)
    {
        return state_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackState(Callback::SPtr& callback)
    {
        state_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo(void)
    {
        return buildInfo_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setBuildInfo(const OpcUaDataValue& dataValue)
    {
        return buildInfo_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getBuildInfo(OpcUaDataValue& dataValue)
    {
        return buildInfo_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackBuildInfo(Callback::SPtr& callback)
    {
        buildInfo_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_ProductUri(void)
    {
        return buildInfo_ProductUri_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setProductUri(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductUri_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getProductUri(OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductUri_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackProductUri(Callback::SPtr& callback)
    {
        buildInfo_ProductUri_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_ManufacturerName(void)
    {
        return buildInfo_ManufacturerName_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setManufacturerName(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ManufacturerName_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getManufacturerName(OpcUaDataValue& dataValue)
    {
        return buildInfo_ManufacturerName_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackManufacturerName(Callback::SPtr& callback)
    {
        buildInfo_ManufacturerName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_ProductName(void)
    {
        return buildInfo_ProductName_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setProductName(const OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductName_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getProductName(OpcUaDataValue& dataValue)
    {
        return buildInfo_ProductName_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackProductName(Callback::SPtr& callback)
    {
        buildInfo_ProductName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_SoftwareVersion(void)
    {
        return buildInfo_SoftwareVersion_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setSoftwareVersion(const OpcUaDataValue& dataValue)
    {
        return buildInfo_SoftwareVersion_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getSoftwareVersion(OpcUaDataValue& dataValue)
    {
        return buildInfo_SoftwareVersion_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackSoftwareVersion(Callback::SPtr& callback)
    {
        buildInfo_SoftwareVersion_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_BuildNumber(void)
    {
        return buildInfo_BuildNumber_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setBuildNumber(const OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildNumber_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getBuildNumber(OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildNumber_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackBuildNumber(Callback::SPtr& callback)
    {
        buildInfo_BuildNumber_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::buildInfo_BuildDate(void)
    {
        return buildInfo_BuildDate_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setBuildDate(const OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildDate_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getBuildDate(OpcUaDataValue& dataValue)
    {
        return buildInfo_BuildDate_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackBuildDate(Callback::SPtr& callback)
    {
        buildInfo_BuildDate_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::secondsTillShutdown(void)
    {
        return secondsTillShutdown_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setSecondsTillShutdown(const OpcUaDataValue& dataValue)
    {
        return secondsTillShutdown_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getSecondsTillShutdown(OpcUaDataValue& dataValue)
    {
        return secondsTillShutdown_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackSecondsTillShutdown(Callback::SPtr& callback)
    {
        secondsTillShutdown_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerStatusType::shutdownReason(void)
    {
        return shutdownReason_->baseNode().lock();
    }
    
    bool
    ServerStatusType::setShutdownReason(const OpcUaDataValue& dataValue)
    {
        return shutdownReason_->setDataValue(dataValue);
    }
    
    bool
    ServerStatusType::getShutdownReason(OpcUaDataValue& dataValue)
    {
        return shutdownReason_->getDataValue(dataValue);
    }
    
    void
    ServerStatusType::setUpdateCallbackShutdownReason(Callback::SPtr& callback)
    {
        shutdownReason_->callback(callback);
    }

}
