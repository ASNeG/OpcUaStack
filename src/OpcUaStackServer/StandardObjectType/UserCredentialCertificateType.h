/*
    ObjectTypeClass: UserCredentialCertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_UserCredentialCertificateType_h__
#define __OpcUaStackServer_UserCredentialCertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT UserCredentialCertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<UserCredentialCertificateType> SPtr;
       typedef std::vector<UserCredentialCertificateType::SPtr> Vec;
   
       UserCredentialCertificateType(void);
       UserCredentialCertificateType(const UserCredentialCertificateType& value);
       virtual ~UserCredentialCertificateType(void);
    
      private:
   
   };

}

#endif
