/*
    ObjectTypeClass: ApplicationCertificateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ApplicationCertificateType_h__
#define __OpcUaStackServer_ApplicationCertificateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ApplicationCertificateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ApplicationCertificateType> SPtr;
       typedef std::vector<ApplicationCertificateType::SPtr> Vec;
   
       ApplicationCertificateType(void);
       ApplicationCertificateType(const ApplicationCertificateType& value);
       virtual ~ApplicationCertificateType(void);
    
      private:
   
   };

}

#endif
