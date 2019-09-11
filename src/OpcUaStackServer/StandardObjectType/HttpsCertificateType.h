/*
    ObjectTypeClass: HttpsCertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_HttpsCertificateType_h__
#define __OpcUaStackServer_HttpsCertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT HttpsCertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<HttpsCertificateType> SPtr;
       typedef std::vector<HttpsCertificateType::SPtr> Vec;
   
       HttpsCertificateType(void);
       HttpsCertificateType(const HttpsCertificateType& value);
       virtual ~HttpsCertificateType(void);
    
      private:
   
   };

}

#endif
