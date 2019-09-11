/*
    VariableTypeClass: BaseObjectType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BaseObjectType.h"

namespace OpcUaStackServer
{
    
    /**
     * The base type for all object nodes.
     */
    BaseObjectType::BaseObjectType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)58);
    }
    
    /**
     * The base type for all object nodes.
     */
    BaseObjectType::BaseObjectType(const BaseObjectType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)58);
    }
    
    BaseObjectType::~BaseObjectType(void)
    {
    }

}
