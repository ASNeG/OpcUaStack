/*
    VariableTypeClass: SessionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SessionDiagnosticsArrayType::SessionDiagnosticsArrayType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2196));
    }
    
    SessionDiagnosticsArrayType::~SessionDiagnosticsArrayType(void)
    {
    }
    
    bool
    SessionDiagnosticsArrayType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }

}
