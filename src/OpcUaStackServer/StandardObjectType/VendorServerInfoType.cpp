/*
    VariableTypeClass: VendorServerInfoType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/VendorServerInfoType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * A base type for vendor specific server information.
     */
    VendorServerInfoType::VendorServerInfoType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2033);
    }
    
    /**
     * A base type for vendor specific server information.
     */
    VendorServerInfoType::VendorServerInfoType(const VendorServerInfoType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2033);
    }
    
    VendorServerInfoType::~VendorServerInfoType(void)
    {
    }

}
