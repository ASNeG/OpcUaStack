/*
    VariableTypeClass: KeyCredentialConfigurationFolderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/KeyCredentialConfigurationFolderType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    KeyCredentialConfigurationFolderType::KeyCredentialConfigurationFolderType(void)
    : ObjectBase()
    , createCredential_Method_(boost::make_shared<ServerMethod>("CreateCredential_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17496);
        setServerMethod(createCredential_Method_);
        createCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationFolderType::call_CreateCredential_Method, this, boost::placeholders::_1));
    }
    
    KeyCredentialConfigurationFolderType::KeyCredentialConfigurationFolderType(const KeyCredentialConfigurationFolderType& value)
    : ObjectBase()
    , createCredential_Method_(boost::make_shared<ServerMethod>("CreateCredential_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17496);
        setServerMethod(createCredential_Method_);
        createCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationFolderType::call_CreateCredential_Method, this, boost::placeholders::_1));
    }
    
    KeyCredentialConfigurationFolderType::~KeyCredentialConfigurationFolderType(void)
    {
    }

    void
    KeyCredentialConfigurationFolderType::call_CreateCredential_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
