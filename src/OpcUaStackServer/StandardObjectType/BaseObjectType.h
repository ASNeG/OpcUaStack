/*
    ObjectTypeClass: BaseObjectType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BaseObjectType_h__
#define __OpcUaStackServer_BaseObjectType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BaseObjectType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BaseObjectType> SPtr;
       typedef std::vector<BaseObjectType::SPtr> Vec;
   
       BaseObjectType(void);
       BaseObjectType(const BaseObjectType& value);
       virtual ~BaseObjectType(void);
    
      private:
   
   };

}

#endif
