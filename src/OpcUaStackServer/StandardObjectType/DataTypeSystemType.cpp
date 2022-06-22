/*
    VariableTypeClass: DataTypeSystemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DataTypeSystemType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    DataTypeSystemType::DataTypeSystemType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)75);
    }
    
    DataTypeSystemType::DataTypeSystemType(const DataTypeSystemType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)75);
    }
    
    DataTypeSystemType::~DataTypeSystemType(void)
    {
    }

}
