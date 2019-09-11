/*
    ObjectTypeClass: NamespacesType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NamespacesType_h__
#define __OpcUaStackServer_NamespacesType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NamespacesType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NamespacesType> SPtr;
       typedef std::vector<NamespacesType::SPtr> Vec;
   
       NamespacesType(void);
       NamespacesType(const NamespacesType& value);
       virtual ~NamespacesType(void);
    
      private:
   
   };

}

#endif
