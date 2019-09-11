/*
    ObjectTypeClass: RsaMinApplicationCertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_RsaMinApplicationCertificateType_h__
#define __OpcUaStackServer_RsaMinApplicationCertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT RsaMinApplicationCertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<RsaMinApplicationCertificateType> SPtr;
       typedef std::vector<RsaMinApplicationCertificateType::SPtr> Vec;
   
       RsaMinApplicationCertificateType(void);
       RsaMinApplicationCertificateType(const RsaMinApplicationCertificateType& value);
       virtual ~RsaMinApplicationCertificateType(void);
    
      private:
   
   };

}

#endif
