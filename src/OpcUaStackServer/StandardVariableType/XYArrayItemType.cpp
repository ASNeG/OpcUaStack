/*
    VariableTypeClass: XYArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/XYArrayItemType.h"

namespace OpcUaStackServer
{
    
    XYArrayItemType::XYArrayItemType(void)
    : ArrayItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , xAxisDefinition_(constructSPtr<ServerVariable>("XAxisDefinition"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(12038));
        serverVariables().registerServerVariable(xAxisDefinition_);
    }
    
    XYArrayItemType::~XYArrayItemType(void)
    {
    }
    
    bool
    XYArrayItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        xAxisDefinition_->addBrowsePath(nodeId, OpcUaQualifiedName("XAxisDefinition", namespaceIndex_));
        ArrayItemType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    XYArrayItemType::xAxisDefinition(void)
    {
        return xAxisDefinition_->baseNode().lock();
    }
    
    bool
    XYArrayItemType::setXAxisDefinition(const OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->setDataValue(dataValue);
    }
    
    bool
    XYArrayItemType::getXAxisDefinition(OpcUaDataValue& dataValue)
    {
        return xAxisDefinition_->getDataValue(dataValue);
    }
    
    void
    XYArrayItemType::setUpdateCallbackXAxisDefinition(Callback::SPtr& callback)
    {
        xAxisDefinition_->callback(callback);
    }

}
