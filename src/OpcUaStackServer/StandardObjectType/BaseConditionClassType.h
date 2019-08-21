/*
    ObjectTypeClass: BaseConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BaseConditionClassType_h__
#define __OpcUaStackServer_BaseConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BaseConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<BaseConditionClassType> SPtr;
       typedef std::vector<BaseConditionClassType::SPtr> Vec;
   
       BaseConditionClassType(void);
       BaseConditionClassType(const BaseConditionClassType& value);
       virtual ~BaseConditionClassType(void);
    
      private:
   
   };

}

#endif
