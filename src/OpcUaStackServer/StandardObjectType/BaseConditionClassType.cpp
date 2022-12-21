/*
    VariableTypeClass: BaseConditionClassType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/BaseConditionClassType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    BaseConditionClassType::BaseConditionClassType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11163);
    }
    
    BaseConditionClassType::BaseConditionClassType(const BaseConditionClassType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11163);
    }
    
    BaseConditionClassType::~BaseConditionClassType(void)
    {
    }

}
