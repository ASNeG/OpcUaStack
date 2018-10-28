/*
    VariableTypeClass: NDimensionArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/NDimensionArrayItemType.h"

namespace OpcUaStackServer
{
    
    NDimensionArrayItemType::NDimensionArrayItemType(void)
    : ArrayItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , axisDefinition_(constructSPtr<ServerVariable>("AxisDefinition"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12068));
        serverVariables().registerServerVariable(axisDefinition_);
    }
    
    NDimensionArrayItemType::~NDimensionArrayItemType(void)
    {
    }
    
    bool
    NDimensionArrayItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        axisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("AxisDefinition", namespaceIndex_));
        ArrayItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    NDimensionArrayItemType::axisDefinition(void)
    {
        return axisDefinition_->baseNode().lock();
    }
    
    bool
    NDimensionArrayItemType::setAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return axisDefinition_->setDataValue(dataValue);
    }
    
    bool
    NDimensionArrayItemType::getAxisDefinition(OpcUaDataValue& dataValue)
    {
        return axisDefinition_->getDataValue(dataValue);
    }
    
    void
    NDimensionArrayItemType::setUpdateCallbackAxisDefinition(Callback::SPtr& callback)
    {
        axisDefinition_->callback(callback);
    }

}
