/*
    VariableTypeClass: ApplicationCertificateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ApplicationCertificateType.h"

namespace OpcUaStackServer
{
    
    ApplicationCertificateType::ApplicationCertificateType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12557);
    }
    
    ApplicationCertificateType::ApplicationCertificateType(const ApplicationCertificateType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)12557);
    }
    
    ApplicationCertificateType::~ApplicationCertificateType(void)
    {
    }

}
