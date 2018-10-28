/*
    VariableTypeClass: FiniteStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/FiniteStateVariableType.h"

namespace OpcUaStackServer
{
    
    FiniteStateVariableType::FiniteStateVariableType(void)
    : StateVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , id_(constructSPtr<ServerVariable>("Id"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2760));
        serverVariables().registerServerVariable(id_);
    }
    
    FiniteStateVariableType::~FiniteStateVariableType(void)
    {
    }
    
    bool
    FiniteStateVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        id_->addBrowsePath(nodeId, OpcUaQualifiedName("Id", namespaceIndex_));
        StateVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    FiniteStateVariableType::id(void)
    {
        return id_->baseNode().lock();
    }
    
    bool
    FiniteStateVariableType::setId(const OpcUaDataValue& dataValue)
    {
        return id_->setDataValue(dataValue);
    }
    
    bool
    FiniteStateVariableType::getId(OpcUaDataValue& dataValue)
    {
        return id_->getDataValue(dataValue);
    }
    
    void
    FiniteStateVariableType::setUpdateCallbackId(Callback::SPtr& callback)
    {
        id_->callback(callback);
    }

}
