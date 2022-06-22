/*
    ObjectTypeClass: AuthorizationServiceConfigurationType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuthorizationServiceConfigurationType_h__
#define __OpcUaStackServer_AuthorizationServiceConfigurationType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuthorizationServiceConfigurationType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuthorizationServiceConfigurationType> SPtr;
       typedef std::vector<AuthorizationServiceConfigurationType::SPtr> Vec;
   
       AuthorizationServiceConfigurationType(void);
       AuthorizationServiceConfigurationType(const AuthorizationServiceConfigurationType& value);
       virtual ~AuthorizationServiceConfigurationType(void);

        //
        // String
        //
        void issuerEndpointUrl_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& issuerEndpointUrl_Variable(void);
        bool get_IssuerEndpointUrl_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_IssuerEndpointUrl_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void serviceCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serviceCertificate_Variable(void);
        bool get_ServiceCertificate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServiceCertificate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serviceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serviceUri_Variable(void);
        bool get_ServiceUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServiceUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr issuerEndpointUrl_Variable_;
        ServerVariable::SPtr serviceCertificate_Variable_;
        ServerVariable::SPtr serviceUri_Variable_;
   
   };

}

#endif
