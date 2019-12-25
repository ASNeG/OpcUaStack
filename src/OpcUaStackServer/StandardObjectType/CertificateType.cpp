/*
    VariableTypeClass: CertificateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/CertificateType.h"

namespace OpcUaStackServer
{
    
    CertificateType::CertificateType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12556);
    }
    
    CertificateType::CertificateType(const CertificateType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12556);
    }
    
    CertificateType::~CertificateType(void)
    {
    }

}