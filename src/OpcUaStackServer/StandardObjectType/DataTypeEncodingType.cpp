/*
    VariableTypeClass: DataTypeEncodingType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DataTypeEncodingType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    DataTypeEncodingType::DataTypeEncodingType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)76);
    }
    
    DataTypeEncodingType::DataTypeEncodingType(const DataTypeEncodingType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)76);
    }
    
    DataTypeEncodingType::~DataTypeEncodingType(void)
    {
    }

}
