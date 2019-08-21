/*
    VariableTypeClass: UserCredentialCertificateType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/UserCredentialCertificateType.h"

namespace OpcUaStackServer
{
    
    UserCredentialCertificateType::UserCredentialCertificateType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15181);
    }
    
    UserCredentialCertificateType::UserCredentialCertificateType(const UserCredentialCertificateType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15181);
    }
    
    UserCredentialCertificateType::~UserCredentialCertificateType(void)
    {
    }

}
