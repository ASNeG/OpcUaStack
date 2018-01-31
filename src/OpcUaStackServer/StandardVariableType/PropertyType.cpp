/*
    VariableTypeClass: PropertyType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/PropertyType.h"

namespace OpcUaStackServer
{
    
    PropertyType::PropertyType(void)
    : BaseVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(68));
    }
    
    PropertyType::~PropertyType(void)
    {
    }
    
    bool
    PropertyType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        BaseVariableType::linkInstanceWithModel(nodeId);
    }

}
