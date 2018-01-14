/*
    VariableTypeClass: ImageItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ImageItemType.h"

namespace OpcUaStackServer
{
    
    ImageItemType::ImageItemType(void)
    : ArrayItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , xAxisDefinition_(constructSPtr<ServerVariable>("XAxisDefinition"))
    , yAxisDefinition_(constructSPtr<ServerVariable>("YAxisDefinition"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12047));
        serverVariables().registerServerVariable(xAxisDefinition_);
        serverVariables().registerServerVariable(yAxisDefinition_);
    }
    
    ImageItemType::~ImageItemType(void)
    {
    }
    
    bool
    ImageItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        xAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("XAxisDefinition", namespaceIndex_));
        yAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("YAxisDefinition", namespaceIndex_));
        ArrayItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ImageItemType::xAxisDefinition(void)
    {
        return xAxisDefinition_->baseNode().lock();
    }
    
    bool
    ImageItemType::setXAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    ImageItemType::getXAxisDefinition(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    ImageItemType::setUpdateCallbackXAxisDefinition(Callback::SPtr& callback)
    {
        xAxisDefinition_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ImageItemType::yAxisDefinition(void)
    {
        return yAxisDefinition_->baseNode().lock();
    }
    
    bool
    ImageItemType::setYAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    ImageItemType::getYAxisDefinition(OpcUaDataValue& dataValue)
    {
        return yAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    ImageItemType::setUpdateCallbackYAxisDefinition(Callback::SPtr& callback)
    {
        yAxisDefinition_->callback(callback);
    }

}
