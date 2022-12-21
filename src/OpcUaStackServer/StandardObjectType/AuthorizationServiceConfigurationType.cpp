/*
    VariableTypeClass: AuthorizationServiceConfigurationType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuthorizationServiceConfigurationType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    AuthorizationServiceConfigurationType::AuthorizationServiceConfigurationType(void)
    : ObjectBase()
    , issuerEndpointUrl_Variable_(boost::make_shared<ServerVariable>("IssuerEndpointUrl_Variable"))
    , serviceCertificate_Variable_(boost::make_shared<ServerVariable>("ServiceCertificate_Variable"))
    , serviceUri_Variable_(boost::make_shared<ServerVariable>("ServiceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17852);
        setServerVariable(issuerEndpointUrl_Variable_);
        setServerVariable(serviceCertificate_Variable_);
        setServerVariable(serviceUri_Variable_);
    }
    
    AuthorizationServiceConfigurationType::AuthorizationServiceConfigurationType(const AuthorizationServiceConfigurationType& value)
    : ObjectBase()
    , issuerEndpointUrl_Variable_(boost::make_shared<ServerVariable>("IssuerEndpointUrl_Variable"))
    , serviceCertificate_Variable_(boost::make_shared<ServerVariable>("ServiceCertificate_Variable"))
    , serviceUri_Variable_(boost::make_shared<ServerVariable>("ServiceUri_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17852);
        setServerVariable(issuerEndpointUrl_Variable_);
        setServerVariable(serviceCertificate_Variable_);
        setServerVariable(serviceUri_Variable_);
    }
    
    AuthorizationServiceConfigurationType::~AuthorizationServiceConfigurationType(void)
    {
    }

    ServerVariable::SPtr&
    AuthorizationServiceConfigurationType::issuerEndpointUrl_Variable(void)
    {
        return issuerEndpointUrl_Variable_;
    }

    ServerVariable::SPtr&
    AuthorizationServiceConfigurationType::serviceCertificate_Variable(void)
    {
        return serviceCertificate_Variable_;
    }

    ServerVariable::SPtr&
    AuthorizationServiceConfigurationType::serviceUri_Variable(void)
    {
        return serviceUri_Variable_;
    }

    void
    AuthorizationServiceConfigurationType::issuerEndpointUrl_Variable(ServerVariable::SPtr& serverVariable)
    {
        issuerEndpointUrl_Variable_ = serverVariable;
    }

    void
    AuthorizationServiceConfigurationType::serviceCertificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        serviceCertificate_Variable_ = serverVariable;
    }

    void
    AuthorizationServiceConfigurationType::serviceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        serviceUri_Variable_ = serverVariable;
    }

    bool
    AuthorizationServiceConfigurationType::get_IssuerEndpointUrl_Variable(OpcUaDataValue& dataValue)
    {
        return issuerEndpointUrl_Variable_->getDataValue(dataValue);
    }

    bool
    AuthorizationServiceConfigurationType::get_ServiceCertificate_Variable(OpcUaDataValue& dataValue)
    {
        return serviceCertificate_Variable_->getDataValue(dataValue);
    }

    bool
    AuthorizationServiceConfigurationType::get_ServiceUri_Variable(OpcUaDataValue& dataValue)
    {
        return serviceUri_Variable_->getDataValue(dataValue);
    }

    bool
    AuthorizationServiceConfigurationType::set_IssuerEndpointUrl_Variable(const OpcUaDataValue& dataValue)
    {
        return issuerEndpointUrl_Variable_->setDataValue(dataValue);
    }

    bool
    AuthorizationServiceConfigurationType::set_ServiceCertificate_Variable(const OpcUaDataValue& dataValue)
    {
        return serviceCertificate_Variable_->setDataValue(dataValue);
    }

    bool
    AuthorizationServiceConfigurationType::set_ServiceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return serviceUri_Variable_->setDataValue(dataValue);
    }

}
