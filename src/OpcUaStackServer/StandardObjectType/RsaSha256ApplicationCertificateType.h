/*
    ObjectTypeClass: RsaSha256ApplicationCertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_RsaSha256ApplicationCertificateType_h__
#define __OpcUaStackServer_RsaSha256ApplicationCertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT RsaSha256ApplicationCertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<RsaSha256ApplicationCertificateType> SPtr;
       typedef std::vector<RsaSha256ApplicationCertificateType::SPtr> Vec;
   
       RsaSha256ApplicationCertificateType(void);
       RsaSha256ApplicationCertificateType(const RsaSha256ApplicationCertificateType& value);
       virtual ~RsaSha256ApplicationCertificateType(void);
    
      private:
   
   };

}

#endif
