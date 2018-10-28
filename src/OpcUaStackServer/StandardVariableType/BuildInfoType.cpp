/*
    VariableTypeClass: BuildInfoType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/BuildInfoType.h"

namespace OpcUaStackServer
{
    
    BuildInfoType::BuildInfoType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , productUri_(constructSPtr<ServerVariable>("ProductUri"))
    , manufacturerName_(constructSPtr<ServerVariable>("ManufacturerName"))
    , productName_(constructSPtr<ServerVariable>("ProductName"))
    , softwareVersion_(constructSPtr<ServerVariable>("SoftwareVersion"))
    , buildNumber_(constructSPtr<ServerVariable>("BuildNumber"))
    , buildDate_(constructSPtr<ServerVariable>("BuildDate"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(3051));
        serverVariables().registerServerVariable(productUri_);
        serverVariables().registerServerVariable(manufacturerName_);
        serverVariables().registerServerVariable(productName_);
        serverVariables().registerServerVariable(softwareVersion_);
        serverVariables().registerServerVariable(buildNumber_);
        serverVariables().registerServerVariable(buildDate_);
    }
    
    BuildInfoType::~BuildInfoType(void)
    {
    }
    
    bool
    BuildInfoType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        productUri_->addBrowsePath(nodeId, OpcUaQualifiedName("ProductUri", namespaceIndex_));
        manufacturerName_->addBrowsePath(nodeId, OpcUaQualifiedName("ManufacturerName", namespaceIndex_));
        productName_->addBrowsePath(nodeId, OpcUaQualifiedName("ProductName", namespaceIndex_));
        softwareVersion_->addBrowsePath(nodeId, OpcUaQualifiedName("SoftwareVersion", namespaceIndex_));
        buildNumber_->addBrowsePath(nodeId, OpcUaQualifiedName("BuildNumber", namespaceIndex_));
        buildDate_->addBrowsePath(nodeId, OpcUaQualifiedName("BuildDate", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::productUri(void)
    {
        return productUri_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setProductUri(const OpcUaDataValue& dataValue)
    {
        return productUri_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getProductUri(OpcUaDataValue& dataValue)
    {
        return productUri_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackProductUri(Callback::SPtr& callback)
    {
        productUri_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::manufacturerName(void)
    {
        return manufacturerName_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setManufacturerName(const OpcUaDataValue& dataValue)
    {
        return manufacturerName_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getManufacturerName(OpcUaDataValue& dataValue)
    {
        return manufacturerName_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackManufacturerName(Callback::SPtr& callback)
    {
        manufacturerName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::productName(void)
    {
        return productName_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setProductName(const OpcUaDataValue& dataValue)
    {
        return productName_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getProductName(OpcUaDataValue& dataValue)
    {
        return productName_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackProductName(Callback::SPtr& callback)
    {
        productName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::softwareVersion(void)
    {
        return softwareVersion_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setSoftwareVersion(const OpcUaDataValue& dataValue)
    {
        return softwareVersion_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getSoftwareVersion(OpcUaDataValue& dataValue)
    {
        return softwareVersion_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackSoftwareVersion(Callback::SPtr& callback)
    {
        softwareVersion_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::buildNumber(void)
    {
        return buildNumber_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setBuildNumber(const OpcUaDataValue& dataValue)
    {
        return buildNumber_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getBuildNumber(OpcUaDataValue& dataValue)
    {
        return buildNumber_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackBuildNumber(Callback::SPtr& callback)
    {
        buildNumber_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    BuildInfoType::buildDate(void)
    {
        return buildDate_->baseNode().lock();
    }
    
    bool
    BuildInfoType::setBuildDate(const OpcUaDataValue& dataValue)
    {
        return buildDate_->setDataValue(dataValue);
    }
    
    bool
    BuildInfoType::getBuildDate(OpcUaDataValue& dataValue)
    {
        return buildDate_->getDataValue(dataValue);
    }
    
    void
    BuildInfoType::setUpdateCallbackBuildDate(Callback::SPtr& callback)
    {
        buildDate_->callback(callback);
    }

}
