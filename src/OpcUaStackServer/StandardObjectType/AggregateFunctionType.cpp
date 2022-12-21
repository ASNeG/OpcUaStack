/*
    VariableTypeClass: AggregateFunctionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AggregateFunctionType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AggregateFunctionType::AggregateFunctionType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2340);
    }
    
    AggregateFunctionType::AggregateFunctionType(const AggregateFunctionType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2340);
    }
    
    AggregateFunctionType::~AggregateFunctionType(void)
    {
    }

}
