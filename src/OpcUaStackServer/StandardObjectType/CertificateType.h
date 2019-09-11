/*
    ObjectTypeClass: CertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_CertificateType_h__
#define __OpcUaStackServer_CertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT CertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<CertificateType> SPtr;
       typedef std::vector<CertificateType::SPtr> Vec;
   
       CertificateType(void);
       CertificateType(const CertificateType& value);
       virtual ~CertificateType(void);
    
      private:
   
   };

}

#endif
