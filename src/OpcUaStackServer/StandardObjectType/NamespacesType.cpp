/*
    VariableTypeClass: NamespacesType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NamespacesType.h"

namespace OpcUaStackServer
{
    
    /**
     * A container for the namespace metadata provided by the server.
     */
    NamespacesType::NamespacesType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11645);
    }
    
    /**
     * A container for the namespace metadata provided by the server.
     */
    NamespacesType::NamespacesType(const NamespacesType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11645);
    }
    
    NamespacesType::~NamespacesType(void)
    {
    }

}
