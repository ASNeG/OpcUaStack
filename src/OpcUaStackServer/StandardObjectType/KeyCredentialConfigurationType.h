/*
    ObjectTypeClass: KeyCredentialConfigurationType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_KeyCredentialConfigurationType_h__
#define __OpcUaStackServer_KeyCredentialConfigurationType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT KeyCredentialConfigurationType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<KeyCredentialConfigurationType> SPtr;
       typedef std::vector<KeyCredentialConfigurationType::SPtr> Vec;
   
       KeyCredentialConfigurationType(void);
       KeyCredentialConfigurationType(const KeyCredentialConfigurationType& value);
       virtual ~KeyCredentialConfigurationType(void);

        //
        // String (Array)
        //
        void endpointUrls_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpointUrls_Variable(void);
        bool get_EndpointUrls_Variable(OpcUaDataValue& dataValue);
        bool set_EndpointUrls_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void profileUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& profileUri_Variable(void);
        bool get_ProfileUri_Variable(OpcUaDataValue& dataValue);
        bool set_ProfileUri_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void resourceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& resourceUri_Variable(void);
        bool get_ResourceUri_Variable(OpcUaDataValue& dataValue);
        bool set_ResourceUri_Variable(const OpcUaDataValue& dataValue);

        //
        // Status
        //
        void serviceStatus_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serviceStatus_Variable(void);
        bool get_ServiceStatus_Variable(OpcUaDataValue& dataValue);
        bool set_ServiceStatus_Variable(const OpcUaDataValue& dataValue);

        virtual void call_DeleteCredential_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetEncryptingKey_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_UpdateCredential_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr endpointUrls_Variable_;
        ServerVariable::SPtr profileUri_Variable_;
        ServerVariable::SPtr resourceUri_Variable_;
        ServerVariable::SPtr serviceStatus_Variable_;
        ServerMethod::SPtr deleteCredential_Method_;
        ServerMethod::SPtr getEncryptingKey_Method_;
        ServerMethod::SPtr updateCredential_Method_;
   
   };

}

#endif
