/*
    VariableTypeClass: SystemConditionClassType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/SystemConditionClassType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SystemConditionClassType::SystemConditionClassType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11166);
    }
    
    SystemConditionClassType::SystemConditionClassType(const SystemConditionClassType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11166);
    }
    
    SystemConditionClassType::~SystemConditionClassType(void)
    {
    }

}
