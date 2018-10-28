/*
    VariableTypeClass: ServerVendorCapabilityType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerVendorCapabilityType.h"

namespace OpcUaStackServer
{
    
    ServerVendorCapabilityType::ServerVendorCapabilityType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2137));
    }
    
    ServerVendorCapabilityType::~ServerVendorCapabilityType(void)
    {
    }
    
    bool
    ServerVendorCapabilityType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }

}
