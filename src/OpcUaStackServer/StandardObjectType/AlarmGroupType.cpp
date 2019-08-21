/*
    VariableTypeClass: AlarmGroupType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AlarmGroupType.h"

namespace OpcUaStackServer
{
    
    AlarmGroupType::AlarmGroupType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)16405);
    }
    
    AlarmGroupType::AlarmGroupType(const AlarmGroupType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)16405);
    }
    
    AlarmGroupType::~AlarmGroupType(void)
    {
    }

}
