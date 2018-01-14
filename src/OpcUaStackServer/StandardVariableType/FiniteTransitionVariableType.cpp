/*
    VariableTypeClass: FiniteTransitionVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/FiniteTransitionVariableType.h"

namespace OpcUaStackServer
{
    
    FiniteTransitionVariableType::FiniteTransitionVariableType(void)
    : TransitionVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , id_(constructSPtr<ServerVariable>("Id"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2767));
        serverVariables().registerServerVariable(id_);
    }
    
    FiniteTransitionVariableType::~FiniteTransitionVariableType(void)
    {
    }
    
    bool
    FiniteTransitionVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        id_->addBrowsePath(nodeId, OpcUaQualifiedName("Id", namespaceIndex_));
        TransitionVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    FiniteTransitionVariableType::id(void)
    {
        return id_->baseNode().lock();
    }
    
    bool
    FiniteTransitionVariableType::setId(const OpcUaDataValue& dataValue)
    {
        return id_->setDataValue(dataValue);
    }
    
    bool
    FiniteTransitionVariableType::getId(OpcUaDataValue& dataValue)
    {
        return id_->getDataValue(dataValue);
    }
    
    void
    FiniteTransitionVariableType::setUpdateCallbackId(Callback::SPtr& callback)
    {
        id_->callback(callback);
    }

}
