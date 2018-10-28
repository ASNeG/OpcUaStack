/*
    VariableTypeClass: DiscreteItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/DiscreteItemType.h"

namespace OpcUaStackServer
{
    
    DiscreteItemType::DiscreteItemType(void)
    : DataItemType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2372));
    }
    
    DiscreteItemType::~DiscreteItemType(void)
    {
    }
    
    bool
    DiscreteItemType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        DataItemType::linkInstanceWithModel(nodeId);
    }

}
