/*
    VariableTypeClass: YArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/YArrayItemType.h"

namespace OpcUaStackServer
{
    
    YArrayItemType::YArrayItemType(void)
    : ArrayItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , xAxisDefinition_(constructSPtr<ServerVariable>("XAxisDefinition"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12029));
        serverVariables().registerServerVariable(xAxisDefinition_);
    }
    
    YArrayItemType::~YArrayItemType(void)
    {
    }
    
    bool
    YArrayItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        xAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("XAxisDefinition", namespaceIndex_));
        ArrayItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    YArrayItemType::xAxisDefinition(void)
    {
        return xAxisDefinition_->baseNode().lock();
    }
    
    bool
    YArrayItemType::setXAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    YArrayItemType::getXAxisDefinition(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    YArrayItemType::setUpdateCallbackXAxisDefinition(Callback::SPtr& callback)
    {
        xAxisDefinition_->callback(callback);
    }

}
