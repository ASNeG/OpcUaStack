/*
    VariableTypeClass: FolderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/FolderType.h"

namespace OpcUaStackServer
{
    
    /**
     * The type for objects that organize other nodes.
     */
    FolderType::FolderType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)61);
    }
    
    /**
     * The type for objects that organize other nodes.
     */
    FolderType::FolderType(const FolderType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)61);
    }
    
    FolderType::~FolderType(void)
    {
    }

}
