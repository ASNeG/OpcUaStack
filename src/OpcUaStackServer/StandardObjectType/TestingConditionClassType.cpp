/*
    VariableTypeClass: TestingConditionClassType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TestingConditionClassType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TestingConditionClassType::TestingConditionClassType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17221);
    }
    
    TestingConditionClassType::TestingConditionClassType(const TestingConditionClassType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17221);
    }
    
    TestingConditionClassType::~TestingConditionClassType(void)
    {
    }

}