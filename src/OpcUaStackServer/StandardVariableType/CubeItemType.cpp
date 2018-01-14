/*
    VariableTypeClass: CubeItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/CubeItemType.h"

namespace OpcUaStackServer
{
    
    CubeItemType::CubeItemType(void)
    : ArrayItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , xAxisDefinition_(constructSPtr<ServerVariable>("XAxisDefinition"))
    , yAxisDefinition_(constructSPtr<ServerVariable>("YAxisDefinition"))
    , zAxisDefinition_(constructSPtr<ServerVariable>("ZAxisDefinition"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12057));
        serverVariables().registerServerVariable(xAxisDefinition_);
        serverVariables().registerServerVariable(yAxisDefinition_);
        serverVariables().registerServerVariable(zAxisDefinition_);
    }
    
    CubeItemType::~CubeItemType(void)
    {
    }
    
    bool
    CubeItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        xAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("XAxisDefinition", namespaceIndex_));
        yAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("YAxisDefinition", namespaceIndex_));
        zAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("ZAxisDefinition", namespaceIndex_));
        ArrayItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    CubeItemType::xAxisDefinition(void)
    {
        return xAxisDefinition_->baseNode().lock();
    }
    
    bool
    CubeItemType::setXAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    CubeItemType::getXAxisDefinition(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    CubeItemType::setUpdateCallbackXAxisDefinition(Callback::SPtr& callback)
    {
        xAxisDefinition_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    CubeItemType::yAxisDefinition(void)
    {
        return yAxisDefinition_->baseNode().lock();
    }
    
    bool
    CubeItemType::setYAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    CubeItemType::getYAxisDefinition(OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    CubeItemType::setUpdateCallbackYAxisDefinition(Callback::SPtr& callback)
    {
        yAxisDefinition_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    CubeItemType::zAxisDefinition(void)
    {
        return zAxisDefinition_->baseNode().lock();
    }
    
    bool
    CubeItemType::setZAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return zAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    CubeItemType::getZAxisDefinition(OpcUaDataValue& dataValue)
    {
        return zAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    CubeItemType::setUpdateCallbackZAxisDefinition(Callback::SPtr& callback)
    {
        zAxisDefinition_->callback(callback);
    }

}
