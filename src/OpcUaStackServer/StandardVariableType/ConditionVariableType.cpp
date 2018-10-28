/*
    VariableTypeClass: ConditionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ConditionVariableType.h"

namespace OpcUaStackServer
{
    
    ConditionVariableType::ConditionVariableType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , sourceTimestamp_(constructSPtr<ServerVariable>("SourceTimestamp"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(9002));
        serverVariables().registerServerVariable(sourceTimestamp_);
    }
    
    ConditionVariableType::~ConditionVariableType(void)
    {
    }
    
    bool
    ConditionVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        sourceTimestamp_->addBrowsePath(nodeId, OpcUaQualifiedName("SourceTimestamp", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ConditionVariableType::sourceTimestamp(void)
    {
        return sourceTimestamp_->baseNode().lock();
    }
    
    bool
    ConditionVariableType::setSourceTimestamp(const OpcUaDataValue& dataValue)
    {
        return sourceTimestamp_->setDataValue(dataValue);
    }
    
    bool
    ConditionVariableType::getSourceTimestamp(OpcUaDataValue& dataValue)
    {
        return sourceTimestamp_->getDataValue(dataValue);
    }
    
    void
    ConditionVariableType::setUpdateCallbackSourceTimestamp(Callback::SPtr& callback)
    {
        sourceTimestamp_->callback(callback);
    }

}
