/*
    VariableTypeClass: HttpsCertificateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/HttpsCertificateType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    HttpsCertificateType::HttpsCertificateType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12558);
    }
    
    HttpsCertificateType::HttpsCertificateType(const HttpsCertificateType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12558);
    }
    
    HttpsCertificateType::~HttpsCertificateType(void)
    {
    }

}
