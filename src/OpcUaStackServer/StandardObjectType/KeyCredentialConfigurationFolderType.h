/*
    ObjectTypeClass: KeyCredentialConfigurationFolderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_KeyCredentialConfigurationFolderType_h__
#define __OpcUaStackServer_KeyCredentialConfigurationFolderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT KeyCredentialConfigurationFolderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<KeyCredentialConfigurationFolderType> SPtr;
       typedef std::vector<KeyCredentialConfigurationFolderType::SPtr> Vec;
   
       KeyCredentialConfigurationFolderType(void);
       KeyCredentialConfigurationFolderType(const KeyCredentialConfigurationFolderType& value);
       virtual ~KeyCredentialConfigurationFolderType(void);

        virtual void call_CreateCredential_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr createCredential_Method_;
   
   };

}

#endif
