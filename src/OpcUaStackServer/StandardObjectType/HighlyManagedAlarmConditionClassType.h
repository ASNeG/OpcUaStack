/*
    ObjectTypeClass: HighlyManagedAlarmConditionClassType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_HighlyManagedAlarmConditionClassType_h__
#define __OpcUaStackServer_HighlyManagedAlarmConditionClassType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT HighlyManagedAlarmConditionClassType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<HighlyManagedAlarmConditionClassType> SPtr;
       typedef std::vector<HighlyManagedAlarmConditionClassType::SPtr> Vec;
   
       HighlyManagedAlarmConditionClassType(void);
       HighlyManagedAlarmConditionClassType(const HighlyManagedAlarmConditionClassType& value);
       virtual ~HighlyManagedAlarmConditionClassType(void);
    
      private:
   
   };

}

#endif
