/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SubscriptionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SubscriptionDiagnosticsArrayType::SubscriptionDiagnosticsArrayType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2171));
    }
    
    SubscriptionDiagnosticsArrayType::~SubscriptionDiagnosticsArrayType(void)
    {
    }
    
    bool
    SubscriptionDiagnosticsArrayType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }

}
