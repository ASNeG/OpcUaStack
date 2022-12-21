/*
    VariableTypeClass: KeyCredentialConfigurationType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/KeyCredentialConfigurationType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    KeyCredentialConfigurationType::KeyCredentialConfigurationType(void)
    : ObjectBase()
    , endpointUrls_Variable_(boost::make_shared<ServerVariable>("EndpointUrls_Variable"))
    , profileUri_Variable_(boost::make_shared<ServerVariable>("ProfileUri_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    , serviceStatus_Variable_(boost::make_shared<ServerVariable>("ServiceStatus_Variable"))
    , deleteCredential_Method_(boost::make_shared<ServerMethod>("DeleteCredential_Method"))
    , getEncryptingKey_Method_(boost::make_shared<ServerMethod>("GetEncryptingKey_Method"))
    , updateCredential_Method_(boost::make_shared<ServerMethod>("UpdateCredential_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)18001);
        setServerVariable(endpointUrls_Variable_);
        setServerVariable(profileUri_Variable_);
        setServerVariable(resourceUri_Variable_);
        setServerVariable(serviceStatus_Variable_);
        setServerMethod(deleteCredential_Method_);
        setServerMethod(getEncryptingKey_Method_);
        setServerMethod(updateCredential_Method_);
        deleteCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_DeleteCredential_Method, this, boost::placeholders::_1));
        getEncryptingKey_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_GetEncryptingKey_Method, this, boost::placeholders::_1));
        updateCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_UpdateCredential_Method, this, boost::placeholders::_1));
    }
    
    KeyCredentialConfigurationType::KeyCredentialConfigurationType(const KeyCredentialConfigurationType& value)
    : ObjectBase()
    , endpointUrls_Variable_(boost::make_shared<ServerVariable>("EndpointUrls_Variable"))
    , profileUri_Variable_(boost::make_shared<ServerVariable>("ProfileUri_Variable"))
    , resourceUri_Variable_(boost::make_shared<ServerVariable>("ResourceUri_Variable"))
    , serviceStatus_Variable_(boost::make_shared<ServerVariable>("ServiceStatus_Variable"))
    , deleteCredential_Method_(boost::make_shared<ServerMethod>("DeleteCredential_Method"))
    , getEncryptingKey_Method_(boost::make_shared<ServerMethod>("GetEncryptingKey_Method"))
    , updateCredential_Method_(boost::make_shared<ServerMethod>("UpdateCredential_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)18001);
        setServerVariable(endpointUrls_Variable_);
        setServerVariable(profileUri_Variable_);
        setServerVariable(resourceUri_Variable_);
        setServerVariable(serviceStatus_Variable_);
        setServerMethod(deleteCredential_Method_);
        setServerMethod(getEncryptingKey_Method_);
        setServerMethod(updateCredential_Method_);
        deleteCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_DeleteCredential_Method, this, boost::placeholders::_1));
        getEncryptingKey_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_GetEncryptingKey_Method, this, boost::placeholders::_1));
        updateCredential_Method_->registerMethod(boost::bind(&KeyCredentialConfigurationType::call_UpdateCredential_Method, this, boost::placeholders::_1));
    }
    
    KeyCredentialConfigurationType::~KeyCredentialConfigurationType(void)
    {
    }

    ServerVariable::SPtr&
    KeyCredentialConfigurationType::endpointUrls_Variable(void)
    {
        return endpointUrls_Variable_;
    }

    ServerVariable::SPtr&
    KeyCredentialConfigurationType::profileUri_Variable(void)
    {
        return profileUri_Variable_;
    }

    ServerVariable::SPtr&
    KeyCredentialConfigurationType::resourceUri_Variable(void)
    {
        return resourceUri_Variable_;
    }

    ServerVariable::SPtr&
    KeyCredentialConfigurationType::serviceStatus_Variable(void)
    {
        return serviceStatus_Variable_;
    }

    void
    KeyCredentialConfigurationType::endpointUrls_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpointUrls_Variable_ = serverVariable;
    }

    void
    KeyCredentialConfigurationType::profileUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        profileUri_Variable_ = serverVariable;
    }

    void
    KeyCredentialConfigurationType::resourceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        resourceUri_Variable_ = serverVariable;
    }

    void
    KeyCredentialConfigurationType::serviceStatus_Variable(ServerVariable::SPtr& serverVariable)
    {
        serviceStatus_Variable_ = serverVariable;
    }

    bool
    KeyCredentialConfigurationType::get_EndpointUrls_Variable(OpcUaDataValue& dataValue)
    {
        return endpointUrls_Variable_->getDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::get_ProfileUri_Variable(OpcUaDataValue& dataValue)
    {
        return profileUri_Variable_->getDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::get_ResourceUri_Variable(OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->getDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::get_ServiceStatus_Variable(OpcUaDataValue& dataValue)
    {
        return serviceStatus_Variable_->getDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::set_EndpointUrls_Variable(const OpcUaDataValue& dataValue)
    {
        return endpointUrls_Variable_->setDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::set_ProfileUri_Variable(const OpcUaDataValue& dataValue)
    {
        return profileUri_Variable_->setDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::set_ResourceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return resourceUri_Variable_->setDataValue(dataValue);
    }

    bool
    KeyCredentialConfigurationType::set_ServiceStatus_Variable(const OpcUaDataValue& dataValue)
    {
        return serviceStatus_Variable_->setDataValue(dataValue);
    }

    void
    KeyCredentialConfigurationType::call_DeleteCredential_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    KeyCredentialConfigurationType::call_GetEncryptingKey_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    KeyCredentialConfigurationType::call_UpdateCredential_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
