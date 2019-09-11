/*
    ObjectTypeClass: SafetyConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SafetyConditionClassType_h__
#define __OpcUaStackServer_SafetyConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SafetyConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SafetyConditionClassType> SPtr;
       typedef std::vector<SafetyConditionClassType::SPtr> Vec;
   
       SafetyConditionClassType(void);
       SafetyConditionClassType(const SafetyConditionClassType& value);
       virtual ~SafetyConditionClassType(void);
    
      private:
   
   };

}

#endif
