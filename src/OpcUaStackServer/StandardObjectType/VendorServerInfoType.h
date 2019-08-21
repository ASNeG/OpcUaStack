/*
    ObjectTypeClass: VendorServerInfoType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_VendorServerInfoType_h__
#define __OpcUaStackServer_VendorServerInfoType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT VendorServerInfoType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<VendorServerInfoType> SPtr;
       typedef std::vector<VendorServerInfoType::SPtr> Vec;
   
       VendorServerInfoType(void);
       VendorServerInfoType(const VendorServerInfoType& value);
       virtual ~VendorServerInfoType(void);
    
      private:
   
   };

}

#endif
